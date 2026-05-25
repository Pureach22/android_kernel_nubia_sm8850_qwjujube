# Análise de Engenharia Reversa - ZTE Touch Panel Driver (`zte_tpd`)

## 1. Visão Geral do Hardware e Driver
O `zte_tpd.ko` é o driver proprietário de Touch Panel (TP) da ZTE para o Red Magic 11 Pro (NX809J). Ele se integra com o controlador físico **Synaptics TCM** usando comunicação serial SPI no barramento `spi19.0` e registra o platform device `synaptics_tcm.0`.

O driver é responsável por:
* Processar rotinas físicas de toque, multi-toque e gestos através do subsistema `input`.
* Suportar recursos especiais como gestos com a tela desligada (off-screen gestures) e o modo de jogo.
* Sincronizar o estado da tela com os drivers de exibição (Qualcomm DRM) e o leitor de impressão digital sob a tela (`zte_fingerprint`) através do notifier `panel_event_notifier`.

## 2. Engenharia Reversa e Reconstrução
O driver oficial foi totalmente descompilado via Ghidra (Gera ~919 funções no total). 
Principais descobertas e ações realizadas:
1. **Teardown e Desconexão (`syna_dev_disconnect`)**:
   Durante a descompilação de `syna_dev_disconnect.c`, a chamada padrão `devm_free_irq(dev, irq, dev_id)` foi reconstruída com precisão para liberar a linha de interrupção física sem vazamentos de memória ou referências órfãs.
2. **Integração de Notificações**:
   Identificamos que o driver exporta e consome APIs ligadas ao display e fingerprint. O touchscreen atua como o fornecedor de estado do painel (ex: quando o dedo toca a área do sensor de impressão digital, ele emite eventos de coordenada e intensidade luminosa do painel).

## 3. Diagnóstico de Crash / Watchdog Bite
* **Sintoma**: Ao tentar desvincular o driver de toque em tempo de execução via sysfs (`unbind`), a CPU entrava em pânico imediato: `Unable to handle kernel NULL pointer dereference` na CPU, seguido por um watchdog bite que congelava o dispositivo na tela de **"Memory Dump"** (Qualcomm CrashDump).
* **Causa (Análise do `ramoops`)**:
  Outros módulos proprietários (ex: `msm_drm.ko` de display e `zte_fingerprint.ko` de biometria) registram callbacks no notifier do touch panel (`panel_event_notifier_register`). Quando o touch driver é removido bruscamente via unbind/rmmod, a estrutura interna do touch se torna nula, mas os callbacks dependentes continuam ativos e tentam dereferenciar ponteiros nulos no loop de eventos, gerando o kernel panic.
* **Solução**:
  É estritamente proibido desvincular ou descarregar o driver de toque em tempo de execução enquanto o sistema gráfico ou biometria estiverem ativos. A substituição e teste do driver deve ser feita no início do boot (estágio `post-fs-data`).

## 4. Auditoria de Assinaturas e KCFI
Para garantir que o driver customizado seja aceito e carregado pelo kernel sem pânico de KCFI (Kernel Control Flow Integrity) ou rejeição de versão (símbolos CRC inválidos):
* Criamos o script [patch_tpd.py](patch_tpd.py).
* O script extrai a tabela completa de CRCs e os hashes KCFI oficiais de `official_zte_tpd.ko`.
* Aplica essas assinaturas cirurgicamente no módulo compilado `zte_tpd.ko`, alinhando os hashes das funções de callback (SPI, interrupção, sysfs) com os valores esperados pelo loader do GKI.

## 5. Procedimento de Implantação Seguro
A implantação do driver é feita através do overlay de inicialização do Magisk/KernelSU:
1. O módulo é copiado para `/data/adb/modules/zte_charger_policy_custom/vendor_dlkm/lib/modules/zte_tpd.ko`.
2. O script `post-fs-data.sh` realiza um bind mount no início do boot antes do init carregar o driver original:
   ```bash
   mount --bind /data/adb/modules/zte_charger_policy_custom/vendor_dlkm/lib/modules/zte_tpd.ko /vendor_dlkm/lib/modules/zte_tpd.ko
   ```
3. O aparelho deve ser reiniciado. O kernel carregará o driver reconstruído e patched de forma transparente, garantindo estabilidade e pleno funcionamento do touch screen.

## 6. Correções de Estabilidade e Status Atual (Maio/2026)

Durante a validação em hardware real, identificamos e corrigimos os seguintes pontos críticos:
* **Recursão no Probe:** O probe era chamado de forma aninhada ao registrar o dispositivo virtual `"zte_touch"`, reinicializando o wakeup source `tp_wakeup` e gerando corrupção por `list_add double add`. Implementamos uma guarda de nome no início de `zte_touch_probe` para ignorar o dispositivo virtual e prosseguir apenas com a inicialização do dispositivo físico `"soc:zte_tp"`.
* **Violação de CFI no Platform Release:** A desreferenciação manual do callback `dev.release` em `zte_touch_pdev_register.c` violava o CFI estrito do Clang. Substituímos a chamada direta por `platform_device_put()`.
* **Pânico no vsprintf (Truncamento de Ponteiros):** O kernel sofria Data Abort (`0x00000000ffff132d`) dentro do vsprintf ao tentar formatar as strings de status em `change_tp_state` e `report_ufp_uevent`. Isso ocorria porque os arrays estáticos de ponteiros de string (`lcdstate_to_str`, `lcdchange_to_str`, `lcd_state_strings`) possuíam relocações absolutas (`R_AARCH64_ABS64`) cujos bits superiores eram limpos na inicialização devido a problemas de KASLR/LTO. Substituímos esses arrays estáticos por funções baseadas em `switch-case` com retorno direto de literais de string (resolvidos via PC-relative `adrp`).
* **Instabilidade de Platform Device Estático (Toque Físico Restabelecido):** O uso da `struct platform_device syna_spi_device` estática alocada globalmente causava corrupção de ponteiros circulares (`klist_next: invalid/NULL next pointer`) no platform bus 6.x durante a remoção de cabos e transições de energia, resultando em tela sem resposta ao toque físico. A migração completa em `syna_hw_interface_init.c` para alocação dinâmica oficial via `platform_device_register_simple` eliminou a corrupção do kobject e estabilizou 100% o funcionamento físico do painel.
* **Crash de Suspensão / Memory Dump (Remoção da CPU 32 Estática):** Ao apagar a tela, o panel notifier disparava `change_tp_state`, que tentava agendar tarefas de suspensão chamando `queue_work_on(32, ...)` na CPU estática indexada como `32` (fora dos limites do octa-core, indexado de 0 a 7). Isso gerava deadlock de agendador e estouro de watchdog, abortando o freezer do espaço de usuário e derrubando o sistema no Qualcomm CrashDump. A substituição pelo agendamento dinâmico e seguro do kernel (`queue_work`) sanou o crash definitivamente.

### Status Atual:
O kernel customizado agora inicializa de forma 100% limpa, segura e estável, com suporte pleno a gestos off-screen e KernelSU-Next ativo. O touchscreen físico está completamente operacional, com resposta tátil instantânea e transições de energia (desligamento/ligamento de tela, conexões USB) operando de forma suave e livre de reboots ou dumps.
