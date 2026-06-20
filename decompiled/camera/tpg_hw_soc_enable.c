__int64 __fastcall tpg_hw_soc_enable(_DWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // [xsp+18h] [xbp-278h] BYREF
  int v9; // [xsp+20h] [xbp-270h]
  int v10; // [xsp+24h] [xbp-26Ch]
  _QWORD s[77]; // [xsp+28h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  memset(s, 0, 0x260u);
  v8 = 0;
  v9 = 5;
  LODWORD(s[0]) = 1;
  *(_QWORD *)((char *)&s[1] + 4) = 0x10000000001LL;
  s[3] = 1024;
  s[4] = 1024;
  s[5] = 1024;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_soc_enable",
      416,
      "TPG[%d] camnoc_bw:%lld mnoc_ab_bw:%lld mnoc_ib_bw:%lld ",
      *a1,
      1024,
      1024,
      1024);
  if ( (unsigned int)cam_cpas_start(a1[3], (__int64)&v8, (__int64)s) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_soc_enable",
      421,
      "TPG[%d] CPAS start failed",
      *a1);
    result = 4294967282LL;
  }
  else
  {
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
           *((_QWORD *)a1 + 5),
           0xFFFFFFFFLL,
           1,
           a2,
           1);
    if ( v5 )
    {
      v6 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_soc_enable",
        431,
        "TPG[%d] enable platform failed",
        *a1);
      cam_cpas_stop(a1[3]);
      result = v6;
    }
    else
    {
      v7 = raw_spin_lock_irqsave(a1 + 24);
      a1[2] = 2;
      raw_spin_unlock_irqrestore(a1 + 24, v7);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
