__int64 __fastcall htt_h2t_rx_cce_super_rule_setup(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  unsigned int v13; // w22
  unsigned int v14; // w21
  _DWORD *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 v25; // x2
  int v26; // w8
  int v27; // w9
  __int64 v28; // x27
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x5
  unsigned int v38; // w24
  __int64 v39; // x9
  __int64 v40; // x9
  unsigned int v41; // w28
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w9
  int v51; // w8
  int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x5
  unsigned int v70; // w24
  __int64 v71; // x9
  __int64 v72; // x9
  unsigned int v73; // w28
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  int v82; // w9
  int v83; // w8
  int v84; // w8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x21
  int v103; // w8
  int v104; // w8
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int v114; // w23
  int v115; // w2
  int v116; // w3
  int v117; // w4
  int v118; // w5
  int v119; // w6
  int v120; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2[2] >= 3u )
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Wrong filter count %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "htt_h2t_rx_cce_super_rule_setup");
    return 49;
  }
  v13 = *a2;
  v14 = a2[1];
  v15 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(a1 + 56), 92, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate SUPER_RULE_SETUP msg ",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "htt_h2t_rx_cce_super_rule_setup");
    return 16;
  }
  v24 = (__int64)v15;
  if ( v15[29] )
  {
    v25 = 84;
  }
  else
  {
    v27 = v15[52];
    v26 = v15[53];
    if ( (unsigned int)(v26 - v27) > 0x53 )
      goto LABEL_10;
    v25 = (unsigned int)(v27 - v26 + 84);
  }
  if ( (unsigned int)pskb_expand_head(v15, 0, v25, 2080) )
  {
    dev_kfree_skb_any_reason(v24, 1);
    goto LABEL_11;
  }
LABEL_10:
  skb_put(v24, 84);
LABEL_11:
  v28 = *(_QWORD *)(v24 + 224);
  *(_DWORD *)(v28 + 80) = 0;
  *(_QWORD *)(v28 + 64) = 0;
  *(_QWORD *)(v28 + 72) = 0;
  *(_QWORD *)(v28 + 48) = 0;
  *(_QWORD *)(v28 + 56) = 0;
  *(_QWORD *)(v28 + 32) = 0;
  *(_QWORD *)(v28 + 40) = 0;
  *(_QWORD *)(v28 + 16) = 0;
  *(_QWORD *)(v28 + 24) = 0;
  *(_QWORD *)v28 = 0;
  *(_QWORD *)(v28 + 8) = 0;
  skb_push(v24, 0);
  *(_DWORD *)v28 = (v14 << 16) | (v13 << 8) | 0x23;
  v37 = *((unsigned __int16 *)a2 + 25);
  v38 = a2[8];
  if ( (_DWORD)v37 == 56710 )
  {
    v39 = *(_QWORD *)(a2 + 17);
    *(_QWORD *)(v28 + 12) = *(_QWORD *)(a2 + 25);
    *(_QWORD *)(v28 + 4) = v39;
    v40 = *(_QWORD *)(a2 + 33);
    *(_QWORD *)(v28 + 28) = *(_QWORD *)(a2 + 41);
    *(_QWORD *)(v28 + 20) = v40;
  }
  else if ( (_DWORD)v37 == 8 )
  {
    *(_DWORD *)(v28 + 4) = *(_DWORD *)(a2 + 9);
    *(_DWORD *)(v28 + 20) = *(_DWORD *)(a2 + 13);
  }
  else
  {
    v41 = *((unsigned __int16 *)a2 + 25);
    qdf_trace_msg(
      0x80u,
      8u,
      "%s: Filter %d not in use.",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "htt_h2t_rx_cce_super_rule_setup",
      0);
    qdf_trace_msg(
      0x80u,
      8u,
      "%s: Filter %d not in use.",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "htt_h2t_rx_cce_super_rule_setup",
      0);
    v37 = v41;
  }
  v50 = *(_DWORD *)(v28 + 40);
  v51 = *(_DWORD *)(v28 + 36) | v37;
  *(_DWORD *)(v28 + 36) = v51;
  *(_DWORD *)(v28 + 36) = (a2[49] << 16) | (v38 << 24) | v51;
  v52 = v50 | *((unsigned __int16 *)a2 + 26);
  *(_DWORD *)(v28 + 40) = v52;
  *(_DWORD *)(v28 + 40) = v52 | (*((unsigned __int16 *)a2 + 27) << 16);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp:: pdev: %u ver %u, flt_num %u, op %u",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "htt_h2t_rx_cce_super_rule_setup",
    v13,
    v37,
    0,
    v14);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: valid %u",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "htt_h2t_rx_cce_super_rule_setup",
    v38);
  v69 = *((unsigned __int16 *)a2 + 77);
  v70 = a2[112];
  if ( (_DWORD)v69 == 8 )
  {
    *(_DWORD *)(v28 + 44) = *(_DWORD *)(a2 + 113);
    *(_DWORD *)(v28 + 60) = *(_DWORD *)(a2 + 117);
  }
  else if ( (_DWORD)v69 == 56710 )
  {
    v71 = *(_QWORD *)(a2 + 121);
    *(_QWORD *)(v28 + 52) = *(_QWORD *)(a2 + 129);
    *(_QWORD *)(v28 + 44) = v71;
    v72 = *(_QWORD *)(a2 + 137);
    *(_QWORD *)(v28 + 68) = *(_QWORD *)(a2 + 145);
    *(_QWORD *)(v28 + 60) = v72;
  }
  else
  {
    v73 = *((unsigned __int16 *)a2 + 77);
    qdf_trace_msg(
      0x80u,
      8u,
      "%s: Filter %d not in use.",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "htt_h2t_rx_cce_super_rule_setup",
      1);
    qdf_trace_msg(
      0x80u,
      8u,
      "%s: Filter %d not in use.",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "htt_h2t_rx_cce_super_rule_setup",
      1);
    v69 = v73;
  }
  v82 = *(_DWORD *)(v28 + 80);
  v83 = *(_DWORD *)(v28 + 76) | v69;
  *(_DWORD *)(v28 + 76) = v83;
  *(_DWORD *)(v28 + 76) = (a2[153] << 16) | (v70 << 24) | v83;
  v84 = v82 | *((unsigned __int16 *)a2 + 78);
  *(_DWORD *)(v28 + 80) = v84;
  *(_DWORD *)(v28 + 80) = v84 | (*((unsigned __int16 *)a2 + 79) << 16);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp:: pdev: %u ver %u, flt_num %u, op %u",
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    "htt_h2t_rx_cce_super_rule_setup",
    v13,
    v69,
    1,
    v14);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: valid %u",
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    "htt_h2t_rx_cce_super_rule_setup",
    v70);
  v93 = htt_htc_pkt_alloc(a1);
  if ( v93 )
  {
    *(_QWORD *)v93 = 0;
    *(_QWORD *)(v93 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v102 = v93;
    *(_QWORD *)(v93 + 48) = *(_QWORD *)(v24 + 224);
    if ( (*(_BYTE *)(v24 + 68) & 4) != 0 )
      v103 = *(unsigned __int16 *)(v24 + 66);
    else
      v103 = 0;
    *(_DWORD *)(v93 + 60) = *(_DWORD *)(v24 + 112) + v103;
    v104 = *(_DWORD *)(a1 + 64);
    *(_WORD *)(v93 + 72) = 13;
    *(_DWORD *)(v93 + 88) = 0;
    *(_BYTE *)(v93 + 80) = 0;
    *(_DWORD *)(v93 + 64) = v104;
    *(_QWORD *)(v93 + 112) = v24;
    v105 = htc_send_pkt(*(_QWORD *)(a1 + 48), v93 + 16);
    if ( v105 )
    {
      v114 = v105;
      ++*(_DWORD *)(a1 + 104);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: failed sending htt msg to FW",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "htt_h2t_rx_cce_super_rule_setup");
      wlan_ipa_log_message(
        (int)"htt_h2t_rx_cce_super_rule_setup",
        (int)"failed sending htt msg to FW",
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        vars0);
      _qdf_nbuf_free(v24);
      htt_htc_pkt_free(a1, v102);
      return v114;
    }
    else
    {
      result = 0;
      if ( (*(_DWORD *)(v102 + 68) | 8) == 9 )
        ++*(_DWORD *)(a1 + 104);
    }
  }
  else
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "htt_h2t_rx_cce_super_rule_setup");
    _qdf_nbuf_free(v24);
    return 2;
  }
  return result;
}
