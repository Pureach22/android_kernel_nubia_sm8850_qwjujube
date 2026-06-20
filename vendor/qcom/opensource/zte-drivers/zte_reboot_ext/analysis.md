# ZTE Reboot Extension Driver Analysis

## Overview
The `zte_reboot_ext` module is a core reliability utility driver that intercepts system panic events via kretprobes to collect dump reasons. It stores this panic telemetry dynamically in ZTE/Qualcomm non-volatile memory (NVMEM) cells. This allows user space to query the historical panic reasons and reboot causes via sysfs (`/sys/kernel/bootreason/boot_nvmem`) after rebooting.

## Binary Audit & Relocations
- **Hooked Interfaces:**
  - `panic` via `register_kretprobe`
  - `panic_notifier_list` via `atomic_notifier_chain_register`
- **NVMEM Cells accessed:**
  - `vendor_zlog_ss` (representing cellular/modem crash dumps)
  - `vendor_zlog_w` (watchdog crash bytes)
  - `vendor_zlog_p` (panic identifier byte 'P')
  - `vendor_zlog_panic_ext` (stores up to 14 bytes of string representation of panic parameters)
- **External Symbols:**
  - `get_ss_panic_buf_byte` (imported dynamically from the `qcom_q6v5` modem subsystem driver)

## Implementation Details
Fully reconstructed in standard C, aligning the struct layout (160 bytes) with exact offsets observed in the ROM binary. Patched to handle AArch64 registers `regs->regs` for parsing dynamic `panic()` format string arguments inside the `entry_panic` probe handler. Aligned the `.remove` callback signature to `void` to match the Linux 6.12/Android 16 platform driver APIs.
