__int64 __fastcall os_if_cstats_log_ndp_indication_evt(__int64 a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  unsigned __int64 StatusReg; // x8
  __int16 v6; // w9
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  int v16; // [xsp+4h] [xbp-2Ch] BYREF
  char v17; // [xsp+8h] [xbp-28h]
  char v18; // [xsp+9h] [xbp-27h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-26h]
  unsigned __int64 v20; // [xsp+12h] [xbp-1Eh]
  char v21; // [xsp+1Ah] [xbp-16h]
  __int16 v22; // [xsp+1Bh] [xbp-15h]
  char v23; // [xsp+1Dh] [xbp-13h]
  __int16 v24; // [xsp+1Eh] [xbp-12h]
  char v25; // [xsp+20h] [xbp-10h]
  char v26; // [xsp+21h] [xbp-Fh]
  __int16 v27; // [xsp+22h] [xbp-Eh]
  int v28; // [xsp+24h] [xbp-Ch]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v16 = 2097196;
  v4 = *(_BYTE *)(a1 + 168);
  v17 = v3;
  v18 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = *(_DWORD *)(a2 + 24);
  v20 = StatusReg;
  LODWORD(StatusReg) = *(_DWORD *)(a2 + 8);
  v27 = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 18);
  v28 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)(a2 + 19);
  v21 = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 23);
  v22 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)(a2 + 12);
  v23 = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 14);
  v24 = StatusReg;
  LOBYTE(StatusReg) = *(_BYTE *)(a2 + 17);
  v25 = v6;
  v26 = StatusReg;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v16, 0x24u, v7, v8, v9, v10, v11, v12, v13, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
