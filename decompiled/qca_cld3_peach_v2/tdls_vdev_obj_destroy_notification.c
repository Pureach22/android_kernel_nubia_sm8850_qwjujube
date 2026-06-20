__int64 __fastcall tdls_vdev_obj_destroy_notification(
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
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w21
  const char *v30; // x2
  __int64 v32; // x22
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  __int64 v43; // x1
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  void (__fastcall *v53)(_QWORD); // x8

  qdf_trace_msg(
    0,
    8u,
    "%s: tdls vdev mode %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_vdev_obj_destroy_notification",
    *(unsigned int *)(a1 + 16));
  if ( (*(_DWORD *)(a1 + 16) | 2) != 2 )
    return 0;
  if ( !a1 )
  {
    v30 = "%s: NULL vdev";
    goto LABEL_11;
  }
  v18 = *(_QWORD *)(a1 + 216);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    v30 = "%s: can't get psoc";
LABEL_11:
    qdf_trace_msg(0, 2u, v30, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v19, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_12:
    v29 = 2;
    qdf_trace_msg(
      0,
      2u,
      "%s: get soc by vdev failed",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tdls_vdev_obj_destroy_notification");
    return v29;
  }
  if ( (*(_BYTE *)(comp_private_obj + 156) & 0x20) != 0 )
  {
    v32 = comp_private_obj;
    v33 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    if ( v33 )
    {
      v42 = v33;
      if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v34, v35, v36, v37, v38, v39, v40, v41) & 1) != 0 )
      {
        if ( (unsigned int)qdf_mc_timer_get_current_state(v42 + 560) != 19 )
          qdf_mc_timer_stop(v42 + 560);
        v44 = *(_QWORD *)(v42 + 952);
        if ( v44 )
        {
          _qdf_mem_free(v44);
          *(_QWORD *)(v42 + 952) = 0;
        }
      }
      qdf_event_destroy(v42 + 1000, v43);
      qdf_mc_timer_stop_sync(v42 + 392);
      qdf_mc_timer_stop_sync(v42 + 560);
      qdf_mc_timer_destroy(v42 + 392);
      qdf_mc_timer_destroy(v42 + 560);
      _qdf_mem_free(*(_QWORD *)(v42 + 952));
      *(_QWORD *)(v42 + 952) = 0;
      tdls_peer_idle_timers_destroy(v42);
      tdls_free_peer_list(v42);
      v29 = wlan_objmgr_vdev_component_obj_detach(a1, 0xAu, v42);
      if ( v29 )
        qdf_trace_msg(
          0,
          2u,
          "%s: Failed to detach vdev tdls component",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "tdls_vdev_obj_destroy_notification");
      v53 = *(void (__fastcall **)(_QWORD))(v32 + 600);
      if ( v53 )
      {
        if ( *((_DWORD *)v53 - 1) != 1458356883 )
          __break(0x8228u);
        v53(a1);
      }
      _qdf_mem_free(v42);
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to get tdls vdev object",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "tdls_vdev_obj_destroy_notification");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: disabled in ini",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tdls_vdev_obj_destroy_notification");
    return 11;
  }
  return v29;
}
