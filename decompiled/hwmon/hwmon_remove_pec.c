__int64 __fastcall hwmon_remove_pec(__int64 a1)
{
  return device_remove_file(a1, &dev_attr_pec);
}
