__int64 __fastcall hwmon_notify_event(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  char *v4; // x8
  bool v5; // zf
  int v6; // w19
  __int64 *v9; // x21
  __int64 *v10; // x20
  __int64 result; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v13[4]; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v14[6]; // [xsp+30h] [xbp-30h] BYREF

  v14[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = v14;
  v12[1] = 0;
  if ( a2 > 9 || _templates_size[a2] <= a3 )
  {
    result = 4294967274LL;
  }
  else
  {
    v4 = _templates[a2];
    memset(v14, 0, 37);
    v5 = a2 == 9 || a2 == 2;
    v6 = a4;
    v13[0] = 0;
    v13[1] = 0;
    if ( v5 )
      a4 = (unsigned int)a4;
    else
      a4 = (unsigned int)(a4 + 1);
    v13[2] = 0;
    v13[3] = 0;
    scnprintf(v13, 32, *(const char **)&v4[8 * a3], a4);
    scnprintf(v14, 37, "NAME=%s", (const char *)v13);
    sysfs_notify(a1, 0, v13);
    kobject_uevent_env(a1, 2, v12);
    if ( a2 == 1 )
    {
      v9 = *(__int64 **)(a1 + 920);
      v10 = (__int64 *)(a1 + 920);
      while ( v9 != v10 )
      {
        if ( *((_DWORD *)v9 + 6) == v6 )
          thermal_zone_device_update(v9[4], 0);
        v9 = (__int64 *)*v9;
      }
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
