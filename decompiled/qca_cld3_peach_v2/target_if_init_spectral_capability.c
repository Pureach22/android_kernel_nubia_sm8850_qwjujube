__int64 __fastcall target_if_init_spectral_capability(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  unsigned int v13; // w10
  __int64 v14; // x11
  int v15; // w12
  bool v17; // w9
  unsigned int v18; // w13
  _DWORD *v19; // x14
  const char *v20; // x2
  unsigned int v21; // w10
  int v22; // w9
  int v23; // w11
  int v24; // w10
  __int64 v25; // x25
  __int64 v26; // x23
  int v27; // w8
  int v28; // w9
  __int64 v29; // x20
  const char *v30; // x2
  char v31; // w10
  __int64 v32; // x0
  unsigned int v33; // w22
  __int64 v34; // x8
  __int64 v35; // x9
  int v36; // w11
  int v37; // w10
  __int64 v38; // x11
  _DWORD *v39; // x8
  __int64 v40; // x8
  int v41; // w9
  __int64 result; // x0
  const char *v43; // x3
  __int64 v44; // x4
  __int64 v45; // x23
  __int64 v46; // x20
  _DWORD *v47; // x26
  unsigned int v48; // w9
  _BYTE *v49; // x8
  __int64 v50; // x0
  __int64 v51; // x8
  char v52; // w9
  char v53; // w9
  _DWORD *v54; // x8
  bool v55; // [xsp+0h] [xbp-10h] BYREF
  bool v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = *(_QWORD *)(*a1 + 80);
  if ( !v11 )
  {
    v20 = "%s: psoc is null";
    goto LABEL_53;
  }
  v12 = *(_QWORD *)(v11 + 2800);
  if ( !v12 )
  {
    v20 = "%s: target_psoc_info is null";
    goto LABEL_53;
  }
  v13 = *(unsigned __int8 *)(v12 + 844);
  v14 = *(_QWORD *)(v12 + 4600);
  v15 = *(unsigned __int8 *)(v10 + 40);
  *((_WORD *)a1 + 92) = 257;
  v17 = (*(_BYTE *)(v10 + 16) & 0x10) != 0;
  *((_DWORD *)a1 + 47) = *((_DWORD *)a1 + 313);
  *((_BYTE *)a1 + 186) = v17;
  *((_BYTE *)a1 + 187) = v17;
  *((_BYTE *)a1 + 203) = (*(_BYTE *)(v10 + 16) & 0x20) == 0;
  *((_BYTE *)a1 + 204) = (*(_BYTE *)(v10 + 16) & 0x40) == 0;
  *((_BYTE *)a1 + 205) = (*(_DWORD *)(v10 + 16) & 0x80) == 0;
  *((_BYTE *)a1 + 206) = (*(_BYTE *)(v10 + 17) & 1) == 0;
  if ( v14 && v13 )
  {
    v18 = 0;
    while ( 1 )
    {
      v19 = (_DWORD *)(v14 + 24LL * v18);
      if ( *v19 == v15 )
        break;
      if ( ++v18 >= v13 )
        goto LABEL_12;
    }
    *((_BYTE *)a1 + 192) = 1;
    *((_WORD *)a1 + 97) = v19[1];
    *((_WORD *)a1 + 98) = v19[2];
    *((_WORD *)a1 + 99) = v19[3];
    *((_WORD *)a1 + 100) = v19[4];
    *((_BYTE *)a1 + 202) = v19[5];
  }
LABEL_12:
  v21 = a2 - 26;
  *((_DWORD *)a1 + 54) = 1;
  a1[26] = 0x100000001LL;
  if ( a2 - 26 > 0x11 )
  {
    v24 = 0;
    v22 = 2;
    v23 = 2;
  }
  else
  {
    v22 = dword_B2ED3C[v21];
    v23 = dword_B2ED84[v21];
    v24 = dword_B2EDCC[v21];
  }
  *((_DWORD *)a1 + 55) = v22;
  *((_DWORD *)a1 + 56) = v23;
  *((_DWORD *)a1 + 57) = v24;
  if ( !a1 )
  {
    v30 = "%s: spectral is null";
LABEL_20:
    qdf_trace_msg(0x56u, 2u, v30, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_populate_supported_sscan_bws");
    goto LABEL_52;
  }
  if ( a2 <= 0x29 && ((1LL << a2) & 0x28900000000LL) != 0 )
  {
    v25 = 0;
    v26 = 0;
    v27 = *((_DWORD *)a1 + 494) | 4;
    v28 = *((_DWORD *)a1 + 503) | 4;
    v29 = 1;
    *((_BYTE *)a1 + 2048) = 1;
    *((_DWORD *)a1 + 494) = v27;
    *((_DWORD *)a1 + 503) = v28;
    *((_BYTE *)a1 + 2057) = 1;
    while ( 1 )
    {
      v32 = *a1;
      v33 = v26 + 1;
      v56 = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v32, (int)v26 + 1, &v56, a3, a4, a5, a6, a7, a8, a9, a10) )
      {
        v43 = "target_if_populate_supported_sscan_bws_be";
        v44 = (unsigned int)(v26 + 1);
        goto LABEL_51;
      }
      if ( v56 )
        break;
LABEL_24:
      ++v26;
      ++v29;
      v25 += 4;
      if ( v26 == 8 )
        goto LABEL_49;
    }
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: Updating supported bw for op_bw: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_populate_supported_sscan_bws_be",
      v33);
    if ( v33 >= 8 )
    {
      v40 = (__int64)a1 + v26;
      *(_BYTE *)(v40 + 2049) = 1;
      *(_BYTE *)(v40 + 2058) = 1;
      if ( v26 == 7 )
      {
LABEL_49:
        result = 0;
        goto LABEL_54;
      }
      v39 = (_DWORD *)((char *)a1 + v25 + 2016);
    }
    else
    {
      v34 = 4LL * (v33 & 7);
      v35 = (__int64)a1 + v25;
      v36 = *(_DWORD *)((char *)&unk_B35408 + v34);
      LOBYTE(v34) = *(unsigned int *)((char *)dword_B354A8 + v34);
      v37 = *(_DWORD *)((char *)a1 + v25 + 1980) | v36;
      v38 = (__int64)a1 + v26;
      *(_DWORD *)(v35 + 1980) = v37;
      *(_BYTE *)(v38 + 2049) = 1;
      *(_DWORD *)(v35 + 2016) = *(_DWORD *)((char *)a1 + v25 + 2016) | (1 << v34);
      *(_BYTE *)(v38 + 2058) = 1;
      if ( v26 == 7 )
        __break(1u);
      v39 = (_DWORD *)a1 + v29 + 503;
    }
    v41 = half_bw_map[v26 + 1];
    if ( v41 <= 3 )
    {
      if ( v41 > 1 )
      {
        if ( v41 == 2 )
          v31 = 4;
        else
          v31 = 5;
      }
      else if ( v41 )
      {
        if ( v41 != 1 )
          goto LABEL_23;
        v31 = 3;
      }
      else
      {
        v31 = 2;
      }
    }
    else if ( v41 <= 5 )
    {
      if ( v41 == 4 )
        v31 = 6;
      else
        v31 = 0;
    }
    else
    {
      switch ( v41 )
      {
        case 8:
          goto LABEL_24;
        case 7:
          v31 = 7;
          break;
        case 6:
          v31 = 1;
          break;
        default:
          goto LABEL_23;
      }
    }
    *v39 |= 1 << v31;
LABEL_23:
    *((_BYTE *)a1 + (unsigned int)v41 + 2057) = 1;
    goto LABEL_24;
  }
  v45 = *(_QWORD *)(v10 + 80);
  if ( !v45 )
  {
    v30 = "%s: psoc is null";
    goto LABEL_20;
  }
  v46 = 0;
  v47 = (_DWORD *)a1 + 503;
  while ( 1 )
  {
    v50 = *a1;
    v55 = 0;
    if ( (unsigned int)wlan_reg_is_chwidth_supported(v50, v46, &v55, a3, a4, a5, a6, a7, a8, a9, a10) )
      break;
    if ( !v55 )
      goto LABEL_60;
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: Updating supported bw for op_bw: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_populate_supported_sscan_bws",
      (unsigned int)v46);
    v51 = (__int64)a1 + 4 * v46;
    if ( (int)v46 > 3 )
    {
      if ( (int)v46 > 5 )
      {
        if ( (_DWORD)v46 == 7 )
        {
          v52 = 7;
          goto LABEL_88;
        }
        if ( (_DWORD)v46 == 6 )
        {
          v52 = 1;
          goto LABEL_88;
        }
      }
      else
      {
        if ( (_DWORD)v46 == 4 )
        {
          v53 = 6;
          goto LABEL_80;
        }
        if ( (_DWORD)v46 == 5 )
        {
          v52 = 0;
          goto LABEL_88;
        }
      }
    }
    else if ( (int)v46 > 1 )
    {
      if ( (_DWORD)v46 == 2 )
      {
        v52 = 4;
        goto LABEL_88;
      }
      if ( (_DWORD)v46 == 3 )
      {
        v53 = 5;
LABEL_80:
        *(_DWORD *)(v51 + 1976) |= 1 << v53;
        v54 = v47;
        *((_BYTE *)a1 + v46 + 2048) = 1;
LABEL_81:
        if ( *((_BYTE *)a1 + 1399) == 1 )
        {
          *v54 |= 0x10u;
          *((_BYTE *)a1 + 2059) = 1;
        }
        if ( (*(_BYTE *)(v45 + 22) & 0x10) == 0 )
          goto LABEL_60;
        *v54 |= 0x20u;
        *((_BYTE *)a1 + 2060) = 1;
        if ( v46 != 3 )
          goto LABEL_60;
        *v54 |= 0x40u;
        v49 = (char *)a1 + 2061;
        goto LABEL_59;
      }
    }
    else
    {
      if ( !(_DWORD)v46 )
      {
        v52 = 2;
        goto LABEL_88;
      }
      if ( (_DWORD)v46 == 1 )
      {
        v52 = 3;
LABEL_88:
        *(_DWORD *)(v51 + 1976) |= 1 << v52;
        v54 = v47;
        *((_BYTE *)a1 + v46 + 2048) = 1;
        goto LABEL_89;
      }
    }
    *((_BYTE *)a1 + v46 + 2048) = 1;
    v54 = (_DWORD *)a1 + v46 + 503;
    if ( (unsigned int)(v46 - 3) < 2 )
      goto LABEL_81;
LABEL_89:
    if ( (unsigned int)v46 <= 7 )
      v48 = dword_B354A8[v46 & 7];
    else
      LOBYTE(v48) = -1;
    *v54 |= 1 << v48;
    v49 = (char *)a1 + v46 + 2057;
LABEL_59:
    *v49 = 1;
LABEL_60:
    ++v46;
    result = 0;
    ++v47;
    if ( v46 == 9 )
      goto LABEL_54;
  }
  v43 = "target_if_populate_supported_sscan_bws";
  v44 = (unsigned int)v46;
LABEL_51:
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: Unable to check if ch_width(%d) is supported",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    v43,
    v44);
LABEL_52:
  v20 = "%s: Unable to populate supported sscan BWs";
LABEL_53:
  qdf_trace_msg(0x56u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_init_spectral_capability");
  result = 16;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
