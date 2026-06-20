__int64 __fastcall ucfg_scan_psoc_disable(
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
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD v44[5]; // [xsp+8h] [xbp-28h] BYREF

  v44[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x15u, 8u, "%s: psoc disable: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_psoc_disable", a1);
  if ( a1 )
  {
    v18 = tgt_scan_unregister_ev_handler(a1, v10, v11, v12, v13, v14, v15, v16, v17);
    v44[1] = tgt_scan_bcn_probe_rx_callback;
    v44[0] = 5;
    v44[3] = tgt_scan_bcn_probe_rx_callback;
    v44[2] = 6;
    if ( (unsigned int)wlan_mgmt_txrx_deregister_rx_cb(a1, 3u, (__int64)v44, 2u, v19, v20, v21, v22, v23, v24, v25, v26) )
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s the Handle with MGMT TXRX layer has failed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "scan_register_unregister_bcn_cb",
        "Deregistering");
    if ( (wlan_reg_is_11d_offloaded(a1) & 1) == 0 )
      scm_11d_cc_db_deinit(a1, v35, v36, v37, v38, v39, v40, v41, v42);
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_scan_psoc_disable");
    v18 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
