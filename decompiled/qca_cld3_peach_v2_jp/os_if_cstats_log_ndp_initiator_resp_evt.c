__int64 __fastcall os_if_cstats_log_ndp_initiator_resp_evt(__int64 a1, _DWORD *a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w8
  int v6; // w9
  int v7; // w10
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  int v17; // [xsp+Ch] [xbp-24h] BYREF
  char v18; // [xsp+10h] [xbp-20h]
  char v19; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  char v22; // [xsp+22h] [xbp-Eh]
  char v23; // [xsp+23h] [xbp-Dh]
  __int16 v24; // [xsp+24h] [xbp-Ch]
  __int16 v25; // [xsp+26h] [xbp-Ah]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v17 = 1572902;
  v4 = *(_BYTE *)(a1 + 104);
  v18 = v3;
  v19 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v5 = a2[5];
  v22 = a2[4];
  v6 = a2[2];
  v7 = a2[3];
  v23 = v5;
  v24 = v6;
  v25 = v7;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v17, 0x1Cu, v8, v9, v10, v11, v12, v13, v14, v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
