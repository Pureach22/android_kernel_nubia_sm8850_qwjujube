__int64 __fastcall lim_cp_stats_cstats_log_assoc_req_evt(
        __int64 a1,
        char a2,
        char *a3,
        char *a4,
        unsigned __int8 a5,
        const void *a6,
        char a7,
        char a8,
        char a9,
        char a10,
        char a11)
{
  int v19; // w9
  unsigned int v20; // w27
  __int16 v21; // w8
  char v22; // w8
  unsigned __int64 StatusReg; // x8
  int v24; // w9
  size_t v25; // x2
  char v26; // w8
  __int16 v27; // w9
  char v28; // w10
  char v29; // w8
  __int16 v30; // w9
  char v31; // w8
  char v32; // w8
  char v33; // w9
  __int64 result; // x0
  _WORD v35[2]; // [xsp+4h] [xbp-4Ch] BYREF
  char v36; // [xsp+8h] [xbp-48h]
  char v37; // [xsp+9h] [xbp-47h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-46h]
  unsigned __int64 v39; // [xsp+12h] [xbp-3Eh]
  char v40; // [xsp+1Ah] [xbp-36h]
  _BYTE v41[53]; // [xsp+1Bh] [xbp-35h] BYREF

  *(_QWORD *)&v41[45] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_DWORD *)(a1 + 7036);
  v20 = a5;
  memset(&v41[32], 0, 13);
  if ( (a11 & 1) != 0 )
    v21 = 3;
  else
    v21 = 1;
  v35[0] = v21;
  v35[1] = 64;
  v22 = *(_BYTE *)(a1 + 10);
  memset(v41, 0, 32);
  v36 = v19;
  v37 = v22;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v24 = *(_DWORD *)(a1 + 284);
  if ( (a5 & 0xE0) != 0 )
    v25 = 32;
  else
    v25 = v20;
  v39 = StatusReg;
  *(_WORD *)&v41[41] = v24;
  v40 = v25;
  qdf_mem_copy(v41, a6, v25);
  v26 = *a3;
  v27 = *(_WORD *)(a3 + 1);
  v28 = a3[5];
  v41[44] = a2;
  v41[33] = v26;
  v29 = *a4;
  *(_WORD *)&v41[34] = v27;
  v30 = *(_WORD *)(a4 + 1);
  v41[37] = v29;
  v31 = a4[5];
  v41[36] = v28;
  *(_WORD *)&v41[38] = v30;
  v41[40] = v31;
  if ( (a7 & 1) != 0 )
  {
    v41[43] |= 2u;
    v32 = a9;
    if ( (a8 & 1) == 0 )
    {
LABEL_9:
      v33 = a10;
      if ( (v32 & 1) == 0 )
        goto LABEL_10;
LABEL_15:
      v41[43] |= 8u;
      if ( (v33 & 1) == 0 )
        goto LABEL_12;
      goto LABEL_11;
    }
  }
  else
  {
    v32 = a9;
    if ( (a8 & 1) == 0 )
      goto LABEL_9;
  }
  v41[43] |= 4u;
  v33 = a10;
  if ( (v32 & 1) != 0 )
    goto LABEL_15;
LABEL_10:
  if ( (v33 & 1) != 0 )
LABEL_11:
    v41[43] |= 0x10u;
LABEL_12:
  result = wlan_cp_stats_cstats_write_to_buff(0, v35, 68);
  _ReadStatusReg(SP_EL0);
  return result;
}
