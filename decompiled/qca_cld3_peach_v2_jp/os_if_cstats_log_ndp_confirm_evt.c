__int64 __fastcall os_if_cstats_log_ndp_confirm_evt(__int64 a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w9
  int v6; // w10
  char v7; // w8
  char v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  int v18; // [xsp+4h] [xbp-2Ch] BYREF
  char v19; // [xsp+8h] [xbp-28h]
  char v20; // [xsp+9h] [xbp-27h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-26h]
  unsigned __int64 StatusReg; // [xsp+12h] [xbp-1Eh]
  int v23; // [xsp+1Ah] [xbp-16h]
  __int16 v24; // [xsp+1Eh] [xbp-12h]
  char v25; // [xsp+20h] [xbp-10h]
  __int16 v26; // [xsp+21h] [xbp-Fh]
  char v27; // [xsp+23h] [xbp-Dh]
  char v28; // [xsp+24h] [xbp-Ch]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v18 = 1900587;
  v4 = *(_BYTE *)(a1 + 104);
  v19 = v3;
  v20 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v5 = *(_DWORD *)(a2 + 8);
  v6 = *(_DWORD *)(a2 + 12);
  v28 = *(_DWORD *)(a2 + 28);
  v7 = *(_BYTE *)(a2 + 20);
  v23 = v5;
  LOWORD(v5) = *(_WORD *)(a2 + 21);
  v25 = v7;
  v8 = *(_BYTE *)(a2 + 25);
  v24 = v6;
  v26 = v5;
  v27 = v8;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v18, 0x21u, v9, v10, v11, v12, v13, v14, v15, v16);
  _ReadStatusReg(SP_EL0);
  return result;
}
