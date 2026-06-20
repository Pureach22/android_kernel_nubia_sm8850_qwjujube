__int64 __fastcall t2lm_deliver_event(
        __int64 a1,
        __int64 a2,
        int a3,
        _BYTE *a4,
        unsigned int a5,
        unsigned __int8 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x9
  const char *v16; // x4
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  const char *v27; // x4
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  const char *v49; // x2
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x3

  v14 = *(_QWORD *)(a1 + 216);
  if ( !v14 )
    return 16;
  if ( !*(_QWORD *)(v14 + 80) )
    return 16;
  if ( (unsigned int)a3 > 8 )
  {
    v16 = (const char *)&unk_98C763;
LABEL_5:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: T2LM event received: %s(%d)",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "t2lm_deliver_event",
      v16,
      (unsigned int)a3);
    qdf_trace_msg(0x68u, 2u, "%s: Unhandled T2LM event", v17, v18, v19, v20, v21, v22, v23, v24, "t2lm_deliver_event");
    return 16;
  }
  v16 = "Unknown";
  if ( a3 > 3 )
  {
    if ( a3 <= 5 )
    {
      if ( a3 == 4 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: T2LM event received: %s(%d)",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "t2lm_deliver_event",
          "WLAN_T2LM_EV_ACTION_FRAME_RX_TEARDOWN");
        return t2lm_handle_rx_teardown(a1, a2, v55, v56, v57, v58, v59, v60, v61, v62);
      }
      v27 = "WLAN_T2LM_EV_ACTION_FRAME_TX_TEARDOWN";
LABEL_16:
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: T2LM event received: %s(%d)",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "t2lm_deliver_event",
        v27);
      return 0;
    }
    if ( a3 == 6 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: T2LM event received: %s(%d)",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "t2lm_deliver_event",
        "WLAN_T2LM_EV_DEL_LINK_UPDATE_MAPPING");
      if ( a2 )
      {
        result = wlan_t2lm_update_peer_mapping_for_del_link(*(_QWORD *)(a2 + 784));
        if ( !(_DWORD)result )
          return result;
        v48 = result;
        v49 = "%s: Update T2LM peer mapping failed";
      }
      else
      {
        v48 = 29;
        v49 = "%s: peer is null";
      }
      v73 = "t2lm_handle_del_mapping_update";
    }
    else
    {
      if ( a3 != 7 )
        goto LABEL_5;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: T2LM event received: %s(%d)",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "t2lm_deliver_event",
        "WLAN_T2LM_EV_ADD_LINK_UPDATE_MAPPING");
      if ( a2 )
      {
        result = wlan_t2lm_update_peer_mapping_for_add_link(*(_QWORD *)(a2 + 784));
        if ( !(_DWORD)result )
          return result;
        v48 = result;
        v49 = "%s: Update T2LM peer mapping failed";
      }
      else
      {
        v48 = 29;
        v49 = "%s: peer is null";
      }
      v73 = "t2lm_handle_add_mapping_update";
    }
    qdf_trace_msg(0x99u, 2u, v49, v40, v41, v42, v43, v44, v45, v46, v47, v73);
    return v48;
  }
  if ( a3 <= 1 )
  {
    if ( !a3 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: T2LM event received: %s(%d)",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "t2lm_deliver_event",
        "WLAN_T2LM_EV_ACTION_FRAME_RX_REQ");
      return t2lm_handle_rx_req(a1, a2, a4, a5, a6);
    }
    v27 = "WLAN_T2LM_EV_ACTION_FRAME_TX_RESP";
    goto LABEL_16;
  }
  if ( a3 == 2 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: T2LM event received: %s(%d)",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "t2lm_deliver_event",
      "WLAN_T2LM_EV_ACTION_FRAME_TX_REQ");
    return t2lm_handle_tx_req(a1, a2, a4, a6, v65, v66, v67, v68, v69, v70, v71, v72);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: T2LM event received: %s(%d)",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "t2lm_deliver_event",
      "WLAN_T2LM_EV_ACTION_FRAME_RX_RESP");
    return t2lm_handle_rx_resp(a1, a2, a4, a5, v31, v32, v33, v34, v35, v36, v37, v38);
  }
}
