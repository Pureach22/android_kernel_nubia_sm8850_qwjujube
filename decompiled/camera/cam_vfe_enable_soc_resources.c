__int64 __fastcall cam_vfe_enable_soc_resources(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w10
  int v4; // w0
  __int64 result; // x0
  int drv_enable; // w0
  unsigned int v7; // w19
  __int64 v8; // x1
  __int64 v9; // [xsp+8h] [xbp-278h] BYREF
  __int64 v10; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = 0;
  memset(s, 0, 0x260u);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_enable_soc_resources",
      264,
      "Error! Invalid params");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v2 = *(_QWORD *)(a1 + 3296);
  LODWORD(v9) = 0;
  v3 = *(_BYTE *)(v2 + 24);
  LODWORD(v10) = 2;
  LODWORD(s[0]) = 1;
  LODWORD(s[2]) = 512;
  if ( (v3 & 1) == 0 )
    HIDWORD(s[2]) = 2;
  HIDWORD(s[1]) = 1;
  s[3] = 2000000000;
  s[4] = 2000000000;
  s[5] = 2000000000;
  v4 = cam_cpas_start(*(_DWORD *)v2, (__int64)&v9, (__int64)s);
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_enable_soc_resources",
      285,
      "Error! CPAS start failed rc=%d",
      v4);
    result = 4294967282LL;
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(v2 + 24) & 1) == 0 )
  {
    drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
    if ( drv_enable )
    {
      v7 = drv_enable;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_enable_soc_resources",
        293,
        "Failed to query DRV enable rc:%d",
        drv_enable);
LABEL_15:
      result = v7;
      goto LABEL_16;
    }
  }
  if ( *(_BYTE *)(a1 + 3200) == 1 )
    v8 = *(unsigned int *)(a1 + 20);
  else
    v8 = 0xFFFFFFFFLL;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
             a1,
             v8,
             1,
             *(unsigned int *)(a1 + 2872),
             1);
  if ( (_DWORD)result )
  {
    v7 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_enable_soc_resources",
      302,
      "Error! enable platform failed rc=%d",
      result);
    cam_cpas_stop(*(_DWORD *)v2);
    goto LABEL_15;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
