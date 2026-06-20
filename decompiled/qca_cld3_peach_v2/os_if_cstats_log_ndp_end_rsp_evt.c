__int64 __fastcall os_if_cstats_log_ndp_end_rsp_evt(__int64 a1, _DWORD *a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w8
  int v6; // w9
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  int v16; // [xsp+Ch] [xbp-24h] BYREF
  char v17; // [xsp+10h] [xbp-20h]
  char v18; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  char v21; // [xsp+22h] [xbp-Eh]
  char v22; // [xsp+23h] [xbp-Dh]
  __int16 v23; // [xsp+24h] [xbp-Ch]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v16 = 1441834;
  v4 = *(_BYTE *)(a1 + 168);
  v17 = v3;
  v18 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = a2[3];
  v5 = a2[4];
  v23 = a2[2];
  v21 = v6;
  v22 = v5;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v16, 0x1Au, v7, v8, v9, v10, v11, v12, v13, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
