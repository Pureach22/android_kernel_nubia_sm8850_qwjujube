__int64 __fastcall os_if_cstats_log_ndp_responder_req_evt(__int64 a1, _DWORD *a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w8
  int v6; // w9
  int v7; // w9
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  int v17; // [xsp+8h] [xbp-28h] BYREF
  char v18; // [xsp+Ch] [xbp-24h]
  char v19; // [xsp+Dh] [xbp-23h]
  unsigned __int64 time_of_the_day_us; // [xsp+Eh] [xbp-22h]
  unsigned __int64 StatusReg; // [xsp+16h] [xbp-1Ah]
  __int16 v22; // [xsp+1Eh] [xbp-12h]
  __int16 v23; // [xsp+20h] [xbp-10h]
  char v24; // [xsp+22h] [xbp-Eh]
  int v25; // [xsp+23h] [xbp-Dh]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v17 = 1769511;
  v4 = *(_BYTE *)(a1 + 104);
  v18 = v3;
  v19 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = a2[2];
  v5 = a2[3];
  v24 = a2[4];
  v22 = v6;
  v7 = a2[144];
  v23 = v5;
  v25 = v7;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v17, 0x1Fu, v8, v9, v10, v11, v12, v13, v14, v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
