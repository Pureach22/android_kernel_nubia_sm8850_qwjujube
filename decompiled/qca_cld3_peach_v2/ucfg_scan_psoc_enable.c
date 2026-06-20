__int64 __fastcall ucfg_scan_psoc_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  _QWORD v35[5]; // [xsp+8h] [xbp-28h] BYREF

  v35[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x15u, 8u, "%s: psoc enable: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_psoc_enable", a1);
  if ( a1 )
  {
    tgt_scan_register_ev_handler(a1, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( (wlan_reg_is_11d_offloaded(a1) & 1) == 0 )
      scm_11d_cc_db_init(a1, v18, v19, v20, v21, v22, v23, v24, v25);
    v35[1] = tgt_scan_bcn_probe_rx_callback;
    v35[0] = 5;
    v35[3] = tgt_scan_bcn_probe_rx_callback;
    v35[2] = 6;
    if ( (unsigned int)wlan_mgmt_txrx_register_rx_cb(a1, 3u, (__int64)v35, 2u, v18, v19, v20, v21, v22, v23, v24, v25) )
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s the Handle with MGMT TXRX layer has failed",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "scan_register_unregister_bcn_cb",
        "Registering");
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 (__fastcall *)()))wlan_serialization_register_apply_rules_cb)(
               a1,
               0,
               scm_serialization_scan_rules_cb);
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_scan_psoc_enable");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
