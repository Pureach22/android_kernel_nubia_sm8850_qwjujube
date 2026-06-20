__int64 __fastcall cm_cp_stats_cstats_log_deauth_evt(__int64 a1, __int16 a2)
{
  int v3; // w9
  char v4; // w8
  __int64 result; // x0
  int v6; // [xsp+Ch] [xbp-24h] BYREF
  char v7; // [xsp+10h] [xbp-20h]
  char v8; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  __int16 v11; // [xsp+22h] [xbp-Eh]
  char v12; // [xsp+24h] [xbp-Ch]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v6 = 1376261;
  v4 = *(_BYTE *)(a1 + 104);
  v7 = v3;
  v8 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v11 = a2;
  v12 = 1;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v6, 25);
  _ReadStatusReg(SP_EL0);
  return result;
}
