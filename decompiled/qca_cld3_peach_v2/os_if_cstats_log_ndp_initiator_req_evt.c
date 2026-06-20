__int64 __fastcall os_if_cstats_log_ndp_initiator_req_evt(__int64 *a1)
{
  __int64 v2; // x8
  int v3; // w10
  int v4; // w8
  int v5; // w8
  char v6; // w9
  char v7; // w9
  char v8; // w9
  char v9; // w9
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  int v19; // [xsp+0h] [xbp-30h] BYREF
  char v20; // [xsp+4h] [xbp-2Ch]
  char v21; // [xsp+5h] [xbp-2Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-2Ah]
  unsigned __int64 StatusReg; // [xsp+Eh] [xbp-22h]
  __int16 v24; // [xsp+16h] [xbp-1Ah]
  __int16 v25; // [xsp+18h] [xbp-18h]
  int v26; // [xsp+1Ah] [xbp-16h]
  __int16 v27; // [xsp+1Eh] [xbp-12h]
  char v28; // [xsp+20h] [xbp-10h]
  __int16 v29; // [xsp+21h] [xbp-Fh]
  char v30; // [xsp+23h] [xbp-Dh]
  char v31; // [xsp+24h] [xbp-Ch]
  char v32; // [xsp+25h] [xbp-Bh]
  char v33; // [xsp+26h] [xbp-Ah]
  char v34; // [xsp+27h] [xbp-9h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v19 = 2359333;
  v3 = *(_DWORD *)(v2 + 16);
  LOBYTE(v2) = *(_BYTE *)(v2 + 168);
  v20 = v3;
  v21 = v2;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v4 = *((_DWORD *)a1 + 3);
  v24 = *((_DWORD *)a1 + 2);
  v25 = v4;
  v5 = *((_DWORD *)a1 + 5);
  v26 = *((_DWORD *)a1 + 4);
  v6 = *((_BYTE *)a1 + 34);
  v27 = v5;
  LOWORD(v5) = *(_WORD *)((char *)a1 + 35);
  v28 = v6;
  v7 = *((_BYTE *)a1 + 39);
  v29 = v5;
  LOBYTE(v5) = *((_BYTE *)a1 + 28);
  v30 = v7;
  v8 = *((_BYTE *)a1 + 29);
  v31 = v5;
  LOBYTE(v5) = *((_BYTE *)a1 + 30);
  v32 = v8;
  v9 = *((_BYTE *)a1 + 33);
  v33 = v5;
  v34 = v9;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v19, 0x28u, v10, v11, v12, v13, v14, v15, v16, v17);
  _ReadStatusReg(SP_EL0);
  return result;
}
