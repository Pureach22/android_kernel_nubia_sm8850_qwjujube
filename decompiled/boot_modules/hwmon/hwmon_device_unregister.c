__int64 __fastcall hwmon_device_unregister(const char **a1)
{
  const char *v2; // x0
  __int64 result; // x0
  unsigned int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[14];
  if ( !v2 )
    v2 = *a1;
  v4 = 0;
  result = sscanf(v2, "hwmon%d", &v4);
  if ( (_DWORD)result == 1 )
  {
    device_unregister(a1);
    result = ida_free(&hwmon_ida, v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
