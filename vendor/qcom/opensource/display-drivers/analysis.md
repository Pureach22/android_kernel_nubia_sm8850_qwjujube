# Análise de Engenharia Reversa e Compilação: display-drivers (msm_drm.ko)

## 1. Visão Geral
Este documento documenta os problemas identificados, soluções implementadas e descobertas relativas ao techpack de Display da Qualcomm (`vendor/qcom/opensource/display-drivers`) para compatibilidade com o kernel do RedMagic 11 Pro (NX809J).

## 2. Gaps e Resoluções de Compilação

### A. SMMU Proxy Include Paths
* **Problema:** Erro de compilação por falta do cabeçalho `<qti-smmu-proxy.h>`.
* **Causa:** O techpack de Display usa o SMMU proxy que pertence ao techpack de `securemsm-kernel`, o qual reside em um diretório irmão.
* **Resolução:** Adicionado `-I$(srctree)/../../vendor/qcom/opensource/securemsm-kernel` aos caminhos de busca de cabeçalhos no arquivo `Kbuild` de display-drivers.

### B. Shift-Count Warning no DMA Bit Mask
* **Problema:** Warning tratado como erro (`-Werror`) devido a `DMA_BIT_MASK(64)` em `sde_kms.c`.
* **Causa:** Uso de `DMA_BIT_MASK(64)` em sistemas de 64 bits por vezes causa shift warnings com otimização ativada.
* **Resolução:** Substituído `DMA_BIT_MASK(64)` por `~0ULL` diretamente em `sde_kms.c`.

### C. Declarações e Stubs de Clocks/GPIO/Socinfo
* **Problema:** Falta de declarações de funções privadas do ecossistema Qualcomm:
  * `msm_gpio_get_pin_address`
  * `socinfo_get_part_info`, `socinfo_get_part_count`, `socinfo_get_subpart_info`
  * Parâmetro `PART_DISPLAY` do enum de Socinfo.
  * `CLKFLAG_RETAIN_MEM` e `CLKFLAG_NORETAIN_MEM` para o voto de clocks de display.
* **Resolução:**
  * Declarado `msm_gpio_get_pin_address` no cabeçalho `linux/pinctrl/qcom-pinctrl.h`.
  * Declarados os métodos de partição/subpartição socinfo e mapeada a macro `PART_DISPLAY` para `SOCINFO_PART_DISPLAY` em `soc/qcom/socinfo.h`.
  * Atualizadas as assinaturas em `drivers/soc/qcom/zte_parity.c` para compatibilidade exata de tipos (por exemplo, `socinfo_get_subpart_info` com 3 argumentos).
  * Definidos os flags `CLKFLAG_RETAIN_MEM` (`0x00000040`) e `CLKFLAG_NORETAIN_MEM` (`0x00000080`) no cabeçalho `linux/clk/qcom.h`.

### D. Inclusão Indireta de pm_wakeup.h
* **Problema:** Erro `#error "please don't include this file directly"` ao compilar `sde_power_handle.c`.
* **Causa:** Em kernels mais recentes, `<linux/pm_wakeup.h>` exige que `<linux/device.h>` seja incluído antes para correta declaração da struct `device`.
* **Resolução:** Incluído `<linux/device.h>` antes de `<linux/pm_wakeup.h>` no arquivo `sde_power_handle.c`.

### E. Incompatibilidade de Tipo de Ponteiro para CRM
* **Problema:** Erro de atribuição e passagem de ponteiros de tipo incompatível entre `struct device *` e `struct crm_dev *`.
* **Causa:** O membro `crm_dev` da estrutura `struct sde_cesta` estava tipado como `const struct device *` em `sde_cesta.h`, enquanto as APIs do CRM esperam `const struct crm_dev *`.
* **Resolução:** Corrigida a declaração de `crm_dev` para `const struct crm_dev *` em `sde_cesta.h`.

## 3. Resultado Final
O módulo de display `msm_drm.ko` de **39MB** foi compilado e gerado com sucesso sem erros de sintaxe ou de link, e está pronto para integração.
