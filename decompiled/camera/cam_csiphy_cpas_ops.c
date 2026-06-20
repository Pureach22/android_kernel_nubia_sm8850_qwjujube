__int64 __fastcall cam_csiphy_cpas_ops(unsigned int a1, char a2)
{
  unsigned int v4; // w19
  const char *v5; // x5
  __int64 v6; // x1
  __int64 v7; // x4
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v11; // [xsp+8h] [xbp-278h] BYREF
  __int64 v12; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  memset(s, 0, 0x260u);
  if ( (a2 & 1) != 0 )
  {
    LODWORD(v12) = 2;
    LODWORD(v11) = 0;
    *(_QWORD *)((char *)&s[1] + 4) = 0x10000000001LL;
    LODWORD(s[0]) = 1;
    s[3] = 1024;
    s[4] = 1024;
    s[5] = 1024;
    v4 = cam_cpas_start(a1, (__int64)&v11, (__int64)s);
    if ( (v4 & 0x80000000) == 0 )
    {
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        v5 = "CPAS START";
        v6 = (unsigned __int16)debug_mdl & 0x8000;
        v7 = 453;
LABEL_10:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v6,
          4,
          "cam_csiphy_cpas_ops",
          v7,
          v5);
        goto LABEL_14;
      }
      goto LABEL_14;
    }
    v8 = "voting CPAS: %d";
    v9 = 450;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_cpas_ops",
      v9,
      v8,
      v4);
    goto LABEL_14;
  }
  v4 = cam_cpas_stop(a1);
  if ( (v4 & 0x80000000) != 0 )
  {
    v8 = "de-voting CPAS: %d";
    v9 = 457;
    goto LABEL_13;
  }
  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
  {
    v5 = "CPAS STOPPED";
    v6 = (unsigned __int16)debug_mdl & 0x8000;
    v7 = 460;
    goto LABEL_10;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v4;
}
