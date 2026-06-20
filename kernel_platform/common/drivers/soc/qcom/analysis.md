# Análise de Símbolos Duplicados e Resolução de Conflitos de Modulagem - drivers/soc/qcom

Este documento documenta o mapeamento de símbolos proprietários da ZTE e da Qualcomm que estavam gerando conflitos de duplicidade (`Exec format error` / `exports duplicate symbol`) ao inicializar o kernel customizado com módulos dinâmicos carregados a partir do ramdisk (recovery/boot image).

## Histórico de Resoluções por Fase

### Fase 1 a 3: KGSL / Gráficos
* **Símbolos desativados**: `kgsl_pwrctrl_*`
* **Motivo**: Conflito com o driver KGSL proprietário (`msm_kgsl.ko`), que já exporta/define a lógica de gerenciamento de energia e GPU.

### Fase 4: IOMMU & MemBuf Core
* **Símbolos desativados**: `qcom_iommu_enable_s1_translation`, `mem_buf_dma_buf_set_destructor`
* **Motivo**: Conflito com a inicialização de IOMMU e buffers de memória compartilhada do sistema.

### Fase 5: IOMMU ASID & IPC Logging
* **Símbolos desativados**: `qcom_iommu_get_asid_nr`, `ipc_log_context_create`, `ipc_log_context_destroy`, `ipc_log_string`
* **Motivo**: O mecanismo de log IPC proprietário e a resolução de ASID do IOMMU causavam falhas no carregamento de múltiplos drivers dependentes.

### Fase 6: Resto do IOMMU
* **Símbolos desativados**: `qcom_iommu_get_context_bank_nr` e stubs TLB skip restantes.
* **Motivo**: Isolamento completo dos stubs estáticos de IOMMU para delegação nativa.

### Fase 7: Coresight Resource Manager (CRM)
* **Símbolos desativados**: `crm_write_pwr_states`, `crm_write_perf_ol`, `crm_get_device`
* **Motivo**: O módulo dinâmico `crm_v2.ko` define nativamente essas funções para gerenciamento de perfis de Coresight.

### Fase 8: RPMH e Diagnóstico de Clocks
* **Símbolos desativados**: `rpmh_write_sleep_and_wake`, `rpmh_mode_solver_set`, `qcom_clk_dump`
* **Motivo**: Conflito com o driver do regulador de hardware RPMH (`qcom_rpmh.ko`) e despejo de clocks.

### Fase 9: Símbolos do Driver de Clock (`clk-qcom.ko`)
* **Símbolos desativados**:
  * `qcom_clk_set_flags`
  * `qcom_clk_crmb_set_rate`
  * `qcom_clk_crmb_set_pwr`
* **Motivo**: Conflito direto no carregamento de `clk-qcom.ko`, que exporta de forma nativa e proprietária estes símbolos. A desativação desses stubs no kernel resolve o `Exec format error` do driver de clock.

### Fase 10: Símbolos do Driver DCVS (`qcom-dcvs.ko`)
* **Símbolos desativados**:
  * `qcom_dcvs_register_voter`
  * `qcom_dcvs_unregister_voter`
  * `qcom_dcvs_update_votes`
  * `qcom_dcvs_hw_minmax_get`
* **Motivo**: Conflito direto no carregamento do módulo `qcom-dcvs.ko` devido a símbolos duplicados exportados estaticamente no kernel. Desativando estes stubs estáticos em `zte_parity.c`, o carregamento e inicialização dinâmica do DCVS do hardware é delegado com sucesso ao driver Qualcomm.

### Fase 11: Resolução em Massa de Múltiplos Conflitos Tardios de Módulos (HW Fence, USB, Painel, SMMU, Sysstats, Perf)
* **Símbolos desativados**:
  * `msm_hw_fence_*`
  * `dwc3_msm_set_dp_mode`
  * `panel_event_notifier_*`
  * `smmu_proxy_*`
  * `sysstats_*`
  * `msm_perf_events_update`
* **Motivo**: Resolução de conflitos de exportação com múltiplos drivers dinâmicos do ecossistema Qualcomm (`msm_hw_fence.ko`, `dwc3_msm.ko`, `panel_event_notifier.ko`, `smmu_proxy_dlkm.ko`, `lsm_sysstats.ko`, `msm_performance.ko`).

### Fase 12: Símbolos do Driver AltMode (`altmode_glink.ko`)
* **Símbolos desativados**:
  * `altmode_register_notifier`
  * `altmode_deregister_notifier`
  * `altmode_register_client`
  * `altmode_deregister_client`
  * `altmode_send_data`
* **Motivo**: Conflito de símbolos duplicados no carregamento dinâmico do driver de modo alternativo USB-C / DisplayPort (`altmode_glink.ko`). Desativando os stubs estáticos no kernel, delegamos o gerenciamento de AltMode nativamente.

### Fase 13: Símbolos do Driver Synx (`synx_driver.ko`)
* **Símbolos desativados**:
  * `synx_initialize`
  * `synx_create`
  * `synx_signal`
  * `synx_import`
  * `synx_release`
  * `synx_uninitialize`
* **Motivo**: Conflito de símbolos duplicados com o driver de sincronização de hardware fence (`synx_driver.ko`). Ao desativar esses stubs estáticos no kernel, as chamadas de sincronização entre os drivers de vídeo, display e câmera são gerenciadas pelo driver dinâmico real.

---
## Conclusão da Abordagem
A desativação sistemática de stubs redundantes em `zte_parity.c` garante que os drivers oficiais e assinados da ZTE/Qualcomm carregados dinamicamente possam registrar seus símbolos globais sem colidir com as definições estáticas do kernel, assegurando a paridade binária e a integridade do ecossistema Android sem causar Kernel Panics.
