__int64 __fastcall lt9611uxc_hpd_work(__int64 result)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(__int64, __int64); // x9
  _DWORD *v3; // x20
  __int64 v4; // x21
  __int64 v5; // x19
  int v6; // w22
  __int64 v7; // x0
  __int64 v8; // x8
  const char *connector_status_name; // x0
  __int64 v10; // x8
  _QWORD v11[5]; // [xsp+0h] [xbp-70h] BYREF
  _QWORD v12[4]; // [xsp+28h] [xbp-48h] BYREF
  _QWORD v13[5]; // [xsp+48h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result != 3448 )
  {
    v1 = *(_QWORD *)(result - 2656);
    if ( v1 )
    {
      v2 = *(__int64 (__fastcall **)(__int64, __int64))(v1 + 16);
      memset(v13, 0, 32);
      memset(v12, 0, sizeof(v12));
      if ( v2 )
      {
        v3 = (_DWORD *)(result - 2880);
        v4 = result;
        v5 = *(_QWORD *)(result - 3072);
        v6 = *(_DWORD *)(result - 2880);
        v7 = result - 3072;
        if ( *((_DWORD *)v2 - 1) != -1859972157 )
          __break(0x8229u);
        result = v2(v7, 1);
        v8 = v4;
        *v3 = result;
        if ( v6 != (_DWORD)result || !*(_QWORD *)(v4 - 3128) )
        {
          if ( (_DWORD)result != 1 )
          {
            *(_BYTE *)(v4 + 568) = 0;
            kfree(*(_QWORD *)(v4 - 3128));
            v8 = v4;
            *(_QWORD *)(v4 - 3128) = 0;
          }
          scnprintf(v13, 32, "name=%s", *(const char **)(v8 - 2976));
          connector_status_name = (const char *)drm_get_connector_status_name((unsigned int)*v3);
          scnprintf(v12, 32, "status=%s", connector_status_name);
          v11[3] = 0;
          v11[4] = 0;
          v11[1] = v12;
          v11[2] = "HOTPLUG=1";
          v10 = *(_QWORD *)(v5 + 64);
          v11[0] = v13;
          result = kobject_uevent_env(*(_QWORD *)(v10 + 8), 2, v11);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
