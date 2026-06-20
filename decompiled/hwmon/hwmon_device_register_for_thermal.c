__int64 __fastcall hwmon_device_register_for_thermal(__int64 a1, char *a2, _QWORD *a3)
{
  __int64 result; // x0

  result = -22;
  if ( a1 )
  {
    if ( a2 )
      return (__int64)_hwmon_device_register(a1, a2, a3, nullptr, 0);
  }
  return result;
}
