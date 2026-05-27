# Plano de Teste Unitário de Módulos via KernelSU (check-list)

Este documento descreve o plano passo a passo para testar individualmente (um por um) os nossos módulos compilados (`.ko`) por cima dos drivers proprietários da ROM stock usando o KernelSU-Next. O objetivo é isolar qual driver possui incompatibilidade de estrutura (mismatch de ABI) e causa falhas de boot ou Kernel Panic.

---

## 🛠️ Instruções de Operação (O Método de Teste)

Para testar um driver de forma isolada e segura:

### Passo 1: Preparar o módulo no celular
Crie a estrutura do diretório no KernelSU e envie o nosso módulo compiled correspondente.
```bash
# Exemplo para testar a GPU (msm_kgsl.ko)
adb shell su -c "mkdir -p /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules"
adb push vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko /local/temp/msm_kgsl.ko
adb shell su -c "cp /local/temp/msm_kgsl.ko /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules/msm_kgsl.ko"
```

### Passo 2: Executar o Boot Temporário na RAM
Reinicie o aparelho no modo bootloader e carregue o kernel customizado:
```bash
adb reboot bootloader
# Aguarde entrar no fastboot...
sudo fastboot boot dev_reverse_perfect.img
```

### Passo 3: Avaliar o Boot e Capturar Logs
*   **Caso o boot seja bem-sucedido:** A tela inicializará o Android normalmente. Verifique se o módulo foi carregado com o nosso MD5 via `adb shell su -c "modinfo <modulo>"`. Marque como `[x] Estável`.
*   **Caso ocorra um Crash Dump / Pânico:** O celular travará ou reiniciará sozinho de volta para a ROM stock (kernel original). Execute o script de captura de ramoops imediatamente para analisar qual símbolo ou endereço deu falta:
    ```bash
    bash scratch/get_ramoops.sh
    # Verifique o arquivo scratch/ramoops.log para ver o Call Trace do pânico.
    ```
*   **Limpeza após falha:** Se o driver travou, remova o arquivo da pasta de overlay do KernelSU a partir do kernel stock (que iniciará normalmente após o crash) para desativar a sobreposição:
    ```bash
    adb shell su -c "rm -f /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules/<driver_que_falhou>.ko"
    ```

---

## 📋 Planilha de Testes dos Drivers

### Grupo A: Infraestrutura e Segurança (Alta Prioridade)
Esses drivers realizam pontes de comunicação seguras e alocações básicas de buffers no kernel.

| Status | Módulo | Caminho do Source compilado | Destino no Aparelho (`/vendor_dlkm/lib/modules/`) | Sintoma / Notas |
| :---: | :--- | :--- | :--- | :--- |
| `[x]` | `zte_tpd.ko` | `vendor/zte/zte_tpd/zte_tpd.ko` | `zte_tpd.ko` | **Estável.** Tela física operacional a 180Hz. |
| `[x]` | `msm-mmrm.ko` | `vendor/qcom/opensource/mmrm-driver/msm-mmrm.ko` | `msm-mmrm.ko` | **Estável.** Assinado como 'Antigravity MMRM Custom'. |
| `[ ]` | `synx_driver.ko` | `vendor/qcom/opensource/synx-kernel/synx_driver.ko` | `synx_driver.ko` | |
| `[ ]` | `smcinvoke_dlkm.ko`| `vendor/qcom/opensource/securemsm-kernel/smcinvoke_dlkm.ko` | `smcinvoke_dlkm.ko` | |
| `[ ]` | `qseecom_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/qseecom_dlkm.ko` | `qseecom_dlkm.ko` | |
| `[ ]` | `qrng_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/qrng_dlkm.ko` | `qrng_dlkm.ko` | |
| `[ ]` | `hdcp_qseecom_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/hdcp_qseecom_dlkm.ko`| `hdcp_qseecom_dlkm.ko`| |

---

### Grupo B: Gráficos e Display (Alta Prioridade para Overclock)
Contêm o controle principal da GPU Adreno e saídas do painel de display.

| Status | Módulo | Caminho do Source compilado | Destino no Aparelho | Sintoma / Notas |
| :---: | :--- | :--- | :--- | :--- |
| `[x]` | `msm_kgsl.ko` | `vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko` | `msm_kgsl.ko` | **Estável com Overclock (1.2GHz).** Assinado como 'Antigravity KGSL Custom'. |
| `[ ]` | `msm_drm.ko` | `vendor/qcom/opensource/display-drivers/msm/msm_drm.ko` | `msm_drm.ko` | Módulo de display principal (39MB) |

---

### Grupo C: Conectividade e Bluetooth (Média Prioridade)

| Status | Módulo | Caminho do Source compilado | Destino no Aparelho | Sintoma / Notas |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `btpower.ko` | `vendor/qcom/opensource/bt-kernel/pwr/btpower.ko` | `btpower.ko` | |
| `[ ]` | `btfmcodec.ko` | `vendor/qcom/opensource/bt-kernel/btfmcodec/btfmcodec.ko` | `btfmcodec.ko` | |
| `[ ]` | `bt_fm_swr.ko` | `vendor/qcom/opensource/bt-kernel/soundwire/bt_fm_swr.ko` | `bt_fm_swr.ko` | |

---

### Grupo D: Câmeras e MM-Drivers (Média Prioridade)

| Status | Módulo | Caminho do Source compilado | Destino no Aparelho | Sintoma / Notas |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `camera.ko` | `vendor/qcom/opensource/camera-kernel/camera.ko` | `camera.ko` | |
| `[ ]` | `msm_hw_fence.ko` | `vendor/qcom/opensource/mm-drivers/hw_fence/msm_hw_fence.ko` | `msm_hw_fence.ko` | |
| `[ ]` | `msm_ext_display.ko`| `vendor/qcom/opensource/mm-drivers/msm_ext_display/msm_ext_display.ko` | `msm_ext_display.ko` | |

---

### Grupo E: Pilha de Áudio (Baixa Prioridade / Executar por último)
Contém os controladores de barramento digital Soundwire e codecs de alto-falantes e microfones.

| Status | Módulo | Caminho do Source compilado | Destino no Aparelho | Sintoma / Notas |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `machine_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/machine_dlkm.ko` | `machine_dlkm.ko` | Principal da placa de som |
| `[ ]` | `swr_haptics_dlkm.ko`| `vendor/qcom/opensource/audio-kernel/asoc/codecs/swr_haptics_dlkm.ko` | `swr_haptics_dlkm.ko` | |
| `[ ]` | `wcd939x_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/codecs/wcd939x/wcd939x_dlkm.ko` | `wcd939x_dlkm.ko` | |
| `[ ]` | `lpass_cdc_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/codecs/lpass-cdc/lpass_cdc_dlkm.ko` | `lpass_cdc_dlkm.ko` | |
| `[ ]` | `aw882xx_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/dsp/aw882xx/aw882xx_dlkm.ko` | `aw882xx_dlkm.ko` | Amplificadores SmartPA |

---

## 📈 Resultados Recentes do Desenvolvimento e Testes (Maio 2026)

*   **Módulo MMRM (`msm-mmrm.ko`)**:
    *   **Descrição**: Implementada assinatura visual `"Qualcomm Multi-Media Resource Manager (MMRM) Driver - Antigravity MMRM Custom"`.
    *   **Resultado**: Compilado out-of-tree com Clang r536225, patcheado com `patch_tpd.py` e validado via montagem no KernelSU. Carregamento e dependências 100% funcionais.
*   **Módulo GPU (`msm_kgsl.ko`)**:
    *   **Descrição**: Implementada assinatura visual `"Adreno 3D Graphics driver - Antigravity KGSL Custom"`.
    *   **Resultado**: Overclock para GPU Adreno 840v2 a **1.2 GHz** ativo e estável. Hashes MD5 comprovam o carregamento correto do nosso driver customizado.

