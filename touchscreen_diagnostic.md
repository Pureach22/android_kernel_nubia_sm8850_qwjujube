# 📋 Diagnóstico e Engenharia Reversa do Touchscreen - Red Magic 11 Pro (NX809J)

Este documento reúne todas as especificações e mapeamento de baixo nível do touchscreen do Red Magic 11 Pro (NX809J), extraídas dinamicamente a partir da **ROM oficial estável** em execução (Android 16 com Kernel 6.12.23-android16-OP-WILD).

---

## 🔍 1. Especificações do Hardware

* **Fabricante e Modelo do IC**: **Synaptics S3910V** (`synaptics_3910V`).
* **Nome de Registro do Input**: `synaptics_tcm_touch` (mapeado dinamicamente em `/dev/input/event9`).
* **Módulo do Driver proprietário**: `zte_tpd.ko` (Driver principal de Touchscreen ZTE que expõe controles do painel).
* **Nó de Inicialização**: `/sys/devices/platform/soc/1ac0000.qcom,qupv3_4_geni_se/1a80000.spi/spi_master/spi19/spi19.0/`

---

## ⚡ 2. Barramento de Comunicação (SPI)

Diferente de controladores de toque mais antigos que utilizam o barramento I2C, este dispositivo topo de linha utiliza uma interface de barramento **SPI** de altíssima velocidade para garantir a latência reduzida ideal para o foco gamer do aparelho.

| Propriedade SPI | Valor Físico (Hexadecimal) | Tradução Técnica |
| :--- | :--- | :--- |
| **Interface** | `SPI Geni #4` | Mapeado no barramento `/dev/spi19.0` |
| **Chip Select (CS)** | `0x00000000` | **CS 0** |
| **Frequência Máxima** | `0x00989680` | **10 MHz** (10.000.000 Hz) |
| **Modo SPI** | `0x00000000` | **Modo 0** (CPOL=0, CPHA=0) |

---

## 📌 3. Mapeamento de Pinos Físicos (GPIO / TLMM)

Os pinos de controle e interrupção estão registrados no controlador central de GPIOs da Qualcomm (TLMM - *Top Level Mode Multiplexer*) com a seguinte estrutura física extraída do Device Tree ativo:

### 📥 Interrupção (IRQ - Interrupt Request)
* **Propriedade DT**: `synaptics,irq-gpio`
* **Vetor Hexadecimal**: `00000033 0000009e 00002008`
  * **Phandle do TLMM**: `0x33` (ID do controlador TLMM)
  * **Pino GPIO**: **GPIO 158** (`0x9e`)
  * **Flags**: `0x2008` (Configuração de interrupção ativa)

### 🔄 Reset (RST)
* **Propriedade DT**: `synaptics,reset-gpio`
* **Vetor Hexadecimal**: `00000033 00000042 00000000`
  * **Phandle do TLMM**: `0x33` (ID do controlador TLMM)
  * **Pino GPIO**: **GPIO 66** (`0x42`)
  * **Flags**: `0x0`

---

## 💾 4. Firmware e Calibração

Informações de firmware e nós virtuais de calibração extraídos dinamicamente do controlador:
* **Versão ativa do Firmware**: **4571021** (formato canônico `4.57.1021`).
* **Configuração de Toque (Config Version)**: **0x4601**.
* **ID do Módulo do Painel (TP Module)**: `0x0`.

---

## 📂 5. Mapeamento dos Nós de Controle (procfs / sysfs)

O driver `zte_tpd` mapeia um conjunto de arquivos utilitários em `/proc/touchscreen/` que controlam comportamentos específicos de toque, taxa de atualização e gestos na ROM oficial:

| Arquivo de Controle | Permissão | Função Principal |
| :--- | :--- | :--- |
| `/proc/touchscreen/ts_information` | Leitura (`r--`) | Exibe as especificações do hardware, firmware e config. |
| `/proc/touchscreen/tp_palm_mode` | Leitura/Escrita (`rw-`) | Ativa/Desativa o modo de rejeição de palma. |
| `/proc/touchscreen/single_game` | Leitura/Escrita (`rw-`) | Configura otimizações de toque de alto desempenho para jogos. |
| `/proc/touchscreen/glove_mode` | Leitura/Escrita (`rw-`) | Ativa a sensibilidade aumentada para uso com luvas. |
| `/proc/touchscreen/FW_upgrade` | Leitura/Escrita (`rw-`) | Permite a gravação manual de novos blocos de firmware de toque. |
| `/proc/touchscreen/tp_self_test` | Leitura/Escrita (`rw-`) | Executa diagnósticos internos de curto-circuito/ruído no painel. |

---

## 🛠️ 6. Próximos Passos de Engenharia Reversa

A inicialização e o funcionamento corretos da tela física dependem da integridade do barramento **SPI Geni #4**. No desenvolvimento do kernel customizado, se o touchscreen se mantiver inoperante:
1. **Verificação de Alimentação**: Garantir que os reguladores de tensão correspondentes aos pinos `avdd-supply` e `vdd-supply` mapeados no Device Tree para o `synaptics_tcm@0` estejam sendo devidamente acionados no início do boot.
2. **Pino de Reset**: Assegurar que o pino **GPIO 66** esteja alternando corretamente os estados de reset no driver customizado para ligar o chip Synaptics antes que o barramento SPI tente fazer o handshake.
3. **Pino de Interrupção**: Monitorar se a interrupção no **GPIO 158** está sendo devidamente registrada sem conflitos com outros drivers ou interrupções fantasmas.
