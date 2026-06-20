__int64 __fastcall lim_cp_stats_cstats_log_auth_evt(__int64 a1, char a2, char a3, char a4, char a5)
{
  int v9; // w9
  char v10; // w8
  __int64 result; // x0
  int v12; // [xsp+Ch] [xbp-24h] BYREF
  char v13; // [xsp+10h] [xbp-20h]
  char v14; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  char v17; // [xsp+22h] [xbp-Eh]
  char v18; // [xsp+23h] [xbp-Dh]
  char v19; // [xsp+24h] [xbp-Ch]
  char v20; // [xsp+25h] [xbp-Bh]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 7036);
  v12 = 1441792;
  v10 = *(_BYTE *)(a1 + 10);
  v13 = v9;
  v14 = v10;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v20 = a2;
  v17 = a3;
  v18 = a4;
  v19 = a5;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v12, 26);
  _ReadStatusReg(SP_EL0);
  return result;
}
