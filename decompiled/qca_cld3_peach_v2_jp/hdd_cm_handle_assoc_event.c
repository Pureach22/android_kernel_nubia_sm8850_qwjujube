__int64 __fastcall hdd_cm_handle_assoc_event(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x20
  __int64 link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7

  context = _cds_get_context(51, (__int64)"hdd_cm_handle_assoc_event", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: hdd_ctx is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "hdd_cm_handle_assoc_event");
  v21 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is NULL for vdev %d",
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             "hdd_cm_handle_assoc_event",
             *(unsigned __int8 *)(a1 + 104));
  v31 = link_info_by_vdev;
  if ( (unsigned int)hdd_objmgr_set_peer_mlme_state(*(_QWORD *)(link_info_by_vdev + 32), 4) )
  {
    if ( a2 )
    {
      v40 = *a2;
      v41 = a2[1];
      v42 = a2[2];
      v43 = a2[5];
    }
    else
    {
      v42 = 0;
      v40 = 0;
      v41 = 0;
      v43 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Peer object %02x:%02x:%02x:**:**:%02x fail to set associated state",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_cm_handle_assoc_event",
      v40,
      v41,
      v42,
      v43);
  }
  v45 = hdd_convert_cfgdot11mode_to_80211mode(*(_DWORD *)(v31 + 680));
  ucfg_dp_add_latency_critical_client(a1, v45, v46, v47, v48, v49, v50, v51, v52, v53);
  ucfg_dp_bus_bw_compute_prev_txrx_stats(a1, v54, v55, v56, v57, v58, v59, v60, v61);
  return ucfg_dp_bus_bw_compute_timer_start(*v21, v62, v63, v64, v65, v66, v67, v68, v69);
}
