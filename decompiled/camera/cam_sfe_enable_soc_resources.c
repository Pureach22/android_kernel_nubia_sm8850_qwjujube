__int64 __fastcall cam_sfe_enable_soc_resources(__int64 a1)
{
  unsigned int *v2; // x20
  int v3; // w0
  __int64 result; // x0
  int drv_enable; // w0
  unsigned int v6; // w19
  __int64 v7; // x1
  __int64 v8; // [xsp+8h] [xbp-278h] BYREF
  __int64 v9; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = 0;
  memset(s, 0, 0x260u);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_enable_soc_resources",
      181,
      "Error! Invalid params");
    result = 4294967274LL;
    goto LABEL_13;
  }
  v2 = *(unsigned int **)(a1 + 3296);
  LODWORD(v9) = 2;
  LODWORD(v8) = 0;
  *(_QWORD *)((char *)&s[1] + 4) = 0x20000000001LL;
  LODWORD(s[0]) = 1;
  s[3] = 2000000000;
  s[4] = 2000000000;
  s[5] = 2000000000;
  v3 = cam_cpas_start(*v2, (__int64)&v8, (__int64)s);
  if ( v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_enable_soc_resources",
      199,
      "CPAS start failed rc=%d",
      v3);
    result = 4294967282LL;
    goto LABEL_13;
  }
  drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
  if ( drv_enable )
  {
    v6 = drv_enable;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_sfe_enable_soc_resources",
      206,
      "Failed to query DRV enable rc:%d",
      drv_enable);
LABEL_12:
    result = v6;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(a1 + 3200) == 1 )
    v7 = *(unsigned int *)(a1 + 20);
  else
    v7 = 0xFFFFFFFFLL;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
             a1,
             v7,
             1,
             *(unsigned int *)(a1 + 2872),
             1);
  if ( (_DWORD)result )
  {
    v6 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_enable_soc_resources",
      218,
      "Enable platform failed rc=%d",
      result);
    cam_cpas_stop(*v2);
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
