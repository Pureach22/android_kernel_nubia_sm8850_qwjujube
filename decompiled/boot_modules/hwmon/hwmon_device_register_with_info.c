__int64 __fastcall hwmon_device_register_with_info(__int64 a1, char *a2, _QWORD *a3, _QWORD *a4, __int64 a5)
{
  __int64 result; // x0

  result = -22;
  if ( a1 && a2 && a4 && *a4 && *(_QWORD *)*a4 )
  {
    if ( a4[1] )
      return (__int64)_hwmon_device_register(a1, a2, a3, a4, a5);
  }
  return result;
}
