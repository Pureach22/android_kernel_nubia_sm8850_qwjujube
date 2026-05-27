# FORMAL GPL v2 COMPLIANCE NOTICE — ZTE CORPORATION

**To:** ZTE Corporation / Nubia Technology Support & Compliance Department  
**Subject:** Formal Request for Complete and Corresponding Source Code for RedMagic 11 Pro (NX809J) Kernel — In accordance with the GNU General Public License v2 (GPLv2)  
**Device:** Nubia RedMagic 11 Pro (Model: NX809J)  
**SoC:** Qualcomm Snapdragon 8 Elite / Gen 5 (SM8750/SM8850 - Codenames: `canoe` / `qwjujube`)  
**Kernel Version:** Linux Kernel 6.12.23 (Android 16 GKI)  

---

## 📄 COVER LETTER (MESSAGE TO SEND)

*Dear ZTE / Nubia Support and Compliance Team,*

*As a user of the Nubia RedMagic 11 Pro (NX809J) and a member of the open-source Android development community, I am writing to formally request compliance with the obligations of the **GNU General Public License version 2 (GPLv2)**, which governs the distribution of the Linux Kernel used in the official firmware of this device.*

*Currently, the kernel source code released by ZTE is incomplete. The provided source tree is missing critical platform configuration files, proprietary API headers, wireless LAN (WLAN) host driver source files, and several ZTE proprietary drivers operating in kernel-space. Due to these omissions, **it is technically impossible to compile a functional, bootable kernel image from the provided source release**, which constitutes a direct violation of Section 3 of the GPLv2.*

*Section 3 of the GPLv2 mandates that the distributor of a GPL-licensed binary must make available the **"complete corresponding source code"**, defined as: "the preferred form of the work for making modifications to it" including "all the source code for all modules it contains, plus any associated interface definition files, plus the scripts used to control compilation and installation of the executable."*

*To assist ZTE in resolving this non-compliance, our engineering team has performed an exhaustive compilation audit, documenting the exact missing configuration fragments, private headers, and driver source directories. A detailed technical audit report is attached below.*

*We request that ZTE releases an updated, complete kernel source package containing these omitted components, or uploads them to your official public source repository.*

*We look forward to your response and a prompt resolution to this compliance matter.*

*Sincerely,*  
*[Your Name / Repository Name]*  
*Contact Email: [Your Email]*  

---

## 📊 TECHNICAL GPL COMPILATION AUDIT REPORT

Below is the detailed list of missing or broken components in the current ZTE NX809J source release:

### 1. Missing Platform Defconfig Fragment
* **Missing File:** `canoe.fragment` (or equivalent board-level configuration fragment for SM8750/SM8850).
* **Expected Path:** `kernel_platform/common/arch/arm64/configs/`
* **Impact:** Compiling with the default `gki_defconfig` disables all Qualcomm SoC-level platform drivers (such as SCM, SMMU, RPMH, regulators, clock controllers, and interconnects). This prevents the compilation of approximately **194 platform-level modules** loaded by the official firmware.

### 2. Omitted WLAN Host Driver Source Code
* **Missing Repositories:**
  * `vendor/qcom/opensource/wlan/qcacld-3.0/`
  * `vendor/qcom/opensource/wlan/qca-wifi-host-cmn/`
* **Delivered Content:** Only API definition headers (`fw-api/`) and device tree bindings (`wlan-devicetree/`).
* **Impact:** The actual WLAN host driver source code is completely missing. The production device runs `qca_cld3_peach_v2.ko` and other supporting WLAN drivers (`cnss2.ko`, `cnss_nl.ko`, `cnss_prealloc.ko`, `cnss_utils.ko`). The omission of this code makes it impossible to build a kernel with working Wi-Fi support.

### 3. Missing Multimedia Framework Drivers (MMRM and Synx)
These frameworks coordinate power voting and hardware synchronization fence operations across the camera, display, video, and GPU chips:
* **Missing MMRM Path:** `vendor/qcom/opensource/mmrm-driver/` and header `<linux/soc/qcom/msm_mmrm.h>`.
* **Missing Synx Path:** `vendor/qcom/opensource/synx-kernel/` and headers `<synx_api.h>` and `<synx_interop.h>`.
* **Impact:** Display, camera, and video drivers fail to compile due to missing headers. The production firmware loads `msm_mmrm.ko` and `synx_driver.ko`.

### 4. Missing Qualcomm Platform Kernel Headers
The following headers are referenced by the delivered drivers but are absent from the kernel tree:
* `<linux/mem-buf.h>` — Used by GPU (KGSL), security (QSEECOM), and video drivers.
* `<linux/msm_ion.h>` — Classic MSM ION memory allocator.
* `<linux/msm_dma_iommu_mapping.h>` — DMA-IOMMU mapping utilities for the video driver.
* `<linux/qcom-iommu-util.h>` — Controls SMMU bypasses and fault handling in the display driver.
* `<soc/qcom/minidump.h>` — Platform crash dump registration.
* `<linux/hdcp_qseecom.h>` — High-bandwidth Digital Content Protection API for display.
* `<linux/soc/qcom/battery_charger.h>` — Battery notifier bindings for the haptics driver.
* `<linux/qti-regmap-debugfs.h>` — Debugfs interfaces for the audio codec driver.

### 5. Incomplete Function/API Declarations in Kernel Tree
Several functions called by the delivered drivers are not declared in the corresponding kernel headers:
* `rproc_set_state()` — Missing from `<linux/remoteproc/qcom_rproc.h>` (Used by `hfi_smmu.c`).
* `msm_gpio_mpm_wake_set()` — Missing from `<linux/pinctrl/qcom-pinctrl.h>` (Used by audio and Bluetooth).
* `msm_gpio_get_pin_address()` — Missing from `<linux/pinctrl/qcom-pinctrl.h>` (Used by display).
* `socinfo_get_part_info()`, `socinfo_get_part_count()`, `socinfo_get_subpart_info()` — Missing from `<soc/qcom/socinfo.h>` (Used by display).

### 6. Missing Source Code for 12 ZTE Proprietary Modules (Kernel-Space)
The following **12 ZTE-branded modules** are loaded in the production firmware, but their source code is completely missing. Since these drivers execute in kernel-space and link dynamically with internal kernel symbols, they are derivative works of the Linux kernel under copyright law and must be open-sourced under the GPL:
1. `zte_charger_policy.ko` — Battery thermal charging policy.
2. `zte_power_supply.ko` — Power supply and battery management.
3. `zte_led.ko` — RGB intelligent LED effects driver.
4. `zte_fingerprint.ko` — Goodix under-display fingerprint sensor bridge.
5. `zte_misc.ko` — Global ZTE property and callback bus.
6. `zte_ir.ko` — Infrared blaster modulation driver.
7. `zte_tpd.ko` — Touch Protection Driver (Synaptics TCM interface via SPI).
8. `zte_imem_info.ko` — Boot style and telemetry decoder via physical IMEM.
9. `zte_sensor_sensitivity.ko` — Sensor physical sensitivity and calibration nodes.
10. `zte_stats_info.ko` — Generic Netlink process statistics driver.
11. `zte_reboot_ext.ko` — Custom panic/crash logger storing data in NVMEM.
12. `zte_ramdisk_reboot.ko` — Early ramdisk-level reboot handler.

### 7. Compilation Errors in the Audio Techpack Build Scripts
* **File:** `vendor/qcom/opensource/audio-kernel/dsp/aw882xx/Kbuild`, line 89
* **Issue:** A syntax error added in the include path directive (`$(ROOT_DIR)/msm-kernel/include` without the `-I` prefix) causes Clang to abort compilation. Additionally, the Makefile enters an infinite recursion loop due to the omission of the `MODNAME=audio` flag in the build options.

---

## 🔧 CRITICAL TECHNICAL SYMPTOM (BOOT HANG)

When attempting to build the kernel and integrate compatibility stub implementations to satisfy the dependencies of the omitted hardware components, the custom GKI image compiles but hangs indefinitely at the initial RedMagic boot logo. The console-ramoops logs reveal that the boot sequence stalls at:

```
[0.181496] arm-scmi arm-scmi.1.auto: Failed to get FC for protocol 13 [MSG_ID:6 / RES_ID:0] - ret:-22
...
[1.112952] arm-scmi arm-scmi.1.auto: timed out in resp (caller: do_xfer+0x140/0x4ec)
[1.116211] scmi_cpuss_telemetry_probe: Not able to find shared memory location
[1.774983] adsp-loader soc:qcom,msm-adsp-loader: fail to get rproc
```

This SCMI timeout prevents CPUSS telemetry from probing, which stalls the remoteproc drivers (`qcom_q6v5_pas`), leaving the ADSP/CDSP co-processors offline. As a result, the `keymint` security daemon cannot initialize, and `vold` is unable to decrypt the `/data` partition (which relies on File-Based Encryption - FBE). 

**This boot hang is a direct consequence of the incomplete source release: without the official platform configurations and drivers, the kernel cannot establish mailbox communication with the bootloader/firmware in the correct sequence.**

---

### 8. Industry Precedents and Market Standards (OEM Compliance)
To prevent any ambiguity regarding the obligation to release the full source code for kernel-space drivers (including in-house or custom-tailored drivers for touchscreens, power management, and battery policies), we highlight that other leading manufacturers who distribute Android devices powered by the Linux kernel regularly publish their complete kernel-space sources in their official public repositories, containing exactly the types of files that ZTE has omitted:
* **Xiaomi (GitHub organization `MiCode`):** Publishes in public repositories (such as `Xiaomi_Kernel_OpenSource`) the full source code for touchscreen ICs under `drivers/input/touchscreen/` (comprising low-level Goodix, Synaptics, and Focaltech implementations), as well as complete charge controllers and voltage regulators under `drivers/power/supply/` for all their flagships (without stubs or precompiled objects).
* **OnePlus / OPPO / Realme (GitHub organization `OnePlusOSS`):** Deliver complete, production-grade kernel trees that compile out of the box. This includes the full source code for their proprietary charging technologies (VOOC/SuperVOOC/Warp Charge) under the `drivers/power/oplus_chg/` directory, and touchscreen drivers under `drivers/input/touchscreen/`.
* **Samsung (Official `opensource.samsung.com` portal):** Strictly publishes all proprietary kernel-space driver code (including third-party touch IC firmware wrappers and battery managers) alongside exact factory compilation configuration files (`defconfig`).
* **Motorola / Lenovo (GitHub organization `MotorolaMobilityLLC`):** Releases 100% functional, bootable kernel source trees on GitHub, including all platform drivers and board-specific config files.

ZTE's omission of these critical kernel-space drivers and configuration fragments places the RedMagic 11 Pro in direct non-compliance with both industry standards and the legally binding terms of the GPLv2.

---

## 🎯 REQUIRED REMEDY

To achieve full GPL compliance, ZTE must release a complete and compilable source code package that includes:
1. All original C source files for the out-of-tree directories (`wlan/`, `mmrm-driver/`, `synx-kernel/`, `zte-drivers/`).
2. The platform compilation configuration files (`canoe.fragment` and platform-specific defconfigs).
3. The necessary core kernel header declarations to support dynamic linking and loadable module execution without restrictive KCFI type mismatches.

