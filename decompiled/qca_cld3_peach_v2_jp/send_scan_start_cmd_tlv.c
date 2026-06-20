__int64 __fastcall send_scan_start_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v2; // x28
  int v3; // w11
  unsigned __int64 v5; // x23
  char *v7; // x22
  int v8; // w21
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v18; // x24
  __int16 v19; // w8
  int v20; // w8
  int v21; // w9
  unsigned int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x8
  _DWORD *v32; // x9
  int *v33; // x10
  int v34; // w11
  int v35; // t1
  unsigned __int64 v36; // x11
  unsigned int v37; // w20
  unsigned int v38; // w4
  _DWORD *v39; // x8
  _DWORD *v40; // x25
  unsigned __int64 v41; // x26
  unsigned __int64 v42; // x19
  _DWORD *v43; // x9
  unsigned int v44; // w21
  __int64 v45; // x25
  unsigned __int64 v46; // x26
  unsigned __int64 v47; // x26
  size_t v48; // x2
  _DWORD *v49; // x8
  __int64 v50; // x9
  int *v51; // x10
  _DWORD *v52; // x11
  int v53; // t1
  __int64 v54; // x9
  unsigned __int64 v55; // x10
  char *v56; // x11
  char v57; // t1
  unsigned int v58; // w10
  __int64 v59; // x10
  int *v60; // x10
  _DWORD *v61; // x9
  __int64 v62; // x10
  int v63; // w11
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int8 v81; // [xsp+8h] [xbp-28h]
  int v82; // [xsp+14h] [xbp-1Ch]
  __int64 v83; // [xsp+18h] [xbp-18h]
  unsigned __int16 v84; // [xsp+20h] [xbp-10h]
  __int64 v85; // [xsp+28h] [xbp-8h]

  v3 = *(unsigned __int8 *)(a2 + 112);
  LODWORD(v5) = *(unsigned __int16 *)(a2 + 2016) + 3;
  LODWORD(v7) = (v3 + 3) & ((int)(*(_DWORD *)(a2 + 84) << 7) >> 31);
  v8 = 36 * *(_DWORD *)(a2 + 104)
     + 4 * v3
     + (v5 & 0xFFFC)
     + 12 * *(_DWORD *)(a2 + 2072)
     + ((unsigned __int8)v7 & 0xFC)
     + 8 * (*(_DWORD *)(a2 + 1944) + *(_DWORD *)(a2 + 100) + *(_DWORD *)(a2 + 2068));
  v9 = wmi_buf_alloc_fl(a1, v8 + 204, "send_scan_start_cmd_tlv", 0x1211u);
  if ( !v9 )
    return 16;
  v18 = *(_DWORD **)(v9 + 224);
  v84 = v5;
  v81 = (unsigned __int8)v7;
  *v18 = 5046440;
  v85 = v9;
  v18[1] = *(_DWORD *)a2;
  v18[2] = *(_DWORD *)(a2 + 4);
  v18[3] = *(_DWORD *)(a2 + 8);
  v18[4] = *(_DWORD *)(a2 + 16);
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 1) != 0 )
  {
    v18[5] |= 1u;
    v19 = *(_WORD *)(a2 + 24);
    if ( (v19 & 2) == 0 )
    {
LABEL_4:
      if ( (v19 & 4) == 0 )
        goto LABEL_5;
      goto LABEL_47;
    }
  }
  else if ( (v19 & 2) == 0 )
  {
    goto LABEL_4;
  }
  v18[5] |= 2u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 4) == 0 )
  {
LABEL_5:
    if ( (v19 & 8) == 0 )
      goto LABEL_6;
    goto LABEL_48;
  }
LABEL_47:
  v18[5] |= 4u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 8) == 0 )
  {
LABEL_6:
    if ( (v19 & 0x10) == 0 )
      goto LABEL_7;
    goto LABEL_49;
  }
LABEL_48:
  v18[5] |= 8u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x10) == 0 )
  {
LABEL_7:
    if ( (v19 & 0x20) == 0 )
      goto LABEL_8;
    goto LABEL_50;
  }
LABEL_49:
  v18[5] |= 0x10u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x20) == 0 )
  {
LABEL_8:
    if ( (v19 & 0x40) == 0 )
      goto LABEL_9;
    goto LABEL_51;
  }
LABEL_50:
  v18[5] |= 0x20u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x40) == 0 )
  {
LABEL_9:
    if ( (v19 & 0x80) == 0 )
      goto LABEL_10;
    goto LABEL_52;
  }
LABEL_51:
  v18[5] |= 0x40u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x80) == 0 )
  {
LABEL_10:
    if ( (v19 & 0x100) == 0 )
      goto LABEL_11;
    goto LABEL_53;
  }
LABEL_52:
  v18[5] |= 0x80u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x100) == 0 )
  {
LABEL_11:
    if ( (v19 & 0x800) == 0 )
      goto LABEL_12;
    goto LABEL_54;
  }
LABEL_53:
  v18[5] |= 0x100u;
  v19 = *(_WORD *)(a2 + 24);
  if ( (v19 & 0x800) == 0 )
  {
LABEL_12:
    if ( (v19 & 0x1000) == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_54:
  v18[5] |= 0x200u;
  if ( (*(_WORD *)(a2 + 24) & 0x1000) != 0 )
LABEL_13:
    v18[5] |= 0x400u;
LABEL_14:
  v18[15] = 0;
  v20 = *(_DWORD *)(a2 + 84) & 1;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x1000) != 0 )
  {
    v20 |= 0x10000u;
    v18[15] = v20;
    v21 = *(_DWORD *)(a2 + 84);
    if ( (v21 & 0x400) == 0 )
    {
LABEL_16:
      if ( (v21 & 0x800) == 0 )
        goto LABEL_17;
      goto LABEL_58;
    }
  }
  else if ( (v21 & 0x400) == 0 )
  {
    goto LABEL_16;
  }
  v20 |= 0x100u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x800) == 0 )
  {
LABEL_17:
    if ( (v21 & 0x2000) == 0 )
      goto LABEL_18;
    goto LABEL_59;
  }
LABEL_58:
  v20 |= 0x8000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x2000) == 0 )
  {
LABEL_18:
    if ( (v21 & 0x4000) == 0 )
      goto LABEL_19;
    goto LABEL_60;
  }
LABEL_59:
  v20 |= 0x20000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x4000) == 0 )
  {
LABEL_19:
    if ( (v21 & 4) == 0 )
      goto LABEL_20;
    goto LABEL_61;
  }
LABEL_60:
  v20 |= 0x40000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 4) == 0 )
  {
LABEL_20:
    if ( (v21 & 8) == 0 )
      goto LABEL_21;
    goto LABEL_62;
  }
LABEL_61:
  v20 |= 4u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 8) == 0 )
  {
LABEL_21:
    if ( (v21 & 0x10) == 0 )
      goto LABEL_22;
    goto LABEL_63;
  }
LABEL_62:
  v20 |= 8u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x10) == 0 )
  {
LABEL_22:
    if ( (v21 & 0x20) == 0 )
      goto LABEL_23;
    goto LABEL_64;
  }
LABEL_63:
  v20 |= 0x10u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x20) == 0 )
  {
LABEL_23:
    if ( (v21 & 2) == 0 )
      goto LABEL_24;
    goto LABEL_65;
  }
LABEL_64:
  v20 |= 0x20u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 2) == 0 )
  {
LABEL_24:
    if ( (v21 & 0x100) == 0 )
      goto LABEL_25;
    goto LABEL_66;
  }
LABEL_65:
  v20 |= 2u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x100) == 0 )
  {
LABEL_25:
    if ( (v21 & 0x200) == 0 )
      goto LABEL_26;
    goto LABEL_67;
  }
LABEL_66:
  v20 |= 0x2000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x200) == 0 )
  {
LABEL_26:
    if ( (v21 & 0x8000) == 0 )
      goto LABEL_27;
    goto LABEL_68;
  }
LABEL_67:
  v20 |= 0x4000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x8000) == 0 )
  {
LABEL_27:
    if ( (v21 & 0x10000) == 0 )
      goto LABEL_28;
    goto LABEL_69;
  }
LABEL_68:
  v20 |= 0x200u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x10000) == 0 )
  {
LABEL_28:
    if ( (v21 & 0x20000) == 0 )
      goto LABEL_29;
    goto LABEL_70;
  }
LABEL_69:
  v20 |= 0x400u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x20000) == 0 )
  {
LABEL_29:
    if ( (v21 & 0x40000) == 0 )
      goto LABEL_30;
    goto LABEL_71;
  }
LABEL_70:
  v20 |= 0x800u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x40000) == 0 )
  {
LABEL_30:
    if ( (v21 & 0x80000) == 0 )
      goto LABEL_31;
    goto LABEL_72;
  }
LABEL_71:
  v20 |= 0x1000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x80000) == 0 )
  {
LABEL_31:
    if ( (v21 & 0x100000) == 0 )
      goto LABEL_32;
    goto LABEL_73;
  }
LABEL_72:
  v20 |= 0x80000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x100000) == 0 )
  {
LABEL_32:
    if ( (v21 & 0x2000000) == 0 )
      goto LABEL_33;
LABEL_74:
    v20 |= 0x1000000u;
    v18[15] = v20;
    if ( (*(_DWORD *)(a2 + 84) & 0x4000000) == 0 )
      goto LABEL_35;
    goto LABEL_34;
  }
LABEL_73:
  v20 |= 0x100000u;
  v18[15] = v20;
  v21 = *(_DWORD *)(a2 + 84);
  if ( (v21 & 0x2000000) != 0 )
    goto LABEL_74;
LABEL_33:
  if ( (v21 & 0x4000000) != 0 )
  {
LABEL_34:
    v20 |= 0x2000000u;
    v18[15] = v20;
  }
LABEL_35:
  v18[15] = ((*(_DWORD *)(a2 + 92) & 7) << 21) | v20;
  v18[6] = *(_DWORD *)(a2 + 28);
  v18[36] = *(_DWORD *)(a2 + 32);
  v18[7] = *(_DWORD *)(a2 + 36);
  v18[40] = *(_DWORD *)(a2 + 40);
  v18[37] = *(_DWORD *)(a2 + 44);
  v18[38] = *(_DWORD *)(a2 + 48);
  v18[39] = *(_DWORD *)(a2 + 80);
  v18[8] = *(_DWORD *)(a2 + 52);
  v18[9] = *(_DWORD *)(a2 + 56);
  v18[10] = *(_DWORD *)(a2 + 60);
  v18[11] = *(_DWORD *)(a2 + 64);
  v18[12] = *(_DWORD *)(a2 + 68);
  v18[13] = *(_DWORD *)(a2 + 72);
  v18[14] = *(_DWORD *)(a2 + 76);
  v18[16] = *(_DWORD *)(a2 + 96);
  v18[17] = *(unsigned __int8 *)(a2 + 112);
  v18[18] = *(_DWORD *)(a2 + 100);
  v18[19] = *(_DWORD *)(a2 + 104);
  v18[20] = *(_DWORD *)(a2 + 2016);
  v18[21] = *(_DWORD *)(a2 + 108);
  v22 = v18[42] & 0xFFFFFF00;
  v18[35] = *(_DWORD *)(a2 + 2064);
  v18[42] = v22;
  v18[42] = v22 | *(unsigned __int8 *)(a2 + 2276);
  qdf_trace_msg(0x31u, 8u, "%s: MLD ID: %u", v10, v11, v12, v13, v14, v15, v16, v17, "send_scan_start_cmd_tlv");
  if ( *(_BYTE *)(a2 + 1892) == 1 )
  {
    v18[22] = *(_DWORD *)(a2 + 1893);
    v18[23] = *(unsigned __int16 *)(a2 + 1897);
    v18[24] = *(_DWORD *)(a2 + 1899);
    v18[25] = *(unsigned __int16 *)(a2 + 1903);
  }
  if ( *(_BYTE *)(a2 + 1908) == 1 )
  {
    v18[26] = *(_DWORD *)(a2 + 1912);
    v18[27] = *(_DWORD *)(a2 + 1916);
    v18[28] = *(_DWORD *)(a2 + 1920);
    v18[29] = *(_DWORD *)(a2 + 1924);
    v18[30] = *(_DWORD *)(a2 + 1928);
    v18[31] = *(_DWORD *)(a2 + 1932);
    v18[32] = *(_DWORD *)(a2 + 1936);
    v18[33] = *(_DWORD *)(a2 + 1940);
    v18[34] = *(_DWORD *)(a2 + 1944);
  }
  v82 = v8;
  v83 = a1;
  if ( *(_BYTE *)(a2 + 112) )
  {
    v31 = 0;
    v32 = v18 + 44;
    v33 = (int *)(a2 + 124);
    do
    {
      if ( v31 == 102 )
        goto LABEL_90;
      v34 = v32[v31] | *(v33 - 2) & 0xFFFFF;
      v32[v31] = v34;
      v35 = *v33;
      v33 += 3;
      v32[v31++] = v34 | (v35 << 20);
      v36 = *(unsigned __int8 *)(a2 + 112);
    }
    while ( v31 < v36 );
  }
  else
  {
    LODWORD(v36) = 0;
  }
  v18[43] = (4 * v36) | 0x100000;
  v38 = *(_DWORD *)(a2 + 104);
  if ( v38 >= 0x11 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid value for num_ssids %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "send_scan_start_cmd_tlv");
    v37 = 16;
    goto LABEL_124;
  }
  v2 = *(unsigned __int8 *)(a2 + 112);
  v39 = &v18[v2 + 43];
  v40 = v39 + 1;
  v39[1] = (36 * v38) | 0x130000;
  if ( *(_DWORD *)(a2 + 104) )
  {
    v41 = 0;
    v31 = (unsigned __int64)(v39 + 2);
    v7 = (char *)(a2 + 1341);
    do
    {
      if ( v41 == 16 )
        goto LABEL_90;
      *(_DWORD *)v31 = (unsigned __int8)*(v7 - 1);
      v42 = v31 + 36;
      qdf_mem_copy((void *)(v31 + 4), v7, (unsigned __int8)*(v7 - 1));
      v5 = *(unsigned int *)(a2 + 104);
      ++v41;
      v7 += 33;
      v31 = v42;
    }
    while ( v41 < v5 );
  }
  else
  {
    LODWORD(v5) = 0;
  }
  LODWORD(v7) = 36;
  v43 = &v40[9 * (unsigned int)v5];
  v43[1] = (8 * (*(_DWORD *)(a2 + 100) & 0x1FFF)) | 0x130000;
  v31 = (unsigned __int64)(v43 + 1);
  if ( !*(_DWORD *)(a2 + 100) )
    goto LABEL_91;
  v43[2] = *(_DWORD *)(a2 + 1868);
  v43[3] = *(unsigned __int16 *)(a2 + 1872);
  v44 = *(_DWORD *)(a2 + 100);
  if ( v44 < 2 )
    goto LABEL_92;
  v43[4] = *(_DWORD *)(a2 + 1874);
  v43[5] = *(unsigned __int16 *)(a2 + 1878);
  v44 = *(_DWORD *)(a2 + 100);
  if ( v44 < 3 )
    goto LABEL_92;
  v43[6] = *(_DWORD *)(a2 + 1880);
  v43[7] = *(unsigned __int16 *)(a2 + 1884);
  v44 = *(_DWORD *)(a2 + 100);
  if ( v44 < 4 )
    goto LABEL_92;
  v43[8] = *(_DWORD *)(a2 + 1886);
  v43[9] = *(unsigned __int16 *)(a2 + 1890);
  v44 = *(_DWORD *)(a2 + 100);
  if ( v44 <= 4 )
    goto LABEL_92;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_90:
        __break(0x5512u);
LABEL_91:
        v44 = 0;
LABEL_92:
        v45 = v84 & 0xFFFC;
        v46 = v31 + 8 * v44;
        *(_DWORD *)(v46 + 4) = v84 & 0xFFFC | 0x110000;
        v47 = v46 + 4;
        v48 = *(unsigned int *)(a2 + 2016);
        if ( (_DWORD)v48 )
          qdf_mem_copy((void *)(v47 + 4), *(const void **)(a2 + 2024), v48);
        *(_DWORD *)(v47 + v45 + 4) = (8 * (*(_DWORD *)(a2 + 1944) & 0x1FFF)) | 0x120000;
        v49 = (_DWORD *)(v47 + v45 + 8);
        v50 = (unsigned int)v18[34];
        if ( (_DWORD)v50 )
        {
          v51 = (int *)(a2 + 1948);
          v52 = (_DWORD *)((char *)&v18[2 * v44 + 49]
                         + v45
                         + v2 * 4
                         + (unsigned int)v5 * (unsigned __int64)(unsigned int)v7);
          do
          {
            *(v52 - 1) = 39256068;
            --v50;
            v53 = *v51++;
            *v52 = v53;
            v52 += 2;
          }
          while ( v50 );
          v49 += 2 * (unsigned int)v18[34];
        }
        if ( (*(_BYTE *)(a2 + 87) & 1) == 0 )
        {
          *v49 = 1114112;
          v31 = (unsigned __int64)(v49 + 1);
          goto LABEL_105;
        }
        v54 = v81 & 0xFC;
        *v49 = v54 | 0x110000;
        v31 = (unsigned __int64)(v49 + 1);
        if ( !*(_BYTE *)(a2 + 112) )
          break;
        v55 = 0;
        v56 = (char *)(a2 + 120);
        while ( v55 != 102 )
        {
          v57 = *v56;
          v56 += 12;
          *(_BYTE *)(v31 + v55++) = v57 + 1;
          if ( v55 >= *(unsigned __int8 *)(a2 + 112) )
            goto LABEL_104;
        }
      }
LABEL_104:
      v31 += v54;
LABEL_105:
      *(_DWORD *)v31 = (8 * (*(_DWORD *)(a2 + 2068) & 0x1FFF)) | 0x130000;
      if ( !*(_DWORD *)(a2 + 2068) )
        break;
      *(_DWORD *)(v31 + 4) = *(_DWORD *)(a2 + 2076);
      *(_DWORD *)(v31 + 8) = *(_DWORD *)(a2 + 2080);
      v58 = *(_DWORD *)(a2 + 2068);
      if ( v58 >= 2 )
      {
        *(_DWORD *)(v31 + 12) = *(_DWORD *)(a2 + 2084);
        *(_DWORD *)(v31 + 16) = *(_DWORD *)(a2 + 2088);
        v58 = *(_DWORD *)(a2 + 2068);
        if ( v58 >= 3 )
        {
          *(_DWORD *)(v31 + 20) = *(_DWORD *)(a2 + 2092);
          *(_DWORD *)(v31 + 24) = *(_DWORD *)(a2 + 2096);
          v58 = *(_DWORD *)(a2 + 2068);
          if ( v58 >= 4 )
          {
            *(_DWORD *)(v31 + 28) = *(_DWORD *)(a2 + 2100);
            *(_DWORD *)(v31 + 32) = *(_DWORD *)(a2 + 2104);
            v58 = *(_DWORD *)(a2 + 2068);
            if ( v58 >= 5 )
            {
              *(_DWORD *)(v31 + 36) = *(_DWORD *)(a2 + 2108);
              *(_DWORD *)(v31 + 40) = *(_DWORD *)(a2 + 2112);
              v58 = *(_DWORD *)(a2 + 2068);
              if ( v58 >= 6 )
              {
                *(_DWORD *)(v31 + 44) = *(_DWORD *)(a2 + 2116);
                *(_DWORD *)(v31 + 48) = *(_DWORD *)(a2 + 2120);
                v58 = *(_DWORD *)(a2 + 2068);
                if ( v58 >= 7 )
                {
                  *(_DWORD *)(v31 + 52) = *(_DWORD *)(a2 + 2124);
                  *(_DWORD *)(v31 + 56) = *(_DWORD *)(a2 + 2128);
                  v58 = *(_DWORD *)(a2 + 2068);
                  if ( v58 >= 8 )
                  {
                    *(_DWORD *)(v31 + 60) = *(_DWORD *)(a2 + 2132);
                    *(_DWORD *)(v31 + 64) = *(_DWORD *)(a2 + 2136);
                    v58 = *(_DWORD *)(a2 + 2068);
                    if ( v58 >= 9 )
                    {
                      *(_DWORD *)(v31 + 68) = *(_DWORD *)(a2 + 2140);
                      *(_DWORD *)(v31 + 72) = *(_DWORD *)(a2 + 2144);
                      v58 = *(_DWORD *)(a2 + 2068);
                      if ( v58 >= 0xA )
                      {
                        *(_DWORD *)(v31 + 76) = *(_DWORD *)(a2 + 2148);
                        *(_DWORD *)(v31 + 80) = *(_DWORD *)(a2 + 2152);
                        v58 = *(_DWORD *)(a2 + 2068);
                        if ( v58 > 0xA )
                          continue;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v59 = (8 * v58) | 4;
      goto LABEL_118;
    }
    v59 = 4;
LABEL_118:
    v60 = (int *)(v31 + v59);
    *v60 = (4 * ((3 * *(_DWORD *)(a2 + 2072)) & 0x3FFF)) | 0x130000;
    if ( !*(_DWORD *)(a2 + 2072) )
      break;
    v31 = 0;
    v61 = v60 + 1;
    v62 = a2 + 2165;
    while ( v31 != 10 )
    {
      ++v31;
      *v61 = *(_DWORD *)(v62 - 9);
      v61[1] = *(_DWORD *)(v62 - 5);
      v63 = *(unsigned __int16 *)(v62 - 1);
      v62 += 12;
      v61[2] = v63;
      v61 += 3;
      if ( v31 >= *(unsigned int *)(a2 + 2072) )
        goto LABEL_122;
    }
  }
LABEL_122:
  qdf_mtrace(49, 100, 0x181u, v18[3], 0);
  v37 = wmi_unified_cmd_send_fl(
          v83,
          v85,
          v82 + 204,
          0x3001u,
          "send_scan_start_cmd_tlv",
          0x12B4u,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71);
  if ( v37 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to start scan: %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "send_scan_start_cmd_tlv",
      v37);
LABEL_124:
    wmi_buf_free();
  }
  return v37;
}
