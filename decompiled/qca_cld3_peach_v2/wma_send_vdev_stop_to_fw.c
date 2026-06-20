__int64 __fastcall wma_send_vdev_stop_to_fw(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 cmpt_obj; // x0
  __int64 v32; // x20
  void *dynamic_vdev_config; // x19
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const void *ini_vdev_config; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  const char *v60; // x2

  v11 = *(_QWORD *)(a1 + 520);
  if ( (wma_is_vdev_valid(a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v21 = v11 + 488LL * a2;
    wlan_mlme_reset_sta_keepalive_period(*(_QWORD *)(a1 + 24), *(_QWORD *)v21);
    v22 = *(_QWORD *)v21;
    *(_WORD *)(v21 + 480) = 0;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v22, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( cmpt_obj )
    {
      v32 = cmpt_obj;
      dynamic_vdev_config = (void *)mlme_get_dynamic_vdev_config(*(_QWORD *)v21, v13, v14, v15, v16, v17, v18, v19, v20);
      ini_vdev_config = (const void *)mlme_get_ini_vdev_config(*(_QWORD *)v21, v34, v35, v36, v37, v38, v39, v40, v41);
      qdf_mem_copy(dynamic_vdev_config, ini_vdev_config, 0x38u);
      LODWORD(dynamic_vdev_config) = vdev_mgr_stop_send(v32, v43, v44, v45, v46, v47, v48, v49, v50);
      mlme_set_chan_switch_in_progress(*(_QWORD *)(v32 + 520), 0, v51, v52, v53, v54, v55, v56, v57, v58);
      return (unsigned int)dynamic_vdev_config;
    }
    v60 = "%s: Failed to get vdev mlme obj for vdev id %d";
  }
  else
  {
    v60 = "%s: Invalid vdev id:%d";
  }
  qdf_trace_msg(0x36u, 2u, v60, v13, v14, v15, v16, v17, v18, v19, v20, "wma_send_vdev_stop_to_fw", a2);
  return 16;
}
