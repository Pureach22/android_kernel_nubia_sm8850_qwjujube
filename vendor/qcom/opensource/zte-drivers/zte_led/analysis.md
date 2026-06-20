# ZTE LED (Awinic AW22XXX) Driver Reverse Engineering Analysis

## Overview
The `zte_led.ko` driver controls the intelligent RGB breathing LED controller chip (Awinic AW22XXX) present on the Nubia Red Magic 11 Pro (NX809J).
It interfaces via I2C and implements specialized firmware update mechanisms, breathing and blinking patterns controlled by kernel threads (`kthreads`) and high-resolution timers (`hrtimers`), and custom sysfs/procfs interfaces for ZTE/Nubia custom software stacks.

---

## 1. Struct `aw22xxx` Memory Layout Mapping
Through detailed binary decompilation, the memory map of the central structure has been fully resolved:
*   `struct i2c_client *i2c;` @ Offset 0 (8 bytes)
*   `struct device *dev;` @ Offset 8 (8 bytes)
*   `struct led_classdev cdev;` @ Offset 16 (448 bytes)
*   `struct work_struct brightness_work;` @ Offset 464 (32 bytes)
*   `struct work_struct task_work;` @ Offset 496 (32 bytes)
*   `struct work_struct fw_work;` @ Offset 528 (32 bytes)
*   `struct work_struct cfg_work;` @ Offset 560 (32 bytes)
*   `struct work_struct recover_work;` @ Offset 592 (32 bytes)
*   `struct hrtimer timer;` @ Offset 624 (40 bytes)
*   `struct mutex cfg_lock;` @ Offset 688 (32 bytes)
*   `u32 reset_gpio;` @ Offset 720 (4 bytes)
*   `u32 irq_gpio;` @ Offset 724 (4 bytes)
*   `u32 nubia_ver_gpio;` @ Offset 728 (4 bytes)
*   `u8 no_interrupt;` @ Offset 732 (1 byte)
*   `u8 chip_type;` @ Offset 749 (1 byte) (1 = aw22118, 2 = aw22127)
*   `u8 init_flag;` @ Offset 750 (1 byte)
*   `u8 container_update_state;` @ Offset 751 (1 byte)
*   `u32 imax;` @ Offset 752 (4 bytes)
*   `u32 task_irq;` @ Offset 760 (4 bytes)
*   `u8 task0;` @ Offset 764 (1 byte)
*   `u8 task1;` @ Offset 765 (1 byte)
*   `u32 effect;` @ Offset 768 (4 bytes)
*   `u8 cfg_custom_en;` @ Offset 772 (1 byte)
*   `u32 rgb_val[9];` @ Offset 780 (36 bytes)
*   `struct pinctrl *pinctrl;` @ Offset 816 (8 bytes)
*   `struct pinctrl_state *pinctrl_default;` @ Offset 824 (8 bytes)
*   `struct pinctrl_state *pinctrl_sleep;` @ Offset 832 (8 bytes)
*   `u8 need_update;` @ Offset 840 (1 byte)

---

## 2. Chip Identification (`aw22xxx_read_chipid`)
The chip ID logic performs specific register initialization to distinguish between `AW22118` and `AW22127`:
1.  Writes register `255 = 0` and `1 = 85` (0x55) to initialize communication page.
2.  Reads register `1`. The response must be `118` (`0x76`).
3.  Reads register `0`:
    *   If `val == 24` (`0x18`), type is `AW22118` (sets `g_chip_id` to ascii string `"aw22118"` = `0x38313132327761ULL`).
    *   If `val == 39` (`0x27`), type is `AW22127` (sets `g_chip_id` to ascii string `"aw22127"` = `0x37323132327761ULL`).

---

## 3. Firmware loading logic (`aw22xxx_fw_loaded` / `aw22xxx_cfg_loaded`)
*   **Checksum Verification**: Computes big-endian 16-bit summation of firmware payload from offset 2 onwards, matching it with the header checksum at word offset 0 (`fw_words[0]`).
*   **Segmented Blocks Transfer**: Writes block segments using standard I2C master commands to registers 33, 34, 48, and transfers configuration byte streams via I2C to register 35 with a limit of 128 bytes per chunk.
*   **RGB Colors Dynamic Mapping**: If `cfg_custom_en` is set, writes to registers in range `0x10`-`0x2B` are intercepted and dynamically replaced with values calculated from the `rgb_val` array, dividing offset by 3 and mapping channels to R, G, and B.

---

## 4. Sysfs Interfaces Exposed
1.  `/sys/class/leds/aw22xxx_led/cfg`: Reads/writes current configuration bin file names.
2.  `/sys/class/leds/aw22xxx_led/effect`: Exposes active breathing or system LED effect index.
3.  `/sys/class/leds/aw22xxx_led/fw`: Direct firmware flash name query interface.
4.  `/sys/class/leds/aw22xxx_led/hwen`: Toggles reset GPIO pin state.
5.  `/sys/class/leds/aw22xxx_led/imax`: Reads/writes current maximum LED current configurations.
6.  `/sys/class/leds/aw22xxx_led/para`: Reads and writes raw LED pulse-width modulation parameter arrays.
7.  `/sys/class/leds/aw22xxx_led/pattern`: Manages the playback state of the kthread breathing patterns.
8.  `/sys/class/leds/aw22xxx_led/reg`: Direct debug register dump (reads/writes using `aw22xxx_reg_access` permission mask).
9.  `/sys/class/leds/aw22xxx_led/rgb`: Direct LED color query and change interface.
10. `/sys/class/leds/aw22xxx_led/task0` & `/sys/class/leds/aw22xxx_led/task1`: Schedules asynchronous workloads on I2C thread pool.

---

## 5. Procfs Interface
*   Creates `/proc/driver/colorleds_id` as read-only.
*   Returns the active chip string representation (`"aw22118"` or `"aw22127"`).
