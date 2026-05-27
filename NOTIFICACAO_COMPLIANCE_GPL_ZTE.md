# NOTIFICAÇÃO DE DESCUMPRIMENTO DA LICENÇA GPL v2 — ZTE CORPORATION

**Para:** ZTE Corporation / Nubia Technology Support & Compliance Department  
**Assunto:** Solicitação Formal do Código-Fonte Completo e Correspondente do Kernel do RedMagic 11 Pro (NX809J) — Em conformidade com a GNU General Public License v2 (GPLv2)  
**Dispositivo:** Nubia RedMagic 11 Pro (Model: NX809J)  
**Processador (SoC):** Qualcomm Snapdragon 8 Elite / Gen 5 (SM8750/SM8850 - Codenames: `canoe` / `qwjujube`)  
**Versão do Kernel:** Linux Kernel 6.12.23 (Android 16 GKI)  

---

## 📄 CARTA DE APRESENTAÇÃO (MENSAGEM A ENVIAR)

*Prezada Equipe de Suporte e Compliance da ZTE / Nubia,*

*Como usuário do dispositivo Nubia RedMagic 11 Pro (NX809J) e membro da comunidade de desenvolvimento de software, venho por meio desta solicitar formalmente o cumprimento integral das obrigações legais previstas pela licença **GNU General Public License versão 2 (GPLv2)**, que rege a distribuição do Kernel Linux utilizado no firmware oficial deste dispositivo.*

*Atualmente, a ZTE disponibilizou o código-fonte do kernel de forma incompleta. A árvore de diretórios fornecida carece de arquivos essenciais de configuração, cabeçalhos de API proprietários, módulos completos de rede sem fio (WLAN), e drivers específicos da ZTE que rodam no espaço de memória do kernel (kernel-space). Devido a essas ausências, **é tecnicamente impossível compilar e inicializar (boot) um kernel funcional a partir do código fornecido**, o que constitui uma violação direta da Seção 3 da licença GPLv2.*

*A Seção 3 da GPLv2 estabelece que o distribuidor do binário deve fornecer o **"código-fonte completo e correspondente"**, definido especificamente como: "a forma preferencial do trabalho para fazer modificações" incluindo "todos os códigos-fonte para todos os módulos que ele contém, mais quaisquer arquivos de definição de interface associados, bem como os scripts usados para controlar a compilação e instalação do executável".*

*Para facilitar a resolução deste problema, nossa equipe de engenharia realizou uma auditoria técnica detalhada, listando de forma exata todos os arquivos de configuração, cabeçalhos privados e códigos de drivers que foram omitidos na liberação pública. O relatório técnico detalhado encontra-se anexo abaixo.*

*Solicitamos que a ZTE providencie a liberação de um pacote de código-fonte atualizado contendo todos esses elementos faltantes ou incorpore-os no repositório oficial de publicação de código de vocês.*

*Aguardo seu retorno no prazo legal de resposta sobre a disponibilização dos fontes.*

*Atenciosamente,*  
*Coding-BR / Ideal Creative*  
*Contato: idealcreativesuporte@idealcreative.com.br*  

---

## 📊 RELATÓRIO TÉCNICO DE AUDITORIA DE COMPILAÇÃO (GPL AUDIT)

Abaixo estão detalhados os componentes indispensáveis que estão ausentes ou corrompidos na liberação atual de código da ZTE:

### 1. Ausência do Fragmento de Configuração da Plataforma (Platform Defconfig)
* **Arquivo Ausente:** `canoe.fragment` (ou o arquivo equivalente de configuração da placa/plataforma para a SoC SM8750/SM8850).
* **Localização Esperada:** `kernel_platform/common/arch/arm64/configs/`
* **Impacto:** Ao compilar apenas com a configuração padrão do Android GKI (`gki_defconfig`), todos os drivers de plataforma específicos da Qualcomm (como SCM - Secure Channel Manager, SMMU, reguladores de tensão, controladores de clock RPMH e conexões de barramento) permanecem desativados. Isso impossibilita a compilação e o carregamento de **194 módulos de plataforma cruciais** que constam na imagem oficial do smartphone.

### 2. Omissão Completa do Driver WLAN (Wireless LAN Host Driver)
* **Diretórios Ausentes:**
  * `vendor/qcom/opensource/wlan/qcacld-3.0/`
  * `vendor/qcom/opensource/wlan/qca-wifi-host-cmn/`
* **Conteúdo Entregue pela ZTE:** Apenas cabeçalhos de API (`fw-api/`) e mapeamentos de device tree (`wlan-devicetree/`).
* **Impacto:** O driver de rede sem fio (Wi-Fi) foi totalmente omitido. O firmware oficial do telefone executa o módulo `qca_cld3_peach_v2.ko` juntamente com drivers auxiliares (`cnss2.ko`, `cnss_nl.ko`, `cnss_prealloc.ko`, `cnss_utils.ko`). A falta desse código impede que o sinal de rede Wi-Fi funcione em qualquer kernel customizado compilado pelos usuários.

### 3. Drivers de Recursos Multimídia Ausentes (MMRM e Synx)
Estes dois frameworks controlam a coordenação de energia e sincronização de hardware entre os chips de câmera, vídeo e GPU:
* **Módulo MMRM Ausente:** Fonte em `vendor/qcom/opensource/mmrm-driver/` e o cabeçalho associado `<linux/soc/qcom/msm_mmrm.h>`.
* **Módulo Synx Ausente:** Fonte em `vendor/qcom/opensource/synx-kernel/` e os cabeçalhos `<synx_api.h>` e `<synx_interop.h>`.
* **Impacto:** Drivers de display, vídeo e câmera falham ao tentar compilar por não encontrarem os cabeçalhos. O firmware oficial carrega os binários correspondentes `msm_mmrm.ko` e `synx_driver.ko`.

### 4. Cabeçalhos de Plataforma Qualcomm Ausentes (Omitidos)
Os cabeçalhos abaixo são importados pelos próprios códigos de drivers que a ZTE disponibilizou, mas os cabeçalhos físicos não foram entregues na pasta `kernel_platform/common/include/linux/` (ou subpastas equivalentes):
* `<linux/mem-buf.h>` — Utilizado pelo driver de GPU (KGSL), segurança (QSEECOM) e vídeo.
* `<linux/msm_ion.h>` — Alocador ION clássico do SecureMSM.
* `<linux/msm_dma_iommu_mapping.h>` — Mapeador DMA-IOMMU para driver de vídeo.
* `<linux/qcom-iommu-util.h>` — Controle de fault, SMMU e switches de segurança de display.
* `<soc/qcom/minidump.h>` — Gerenciador de dump de falhas (panic logs).
* `<linux/hdcp_qseecom.h>` — Controle do protocolo de proteção de mídia de display HDCP.
* `<linux/soc/qcom/battery_charger.h>` — Assinatura de notificação do driver de haptics.
* `<linux/qti-regmap-debugfs.h>` — Depuração do codec de áudio.

### 5. Cabeçalhos e APIs Incompletos no Kernel Principal
Os drivers que a ZTE incluiu chamam funções no kernel que não estão declaradas nos headers correspondentes entregues:
* `rproc_set_state()` — Faltando em `<linux/remoteproc/qcom_rproc.h>` (Necessário em `hfi_smmu.c`).
* `msm_gpio_mpm_wake_set()` — Faltando em `<linux/pinctrl/qcom-pinctrl.h>` (Necessário em áudio e bluetooth).
* `msm_gpio_get_pin_address()` — Faltando em `<linux/pinctrl/qcom-pinctrl.h>` (Necessário em display).
* `socinfo_get_part_info()`, `socinfo_get_part_count()`, `socinfo_get_subpart_info()` — Faltando em `<soc/qcom/socinfo.h>` (Necessário em display).

### 6. Ausência do Código dos Drivers Proprietários ZTE (Kernel-Space Modules)
Os **12 drivers de kernel a seguir** são desenvolvidos ou modificados pela ZTE e rodam diretamente integrados no kernel de fábrica (`vendor_boot` ou `vendor_dlkm`), mas os códigos-fonte não constam na pasta `vendor/qcom/opensource/zte-drivers/` ou adjacências. Como estes drivers não rodam no espaço de usuário (user-space), eles são vinculados estática ou dinamicamente aos símbolos internos do Kernel Linux, tornando-se obras derivadas e legalmente sujeitos à liberação sob os termos da licença GPL:
1. `zte_charger_policy.ko` — Política de controle e proteção de carregamento térmico.
2. `zte_power_supply.ko` — Gerenciamento da fonte de alimentação e baterias.
3. `zte_led.ko` — Driver físico dos efeitos de luz RGB inteligente do dispositivo.
4. `zte_fingerprint.ko` — Ponte física do leitor óptico de digitais sob a tela com a CPU.
5. `zte_misc.ko` — Interface global e barramento de barreira de sinal da ZTE.
6. `zte_ir.ko` — Driver de controle de modulação e disparo do emissor de infravermelho.
7. `zte_tpd.ko` — Touch Protection Driver (mecanismo que lida com o touchscreen Synaptics TCM via SPI).
8. `zte_imem_info.ko` — Mapeador físico e telemetria de boot via IMEM.
9. `zte_sensor_sensitivity.ko` — Ajuste físico e calibração de sensores (acelerômetro, giroscópio).
10. `zte_stats_info.ko` — Canal netlink genérico para estatísticas de processos.
11. `zte_reboot_ext.ko` — Capturador de panics e bootreason salvos em células NVMEM.
12. `zte_ramdisk_reboot.ko` — Gerenciador de reboot tardio em nível de ramdisk.

### 7. Erros de Compilação do Build System Entregue (Techpack de Áudio)
* **Arquivo:** `vendor/qcom/opensource/audio-kernel/dsp/aw882xx/Kbuild` na linha 89.
* **Problema:** Um erro de sintaxe adicionado manualmente pela engenharia da ZTE (`$(ROOT_DIR)/msm-kernel/include` sem o prefixo `-I`) faz com que o Clang aborte a compilação do driver do codec de áudio. Além disso, o Makefile entra em loop infinito por falta da variável de definição do módulo principal do kernel (`MODNAME=audio`).

---

## 🔧 SINTOMA TÉCNICO CRÍTICO EM CONCURSO (BOOT HANG)

Ao tentarmos compilar o kernel fornecido e desenvolver implementações de stubs de compatibilidade para suprir as dependências dos componentes de hardware omitidos, o dispositivo depara-se com um travamento de boot inultrapassável devido ao firmware proprietário (`PDP0`) esperar inicializações síncronas de mailbox/SCMI que dependem dos códigos de plataforma ocultados:

```
[0.181496] arm-scmi arm-scmi.1.auto: Failed to get FC for protocol 13 [MSG_ID:6 / RES_ID:0] - ret:-22
...
[1.112952] arm-scmi arm-scmi.1.auto: timed out in resp (caller: do_xfer+0x140/0x4ec)
[1.116211] scmi_cpuss_telemetry_probe: Not able to find shared memory location
[1.774983] adsp-loader soc:qcom,msm-adsp-loader: fail to get rproc
```

Este timeout do SCMI trava a subida do ADSP/CDSP (remoteproc), o que consequentemente impede a inicialização do driver de segurança `keymint`, inviabilizando que o gerenciador de volumes `vold` consiga descriptografar a partição `/data` criptografada por chaves físicas (FBE - File-Based Encryption). Sem poder descriptografar a partição `/data`, o sistema operacional do RedMagic fica congelado na tela inicial de logo indefinitely.

**Este travamento ocorre precisamente porque a árvore de compilação da ZTE está incompleta, impedindo que o sistema configure a mailbox do coprocessador em perfeita sincronia com o firmware de boot.**

---

### 8. Precedentes da Indústria e Padrão de Mercado (Compliance de Outros Fabricantes)
Para evitar quaisquer dúvidas quanto à obrigatoriedade da entrega do código-fonte completo dos drivers de kernel (incluindo aqueles desenvolvidos in-house ou sob medida para controladores de toque, carregamento e energia), ressaltamos que outros fabricantes líderes do setor que distribuem dispositivos Android baseados no Linux Kernel disponibilizam rotineiramente a totalidade de seus fontes de kernel-space em seus repositórios públicos oficiais, contendo exatamente o tipo de arquivo que a ZTE omitiu:
* **Xiaomi (Organização `MiCode` no GitHub):** Disponibiliza nos repositórios públicos (como em [MiCode/Xiaomi_Kernel_OpenSource](https://github.com/MiCode/Xiaomi_Kernel_OpenSource)) todo o código-fonte dos drivers de tela física em kernel-space. Por exemplo, na branch [sweet-r-oss](https://github.com/MiCode/Xiaomi_Kernel_OpenSource/tree/sweet-r-oss/drivers/input/touchscreen) (Redmi Note 10 Pro) e na branch [star-r-oss](https://github.com/MiCode/Xiaomi_Kernel_OpenSource/tree/star-r-oss/drivers/input/touchscreen) (Mi 11 Pro/Ultra e Mi 11 Lite 5G), encontram-se os drivers completos de touchscreen (Goodix, Synaptics e Focaltech), bem como o gerenciamento completo de carga e reguladores de tensão em `drivers/power/supply/` para todos os seus flagships (sem stubs ou blobs pré-compilados).
* **OnePlus / OPPO / Realme (Organização `OnePlusOSS` no GitHub):** Fornecem árvores de kernel completas de produção que compilam nativamente. Por exemplo, no repositório [android_kernel_oneplus_sm8350](https://github.com/OnePlusOSS/android_kernel_oneplus_sm8350) (OnePlus 9 series), os drivers de touchscreen e barramento de entrada encontram-se abertamente em [drivers/input/touchscreen](https://github.com/OnePlusOSS/android_kernel_oneplus_sm8350/tree/master/drivers/input/touchscreen) e os drivers de controle de bateria e carregamento proprietário encontram-se em `drivers/power/supply/` (referenciados como oplus/oplus_chg).
* **Samsung (Portal `opensource.samsung.com`):** Publica de forma estrita o código-fonte de todos os drivers proprietários que rodam em kernel-space (incluindo firmware de toque e gerenciadores de bateria de terceiros) e os arquivos de configuração de compilação exatos (`defconfig`) de fábrica.
* **Motorola / Lenovo (Organização `MotorolaMobilityLLC` no GitHub):** Disponibiliza no GitHub as árvores de código-fonte de kernel 100% funcionais, incluindo todos os drivers de plataforma e arquivos de configuração específicos da placa.

A recusa ou omissão dessas partes do software em espaço de kernel por parte da ZTE coloca o RedMagic 11 Pro em desconformidade direta com as práticas aceitas do ecossistema e com os termos da licença GPL v2.

---

## 🎯 RESOLUÇÃO EXIGIDA

Solicitamos formalmente que a ZTE forneça o **pacote completo do código-fonte e suas receitas de compilação**, compreendendo:
1. Todos os diretórios e repositórios out-of-tree (`wlan/`, `mmrm-driver/`, `synx-kernel/`, `zte-drivers/`) contendo o código-fonte em linguagem C original (e não binários compilados stubs ou .ko fechados).
2. O arquivo de configuração de compilação completo (`canoe.fragment` e/ou `canoe_defconfig`) que reflita exatamente o binário operacional empacotado nos celulares RedMagic 11 Pro de produção.
3. A correção estrutural de cabeçalhos do kernel principal para garantir que os módulos possam ser montados e linkados dinamicamente via modpost sem warnings de CFI restritivos ou assinaturas de tipos corrompidos.

