__int64 __fastcall htt_h2t_tx_super_rule_setup(
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
  unsigned int v14; // w23
  _DWORD *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x24
  __int64 v25; // x2
  int v26; // w8
  int v27; // w9
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w24
  __int64 v38; // x28
  unsigned __int8 *v39; // x8
  unsigned int v40; // w19
  int v41; // w27
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  __int64 v51; // x8
  __int64 v52; // x4
  __int64 v53; // x8
  int v54; // t1
  int v55; // w9
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x19
  int v82; // w8
  int v83; // w8
  unsigned int v84; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w20
  int v94; // w2
  int v95; // w3
  int v96; // w4
  int v97; // w5
  int v98; // w6
  int v99; // w7
  char v100; // [xsp+0h] [xbp-20h]
  __int64 v101; // [xsp+10h] [xbp-10h]
  __int64 v102; // [xsp+18h] [xbp-8h]

  if ( a2[2] >= 4u )
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Wrong tx filter count %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "htt_h2t_tx_super_rule_setup");
    return 49;
  }
  v13 = *a2;
  v14 = a2[1];
  v15 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(a1 + 56), 132, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate TX SUPER_RULE_SETUP msg ",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "htt_h2t_tx_super_rule_setup");
    return 16;
  }
  v24 = v15;
  v102 = a1;
  if ( v15[29] )
  {
    v25 = 124;
  }
  else
  {
    v27 = v15[52];
    v26 = v15[53];
    if ( (unsigned int)(v26 - v27) > 0x7B )
      goto LABEL_10;
    v25 = (unsigned int)(v27 - v26 + 124);
  }
  if ( (unsigned int)pskb_expand_head(v15, 0, v25, 2080) )
  {
    dev_kfree_skb_any_reason(v24, 1);
    goto LABEL_11;
  }
LABEL_10:
  skb_put(v24, 124);
LABEL_11:
  v28 = *((_QWORD *)v24 + 28);
  v101 = (__int64)v24;
  *(_DWORD *)(v28 + 120) = 0;
  *(_QWORD *)(v28 + 104) = 0;
  *(_QWORD *)(v28 + 112) = 0;
  *(_QWORD *)(v28 + 88) = 0;
  *(_QWORD *)(v28 + 96) = 0;
  *(_QWORD *)(v28 + 72) = 0;
  *(_QWORD *)(v28 + 80) = 0;
  *(_QWORD *)(v28 + 56) = 0;
  *(_QWORD *)(v28 + 64) = 0;
  *(_QWORD *)(v28 + 40) = 0;
  *(_QWORD *)(v28 + 48) = 0;
  *(_QWORD *)(v28 + 24) = 0;
  *(_QWORD *)(v28 + 32) = 0;
  *(_QWORD *)(v28 + 8) = 0;
  *(_QWORD *)(v28 + 16) = 0;
  *(_QWORD *)v28 = 0;
  skb_push(v24, 0);
  v37 = 0;
  v38 = -312;
  *(_DWORD *)v28 = (v14 << 16) | (v13 << 8) | 0x26;
  do
  {
    v39 = &a2[v38];
    if ( !a2[v38 + 372] )
    {
      v28 += 40;
      goto LABEL_13;
    }
    v40 = *((unsigned __int16 *)v39 + 181);
    v41 = v39[320];
    if ( v40 == 56710 )
    {
      v51 = *(_QWORD *)&a2[v38 + 337];
      *(_QWORD *)(v28 + 4) = *(_QWORD *)&a2[v38 + 329];
      v52 = *(unsigned int *)(v28 + 4);
      *(_QWORD *)(v28 + 12) = v51;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: src_ipv6_addr 0x%x in msg_word",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "htt_h2t_tx_super_rule_setup",
        v52);
      v53 = *(_QWORD *)&a2[v38 + 353];
      v50 = "%s: dst_ipv6_addr 0x%x in msg_word";
      *(_QWORD *)(v28 + 20) = *(_QWORD *)&a2[v38 + 345];
      *(_QWORD *)(v28 + 28) = v53;
      goto LABEL_19;
    }
    if ( v40 == 8 )
    {
      *(_DWORD *)(v28 + 4) = *(_DWORD *)&a2[v38 + 321];
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: src_ipv4_addr 0x%x in msg_word",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "htt_h2t_tx_super_rule_setup");
      v50 = "%s: dst_ipv4_addr 0x%x in msg_word";
      *(_DWORD *)(v28 + 20) = *(_DWORD *)&a2[v38 + 325];
LABEL_19:
      qdf_trace_msg(0x45u, 5u, v50, v42, v43, v44, v45, v46, v47, v48, v49, "htt_h2t_tx_super_rule_setup");
    }
    v54 = *(_DWORD *)(v28 + 40);
    v28 += 40;
    v55 = *(_DWORD *)(v28 - 4) | v40;
    *(_DWORD *)(v28 - 4) = v55;
    *(_DWORD *)(v28 - 4) = (a2[v38 + 361] << 16) | (v41 << 24) | v55;
    *(_DWORD *)v28 = v54 | *(unsigned __int16 *)&a2[v38 + 364];
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: src_port 0x%x in msg_word",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "htt_h2t_tx_super_rule_setup");
    *(_DWORD *)v28 |= *(unsigned __int16 *)&a2[v38 + 366] << 16;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: dst_port 0x%x in msg_word",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "htt_h2t_tx_super_rule_setup");
    v100 = v41;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl:: pdev: %u ver %u, flt_num %u, op %u, valid %u ",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "htt_h2t_tx_super_rule_setup",
      v13,
      v40,
      v37,
      v14);
LABEL_13:
    v38 += 104;
    ++v37;
  }
  while ( v38 );
  v72 = htt_htc_pkt_alloc(v102);
  if ( v72 )
  {
    *(_QWORD *)v72 = 0;
    v81 = v72;
    *(_QWORD *)(v72 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    *(_QWORD *)(v72 + 48) = *(_QWORD *)(v101 + 224);
    if ( (*(_BYTE *)(v101 + 68) & 4) != 0 )
      v82 = *(unsigned __int16 *)(v101 + 66);
    else
      v82 = 0;
    *(_DWORD *)(v72 + 60) = *(_DWORD *)(v101 + 112) + v82;
    v83 = *(_DWORD *)(v102 + 64);
    *(_WORD *)(v72 + 72) = 13;
    *(_DWORD *)(v72 + 88) = 0;
    *(_BYTE *)(v72 + 80) = 0;
    *(_DWORD *)(v72 + 64) = v83;
    *(_QWORD *)(v72 + 112) = v101;
    v84 = htc_send_pkt(*(_QWORD *)(v102 + 48), v72 + 16);
    if ( v84 )
    {
      v93 = v84;
      ++*(_DWORD *)(v102 + 104);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: failed to send htt msg to FW",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        "htt_h2t_tx_super_rule_setup");
      wlan_ipa_log_message(
        (int)"htt_h2t_tx_super_rule_setup",
        (int)"failed to send htt msg to FW",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100);
      _qdf_nbuf_free(v101);
      htt_htc_pkt_free(v102, v81);
      return v93;
    }
    else
    {
      result = 0;
      if ( (*(_DWORD *)(v81 + 68) | 8) == 9 )
        ++*(_DWORD *)(v102 + 104);
    }
  }
  else
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "htt_h2t_tx_super_rule_setup");
    _qdf_nbuf_free(v101);
    return 2;
  }
  return result;
}
