__int64 __fastcall lim_populate_vht_mcs_set(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        __int64 a6)
{
  int v6; // w8
  bool v8; // zf
  unsigned int bw_for_mcs_set; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  __int64 v25; // x10
  unsigned int v26; // w23
  __int64 v27; // x9
  int v28; // w11
  __int64 v29; // x4
  __int64 v30; // x5
  int v31; // w11
  unsigned int v32; // w9
  int v33; // w12
  __int64 v34; // x9
  unsigned __int8 v35; // w14
  unsigned int v36; // w15
  unsigned int v37; // w16
  unsigned int v38; // w16
  int v39; // w15
  unsigned int v40; // w15
  unsigned int v41; // w14
  int v42; // w14
  unsigned int v43; // w11
  int v44; // w12
  unsigned int v45; // w12
  unsigned int v46; // w12
  unsigned int v47; // w8
  unsigned int v48; // w8
  __int64 v49; // x24
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w4
  unsigned __int8 v59; // w22
  int v60; // w8
  int v61; // w8
  int v62; // w8
  char v63; // w8
  int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char v73; // w4
  unsigned int v74; // w8
  char v75; // w5

  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
  v8 = (unsigned int)(v6 - 8) >= 6 && v6 != 0 || a3 == 0;
  if ( v8 || !*(_BYTE *)a3 )
    return 0;
  bw_for_mcs_set = lim_get_bw_for_mcs_set();
  v24 = a5;
  v25 = *(_QWORD *)(a1 + 8);
  v26 = bw_for_mcs_set;
  v27 = -1LL << (2 * a5);
  v28 = v27 | *(_DWORD *)(v25 + 2632);
  a2[21] = v28;
  v29 = (unsigned __int16)v28;
  LODWORD(v27) = v27 | *(_DWORD *)(v25 + 2636);
  v30 = (unsigned __int16)v27;
  a2[23] = v27;
  if ( a5 )
  {
    v31 = 0;
    v32 = (unsigned __int8)(a5 + 1);
    if ( v32 <= 2 )
      v32 = 2;
    v33 = 2 * v32 - 2;
    v34 = a4;
    do
    {
      if ( bw_for_mcs_set )
        v35 = 0;
      else
        v35 = *(_BYTE *)(v25 + 2666) ^ 1;
      if ( (~(*(unsigned __int16 *)(a3 + 10) >> v31) & 3) == 0 )
      {
        v29 = (unsigned int)v29 | (unsigned __int16)(3 << v31);
        a2[21] = v29;
      }
      if ( (~(*(unsigned __int16 *)(a3 + 6) >> v31) & 3) == 0 )
      {
        v30 = (unsigned int)v30 | (unsigned __int16)(3 << v31);
        a2[23] = v30;
      }
      v36 = ((unsigned int)v29 >> v31) & 3;
      if ( v36 != 3 )
      {
        v37 = (*(unsigned __int16 *)(a3 + 10) >> v31) & 3;
        if ( (v35 & (v37 == 2)) != 0 )
          v37 = 1;
        if ( v37 < v36 )
        {
          v38 = v37 << v31;
          v39 = v29 & ~(3 << v31) | v38;
          v29 = (unsigned __int16)(v29 & ~(3 << v31) | v38);
          a2[21] = v39;
        }
      }
      v40 = ((unsigned int)v30 >> v31) & 3;
      if ( v40 != 3 )
      {
        v41 = (v35 & (((*(unsigned __int16 *)(a3 + 6) >> v31) & 3) == 2)) != 0
            ? 1
            : (*(unsigned __int16 *)(a3 + 6) >> v31) & 3;
        if ( v41 < v40 )
        {
          v42 = v30 & ~(3 << v31) | (v41 << v31);
          v30 = (unsigned __int16)v42;
          a2[23] = v42;
        }
      }
      v31 += 2;
    }
    while ( v33 != v31 );
  }
  else
  {
    v34 = a4;
  }
  v43 = *(_WORD *)(a3 + 12) & 0x1FFF;
  if ( (*(_WORD *)(a3 + 12) & 0x1FFF) != 0 )
  {
    if ( a5 >= 2u )
      v44 = 2;
    else
      v44 = a5;
    v45 = v44 - 1;
    if ( v45 >= 4 )
      goto LABEL_104;
    v46 = vht_supported_datarate_bw80_gi400ns[v45];
    if ( v46 < v43 )
      LOWORD(v43) = v46;
    a2[24] = v43;
  }
  if ( (*(_WORD *)(a3 + 8) & 0x1FFF) == 0 )
    goto LABEL_48;
  if ( a5 >= 2u )
    v24 = 2;
  v47 = v24 - 1;
  if ( v47 <= 3 )
  {
    v48 = vht_supported_datarate_bw80_gi400ns[v47];
    if ( v48 >= (*(_WORD *)(a3 + 8) & 0x1FFFu) )
      LOWORD(v48) = *(_WORD *)(a3 + 8) & 0x1FFF;
    a2[22] = v48;
LABEL_48:
    v49 = v34 + 0x2000;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RxMCSMap %x TxMCSMap %x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_populate_vht_mcs_set",
      v29,
      v30);
    *(_BYTE *)(v49 + 461) = (unsigned __int16)a2[23] > 0xFFFBu;
    if ( !a6 || v26 < 3 )
      return 0;
    *(_BYTE *)(a6 + 358) = (*(_WORD *)(a3 + 12) & 0x2000) != 0;
    if ( (*(_WORD *)(a3 + 12) & 0x2000) == 0 )
    {
      *(_WORD *)(a6 + 356) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: peer does not support vht extnd nss bw",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "lim_get_vht_gt80_nss");
      return 0;
    }
    v58 = *(unsigned __int16 *)(a3 + 6);
    if ( (~v58 & 3) != 0 )
    {
      if ( (~v58 & 0xC) != 0 )
      {
        if ( (~v58 & 0x30) != 0 )
        {
          if ( (~v58 & 0xC0) != 0 )
          {
            if ( (~v58 & 0x300) != 0 )
            {
              if ( (~v58 & 0xC00) != 0 )
              {
                if ( (~v58 & 0x3000) != 0 )
                {
                  if ( (~v58 & 0xC000) != 0 )
                    v59 = 8;
                  else
                    v59 = 7;
                }
                else
                {
                  v59 = 6;
                }
              }
              else
              {
                v59 = 5;
              }
            }
            else
            {
              v59 = 4;
            }
          }
          else
          {
            v59 = 3;
          }
        }
        else
        {
          v59 = 2;
        }
LABEL_56:
        v60 = (*(unsigned __int16 *)(a3 + 1) >> 2) & 3;
        if ( v60 == 2 )
        {
          if ( (~*(unsigned __int16 *)(a3 + 4) & 0x180) != 0 )
          {
            *(_BYTE *)(a6 + 356) = v59;
            *(_BYTE *)(a6 + 357) = v59;
            goto LABEL_89;
          }
          if ( v59 >= 5u )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Invalid extnd nss bw support val",
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              "lim_get_vht_gt80_nss");
            goto LABEL_89;
          }
        }
        else
        {
          if ( v60 != 1 )
          {
            if ( v60 )
              goto LABEL_63;
            v61 = (*(unsigned __int16 *)(a3 + 4) >> 7) & 3;
            switch ( v61 )
            {
              case 3:
                v63 = (unsigned __int8)(3 * v59) >> 2;
                break;
              case 2:
                v63 = v59 >> 1;
                break;
              case 1:
                *(_WORD *)(a6 + 356) = v59 >> 1;
LABEL_89:
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: AP Nss config: 160MHz: %d, 80P80MHz %d",
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  "lim_get_vht_gt80_nss",
                  *(unsigned __int8 *)(a6 + 356),
                  *(unsigned __int8 *)(a6 + 357));
                if ( *(unsigned __int8 *)(a6 + 356) >= (unsigned int)*(unsigned __int8 *)(v49 + 443) )
                  v73 = *(_BYTE *)(v49 + 443);
                else
                  v73 = *(_BYTE *)(a6 + 356);
                v74 = *(unsigned __int8 *)(a6 + 357);
                *(_BYTE *)(a6 + 356) = v73;
                if ( v74 >= *(unsigned __int8 *)(v49 + 443) )
                  v75 = *(_BYTE *)(v49 + 443);
                else
                  v75 = v74;
                *(_BYTE *)(a6 + 357) = v75;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Session Nss config: 160MHz: %d, 80P80MHz %d, session Nss %d",
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  "lim_get_vht_gt80_nss");
                return 0;
              default:
LABEL_63:
                *(_WORD *)(a6 + 356) = 0;
                goto LABEL_89;
            }
            *(_BYTE *)(a6 + 356) = v63;
            *(_BYTE *)(a6 + 357) = v63;
            goto LABEL_89;
          }
          *(_BYTE *)(a6 + 356) = v59;
          v62 = (*(unsigned __int16 *)(a3 + 4) >> 7) & 3;
          if ( v62 != 3 )
          {
            if ( v62 == 2 )
            {
              *(_BYTE *)(a6 + 357) = (unsigned __int8)(3 * v59) >> 2;
              goto LABEL_89;
            }
            if ( v62 != 1 )
            {
              *(_BYTE *)(a6 + 357) = 0;
              goto LABEL_89;
            }
LABEL_79:
            *(_BYTE *)(a6 + 357) = v59 >> 1;
            goto LABEL_89;
          }
          if ( v59 >= 5u )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Invalid extnd nss bw support val",
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              "lim_get_vht_gt80_nss");
            goto LABEL_79;
          }
          *(_BYTE *)(a6 + 356) = 2 * v59;
        }
        v64 = *(unsigned __int8 *)(v49 + 443);
        if ( v64 != 2 && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2667LL) )
          *(_BYTE *)(v49 + 443) = 2 * v64;
        goto LABEL_89;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Invalid peer VHT MCS map %0X",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "lim_get_vht_gt80_nss");
    }
    v59 = 1;
    goto LABEL_56;
  }
LABEL_104:
  __break(0x5512u);
  return lim_populate_own_rate_set();
}
