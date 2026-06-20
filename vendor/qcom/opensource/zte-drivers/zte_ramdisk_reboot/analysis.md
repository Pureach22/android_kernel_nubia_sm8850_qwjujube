# ZTE Ramdisk Reboot Driver Analysis

## Overview
The `zte_ramdisk_reboot` module is a critical platform driver responsible for extracting low-level boot time parameters and telemetries from the Qualcomm Extensible Boot Loader (XBL) memory region. It exposes a custom sysfs kobject path to query the Serial Number and Overcurrent Protection (OCP) status, and exports the `zte_ramdisk_reboot_write` API for watchdog reboot status synchronization.

## Struct Details & Offsets
The driver defines a private control structure `struct zte_ramdisk_reboot_data` of exactly 136 bytes on AArch64 (64-bit kernel):
- `struct device *dev` (offset `0`, size `8` bytes)
- `struct kobject kobj` (offset `8`, size `96` bytes)
- `struct nvmem_cell *cell` (offset `104`, size `8` bytes)
- `phys_addr_t base` (offset `112`, size `8` bytes)
- `size_t size` (offset `120`, size `8` bytes)
- `void __iomem *vaddr` (offset `128`, size `8` bytes)

## Memory-Region Retrieval
The memory region is parsed from the device tree using the `memory-region` phandle reference associated with the driver's device node:
- Uses `of_parse_phandle_with_args(np, "memory-region", NULL, 0, &args)`
- Resolves to reserved memory via `of_reserved_mem_lookup(args.np)`
- Maps the physical base to virtual space using `devm_ioremap_wc` (Write-Combined cache policy for reading XBL log memory efficiently)

## Log Parsing Logic
At probe, the driver scans the first `0x3000` bytes (or less if the mapped region is smaller) of the XBL log region in memory for two specific patterns:
1. `"OCP Occured: "` - Extracts the overcurrent status and flags.
2. `"serialno"` - Extracts the unique hardware serial number.

- **OCP extraction**: Extracts content from the pattern `"OCP Occured: <telemetry> Status: "` using `strstr` offsets.
- **SN extraction**: Extracts content after the `" = "` separator.
- **sysfs output format**: `"SN: <serial_number>, OCP: <ocp_status>"`

## Sysfs Attribute Node
The driver registers a custom kobject named `ramdisk_reboot` directly under the standard `kernel_kobj` (`/sys/kernel/ramdisk_reboot`).
- **Exposed Attribute**: `/sys/kernel/ramdisk_reboot/ramdisk_nvmem`
- **Permissions**: `0644` (read/write, though writing is prohibited returning `-EINVAL` dynamically)
- **Show Function**: Outputs the formatted `extract_buffer` containing the parsed XBL boot telemetries.

## External API & Watchdog Integration
- **Function**: `zte_ramdisk_reboot_write(unsigned char *val, int len)` (Exported via `EXPORT_SYMBOL_GPL`)
- **Integration**: The Qualcomm Watchdog core driver (`qcom_wdt_core.ko`) links against this symbol to write a 1-byte reset code to the `"ramdisk-rb"` NVMEM cell when a watchdog bite/bark triggers.
