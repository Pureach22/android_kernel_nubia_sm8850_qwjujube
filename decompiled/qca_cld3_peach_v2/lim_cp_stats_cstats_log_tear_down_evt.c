__int64 __fastcall lim_cp_stats_cstats_log_tear_down_evt(int *a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  unsigned __int64 StatusReg; // x8
  char v6; // w9
  int v7; // w9
  unsigned __int64 v8; // t2
  __int64 result; // x0
  int v10; // [xsp+0h] [xbp-30h] BYREF
  char v11; // [xsp+4h] [xbp-2Ch]
  char v12; // [xsp+5h] [xbp-2Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-2Ah]
  unsigned __int64 v14; // [xsp+Eh] [xbp-22h]
  __int16 v15; // [xsp+16h] [xbp-1Ah]
  char v16; // [xsp+18h] [xbp-18h]
  char v17; // [xsp+19h] [xbp-17h]
  char v18; // [xsp+1Ah] [xbp-16h]
  __int16 v19; // [xsp+1Bh] [xbp-15h]
  char v20; // [xsp+1Dh] [xbp-13h]
  char v21; // [xsp+1Eh] [xbp-12h]
  char v22; // [xsp+1Fh] [xbp-11h]
  char v23; // [xsp+20h] [xbp-10h]
  char v24; // [xsp+21h] [xbp-Fh]
  int v25; // [xsp+22h] [xbp-Eh]
  char v26; // [xsp+26h] [xbp-Ah]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 7036);
  v10 = 2424852;
  v4 = *(_BYTE *)(a2 + 10);
  v11 = v3;
  v12 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = *((_BYTE *)a1 + 231);
  v14 = StatusReg;
  LOWORD(StatusReg) = *((_WORD *)a1 + 116);
  v18 = v6;
  v7 = *a1;
  v19 = StatusReg;
  LOBYTE(StatusReg) = *((_BYTE *)a1 + 236);
  HIDWORD(v8) = v7;
  LODWORD(v8) = v7;
  v26 = 0;
  v20 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)((char *)a1 + 225);
  v25 = v8 >> 16;
  LOBYTE(v7) = *((_BYTE *)a1 + 227);
  v15 = StatusReg;
  LOBYTE(StatusReg) = *((_BYTE *)a1 + 230);
  v16 = v7;
  LOBYTE(v7) = *((_BYTE *)a1 + 237);
  v17 = StatusReg;
  LOBYTE(StatusReg) = *((_BYTE *)a1 + 238);
  v21 = v7;
  LOBYTE(v7) = *((_BYTE *)a1 + 239);
  v22 = StatusReg;
  LOBYTE(StatusReg) = *((_BYTE *)a1 + 242);
  v23 = v7;
  v24 = StatusReg;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v10, 39);
  _ReadStatusReg(SP_EL0);
  return result;
}
