__int64 __fastcall hwmon_device_register_with_groups(int a1, char *a2)
{
  if ( a2 )
    return _hwmon_device_register(a1, a2);
  else
    return -22;
}
