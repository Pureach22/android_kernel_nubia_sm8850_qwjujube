__int64 __fastcall mlo_link_recfg_send_request_frame(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int16 v11; // w8
  unsigned __int8 v13; // w8
  __int64 v14; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v16; // x21
  __int64 v17; // x20
  unsigned int v18; // w23
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
  __int64 v35; // x24
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  __int64 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v55[4]; // [xsp+10h] [xbp-20h] BYREF

  v55[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v55, 0, 24);
  v54 = 0;
  if ( !a2 )
  {
    v44 = "%s: Link recfg req is null";
LABEL_15:
    qdf_trace_msg(0x8Fu, 2u, v44, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_link_recfg_send_request_frame");
    result = 29;
    goto LABEL_16;
  }
  if ( !a1 )
  {
    v44 = "%s: Link recfg ctx is null";
    goto LABEL_15;
  }
  v11 = *(unsigned __int8 *)(a1 + 3460);
  LOWORD(v55[0]) = 2853;
  if ( ((v11 + 1) & 0x100) != 0 )
    v13 = 1;
  else
    v13 = v11 + 1;
  *(_BYTE *)(a1 + 3460) = v13;
  *(_BYTE *)(a2 + 256) = v13;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: gen dialog token %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_link_recfg_dialog_token",
    v13);
  v14 = *(_QWORD *)a1;
  HIDWORD(v55[0]) = *(unsigned __int8 *)(a2 + 256);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v14, (_BYTE *)(a2 + 257), 0x5Au);
  if ( !peer_by_mac )
  {
    v44 = "%s: Peer is null";
    goto LABEL_15;
  }
  v16 = peer_by_mac[12];
  if ( !v16 )
  {
    v44 = "%s: Vdev is null";
    goto LABEL_15;
  }
  v17 = (__int64)peer_by_mac;
  v18 = lim_send_link_recfg_action_req_frame(
          *(unsigned __int8 *)(v16 + 168),
          (unsigned __int8 *)(a2 + 257),
          (__int64)v55,
          a2);
  if ( v18 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to send Link Reconfiguration action request frame",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "mlo_link_recfg_send_request_frame");
    v35 = *(_QWORD *)(v16 + 1360);
    v54 = v18;
    if ( v35 )
    {
      qdf_mutex_acquire(*(_QWORD *)(v35 + 3888) + 760LL);
      wlan_sm_dispatch(
        *(_QWORD *)(*(_QWORD *)(v35 + 3888) + 824LL),
        7u,
        4u,
        (__int64)&v54,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43);
      qdf_mutex_release(*(_QWORD *)(v35 + 3888) + 760LL);
    }
  }
  else if ( (unsigned int)qdf_mc_timer_start(a1 + 3288, 0x1388u) )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to start the timer",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "mlo_link_recfg_send_request_frame");
  }
  if ( *(unsigned __int8 *)(a1 + 288) != 255 && *(_DWORD *)(a1 + 284) == 4 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: no comm link recfg_type %d join_pending_vdev_id %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "mlo_link_recfg_is_no_comm",
      4);
    wlan_mlo_send_vdev_pause(*(_QWORD *)a1, v46, v47, v48, v49, v50, v51, v52, v53);
  }
  wlan_objmgr_peer_release_ref(v17, 0x5Au, v27, v28, v29, v30, v31, v32, v33, v34);
  result = v18;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
