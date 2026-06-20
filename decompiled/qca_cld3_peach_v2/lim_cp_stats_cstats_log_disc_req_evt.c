__int64 __fastcall lim_cp_stats_cstats_log_disc_req_evt(char *a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  __int16 v5; // w9
  char v6; // w8
  __int16 v7; // w9
  char v8; // w8
  __int16 v9; // w9
  char v10; // w8
  char v11; // w8
  __int16 v12; // w9
  char v13; // w8
  __int64 result; // x0
  int v15; // [xsp+0h] [xbp-30h] BYREF
  char v16; // [xsp+4h] [xbp-2Ch]
  char v17; // [xsp+5h] [xbp-2Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-2Ah]
  unsigned __int64 StatusReg; // [xsp+Eh] [xbp-22h]
  __int16 v20; // [xsp+16h] [xbp-1Ah]
  char v21; // [xsp+18h] [xbp-18h]
  char v22; // [xsp+19h] [xbp-17h]
  char v23; // [xsp+1Ah] [xbp-16h]
  __int16 v24; // [xsp+1Bh] [xbp-15h]
  char v25; // [xsp+1Dh] [xbp-13h]
  char v26; // [xsp+1Eh] [xbp-12h]
  __int16 v27; // [xsp+1Fh] [xbp-11h]
  char v28; // [xsp+21h] [xbp-Fh]
  char v29; // [xsp+22h] [xbp-Eh]
  __int16 v30; // [xsp+23h] [xbp-Dh]
  char v31; // [xsp+25h] [xbp-Bh]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 7036);
  v15 = 2228239;
  v4 = *(_BYTE *)(a2 + 10);
  v16 = v3;
  v17 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v5 = *(_WORD *)(a1 + 1);
  v29 = *a1;
  v6 = a1[10];
  v30 = v5;
  v7 = *(_WORD *)(a1 + 11);
  v23 = v6;
  v8 = a1[15];
  v24 = v7;
  v9 = *((_WORD *)a1 + 2);
  v25 = v8;
  v10 = a1[6];
  v20 = v9;
  LOBYTE(v9) = a1[9];
  v21 = v10;
  v11 = a1[16];
  v22 = v9;
  v12 = *(_WORD *)(a1 + 17);
  v26 = v11;
  v13 = a1[21];
  v31 = 0;
  v27 = v12;
  v28 = v13;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v15, 38);
  _ReadStatusReg(SP_EL0);
  return result;
}
