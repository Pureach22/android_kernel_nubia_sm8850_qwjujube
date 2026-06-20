__int64 __fastcall devm_hwmon_release(__int64 a1, const char ***a2)
{
  const char **v2; // x19
  const char *v3; // x0
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v3 = (*a2)[14];
  if ( !v3 )
    v3 = *v2;
  v5 = 0;
  result = sscanf(v3, "hwmon%d", &v5);
  if ( (_DWORD)result == 1 )
  {
    device_unregister(v2);
    result = ida_free(&hwmon_ida, v5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
