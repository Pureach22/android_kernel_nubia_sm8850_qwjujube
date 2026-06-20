__int64 __fastcall osif_dp_populate_connectivity_check_stats_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char pkt_type_bitmap_value; // w0
  __int64 v13; // x22
  __int64 v14; // x23
  char v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _WORD *v24; // x25
  unsigned int v25; // w22
  unsigned int v26; // w8
  __int64 result; // x0
  __int64 v28; // x22
  __int64 v29; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _WORD *v38; // x26
  __int64 dns_stats; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _WORD *v48; // x23
  unsigned int track_dns_domain_len_value; // w24
  _BYTE *v50; // x0
  _BYTE *v51; // x22
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  _BYTE *v61; // x10
  _BYTE *v62; // x11
  const char *v63; // x2
  __int64 v64; // x4
  __int64 v65; // x23
  __int64 v66; // x24
  _WORD *v67; // x23
  unsigned int v68; // w23
  __int64 v69; // x24
  __int64 v70; // x26
  _WORD *v71; // x24
  int v72; // w0
  __int64 v73; // x24
  __int64 v74; // x26
  _WORD *v75; // x24
  int v76; // w0
  __int64 v77; // x22
  __int64 v78; // x23
  unsigned int v79; // w21
  _WORD *v80; // x23
  _WORD *icmpv4_stats; // x22
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  int track_dest_ipv4_value; // w0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  int v99; // w20
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v109; // [xsp+8h] [xbp-8h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pkt_type_bitmap_value = ucfg_dp_get_pkt_type_bitmap_value(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *(_QWORD *)(a2 + 216);
  v14 = *(unsigned int *)(a2 + 208);
  v15 = pkt_type_bitmap_value;
  if ( (nla_put(a2, 32779, 0, 0) & 0x80000000) != 0 || (v24 = (_WORD *)(v13 + v14)) == nullptr )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: nla_nest_start failed",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "osif_dp_populate_connectivity_check_stats_info");
LABEL_61:
    result = 4294967274LL;
    goto LABEL_62;
  }
  if ( (v15 & 2) == 0 )
  {
    v25 = 0;
    if ( (v15 & 4) == 0 )
      goto LABEL_5;
LABEL_29:
    v65 = *(_QWORD *)(a2 + 216);
    v66 = *(unsigned int *)(a2 + 208);
    if ( (nla_put(a2, v25 | 0x8000, 0, 0) & 0x80000000) != 0 || (v67 = (_WORD *)(v65 + v66)) == nullptr )
    {
      v63 = "%s: nla_nest_start failed count %u";
      v64 = v25;
      goto LABEL_60;
    }
    if ( (unsigned int)osif_dp_populate_tcp_stats_info(a1, a2, 32) )
    {
      v64 = v25;
    }
    else
    {
      *v67 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v67;
      v68 = v25 + 1;
      v69 = *(_QWORD *)(a2 + 216);
      v70 = *(unsigned int *)(a2 + 208);
      if ( (nla_put(a2, v25 + 32769, 0, 0) & 0x80000000) != 0 )
        goto LABEL_56;
      v71 = (_WORD *)(v69 + v70);
      if ( !v71 )
        goto LABEL_56;
      v72 = osif_dp_populate_tcp_stats_info(a1, a2, 64);
      v64 = v68;
      if ( v72 )
        goto LABEL_59;
      v68 = v25 | 2;
      *v71 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v71;
      v73 = *(_QWORD *)(a2 + 216);
      v74 = *(unsigned int *)(a2 + 208);
      if ( (nla_put(a2, v25 | 0x8002, 0, 0) & 0x80000000) != 0 || (v75 = (_WORD *)(v73 + v74)) == nullptr )
      {
LABEL_56:
        v63 = "%s: nla_nest_start failed count %u";
        v64 = v68;
        goto LABEL_60;
      }
      v76 = osif_dp_populate_tcp_stats_info(a1, a2, 128);
      v64 = v68;
      if ( !v76 )
      {
        *v75 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v75;
        v26 = v25 + 3;
        if ( (v15 & 8) == 0 )
          goto LABEL_6;
        goto LABEL_41;
      }
    }
LABEL_59:
    v63 = "%s: QCA_WLAN_VENDOR_ATTR put fail. count %u";
    goto LABEL_60;
  }
  v28 = *(_QWORD *)(a2 + 216);
  v29 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 0x8000, 0, 0) & 0x80000000) != 0 || (v38 = (_WORD *)(v28 + v29)) == nullptr )
  {
    v63 = "%s: nla_nest_start failed count %u";
    v64 = 0;
    goto LABEL_60;
  }
  dns_stats = ucfg_dp_get_dns_stats(a1, v30, v31, v32, v33, v34, v35, v36, v37);
  if ( !dns_stats )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get DNS stats",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "osif_dp_populate_dns_stats_info");
    goto LABEL_27;
  }
  v48 = (_WORD *)dns_stats;
  track_dns_domain_len_value = ucfg_dp_get_track_dns_domain_len_value(a1, v40, v41, v42, v43, v44, v45, v46, v47);
  v50 = (_BYTE *)_qdf_mem_malloc(track_dns_domain_len_value + 1, "osif_dp_populate_dns_stats_info", 758);
  if ( !v50 )
  {
LABEL_27:
    v64 = 0;
    goto LABEL_59;
  }
  v51 = v50;
  ucfg_dp_get_dns_payload_value(a1, v50, v30, v31, v32, v33, v34, v35, v36, v37);
  LOWORD(v108) = 2;
  if ( (unsigned int)nla_put(a2, 1, 2, &v108) )
    goto LABEL_24;
  v60 = (unsigned __int8)*v51;
  if ( *v51 )
  {
    v61 = v51;
    do
    {
      v62 = &v61[v60];
      *v61 = 46;
      v60 = (unsigned __int8)v62[1];
      v61 = v62 + 1;
    }
    while ( v62[1] );
  }
  if ( (unsigned int)nla_put(a2, 2, track_dns_domain_len_value, v51 + 1)
    || (LOWORD(v108) = *v48, (unsigned int)nla_put(a2, 7, 2, &v108))
    || (LOWORD(v108) = v48[5], (unsigned int)nla_put(a2, 8, 2, &v108))
    || (LOWORD(v108) = v48[5], (unsigned int)nla_put(a2, 9, 2, &v108))
    || (LOWORD(v108) = v48[7], (unsigned int)nla_put(a2, 10, 2, &v108))
    || (LOWORD(v108) = v48[1], (unsigned int)nla_put(a2, 12, 2, &v108))
    || (LOWORD(v108) = v48[3], (unsigned int)nla_put(a2, 13, 2, &v108))
    || (LOWORD(v108) = v48[6], (unsigned int)nla_put(a2, 14, 2, &v108)) )
  {
LABEL_24:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: nla put fail",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "osif_dp_populate_dns_stats_info");
    _qdf_mem_free((__int64)v51);
    sk_skb_reason_drop(0, a2, 2);
    goto LABEL_27;
  }
  _qdf_mem_free((__int64)v51);
  v25 = 1;
  *v38 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v38;
  if ( (v15 & 4) != 0 )
    goto LABEL_29;
LABEL_5:
  v26 = v25;
  if ( (v15 & 8) != 0 )
  {
LABEL_41:
    v77 = *(_QWORD *)(a2 + 216);
    v78 = *(unsigned int *)(a2 + 208);
    v79 = v26;
    if ( (nla_put(a2, v26 | 0x8000, 0, 0) & 0x80000000) == 0 )
    {
      v80 = (_WORD *)(v77 + v78);
      if ( v80 )
      {
        icmpv4_stats = (_WORD *)ucfg_dp_get_icmpv4_stats(a1, v30, v31, v32, v33, v34, v35, v36, v37);
        track_dest_ipv4_value = ucfg_dp_get_track_dest_ipv4_value(a1, v82, v83, v84, v85, v86, v87, v88, v89);
        if ( icmpv4_stats )
        {
          v99 = track_dest_ipv4_value;
          LOWORD(v108) = 8;
          if ( !(unsigned int)nla_put(a2, 1, 2, &v108) )
          {
            v108 = v99;
            if ( !(unsigned int)nla_put(a2, 5, 4, &v108) )
            {
              LOWORD(v108) = *icmpv4_stats;
              if ( !(unsigned int)nla_put(a2, 7, 2, &v108) )
              {
                LOWORD(v108) = icmpv4_stats[5];
                if ( !(unsigned int)nla_put(a2, 8, 2, &v108) )
                {
                  LOWORD(v108) = icmpv4_stats[5];
                  if ( !(unsigned int)nla_put(a2, 9, 2, &v108) )
                  {
                    LOWORD(v108) = icmpv4_stats[8];
                    if ( !(unsigned int)nla_put(a2, 10, 2, &v108) )
                    {
                      LOWORD(v108) = icmpv4_stats[7];
                      if ( !(unsigned int)nla_put(a2, 11, 2, &v108) )
                      {
                        LOWORD(v108) = icmpv4_stats[1];
                        if ( !(unsigned int)nla_put(a2, 12, 2, &v108) )
                        {
                          LOWORD(v108) = icmpv4_stats[3];
                          if ( !(unsigned int)nla_put(a2, 13, 2, &v108) )
                          {
                            LOWORD(v108) = icmpv4_stats[6];
                            if ( !(unsigned int)nla_put(a2, 14, 2, &v108) )
                            {
                              *v80 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v80;
                              goto LABEL_6;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: nla put fail",
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "osif_dp_populate_icmpv4_stats_info");
          sk_skb_reason_drop(0, a2, 2);
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Unable to get ICMP stats",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            "osif_dp_populate_icmpv4_stats_info");
        }
        v64 = v79;
        goto LABEL_59;
      }
    }
    v63 = "%s: nla_nest_start failed count %u";
    v64 = v79;
LABEL_60:
    qdf_trace_msg(
      0x45u,
      2u,
      v63,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "osif_dp_populate_connectivity_check_stats_info",
      v64);
    goto LABEL_61;
  }
LABEL_6:
  result = 0;
  *v24 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v24;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
