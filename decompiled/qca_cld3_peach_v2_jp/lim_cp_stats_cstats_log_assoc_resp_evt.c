__int64 __fastcall lim_cp_stats_cstats_log_assoc_resp_evt(
        __int64 a1,
        char a2,
        __int16 a3,
        __int16 a4,
        __int64 a5,
        char *a6,
        char a7,
        char a8,
        char a9,
        char a10,
        char a11)
{
  char v11; // w26
  __int64 v12; // x9
  __int16 v16; // w8
  int v18; // w9
  char v19; // w8
  char v23; // w8
  __int16 v24; // w9
  char v25; // w10
  char v26; // w8
  __int16 v27; // w9
  char v28; // w8
  __int64 result; // x0
  _WORD v30[2]; // [xsp+4h] [xbp-2Ch] BYREF
  char v31; // [xsp+8h] [xbp-28h]
  char v32; // [xsp+9h] [xbp-27h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-26h]
  unsigned __int64 StatusReg; // [xsp+12h] [xbp-1Eh]
  __int64 v35; // [xsp+1Ah] [xbp-16h]
  __int16 v36; // [xsp+22h] [xbp-Eh]
  __int16 v37; // [xsp+24h] [xbp-Ch]
  char v38; // [xsp+26h] [xbp-Ah]
  char v39; // [xsp+27h] [xbp-9h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v11 = 2;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a11 & 1) != 0 )
    v16 = 4;
  else
    v16 = 2;
  v40 = v12;
  v30[0] = v16;
  v18 = *(_DWORD *)(a1 + 7036);
  v30[1] = 32;
  v19 = *(_BYTE *)(a1 + 10);
  v39 = 0;
  v35 = 0;
  v32 = v19;
  v31 = v18;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v38 = a2;
  v36 = a3;
  v37 = a4;
  if ( (a7 & 1) == 0 )
  {
    v11 = 0;
    v23 = a9;
    if ( (a8 & 1) == 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
  v39 = 2;
  v23 = a9;
  if ( (a8 & 1) != 0 )
  {
LABEL_8:
    v11 |= 4u;
    v39 = v11;
  }
LABEL_9:
  if ( (v23 & 1) != 0 )
  {
    v11 |= 8u;
    v39 = v11;
    if ( (a10 & 1) == 0 )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( (a10 & 1) != 0 )
LABEL_11:
    v39 = v11 | 0x10;
LABEL_12:
  v24 = *(_WORD *)(a5 + 1);
  v25 = *(_BYTE *)(a5 + 5);
  BYTE4(v35) = *(_BYTE *)a5;
  v26 = *a6;
  *(_WORD *)((char *)&v35 + 5) = v24;
  v27 = *(_WORD *)(a6 + 1);
  LOBYTE(v35) = v26;
  v28 = a6[5];
  HIBYTE(v35) = v25;
  *(_WORD *)((char *)&v35 + 1) = v27;
  BYTE3(v35) = v28;
  result = wlan_cp_stats_cstats_write_to_buff(0, v30, 36);
  _ReadStatusReg(SP_EL0);
  return result;
}
