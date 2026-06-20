__int64 __fastcall lim_cp_stats_cstats_log_disc_resp_evt(char *a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  unsigned __int64 StatusReg; // x8
  char v6; // w9
  int v7; // w10
  char v8; // w8
  char v9; // w9
  char v10; // w10
  __int16 v11; // w8
  __int16 v12; // w8
  char v13; // w9
  __int16 v14; // w10
  __int64 result; // x0
  int v16; // [xsp+0h] [xbp-30h] BYREF
  char v17; // [xsp+4h] [xbp-2Ch]
  char v18; // [xsp+5h] [xbp-2Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-2Ah]
  unsigned __int64 v20; // [xsp+Eh] [xbp-22h]
  __int64 v21; // [xsp+16h] [xbp-1Ah]
  __int64 v22; // [xsp+1Eh] [xbp-12h]
  char v23; // [xsp+26h] [xbp-Ah]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 7036);
  v23 = 0;
  v16 = 2293776;
  v4 = *(_BYTE *)(a2 + 10);
  v22 = 0;
  v21 = 0;
  v17 = v3;
  v18 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = *a1;
  v20 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)(a1 + 1);
  v7 = (unsigned __int8)a1[568];
  BYTE4(v22) = v6;
  *(_WORD *)((char *)&v22 + 5) = StatusReg;
  if ( v7 )
  {
    v8 = 2;
    v23 = 2;
    if ( !a1[652] )
      goto LABEL_4;
    goto LABEL_3;
  }
  v8 = 0;
  if ( a1[652] )
  {
LABEL_3:
    v8 |= 4u;
    v23 = v8;
  }
LABEL_4:
  if ( a1[668] )
    v23 = v8 | 8;
  v9 = a1[642];
  v10 = a1[631];
  *(_WORD *)((char *)&v21 + 5) = *((_WORD *)a1 + 319);
  v11 = *((_WORD *)a1 + 316);
  HIBYTE(v21) = v9;
  *(_WORD *)((char *)&v21 + 1) = v11;
  v12 = *(_WORD *)(a1 + 643);
  v13 = a1[645];
  LOBYTE(v21) = v10;
  v14 = *((_WORD *)a1 + 318);
  LOWORD(v22) = v12;
  LOBYTE(v12) = a1[648];
  *(_WORD *)((char *)&v21 + 3) = v14;
  BYTE2(v22) = v13;
  BYTE3(v22) = v12;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v16, 39);
  _ReadStatusReg(SP_EL0);
  return result;
}
