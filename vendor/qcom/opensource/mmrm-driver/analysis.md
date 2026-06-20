# Análise e Reconstrução - Multi-Media Resource Manager (MMRM) Driver

O driver MMRM (Multi-Media Resource Manager) é um componente Qualcomm ausente na árvore de código liberada pela ZTE. Ele atua como um coordenador centralizado para escala de recursos e votação de clocks/tensões dinâmicas dos subsistemas de multimídia (Câmera, Display e Vídeo).

---

## 1. Descobertas e Análise da Engenharia Reversa (Fase 1 e 2)

A partir da análise dos arquivos descompilados em `decompiled/msm-mmrm/`, identificamos a estrutura e lógica operacional do driver original:

### Estrutura do Nó de Device Tree (`canoe-mmrm.dtsi`)
O nó do driver no device tree compatível com `"qcom,msm-mmrm"` define propriedades chave:
* `mmrm-client-info`: Lista de tuplas de 5 elementos (20 bytes cada) contendo o domínio do cliente (`camera=1`, `eva=2`, `display=3`, `video=4`), o ID do clock, fator dinâmico de escala, fator de fuga (leakage) e o número de blocos de hardware.
* `mmrm-peak-threshold`: Limite superior de corrente/frequência de pico.

### Funcionamento Interno
O driver original gerencia um conjunto de callbacks (`clk_client_swops`) mapeados para operações do cliente:
1. `mmrm_client_register` / `mmrm_sw_clk_client_register`
2. `mmrm_client_deregister` / `mmrm_sw_clk_client_deregister`
3. `mmrm_client_set_value` / `mmrm_sw_clk_client_setval` (onde de fato invoca-se `clk_set_rate` no clock do cliente).
4. `mmrm_client_set_value_in_range` / `mmrm_sw_clk_client_setval_inrange`

---

## 2. Abordagem de Reconstrução do Driver

Para garantir a portabilidade e evitar erros de compilação sem depender de stubs dummy que desativam o recurso (o que causaria falhas em tempo de execução ao iniciar a câmera ou acelerador de vídeo), reconstruímos um driver MMRM real, funcional e limpo, que realiza as seguintes funções:

1. **Definição de Cabeçalho Oficial:** Criado `<linux/soc/qcom/msm_mmrm.h>` contendo todas as estruturas (`mmrm_client_desc`, `mmrm_client_data`, `mmrm_client_res_value`, `mmrm_client_notifier_data`) e as assinaturas das 7 APIs oficiais exportadas.
2. **Implementação do Driver (`msm_mmrm.c`):**
   * Registra um driver de plataforma para `"qcom,msm-mmrm"`.
   * Gerencia uma lista dinâmica de clientes registrados.
   * Quando um cliente vota por uma frequência via `mmrm_client_set_value` ou `mmrm_client_set_value_in_range`, o driver aplica o clock diretamente via `clk_set_rate(clk, rate)` do subsistema de clock do Linux.
   * Responde às chamadas de `mmrm_client_get_value` retornando a última taxa votada pelo cliente.
   * Lê a quantidade de clientes definidos no Device Tree (`mmrm-client-info`) durante o `probe` para retornar o valor real sob demanda em `mmrm_client_get_clk_count`.
   * Exporta todos os 7 símbolos (`EXPORT_SYMBOL`) para paridade binária e de ABI total:
     - `mmrm_client_register`
     - `mmrm_client_deregister`
     - `mmrm_client_set_value`
     - `mmrm_client_set_value_in_range`
     - `mmrm_client_get_value`
     - `mmrm_client_get_clk_count`
     - `mmrm_client_check_scaling_supported`
3. **Estrutura de Build Reconstruída:**
   * `BUILD.bazel`: Configuração Bazel/Kleaf mapeando os alvos para todas as variantes do target `canoe` (`canoe_gki_mmrm_driver`, `canoe_perf_mmrm_driver`, etc.).
   * `Android.mk`, `Makefile`, `Kbuild`, `Kconfig`: Arquivos clássicos de compilação do Android e Linux integrados.
   * `config/waipiommrm.conf`: Mock de configuração para satisfazer dependências do techpack de câmera.

---

## 3. Validação Dinâmica via KernelSU Overlay
* **Status:** Concluído com sucesso.
* **Procedimento:** O módulo `msm-mmrm.ko` compilado a partir do código reconstruído foi injetado via bind-mount usando o KernelSU-Next na partição `vendor_dlkm`.
* **Resultados:**
  * O driver de gerenciamento de recursos MMRM inicializou perfeitamente.
  * O módulo foi carregado com sucesso na RAM e está ativo, com 3 referências registradas em tempo de execução: `camera`, `msm_eva` e `msm_video` (confirmado via `lsmod`).
  * Não foram observados panics de desalinhamento de struct ou crash de watchdog.
