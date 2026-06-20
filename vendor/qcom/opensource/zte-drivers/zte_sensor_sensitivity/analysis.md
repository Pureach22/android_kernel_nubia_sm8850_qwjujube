# ZTE Sensors Sensitivity Calibration Driver Analysis

## Overview
The `zte_sensor_sensitivity` module is a utility hardware calibration interface. It creates a sysfs class named `sensors_sensitivity` and spawns two virtual character devices (`accel` and `gyro`) to configure accelerometer and gyroscope sensitivity properties.

## Sysfs Design & Boundaries
- **Virtual Devices:**
  - `/sys/class/sensors_sensitivity/accel/`
  - `/sys/class/sensors_sensitivity/gyro/`
- **Dynamic attributes for both devices:**
  - `enable` (bool, accepted values: `0` or `1`)
  - `x_axial` (integer, safety constraint: strictly less than `201`)
  - `y_axial` (integer, safety constraint: strictly less than `201`)
  - `z_axial` (integer, safety constraint: strictly less than `201`)
- **Locks & Synchronization:**
  - Shared mutex (`struct mutex lock` inside `sensors_sens_data`) ensures thread-safe updates to calibration metrics.

## Implementation Details
Reconstructed in standard C with exact structure layout alignment (96 bytes). Safely utilizes a global pointer reference `sensors_sens_data_ptr` to access state from inside sysfs callbacks, bypassing unreliable static offset arithmetic inside `struct device` (`dev + 152`) which changes dynamically across kernel versions.
