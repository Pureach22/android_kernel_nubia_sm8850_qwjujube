__int64 __fastcall p2p_psoc_start(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v21 = comp_private_obj;
      v22 = (_QWORD *)_qdf_mem_malloc(0x40u, "p2p_psoc_start", 850);
      if ( v22 )
      {
        *v22 = *a2;
        v22[1] = a2[1];
        v22[2] = a2[2];
        v22[3] = a2[3];
        v22[4] = a2[4];
        v22[5] = a2[5];
        v22[6] = a2[6];
        v22[7] = a2[7];
        *(_QWORD *)(v21 + 88) = v22;
        *(_DWORD *)(v21 + 276) = 0;
        tgt_p2p_register_lo_ev_handler(a1);
        tgt_p2p_register_noa_ev_handler(a1);
        tgt_p2p_register_macaddr_rx_filter_evt_handler(a1, 1);
        tgt_p2p_register_mcc_quota_ev_handler(a1, 1);
        v23 = tgt_p2p_register_ap_assist_bmiss_ev_handler(a1);
        *(_WORD *)(v21 + 80) = wlan_scan_register_requester(
                                 a1,
                                 "P2P",
                                 (__int64)tgt_p2p_scan_event_cb,
                                 v21,
                                 v23,
                                 v24,
                                 v25,
                                 v26,
                                 v27,
                                 v28,
                                 v29,
                                 v30);
        p2p_mgmt_rx_action_ops(a1, 1);
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p psoc start successful, scan request id:%d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "p2p_psoc_start",
          *(unsigned __int16 *)(v21 + 80));
        return 0;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(0x4Eu, 2u, "%s: P2P soc object is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "p2p_psoc_start");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: psoc context passed is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "p2p_psoc_start");
    return 4;
  }
}
