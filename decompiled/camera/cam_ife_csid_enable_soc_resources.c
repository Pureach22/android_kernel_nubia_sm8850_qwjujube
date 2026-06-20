__int64 __fastcall cam_ife_csid_enable_soc_resources(__int64 a1, unsigned int a2)
{
  __int64 v4; // x22
  unsigned int v5; // w21
  unsigned int drv_enable; // w0
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v9; // x1
  __int64 v11; // [xsp+8h] [xbp-278h] BYREF
  __int64 v12; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  memset(s, 0, 0x260u);
  v4 = *(_QWORD *)(a1 + 3296);
  LODWORD(v12) = 2;
  LODWORD(s[0]) = 1;
  *(_QWORD *)((char *)&s[1] + 4) = 0x10000000001LL;
  s[3] = 1024;
  s[4] = 1024;
  s[5] = 1024;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_enable_soc_resources",
      183,
      "csid camnoc_bw:%lld mnoc_ab_bw:%lld mnoc_ib_bw:%lld ",
      1024,
      1024,
      1024);
  if ( (unsigned int)cam_cpas_start(*(_DWORD *)v4, (__int64)&v11, (__int64)s) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_enable_soc_resources",
      187,
      "Error CPAS start failed");
    v5 = -14;
    goto LABEL_15;
  }
  if ( (*(_BYTE *)(v4 + 12) & 1) == 0 )
  {
    drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
    if ( drv_enable )
    {
      v5 = drv_enable;
      v7 = "Failed to query DRV enable rc:%d";
      v8 = 196;
LABEL_14:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_enable_soc_resources",
        v8,
        v7,
        v5);
      cam_cpas_stop(*(_DWORD *)v4);
      goto LABEL_15;
    }
  }
  if ( *(_BYTE *)(a1 + 3200) == 1 )
    v9 = *(unsigned int *)(a1 + 20);
  else
    v9 = 0xFFFFFFFFLL;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
         a1,
         v9,
         1,
         a2,
         1);
  if ( v5 )
  {
    v7 = "enable platform failed rc %d";
    v8 = 205;
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v5;
}
