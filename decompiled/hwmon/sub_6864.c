__int64 sub_6864()
{
  __int64 v0; // x12

  if ( (v0 & 0x800000000000000LL) != 0 )
    JUMPOUT(0x808);
  return hwmon_device_register_with_groups();
}
