__int64 __fastcall p2p_psoc_stop(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  __int64 v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v38; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v19 = *(_QWORD **)(comp_private_obj + 88);
      v20 = comp_private_obj;
      *(_QWORD *)(comp_private_obj + 88) = 0;
      if ( v19 )
      {
        p2p_mgmt_rx_action_ops(a1, 0);
        p2p_cleanup_tx_sync(v20, 0);
        v21 = p2p_cleanup_roc(v20, 0, 1);
        wlan_scan_unregister_requester(a1, *(unsigned __int16 *)(v20 + 80), v21, v22, v23, v24, v25, v26, v27, v28);
        tgt_p2p_unregister_ap_assist_bmiss_ev_handler(a1);
        tgt_p2p_register_mcc_quota_ev_handler(a1, 0);
        tgt_p2p_register_macaddr_rx_filter_evt_handler(a1, 0);
        tgt_p2p_unregister_lo_ev_handler(a1);
        tgt_p2p_unregister_noa_ev_handler(a1);
        *v19 = 0;
        v19[1] = 0;
        v19[2] = 0;
        v19[3] = 0;
        v19[4] = 0;
        v19[5] = 0;
        _qdf_mem_free((__int64)v19);
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p psoc stop successful",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "p2p_psoc_stop");
        return 0;
      }
      v38 = "%s: start parameters is NULL";
    }
    else
    {
      v38 = "%s: P2P soc object is NULL";
    }
    qdf_trace_msg(0x4Eu, 2u, v38, v11, v12, v13, v14, v15, v16, v17, v18, "p2p_psoc_stop");
    return 16;
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: psoc context passed is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_psoc_stop");
    return 4;
  }
}
