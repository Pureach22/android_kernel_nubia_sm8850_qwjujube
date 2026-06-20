__int64 __fastcall lim_obss_generate_detection_config(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w22
  unsigned int v15; // w23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v57; // x8
  __int64 v58; // [xsp+0h] [xbp-20h]
  __int64 v59; // [xsp+8h] [xbp-18h]
  __int64 v60; // [xsp+10h] [xbp-10h]

  if ( !a1 || !a2 || !a3 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid params mac_ctx %pK, session %pK, cfg %pK",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_obss_generate_detection_config",
      a1,
      a2,
      a3);
    return 4;
  }
  v14 = *(_DWORD *)(a2 + 7232);
  v15 = *(_DWORD *)(a2 + 168);
  qdf_mem_set(a3, 7u, 0);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: band:%d, phy_mode:%d, ht_cap:%d, ht_oper_mode:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_obss_generate_detection_config",
    v15,
    v14,
    *(unsigned __int8 *)(a2 + 155),
    *(unsigned int *)(a1 + 12232));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: assoc_sta: 11b:%d, 11g:%d, 11a:%d, ht20:%d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "lim_obss_generate_detection_config",
    *(unsigned __int8 *)(a2 + 437),
    *(unsigned __int8 *)(a2 + 441),
    *(unsigned __int8 *)(a2 + 439),
    *(unsigned __int8 *)(a2 + 445));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: obss: 11b:%d, 11g:%d, 11a:%d, ht20:%d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "lim_obss_generate_detection_config",
    *(unsigned __int8 *)(a2 + 1225),
    *(unsigned __int8 *)(a2 + 1227),
    *(unsigned __int8 *)(a2 + 1229),
    *(unsigned __int8 *)(a2 + 1231));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: detect: b_ap:%d, b_s:%d, g:%d, a:%d, htl:%d, htm:%d, ht20:%d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "lim_obss_generate_detection_config",
    *(unsigned __int8 *)(a2 + 9999),
    *(unsigned __int8 *)(a2 + 10000),
    *(unsigned __int8 *)(a2 + 10001),
    *(unsigned __int8 *)(a2 + 10002),
    *(unsigned __int8 *)(a2 + 10003),
    *(unsigned __int8 *)(a2 + 10004),
    *(unsigned __int8 *)(a2 + 10005));
  if ( v15 == 1 )
  {
    if ( *(_BYTE *)(a2 + 155) )
    {
      if ( *(_BYTE *)(a2 + 439) )
      {
        *(_BYTE *)(a2 + 1229) = 0;
      }
      else if ( *(_BYTE *)(a2 + 1229) )
      {
        if ( *(_BYTE *)(a2 + 10002) == 1 )
          a3[3] = 2;
      }
      else
      {
        a3[3] = 1;
      }
      goto LABEL_30;
    }
  }
  else if ( !v15 )
  {
    if ( v14 == 2 || *(_BYTE *)(a2 + 155) )
    {
      if ( !*(_BYTE *)(a2 + 437) )
      {
        if ( *(_BYTE *)(a2 + 1225) || *(_BYTE *)(a2 + 1227) )
        {
          if ( *(_BYTE *)(a2 + 9999) == 1 )
            *a3 = 2;
          if ( *(_BYTE *)(a2 + 10000) == 1 )
            a3[1] = 2;
        }
        else
        {
          *(_WORD *)a3 = 257;
        }
LABEL_10:
        if ( *(_BYTE *)(a2 + 155) && (*(_WORD *)(a2 + 432) & 4) != 0 )
        {
          if ( !*(_BYTE *)(a2 + 441) )
          {
            if ( *(_BYTE *)(a2 + 1227) )
            {
              if ( *(_BYTE *)(a2 + 10001) == 1 )
                a3[2] = 2;
              if ( *(_BYTE *)(a2 + 10003) == 1 )
                a3[4] = 2;
              if ( *(_BYTE *)(a2 + 10004) == 1 )
                a3[5] = 2;
            }
            else
            {
              a3[2] = 1;
              *((_WORD *)a3 + 2) = 257;
            }
            goto LABEL_26;
          }
LABEL_25:
          *(_BYTE *)(a2 + 1227) = 0;
LABEL_26:
          v57 = *(_QWORD *)(a1 + 8);
          if ( *(_BYTE *)(v57 + 3532) == 1 )
          {
            a3[1] = 0;
            v57 = *(_QWORD *)(a1 + 8);
          }
          if ( *(_BYTE *)(v57 + 3388) == 1 )
            a3[4] = 0;
LABEL_30:
          if ( *(_BYTE *)(a2 + 155) )
          {
            if ( *(_BYTE *)(a2 + 445) )
            {
              *(_BYTE *)(a2 + 1231) = 0;
            }
            else if ( *(_BYTE *)(a2 + 1231) )
            {
              if ( *(_BYTE *)(a2 + 10005) == 1 )
                a3[6] = 2;
            }
            else
            {
              a3[6] = 1;
            }
          }
          goto LABEL_33;
        }
LABEL_12:
        if ( !*(_BYTE *)(a2 + 441) )
          goto LABEL_26;
        goto LABEL_25;
      }
    }
    else if ( !*(_BYTE *)(a2 + 437) )
    {
      goto LABEL_12;
    }
    *(_BYTE *)(a2 + 1225) = 0;
    goto LABEL_10;
  }
LABEL_33:
  LODWORD(v59) = a3[5];
  LODWORD(v60) = a3[6];
  LODWORD(v58) = a3[4];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: b_ap:%d, b_s:%d, g:%d, a:%d, ht_le:%d, ht_m:%d, ht_20:%d",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "lim_obss_generate_detection_config",
    *a3,
    a3[1],
    a3[2],
    a3[3],
    v58,
    v59,
    v60);
  return 0;
}
