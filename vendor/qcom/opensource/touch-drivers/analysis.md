# Análise de Portabilidade e Modificações - Touch Drivers (NX809J)

Este documento detalha o processo de portabilidade e as modificações realizadas no techpack `touch-drivers` para compilação bem-sucedida sob o Kernel GKI 6.12 da firmware userdebug do Red Magic 11 Pro (NX809J).

---

## 1. Mapeamento de Gaps e Dependências

Durante a triagem inicial, identificou-se que o driver Synaptics TCM (`synaptics_tcm`) possuía forte dependência de subsistemas Qualcomm que não estão expostos no ambiente GKI padrão, além de incompatibilidades com APIs modificadas a partir do Kernel 6.1.

### Principais Falhas e Soluções:

1. **Dependência do Hipervisor Gunyah (VM/Message Queue):**
   * **Problema:** O driver tentava incluir headers ausentes: `<linux/gunyah/gh_mem_notifier.h>`, `<linux/gunyah/gh_irq_lend.h>`, `<linux/gunyah/gh_rm_drv.h>` e `<linux/gunyah/gh_msgq.h>`.
   * **Solução:** Foram criados stubs locais e definições vazias seguras para esses cabeçalhos em `vendor/qcom/opensource/touch-drivers/include/linux/gunyah/` para permitir a compilação limpa sem alterar a lógica principal.

2. **Acoplamento Circular com Display-Drivers (`drm_panel.h`):**
   * **Problema:** O driver de toque depende do driver de display para receber notificações de eventos do painel LCD (como transições de estado para habilitar/desabilitar gestos de tela desligada).
   * **Solução:** Injeção global do header `drm_panel.h` via diretiva `Kbuild` (`ccflags-y += -include drm/drm_panel.h`), evitando a importação explícita de caminhos cruzados complexos e resolvendo todas as referências a `struct drm_panel`.

3. **Conflito de Definições de Macros (`MIN` e `MAX`):**
   * **Problema:** Redefinição de macros utilitárias `MIN`/`MAX` no arquivo `synaptics_tcm_core.h` gerava interrupções pelo compilador.
   * **Solução:** Proteção das macros com guards `#ifndef MIN` / `#ifndef MAX`.

4. **Remoção de Funções e APIs no Kernel 6.12:**
   * **Problema 1:** A API `of_get_named_gpio_flags` foi removida em kernels mais novos em prol do subsistema `gpiod`.
   * **Solução 1:** Implementação de stubs inlines compatíveis usando `of_get_named_gpio` nos arquivos de transporte (`synaptics_tcm_i2c.c` e `synaptics_tcm_spi.c`).
   * **Problema 2:** Símbolos pinctrl como `devm_pinctrl_get` e `pinctrl_select_state` não estavam declarados em `synaptics_tcm_core.c`.
   * **Solução 2:** Inclusão explícita de `<linux/pinctrl/consumer.h>`.

5. **Evolução de Assinaturas de Drivers de Barramento (Kernel >= 6.1):**
   * **Problema 1:** A função de `probe` de `struct i2c_driver` não aceita mais a struct de ID de dispositivo (`const struct i2c_device_id *`).
   * **Solução 1:** Modificação da assinatura de `syna_tcm_i2c_probe` condicionalmente usando macros de versão do kernel.
   * **Problema 2:** O callback `.remove` de drivers de plataforma (`platform_driver`) passou de `int` para `void`.
   * **Solução 2:** Adaptação de `syna_tcm_remove` para retornar `void` sob kernels superiores a 6.1.0.

---

## 2. Binários Produzidos

A compilação gerou os seguintes módulos prontos para empacotamento:
* `synaptics_tcm_ts.ko` (Driver core e transportes Synaptics)
* `goodix_ts.ko` (Driver principal para painéis Goodix Berlin)
* `nt36xxx-i2c.ko` (Driver Novatek)
* `st_fts.ko` (Driver STMicroelectronics)
* `atmel_mxt_ts.ko` (Driver Atmel)
* `qts.ko` (Driver auxiliar Qualcomm)

---

## 3. Próximos Passos (Integração e Auditoria)

1. Validação de símbolos importados via script de auditoria para garantir ausência de referências a símbolos privados não exportados pelo GKI.
2. Início do desenvolvimento e adaptação do driver de rede proprietário Qualcomm IPA (`dataipa`).
