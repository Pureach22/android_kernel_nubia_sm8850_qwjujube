__int64 sub_72C8()
{
  __int64 v0; // x12

  if ( (v0 & 0x800000000000000LL) != 0 )
    JUMPOUT(0x126C);
  return devm_hwmon_device_register_with_groups();
}
