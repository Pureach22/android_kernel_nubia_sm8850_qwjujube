__int64 __fastcall dp_nud_netevent_cb(
        unsigned __int8 *a1,
        unsigned __int8 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x25
  __int64 intf_by_macaddr; // x0
  __int64 v33; // x20
  const char *v34; // x2
  unsigned int v35; // w1
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 v39; // x7
  const char *v40; // x2
  unsigned int v41; // w1
  __int64 v43; // x22
  __int64 vdev_by_user; // x0
  __int64 v45; // x23
  bool is_vdev_active; // w24
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w9
  int v57; // w10
  int v58; // w11
  int v59; // w12
  __int64 v60; // x9
  int tx_ack_count; // w0

  qdf_trace_msg(0x45u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "dp_nud_netevent_cb");
  qdf_trace_msg(0x45u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "dp_nud_filter_netevent");
  context = dp_get_context();
  if ( !context )
  {
    v34 = "%s: unable to get DP context";
    goto LABEL_6;
  }
  v31 = context;
  intf_by_macaddr = dp_get_intf_by_macaddr(context, (__int64)a1);
  if ( !intf_by_macaddr )
  {
    if ( a1 )
    {
      v36 = *a1;
      v37 = a1[1];
      v38 = a1[2];
      v39 = a1[5];
    }
    else
    {
      v38 = 0;
      v36 = 0;
      v37 = 0;
      v39 = 0;
    }
    v40 = "%s: Unable to get DP intf for MAC %02x:%02x:%02x:**:**:%02x";
    v41 = 2;
    goto LABEL_15;
  }
  v33 = intf_by_macaddr;
  if ( (unsigned int)is_dp_intf_valid(intf_by_macaddr, v23, v24, v25, v26, v27, v28, v29, v30) )
  {
    v34 = "%s: invalid dp_intf";
LABEL_6:
    v35 = 2;
LABEL_7:
    qdf_trace_msg(0x45u, v35, v34, v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_filter_netevent");
    return qdf_trace_msg(0x45u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_netevent_cb");
  }
  if ( *(_DWORD *)(v33 + 28) )
    return qdf_trace_msg(0x45u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_netevent_cb");
  if ( *(_BYTE *)(v33 + 3481) == 1 )
  {
    v34 = "%s: NUD Tracking is Disabled";
LABEL_26:
    v35 = 5;
    goto LABEL_7;
  }
  if ( (*(_BYTE *)(v33 + 3569) & 1) == 0 )
  {
    v34 = "%s: GW is not updated";
    goto LABEL_26;
  }
  v43 = *(_QWORD *)(v33 + 3664);
  vdev_by_user = _dp_objmgr_get_vdev_by_user(v43, 0x61u, (__int64)"dp_nud_filter_netevent");
  if ( !vdev_by_user )
    return qdf_trace_msg(0x45u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_netevent_cb");
  v45 = vdev_by_user;
  is_vdev_active = wlan_cm_is_vdev_active(vdev_by_user, v23, v24, v25, v26, v27, v28, v29, v30);
  _dp_objmgr_put_vdev_by_user(
    v45,
    0x61u,
    (__int64)"dp_nud_filter_netevent",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55);
  if ( !is_vdev_active )
  {
    v34 = "%s: Not in Connected State";
    goto LABEL_26;
  }
  if ( !*(_BYTE *)(v43 + 77) )
  {
    v36 = *(unsigned __int8 *)(v33 + 20);
    v37 = *(unsigned __int8 *)(v33 + 21);
    v40 = "%s: client %02x:%02x:%02x:**:**:%02x is in the middle of WPS/EAPOL exchange.";
    v38 = *(unsigned __int8 *)(v33 + 22);
    v39 = *(unsigned __int8 *)(v33 + 25);
    v41 = 5;
LABEL_15:
    qdf_trace_msg(0x45u, v41, v40, v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_filter_netevent", v36, v37, v38, v39);
    return qdf_trace_msg(0x45u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_netevent_cb");
  }
  if ( qdf_is_macaddr_equal_4(v33 + 3512, (__int64)a2) )
  {
    if ( *(_BYTE *)(v31 + 873) == 1 )
    {
      v34 = "%s: wlan is suspended, ignore NUD event";
      goto LABEL_26;
    }
    if ( (unsigned __int8)a3 > 4u )
    {
      if ( (unsigned __int8)a3 == 6 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: DP_NUD_FAILED [0x%x]",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "dp_nud_filter_netevent");
        if ( *(_BYTE *)(v33 + 3480) )
        {
          dp_nud_process_failure_event(v33);
          goto LABEL_43;
        }
        v60 = *(_QWORD *)(v33 + 2888);
        *(_DWORD *)(v33 + 3484) = *(_QWORD *)(v33 + 2896);
        *(_DWORD *)(v33 + 3492) = v60;
        tx_ack_count = dp_txrx_get_tx_ack_count(v33);
        *(_BYTE *)(v33 + 3480) = 5;
        *(_DWORD *)(v33 + 3488) = tx_ack_count;
        goto LABEL_39;
      }
      if ( (unsigned __int8)a3 != 5 )
        goto LABEL_40;
    }
    else if ( (unsigned __int8)a3 != 1 )
    {
      if ( (unsigned __int8)a3 == 2 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: DP_NUD_REACHABLE [0x%x]",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "dp_nud_filter_netevent");
        *(_BYTE *)(v33 + 3480) = 0;
        *(_DWORD *)(v33 + 3508) = 0;
        *(_BYTE *)(v33 + 3568) = 0;
LABEL_43:
        v34 = "%s: exit";
        v35 = 8;
        goto LABEL_7;
      }
LABEL_40:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Event For Other State [0x%x]",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "dp_nud_filter_netevent");
      goto LABEL_43;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: DP_NUD_START [0x%x]",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_nud_filter_netevent");
    dp_nud_capture_stats(v33, a3);
    *(_BYTE *)(v33 + 3480) = a3;
LABEL_39:
    *(_DWORD *)(v33 + 3508) = 0;
    *(_BYTE *)(v33 + 3568) = 1;
    goto LABEL_43;
  }
  if ( a2 )
  {
    v56 = *a2;
    v57 = a2[1];
    v58 = a2[2];
    v59 = a2[5];
  }
  else
  {
    v58 = 0;
    v56 = 0;
    v57 = 0;
    v59 = 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: MAC mismatch NUD state %d GW MAC %02x:%02x:%02x:**:**:%02x Event MAC %02x:%02x:%02x:**:**:%02x",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "dp_nud_filter_netevent",
    (unsigned __int8)a3,
    *(unsigned __int8 *)(v33 + 3512),
    *(unsigned __int8 *)(v33 + 3513),
    *(unsigned __int8 *)(v33 + 3514),
    *(unsigned __int8 *)(v33 + 3517),
    v56,
    v57,
    v58,
    v59);
  return qdf_trace_msg(0x45u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "dp_nud_netevent_cb");
}
