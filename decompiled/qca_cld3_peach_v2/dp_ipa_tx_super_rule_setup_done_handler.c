__int64 __fastcall dp_ipa_tx_super_rule_setup_done_handler(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // w22
  int v11; // w19
  int v12; // w4
  int v13; // w5
  int v14; // w6
  int v15; // w7
  unsigned int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  char v52; // [xsp+0h] [xbp-20h]
  __int16 v53; // [xsp+Ch] [xbp-14h] BYREF
  char v54; // [xsp+Eh] [xbp-12h]
  char v55; // [xsp+Fh] [xbp-11h]
  __int16 v56; // [xsp+10h] [xbp-10h]
  char v57; // [xsp+12h] [xbp-Eh]
  char v58; // [xsp+13h] [xbp-Dh]
  __int16 v59; // [xsp+14h] [xbp-Ch]
  char v60; // [xsp+16h] [xbp-Ah]
  char v61; // [xsp+17h] [xbp-9h]
  __int64 v62; // [xsp+18h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (unsigned __int8)BYTE1(*a1);
  v11 = (unsigned __int8)BYTE2(*a1);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp_ctrl:: tx_super_rule_rsp, pdev_id: %d resp_type: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_ipa_tx_super_rule_setup_done_handler",
    (unsigned __int8)BYTE1(*a1),
    (unsigned __int8)BYTE2(*a1));
  wlan_ipa_log_message(
    (int)"dp_ipa_tx_super_rule_setup_done_handler",
    (int)"opt_dp_ctrl:: tx_super_rule_rsp, pdev_id: %d resp_type: %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v52);
  v16 = a1[1];
  v54 = HIBYTE(v16);
  v55 = BYTE2(v16);
  v53 = v16;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: response receives by FW, flt_hld: %d, valid: %u, result: %u, dst_port: %u",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "dp_ipa_tx_super_rule_setup_done_handler",
    0,
    HIBYTE(v16),
    BYTE2(v16),
    (unsigned __int16)v16);
  v25 = a1[2];
  v56 = v25;
  v57 = HIBYTE(v25);
  v58 = BYTE2(v25);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: response receives by FW, flt_hld: %d, valid: %u, result: %u, dst_port: %u",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "dp_ipa_tx_super_rule_setup_done_handler",
    1,
    HIBYTE(v25),
    BYTE2(v25),
    (unsigned __int16)v25);
  v34 = a1[3];
  v59 = v34;
  v60 = HIBYTE(v34);
  v61 = BYTE2(v34);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: response receives by FW, flt_hld: %d, valid: %u, result: %u, dst_port: %u",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "dp_ipa_tx_super_rule_setup_done_handler",
    2,
    HIBYTE(v34),
    BYTE2(v34),
    (unsigned __int16)v34);
  if ( v11 == 1 )
  {
    result = dp_ipa_wdi_opt_dpath_ctrl_notify_flt_delete(&v53);
  }
  else if ( v11 )
  {
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: opt_dp:: Wrong Super rule setup response",
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               "dp_ipa_tx_super_rule_setup_done_handler");
  }
  else
  {
    result = dp_ipa_wdi_opt_dpath_ctrl_notify_flt_install(&v53);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
