__int64 __fastcall dp_ipa_rx_cce_super_rule_setup_done_handler(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w19
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  unsigned int v23; // w21
  unsigned int v24; // w22
  unsigned int v25; // w23
  unsigned int v26; // w24
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w8
  bool v36; // nf
  int v37; // w8
  int v38; // w2
  int v39; // w3
  int v40; // w4
  int v41; // w5
  int v42; // w6
  int v43; // w7
  int v44; // w3
  int v45; // w4
  int v46; // w5
  int v47; // w6
  int v48; // w7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w7
  char v67; // [xsp+0h] [xbp-10h]

  v12 = (unsigned __int8)BYTE1(*a2);
  v13 = (unsigned __int8)BYTE2(*a2);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp:: cce_super_rule_rsp pdev_id: %d resp_type: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_ipa_rx_cce_super_rule_setup_done_handler",
    (unsigned __int8)BYTE1(*a2),
    (unsigned __int8)BYTE2(*a2));
  if ( v13 == 2 )
  {
    v25 = HIBYTE(*a2) & 1;
    v26 = (*a2 >> 25) & 1;
    dp_ipa_wdi_opt_dpath_notify_flt_rlsd(v25, v26);
    goto LABEL_8;
  }
  if ( v13 == 1 )
  {
    v25 = HIBYTE(*a2) & 1;
    v26 = (*a2 >> 25) & 1;
    dp_ipa_wdi_opt_dpath_notify_flt_add_rem_cb(v25, v26);
LABEL_8:
    v23 = 0;
    v24 = 0;
    goto LABEL_15;
  }
  if ( v13 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp:: Wrong Super rule setup response",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_ipa_rx_cce_super_rule_setup_done_handler");
    v23 = 0;
    v24 = 0;
  }
  else
  {
    v22 = *a2;
    v23 = HIBYTE(*a2) & 1;
    v24 = v22 >> 25;
    if ( (v22 & 0x1000000) != 0 )
    {
      *(_DWORD *)(a1 + 112) = 0;
    }
    else
    {
      v35 = *(_DWORD *)(a1 + 112) + 1;
      v36 = *(_DWORD *)(a1 + 112) - 5 < 0;
      *(_DWORD *)(a1 + 112) = v35;
      if ( v36 == __OFSUB__(v35, 6) )
      {
        v37 = *(_DWORD *)(a1 + 116) + 1;
        *(_DWORD *)(a1 + 112) = 0;
        *(_DWORD *)(a1 + 116) = v37;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: opt_dp: Filter reserve failed max attempts",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "dp_ipa_rx_cce_super_rule_setup_done_handler");
        wlan_ipa_log_message(
          (int)"dp_ipa_rx_cce_super_rule_setup_done_handler",
          (int)"opt_dp: Filter reserve failed max attempts",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v67);
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: opt_dp:: Filter reserve failed. Rules avail %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_ipa_rx_cce_super_rule_setup_done_handler",
        v24);
      wlan_ipa_log_message(
        (int)"dp_ipa_rx_cce_super_rule_setup_done_handler",
        (int)"opt_dp:: Filter reserve failed. Rules avail %d",
        v24,
        v44,
        v45,
        v46,
        v47,
        v48,
        v67);
    }
    dp_ipa_wdi_opt_dpath_notify_flt_rsvd(v23);
  }
  v25 = 0;
  v26 = 0;
LABEL_15:
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp:: cce super rule resp type: %d, is_rules_enough: %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "dp_ipa_rx_cce_super_rule_setup_done_handler",
    v13,
    v23);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: num_rules_avail: %d, rslt0: %d, rslt1: %d",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "dp_ipa_rx_cce_super_rule_setup_done_handler",
    v24,
    v25,
    v26);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp: pdev_id: %d resp_type: %d, rules_enough: %d, rslt0: %d, rslt1: %d",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "dp_ipa_rx_cce_super_rule_setup_done_handler",
    v12,
    v13,
    v23,
    v25);
  return wlan_ipa_log_message(
           (int)"dp_ipa_rx_cce_super_rule_setup_done_handler",
           (int)"opt_dp: pdev_id: %d resp_type: %d, rules_enough: %d, rslt0: %d, rslt1: %d",
           v12,
           v13,
           v23,
           v25,
           v26,
           v65,
           v26);
}
