const char **__fastcall hwmon_device_register(__int64 a1)
{
  dev_warn(
    a1,
    "hwmon_device_register() is deprecated. Please convert the driver to use hwmon_device_register_with_info().\n");
  return _hwmon_device_register(a1, nullptr, nullptr, nullptr, 0);
}
