__int64 __fastcall cam_cdm_util_cpas_start(__int64 a1)
{
  _DWORD *v2; // x20
  unsigned int v3; // w0
  unsigned int v4; // w19
  __int64 v6; // [xsp+8h] [xbp-278h] BYREF
  __int64 v7; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v7 = 0;
  memset(s, 0, 0x260u);
  if ( a1 )
  {
    v2 = *(_DWORD **)(a1 + 3680);
    LODWORD(v7) = 2;
    v3 = v2[1217];
    LODWORD(s[2]) = 256;
    LODWORD(v6) = 0;
    LODWORD(s[0]) = 1;
    s[3] = 1024;
    s[4] = 1024;
    s[5] = 1024;
    v4 = cam_cpas_start(v3, (__int64)&v6, (__int64)s);
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_util_cpas_start",
        49,
        "CDM[%d] CPAS start failed rc=%d",
        *v2,
        v4);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_util_cpas_start",
      32,
      "Invalid cdm hw");
    v4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
