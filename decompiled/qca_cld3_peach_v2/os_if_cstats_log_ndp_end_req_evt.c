__int64 __fastcall os_if_cstats_log_ndp_end_req_evt(__int64 a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  int v15; // [xsp+Ch] [xbp-24h] BYREF
  char v16; // [xsp+10h] [xbp-20h]
  char v17; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  __int16 v20; // [xsp+22h] [xbp-Eh]
  char v21; // [xsp+24h] [xbp-Ch]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v15 = 1376297;
  v4 = *(_BYTE *)(a1 + 168);
  v16 = v3;
  v17 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v5 = *(_DWORD *)(a2 + 12);
  v20 = *(_DWORD *)(a2 + 8);
  v21 = v5;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v15, 0x19u, v6, v7, v8, v9, v10, v11, v12, v13);
  _ReadStatusReg(SP_EL0);
  return result;
}
