# Análise e Engenharia Reversa - `bt-kernel` (Bluetooth)

Este documento detalha o processo de compilação, adaptações e auditoria dos drivers de Bluetooth (`bt-kernel`) para o Red Magic 11 Pro (NX809J) com o processador Snapdragon 8 Gen 5 (plataforma `canoe`).

---

## 1. Mapeamento de Arquivos e Dependências
A árvore do driver de Bluetooth original contém 7 subdiretórios que geram módulos independentes:
1. `pwr/btpower.ko` - Gerenciamento de energia física do chip de Bluetooth/WLAN.
2. `rtc6226/radio-i2c-rtc6226-qca.ko` - Driver do receptor FM.
3. `soundwire/bt_fm_swr.ko` - Interface Soundwire para áudio FM/Bluetooth.
4. `slimbus/btfm_slim_codec.ko` - Interface Slimbus para áudio FM/Bluetooth.
5. `btfmcodec/btfmcodec.ko` - Codec Bluetooth FM.
6. `spi/spi_cnss_proto.ko` - Protocolo SPI para comunicação com o chip Bluetooth/UWB.
7. `thq-spi/thqspi_proto.ko` - Protocolo SPI de Quartz para controle do chip.

---

## 2. Correções Aplicadas na Compilação

Para viabilizar a compilação cruzada contra o GKI kernel (`kernel_platform/common`), foram realizadas 4 modificações corretivas:

### A. Stub/Declaração de Cabeçalhos Faltantes
* **`cnss_utils.h`**: A opção `CONFIG_FMD_ENABLE=y` exige a função `cnss_utils_fmd_status()`. Como os fontes de WLAN proprietários não estão na árvore, criamos o cabeçalho local `include/cnss_utils.h` com a declaração:
  ```c
  int cnss_utils_fmd_status(bool status);
  ```
  *(O símbolo real é exportado dinamicamente pelo módulo `cnss_utils` em tempo de execução no smartphone físico).*

### B. Correção de Diretórios Faltantes ou Renomeados
* **`thq-spi/Makefile`**: O Makefile original apontava incorretamente para `th-quartz-spi` em seus include paths (`ccflags-y`). Corrigimos os caminhos para apontarem para o diretório correto `thq-spi`.
  ```diff
  -ccflags-y += -I$(BT_ROOT)/th-quartz-spi
  -ccflags-y += -I$(BT_ROOT)/th-quartz-spi/include
  +ccflags-y += -I$(BT_ROOT)/thq-spi
  +ccflags-y += -I$(BT_ROOT)/thq-spi/include
  ```

### C. Inclusão de Cabeçalhos de Áudio e Codecs
* **`soundwire/Makefile`**: O módulo Soundwire depende de cabeçalhos de codecs de áudio localizados em `btfmcodec/include` e `audio-kernel/include`. Adicionamos esses caminhos ao `ccflags-y`:
  ```diff
  -ccflags-y += -I$(BT_ROOT)/include
  +ccflags-y += -I$(BT_ROOT)/include -I$(BT_ROOT)/btfmcodec/include -I$(BT_ROOT)/../audio-kernel/include
  ```

### D. Declaração de API Proprietária do Slimbus
* **`slimbus/btfm_slim.h`**: A função proprietária Qualcomm `slim_stream_unprepare_disconnect_port` é utilizada em `btfm_slim.c`, mas não consta no cabeçalho GKI padrão (`linux/slimbus.h`). Adicionamos a assinatura correspondente (validada contra o binário descompilado do Ghidra) em `btfm_slim.h` para satisfazer as checagens do compilador:
  ```c
  int slim_stream_unprepare_disconnect_port(struct slim_stream_runtime *stream,
                                            bool unprepare, bool disconnect);
  ```

---

## 3. Relatório de Auditoria de Símbolos (`Symbol Auditing`)

A validação das tabelas de símbolos indefinidos dos binários `.ko` compilados foi realizada via script `check_ko_symbols.py` contra o mapa de símbolos real `/proc/kallsyms` extraído do smartphone Red Magic 11 Pro ativo.

### Resultado:
```
[OK] vendor/qcom/opensource/bt-kernel/pwr/btpower.ko
[OK] vendor/qcom/opensource/bt-kernel/rtc6226/radio-i2c-rtc6226-qca.ko
[OK] vendor/qcom/opensource/bt-kernel/soundwire/bt_fm_swr.ko
[OK] vendor/qcom/opensource/bt-kernel/thq-spi/thqspi_proto.ko
[OK] vendor/qcom/opensource/bt-kernel/spi/spi_cnss_proto.ko
[OK] vendor/qcom/opensource/bt-kernel/slimbus/btfm_slim_codec.ko
[OK] vendor/qcom/opensource/bt-kernel/btfmcodec/btfmcodec.ko
```

**Conclusão**: Todos os 7 drivers compilados estão com status **[OK]**, com **0 símbolos não resolvidos**, garantindo total paridade dinâmica de carregamento com a ROM userdebug original.
