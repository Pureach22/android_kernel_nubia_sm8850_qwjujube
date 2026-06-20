__int64 __fastcall lim_cp_stats_cstats_log_setup_resp_evt(__int16 *a1, __int64 a2)
{
  int v3; // w9
  char v4; // w8
  unsigned __int64 StatusReg; // x8
  __int16 v6; // w9
  int v7; // w10
  char v8; // w8
  __int16 v9; // w9
  __int16 v10; // w8
  __int16 v11; // w8
  __int16 v12; // w9
  __int16 v13; // w8
  __int64 result; // x0
  int v15; // [xsp+Ch] [xbp-34h] BYREF
  char v16; // [xsp+10h] [xbp-30h]
  char v17; // [xsp+11h] [xbp-2Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-2Eh]
  unsigned __int64 v19; // [xsp+1Ah] [xbp-26h]
  _BYTE v20[19]; // [xsp+22h] [xbp-1Eh]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 7036);
  *(_DWORD *)&v20[15] = 0;
  v15 = 2424850;
  v4 = *(_BYTE *)(a2 + 10);
  *(_QWORD *)&v20[8] = 0;
  *(_QWORD *)v20 = 0;
  v16 = v3;
  v17 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v6 = *a1;
  v19 = StatusReg;
  LOBYTE(StatusReg) = *((_BYTE *)a1 + 4);
  v7 = *((unsigned __int8 *)a1 + 820);
  *(_WORD *)&v20[14] = v6;
  *(_WORD *)&v20[16] = (unsigned __int8)StatusReg;
  if ( v7 )
  {
    v8 = 2;
    v20[18] = 2;
    if ( !*((_BYTE *)a1 + 908) )
      goto LABEL_4;
    goto LABEL_3;
  }
  v8 = 0;
  if ( *((_BYTE *)a1 + 908) )
  {
LABEL_3:
    v8 |= 4u;
    v20[18] = v8;
  }
LABEL_4:
  if ( *((_BYTE *)a1 + 928) )
    v20[18] = v8 | 8;
  v9 = a1[445];
  *(_WORD *)&v20[12] = a1[1];
  v10 = a1[447];
  *(_WORD *)&v20[5] = v9;
  LOBYTE(v9) = *((_BYTE *)a1 + 883);
  *(_WORD *)&v20[7] = v10;
  v11 = a1[442];
  v20[0] = v9;
  v12 = a1[444];
  *(_WORD *)&v20[1] = v11;
  v13 = a1[448];
  *(_WORD *)&v20[3] = v12;
  LOBYTE(v12) = *((_BYTE *)a1 + 900);
  *(_WORD *)&v20[9] = v13;
  v20[11] = v12;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v15, 41);
  _ReadStatusReg(SP_EL0);
  return result;
}
