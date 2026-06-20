# Análise de Engenharia Reversa e Arquitetura - Injeção de Overclock Adreno 750 (1230MHz)

Este documento detalha os fundamentos arquiteturais, os offsets e a estratégia de injeção direta em memória utilizados neste módulo do KernelSU-Next para o Red Magic 11 Pro (NX809J).

## 1. Mapeamento de Memória do Driver KGSL (`msm_kgsl`)

A análise estática no Ghidra dos submódulos originais da ZTE (`_max_clock_mhz_store.c`, `max_gpuclk_store.c` e `adreno_of_parse_pwrlevels.c`) revelou o layout exato da estrutura `kgsl_device` (e seu subcomponente `pwrctrl` no offset `152`):

```
+-------------------------------------------------------------+
| struct kgsl_device / kgsl_pwrctrl                           |
+-------------------------------------------------------------+
| [Offset 0x23B8 / 9144]  -> struct kgsl_pwrlevel pwrlevels[32]
| [Offset 0x2748 / 10056] -> unsigned int min_pwrlevel        |
| [Offset 0x274C / 10060] -> unsigned int max_pwrlevel        |
| [Offset 0x2754 / 10068] -> unsigned int num_pwrlevels       |
| [Offset 0x2BA0 / 11168] -> struct device *dev_opp           |
+-------------------------------------------------------------+
```

### Estrutura Interna de `kgsl_pwrlevel` (Tamanho: 28 bytes)
Cada nível na tabela de frequências da GPU possui 7 inteiros de 32 bits (`unsigned int`):
1. `gpu_freq` (Offset 0): Frequência exata da GPU em Hz.
2. `bus_freq` (Offset 4): Frequência do barramento DDR em Hz.
3. `bus_min` (Offset 8): Frequência mínima do barramento.
4. `bus_max` (Offset 12): Frequência máxima do barramento.
5. `acd_level` (Offset 16): Nível de controle ACD.
6. `cx_level` (Offset 20): Nível de voltagem CX (Corner).
7. `voltage_level` (Offset 24): Nível de voltagem GFX / CPR corner (ex: `0x1c0`, `0x1d0`, `51`, `52`).

## 2. Estratégia de Overclock e Overvolt (1230MHz)

Para ultrapassar o limite original de 1200MHz e garantir paridade de estabilidade, o módulo C (`adreno_overclock.c`) atua diretamente na estrutura em memória da GPU Adreno (`kgsl-3d0`):

1. **Bypass de Símbolos Privados (Kprobes)**:
   Em kernels 6.12+, `kallsyms_lookup_name` não é exportado. O módulo registra temporariamente um Kprobe na função `kallsyms_lookup_name` para obter seu endereço em memória e, em seguida, utiliza esse ponteiro para buscar a função privada `kgsl_get_device`.
2. **Injeção da Frequência de 1230MHz**:
   O módulo acessa `pwrlevels[0]` (o nível de máxima performance) e substitui o valor original de `1200000000` Hz por `1230000000` Hz (1230 MHz).
3. **Overvolt de Estabilização**:
   Para evitar falhas de comunicação com o TrustZone/SCM e quedas de tensão sob carga pesada, o `voltage_level` é incrementado (de `0x1c0` para `0x1d0`, ou fixado no índice CPR máximo `53`). O `cx_level` é travado no patamar Super Turbo (`64`).
4. **Sincronização com o Kernel Linux (OPP Table)**:
   Para que o governador do kernel reconheça a nova frequência e forneça a corrente correta, o módulo invoca `dev_pm_opp_add(dev, 1230000000, 1050000)`.

## 3. Blindagem Dinâmica (Espaço de Usuário)
O script de serviço `service.sh` complementa a blindagem parando os daemons proprietários da ZTE (`com.zte.thermald`, `perfservice`, `thermal-engine-v2`) e forçando `max_pwrlevel = 0` no sysfs, protegendo o registro com permissões somente leitura (`chmod 444`).

## 4. Conclusão
Esta arquitetura atende integralmente ao Protocolo REP, combinando engenharia reversa estática com injeção dinâmica e garantindo fidelidade total ao hardware do Red Magic 11 Pro.
