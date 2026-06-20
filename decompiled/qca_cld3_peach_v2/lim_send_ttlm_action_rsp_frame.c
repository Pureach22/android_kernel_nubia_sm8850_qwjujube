__int64 __fastcall lim_send_ttlm_action_rsp_frame(
        char a1,
        unsigned __int16 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  __int64 v15; // x23
  _QWORD *peer_by_mac; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  unsigned int v26; // w24
  _QWORD *v27; // x25
  __int64 session_by_vdev_id; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19

  context = _cds_get_context(53, (__int64)"lim_send_ttlm_action_rsp_frame", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v15 = (__int64)context;
    peer_by_mac = wlan_objmgr_get_peer_by_mac(context[2703], a3, 7u);
    if ( peer_by_mac )
    {
      v25 = peer_by_mac[12];
      if ( v25 )
      {
        v26 = *(unsigned __int8 *)(v25 + 168);
        v27 = peer_by_mac;
        session_by_vdev_id = pe_find_session_by_vdev_id(v15, *(unsigned __int8 *)(v25 + 168));
        if ( session_by_vdev_id )
        {
          if ( !(unsigned int)lim_send_t2lm_action_rsp_frame(v15, a3, session_by_vdev_id, a1, a2) )
          {
            wlan_send_peer_level_tid_to_link_mapping(v25, v27);
            ((void (__fastcall *)(__int64))wlan_connectivity_t2lm_status_event)(v25);
            peer_by_mac = v27;
            v45 = 0;
            goto LABEL_13;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: T2LM action response frame not sent",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "lim_send_ttlm_action_rsp_frame");
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: session not found for given vdev_id %d",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "lim_send_ttlm_action_rsp_frame",
            v26);
        }
        v45 = 0;
        peer_by_mac = v27;
      }
      else
      {
        v45 = 16;
      }
LABEL_13:
      wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v17, v18, v19, v20, v21, v22, v23, v24);
      return v45;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Peer is null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_send_ttlm_action_rsp_frame");
    return 16;
  }
  else
  {
    return 16;
  }
}
