__int64 __fastcall os_if_cstats_log_ndi_delete_resp_evt(__int64 a1, _DWORD *a2)
{
  int v4; // w9
  char v5; // w8
  int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  int v24; // [xsp+Ch] [xbp-24h] BYREF
  char v25; // [xsp+10h] [xbp-20h]
  char v26; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  __int16 v29; // [xsp+22h] [xbp-Eh]
  char v30; // [xsp+24h] [xbp-Ch]
  char v31; // [xsp+25h] [xbp-Bh]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 16);
  v24 = 1441828;
  v5 = *(_BYTE *)(a1 + 168);
  v25 = v4;
  v26 = v5;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = a2[1];
  v30 = *a2;
  v31 = v6;
  v29 = ucfg_nan_get_ndp_delete_transaction_id(a1, v7, v8, v9, v10, v11, v12, v13, v14);
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v24, 0x1Au, v15, v16, v17, v18, v19, v20, v21, v22);
  _ReadStatusReg(SP_EL0);
  return result;
}
