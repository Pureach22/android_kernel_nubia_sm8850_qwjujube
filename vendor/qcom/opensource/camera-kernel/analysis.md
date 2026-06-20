# Análise de Engenharia Reversa - Driver de Câmera (ZTE RedMagic 11 Pro - NX809J)

## 1. Visão Geral do Módulo `camera.ko`
O driver de câmera da Qualcomm (`camera-kernel`) gerencia o pipeline de processamento de imagem, incluindo CPAS (Camera Power and Alignment Subsystem), CSID/CSIPHY, controladores ISP/VFE, ICP (Image Cognition Processor), JPEG encoders e o subsistema de foco por ToF (Time of Flight).

---

## 2. Inconsistência no Build System da ZTE (Kbuild vs. Bazel)
Durante o mapeamento e compilação do driver, identificamos uma falha de sincronização no empacotamento de código realizado pela ZTE:
* **Bazel/Kleaf (`camera_modules.bzl`)**: Incluía os arquivos da pasta `vi530x/` (FlightSense ToF da STMicroelectronics) diretamente no target do driver `camera.ko` se `CONFIG_SPECTRA_SENSOR` estivesse habilitado.
* **Kbuild/Makefile (`Kbuild`)**: Os arquivos sob o diretório `vi530x/` foram omitidos na lista de compilação do Kbuild local, o que resultava em erros de link de símbolos indefinidos (`vi530x_init`, `vi530x_exit`, `vi530x_resources_close`) ao gerar o arquivo `camera.ko` fora do ambiente Bazel.

### Resolução
Adicionamos os objetos compilados do ToF diretamente ao `Kbuild` no bloco associado à flag `CONFIG_SPECTRA_SENSOR`:
```makeup
	vi530x/vi530x_api.o \
	vi530x/vi530x_firmware.o \
	vi530x/vi530x_module.o \
	vi530x/vi530x_platform.o
```

---

## 3. Dependências e Resolução de Símbolos do Kernel GKI
A compilação out-of-tree no Android 16 (GKI) requer o tratamento de símbolos exportados por drivers específicos da plataforma Qualcomm (como Secure Channel Manager - SCM). Para viabilizar a compilação paralela mantendo a portabilidade:
* Compilamos utilizando a flag `KBUILD_MODPOST_WARN=1` para converter referências não resolvidas a símbolos do SCM (`qcom_scm_io_readl`, `qcom_scm_io_writel`, `qcom_scm_pas_shutdown`, `qcom_scm_set_remote_state`) em avisos em tempo de build, garantindo a geração correta do arquivo binário `camera.ko`.
* Em tempo de execução (runtime), o linker dinâmico do kernel carrega as dependências cruzadas a partir de outros módulos do sistema de arquivos DLKM oficial.
