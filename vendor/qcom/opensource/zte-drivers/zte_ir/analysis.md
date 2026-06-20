# ZTE IR SPI Driver Analysis

## Overview
The `zte_ir` module is a custom SPI infrared driver (IR Blaster) that registers a dynamic character device (`/dev/zte_ir`) to receive modulated pulse inputs from userspace. It translates duration values (in microseconds) into specific carrier wave duty-cycles at a set frequency (default 38kHz) and transmits them synchronously via SPI.

## Binary & Struct Offsets
- **Struct size:** `80104` bytes
- **Field alignment:**
  - `dev_t devt` (offset `0`)
  - `u16 tx_buf[40000]` (offset `4` -> `80004` bytes, buffer for modulating up to 40k carrier pulses)
  - `u16 pattern_high` (offset `80004` - value `31`, modulation duty-cycle on marker)
  - `u16 pattern_low` (offset `80006` - value `0`, space/silence pattern)
  - `u32 speed_hz` (offset `80008` - value `608000`, corresponds to 16 * 38kHz)
  - `struct spi_device *spi` (offset `80016`)
  - `u32 state` (offset `80032`)
  - `struct mutex buf_lock` (offset `80040`)
  - `struct list_head device_entry` (offset `80088`)

## IOCTL Interface
- **Command:** `ZTE_IR_IOC_SET_FREQ = 0x40046b31` (`_IOW('k', 0x31, unsigned int)`)
- **Action:** Sets the carrier frequency. Dynamically updates `speed_hz` to `16 * freq` which in turn alters the SPI baudrate to output a matching frequency over the wire.

## Write Modulation Logic
For each pulse duration in microseconds (`pulse_val`):
- Converts time to SPI words based on the formula:
  `spi_word_count = ((u64)pulse_val * (speed_hz >> 4) + 500000) / 1000000`
- Fills `tx_buf` sequentially using `pattern_high` for even pulses (carrier waves) and `pattern_low` for odd pulses (silences).
- Initiates síncronous SPI transfer using `spi_sync`.
