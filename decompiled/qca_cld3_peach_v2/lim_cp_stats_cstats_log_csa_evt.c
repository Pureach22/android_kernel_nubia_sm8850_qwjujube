__int64 __fastcall lim_cp_stats_cstats_log_csa_evt(__int64 a1, char a2, __int16 a3, char a4, char a5)
{
  int v10; // w9
  char v11; // w8
  int v12; // w8
  int v13; // w9
  __int64 result; // x0
  int v15; // [xsp+8h] [xbp-28h] BYREF
  char v16; // [xsp+Ch] [xbp-24h]
  char v17; // [xsp+Dh] [xbp-23h]
  unsigned __int64 time_of_the_day_us; // [xsp+Eh] [xbp-22h]
  unsigned __int64 StatusReg; // [xsp+16h] [xbp-1Ah]
  char v20; // [xsp+1Eh] [xbp-12h]
  __int16 v21; // [xsp+1Fh] [xbp-11h]
  char v22; // [xsp+21h] [xbp-Fh]
  __int16 v23; // [xsp+22h] [xbp-Eh]
  char v24; // [xsp+24h] [xbp-Ch]
  char v25; // [xsp+25h] [xbp-Bh]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 7036);
  v15 = 1703983;
  v11 = *(_BYTE *)(a1 + 10);
  v16 = v10;
  v17 = v11;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v12 = *(_DWORD *)(a1 + 284);
  v13 = *(_DWORD *)(a1 + 7176);
  v20 = a2;
  v21 = a3;
  v22 = a4;
  v23 = v12;
  v24 = v13;
  v25 = a5;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v15, 30);
  _ReadStatusReg(SP_EL0);
  return result;
}
