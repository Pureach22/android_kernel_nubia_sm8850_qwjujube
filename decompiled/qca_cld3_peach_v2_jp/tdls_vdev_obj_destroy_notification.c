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
  __int64 v34; // x1
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x20
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  void (__fastcall *v52)(_QWORD); // x8

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
  v18 = *(_QWORD *)(a1 + 152);
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
      v43 = v33;
      qdf_event_destroy(v33 + 1000, v34);
      qdf_mc_timer_stop_sync(v43 + 392);
      qdf_mc_timer_stop_sync(v43 + 560);
      qdf_mc_timer_destroy(v43 + 392);
      qdf_mc_timer_destroy(v43 + 560);
      _qdf_mem_free(*(_QWORD *)(v43 + 952));
      *(_QWORD *)(v43 + 952) = 0;
      tdls_peer_idle_timers_destroy(v43);
      tdls_free_peer_list(v43);
      v29 = wlan_objmgr_vdev_component_obj_detach(a1, 0xAu, v43);
      if ( v29 )
        qdf_trace_msg(
          0,
          2u,
          "%s: Failed to detach vdev tdls component",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "tdls_vdev_obj_destroy_notification");
      v52 = *(void (__fastcall **)(_QWORD))(v32 + 592);
      if ( v52 )
      {
        if ( *((_DWORD *)v52 - 1) != 1458356883 )
          __break(0x8228u);
        v52(a1);
      }
      _qdf_mem_free(v43);
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to get tdls vdev object",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
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
