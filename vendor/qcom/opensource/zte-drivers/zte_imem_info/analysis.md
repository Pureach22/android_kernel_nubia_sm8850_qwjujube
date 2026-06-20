# ZTE IMEM Info Driver Analysis

## Overview
The `zte_imem_info` module is a small utility driver that maps memory-mapped hardware regions (IMEM) to retrieve hardware revisions, boot styles, or device-specific states.

## Binary Audit Findings
- **Exported Symbols:**
  - `zte_get_boot_style`
- **Ghidra Analysis:**
  - Standard Linux `platform_driver` probe that reads a register boundary from the Device Tree and exposes a helper function to other ZTE modules.
- **Header dependencies:**
  - Requires `<linux/of_address.h>` to resolve `of_iomap` mapping of physical memory regions.

## Implementation Details
Reconstructed in standard C, linked using the Android 16 Clang compiler, and verified to be signature-compatible with original ZTE calls.
