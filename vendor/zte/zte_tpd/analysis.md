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
