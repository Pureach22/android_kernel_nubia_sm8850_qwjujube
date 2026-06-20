# Module Unit Testing Plan via KernelSU (Checklist)

This document describes the step-by-step plan to test our custom-compiled kernel modules (`.ko`) individually on top of the stock ROM proprietary drivers using KernelSU-Next. The objective is to isolate any driver structure incompatibilities (ABI mismatches) causing boot loops or Kernel Panics.

---

## 🛠️ Operating Instructions (The Testing Methodology)

To test a module in isolation safely:

### Step 1: Prepare the Module on the Device
Create the directory structure inside KernelSU and push our corresponding compiled module:
```bash
# Example for testing the GPU driver (msm_kgsl.ko)
adb shell su -c "mkdir -p /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules"
adb push vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko /local/temp/msm_kgsl.ko
adb shell su -c "cp /local/temp/msm_kgsl.ko /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules/msm_kgsl.ko"
```

### Step 2: Perform a Temporary Boot in RAM
Reboot the device into bootloader mode and boot the custom kernel:
```bash
adb reboot bootloader
# Wait for the device to enter fastboot mode...
sudo fastboot boot dev_reverse_perfect.img
```

### Step 3: Evaluate Boot Status and Capture Logs
*   **If the boot succeeds:** Android will boot normally. Verify that the loaded module has our custom MD5 hash by running `adb shell su -c "modinfo <module>"`. Mark it as `[x] Stable`.
*   **If a Crash Dump / Kernel Panic occurs:** The device will freeze or automatically reboot back to the stock ROM (running the original kernel). Immediately execute the ramoops log capture script to analyze which symbol or memory offset triggered the error:
    ```bash
    bash scratch/get_ramoops.sh
    # Inspect scratch/ramoops.log for the kernel panic Call Trace.
    ```
*   **Cleanup after a failure:** If the driver caused a boot crash, remove it from the KernelSU overlay directory from within the stock kernel (which boots normally after a crash) to disable the overlay:
    ```bash
    adb shell su -c "rm -f /data/adb/modules/zte_tpd_only/vendor_dlkm/lib/modules/<failed_driver>.ko"
    ```

---

## 📋 Driver Testing Checklist

### Group A: Infrastructure and Security (High Priority)
These drivers handle secure communication bridges and basic kernel buffer allocations.

| Status | Module | Compiled Source Path | Device Destination (`/vendor_dlkm/lib/modules/`) | Symptom / Notes |
| :---: | :--- | :--- | :--- | :--- |
| `[x]` | `zte_tpd.ko` | `vendor/zte/zte_tpd/zte_tpd.ko` | `zte_tpd.ko` | **Stable.** Physical touchscreen operational at 180Hz. |
| `[x]` | `msm-mmrm.ko` | `vendor/qcom/opensource/mmrm-driver/msm-mmrm.ko` | `msm-mmrm.ko` | **Stable.** Signed as 'Antigravity MMRM Custom'. |
| `[ ]` | `synx_driver.ko` | `vendor/qcom/opensource/synx-kernel/synx_driver.ko` | `synx_driver.ko` | |
| `[ ]` | `smcinvoke_dlkm.ko`| `vendor/qcom/opensource/securemsm-kernel/smcinvoke_dlkm.ko` | `smcinvoke_dlkm.ko` | |
| `[ ]` | `qseecom_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/qseecom_dlkm.ko` | `qseecom_dlkm.ko` | |
| `[ ]` | `qrng_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/qrng_dlkm.ko` | `qrng_dlkm.ko` | |
| `[ ]` | `hdcp_qseecom_dlkm.ko` | `vendor/qcom/opensource/securemsm-kernel/hdcp_qseecom_dlkm.ko`| `hdcp_qseecom_dlkm.ko`| |

---

### Group B: Graphics and Display (High Priority for Overclocking)
These contain the main driver controls for the Adreno GPU and display panel outputs.

| Status | Module | Compiled Source Path | Device Destination | Symptom / Notes |
| :---: | :--- | :--- | :--- | :--- |
| `[x]` | `msm_kgsl.ko` | `vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko` | `msm_kgsl.ko` | **Stable with Overclock (1.2GHz).** Signed as 'Antigravity KGSL Custom'. |
| `[ ]` | `msm_drm.ko` | `vendor/qcom/opensource/display-drivers/msm/msm_drm.ko` | `msm_drm.ko` | Main display module (39MB) |

---

### Group C: Connectivity and Bluetooth (Medium Priority)

| Status | Module | Compiled Source Path | Device Destination | Symptom / Notes |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `btpower.ko` | `vendor/qcom/opensource/bt-kernel/pwr/btpower.ko` | `btpower.ko` | |
| `[ ]` | `btfmcodec.ko` | `vendor/qcom/opensource/bt-kernel/btfmcodec/btfmcodec.ko` | `btfmcodec.ko` | |
| `[ ]` | `bt_fm_swr.ko` | `vendor/qcom/opensource/bt-kernel/soundwire/bt_fm_swr.ko` | `bt_fm_swr.ko` | |

---

### Group D: Cameras and MM-Drivers (Medium Priority)

| Status | Module | Compiled Source Path | Device Destination | Symptom / Notes |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `camera.ko` | `vendor/qcom/opensource/camera-kernel/camera.ko` | `camera.ko` | |
| `[ ]` | `msm_hw_fence.ko` | `vendor/qcom/opensource/mm-drivers/hw_fence/msm_hw_fence.ko` | `msm_hw_fence.ko` | |
| `[ ]` | `msm_ext_display.ko`| `vendor/qcom/opensource/mm-drivers/msm_ext_display/msm_ext_display.ko` | `msm_ext_display.ko` | |

---

### Group E: Audio Stack (Low Priority / Execute Last)
Contains the Soundwire digital bus controllers and audio speaker/microphone codecs.

| Status | Module | Compiled Source Path | Device Destination | Symptom / Notes |
| :---: | :--- | :--- | :--- | :--- |
| `[ ]` | `machine_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/machine_dlkm.ko` | `machine_dlkm.ko` | Soundcard master driver |
| `[ ]` | `swr_haptics_dlkm.ko`| `vendor/qcom/opensource/audio-kernel/asoc/codecs/swr_haptics_dlkm.ko` | `swr_haptics_dlkm.ko` | |
| `[ ]` | `wcd939x_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/codecs/wcd939x/wcd939x_dlkm.ko` | `wcd939x_dlkm.ko` | |
| `[ ]` | `lpass_cdc_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/asoc/codecs/lpass-cdc/lpass_cdc_dlkm.ko` | `lpass_cdc_dlkm.ko` | |
| `[ ]` | `aw882xx_dlkm.ko` | `vendor/qcom/opensource/audio-kernel/dsp/aw882xx/aw882xx_dlkm.ko` | `aw882xx_dlkm.ko` | SmartPA Amplifiers |

---

## 📈 Recent Development and Test Results (May 2026)

*   **MMRM Module (`msm-mmrm.ko`)**:
    *   **Description**: Custom signature implemented as `"Qualcomm Multi-Media Resource Manager (MMRM) Driver - Antigravity MMRM Custom"`.
    *   **Result**: Compiled out-of-tree using Clang r536225, patched with `patch_tpd.py` to fix KCFI/CRC alignment, and verified via KernelSU overlays. Loading and all dependent references are 100% operational.
*   **GPU Module (`msm_kgsl.ko`)**:
    *   **Description**: Custom signature implemented as `"Adreno 3D Graphics driver - Antigravity KGSL Custom"`.
    *   **Result**: Stable **1.2 GHz** overclock successfully enabled for the Adreno 840v2 GPU. MD5 hash verification confirms that the custom compiled driver is active on the device. All clocks and voltage profiles respond correctly in the sysfs node without triggering the ZTE Dumper crash.
