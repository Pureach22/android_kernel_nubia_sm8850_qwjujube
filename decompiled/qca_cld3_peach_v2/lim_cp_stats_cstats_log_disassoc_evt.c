__int64 __fastcall lim_cp_stats_cstats_log_disassoc_evt(__int64 a1, char a2, __int16 a3)
{
  int v5; // w9
  char v6; // w8
  __int64 result; // x0
  int v8; // [xsp+Ch] [xbp-24h] BYREF
  char v9; // [xsp+10h] [xbp-20h]
  char v10; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  __int16 v13; // [xsp+22h] [xbp-Eh]
  char v14; // [xsp+24h] [xbp-Ch]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 7036);
  v8 = 1376262;
  v6 = *(_BYTE *)(a1 + 10);
  v9 = v5;
  v10 = v6;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v13 = a3;
  v14 = a2;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v8, 25);
  _ReadStatusReg(SP_EL0);
  return result;
}
