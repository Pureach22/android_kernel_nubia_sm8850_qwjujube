__int64 __fastcall sensor_create_sysfs_interfaces(__int64 a1, __int64 a2)
{
  int v4; // w21
  __int64 result; // x0
  __int64 v6; // x23

  v4 = ((__int64 (*)(void))device_create_file)();
  if ( v4 )
  {
    v6 = 0;
  }
  else if ( (unsigned int)device_create_file(a1, a2 + 32) )
  {
    v6 = 1;
  }
  else if ( (unsigned int)device_create_file(a1, a2 + 64) )
  {
    v6 = 2;
  }
  else
  {
    result = device_create_file(a1, a2 + 96);
    if ( !(_DWORD)result )
      return result;
    v6 = 3;
  }
  device_remove_file(a1, a2 + 32 * v6);
  if ( !v4 )
  {
    device_remove_file(a1, a2 + 32 * (v6 - 1));
    if ( v6 != 1 )
    {
      device_remove_file(a1, a2 + 32 * (v6 - 2));
      if ( v6 != 2 )
        device_remove_file(a1, a2 + 32 * v6 - 96);
    }
  }
  printk(&unk_7603, "NUBIA_SENSORS_SENS", "sensor_create_sysfs_interfaces", 57);
  return 4294967277LL;
}
