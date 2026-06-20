__int64 __fastcall wlan_cp_stats_cstats_pkt_log(
        char *a1,
        char *a2,
        int a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        char a7,
        char a8)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 StatusReg; // x8
  char v23; // w9
  char v24; // w10
  char v25; // w9
  char v26; // w9
  unsigned __int64 v27; // x8
  char v28; // w9
  char v29; // w8
  char v30; // w8
  __int64 result; // x0
  int v32; // [xsp+4h] [xbp-2Ch] BYREF
  char v33; // [xsp+8h] [xbp-28h]
  char v34; // [xsp+9h] [xbp-27h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-26h]
  unsigned __int64 v36; // [xsp+12h] [xbp-1Eh]
  char v37; // [xsp+1Ah] [xbp-16h]
  __int16 v38; // [xsp+1Bh] [xbp-15h]
  char v39; // [xsp+1Dh] [xbp-13h]
  char v40; // [xsp+1Eh] [xbp-12h]
  __int16 v41; // [xsp+1Fh] [xbp-11h]
  char v42; // [xsp+21h] [xbp-Fh]
  __int16 v43; // [xsp+22h] [xbp-Eh]
  char v44; // [xsp+24h] [xbp-Ch]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v43 = 0;
  v32 = 1900590;
  v33 = a8;
  v34 = a7;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v23 = *a1;
  v36 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)(a1 + 1);
  v24 = a1[5];
  v37 = v23;
  v25 = *a2;
  v38 = StatusReg;
  LOWORD(StatusReg) = *(_WORD *)(a2 + 1);
  v40 = v25;
  v26 = a2[5];
  v39 = v24;
  v41 = StatusReg;
  v42 = v26;
  if ( a3 )
  {
    LOBYTE(v27) = 0;
    if ( a3 == 1 )
    {
      if ( a4 >= 5 )
        LOBYTE(v27) = 0;
      else
        LOBYTE(v27) = a4;
    }
  }
  else if ( a4 - 5 > 7 )
  {
    LOBYTE(v27) = 0;
  }
  else
  {
    v27 = 0xC0B0A0908060705uLL >> (8 * ((unsigned __int8)a4 - 5));
  }
  LOBYTE(v43) = v27;
  if ( a5 == 1 )
    v28 = 1;
  else
    v28 = 2;
  if ( a5 )
    v29 = v28;
  else
    v29 = 0;
  HIBYTE(v43) = v29;
  if ( a6 >= 7 )
    v30 = 0;
  else
    v30 = a6;
  v44 = v30;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v32, 0x21u, v14, v15, v16, v17, v18, v19, v20, v21);
  _ReadStatusReg(SP_EL0);
  return result;
}
