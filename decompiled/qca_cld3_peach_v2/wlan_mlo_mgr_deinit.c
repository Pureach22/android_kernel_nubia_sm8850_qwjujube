__int64 wlan_mlo_mgr_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 mlo_ctx; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  const char *v27; // x2
  __int64 v28; // x19
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  if ( !wlan_objmgr_get_mlo_ctx() )
  {
    v26 = 16;
    v27 = "%s: MLO global object is not allocated";
LABEL_18:
    qdf_trace_msg(0x8Fu, 2u, v27, v0, v1, v2, v3, v4, v5, v6, v7, "wlan_mlo_mgr_deinit");
    return v26;
  }
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: global mlo mgr not initialized",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "mlo_mgr_unregister_link_switch_notifier");
    v17 = wlan_objmgr_get_mlo_ctx();
    if ( !v17 )
      goto LABEL_14;
    goto LABEL_9;
  }
  if ( *(_BYTE *)(mlo_ctx + 1024) == 1 )
  {
    *(_BYTE *)(mlo_ctx + 1024) = 0;
    *(_QWORD *)(mlo_ctx + 1032) = 0;
  }
  v17 = wlan_objmgr_get_mlo_ctx();
  if ( v17 )
  {
LABEL_9:
    v28 = v17;
    v29 = qdf_list_empty((_QWORD *)(v17 + 192));
    if ( (v29 & 1) != 0 )
      v29 = qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: ML dev list is not empty",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "mlo_global_ctx_deinit");
    mlo_msgq_free(v29);
    qdf_mutex_destroy(v28 + 128);
    qdf_mutex_destroy(v28);
    qdf_mutex_destroy(v28 + 64);
    if ( *(_DWORD *)(v28 + 208) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "qdf_list_destroy");
    _qdf_mem_free(v28);
    wlan_objmgr_set_mlo_ctx(0);
  }
LABEL_14:
  if ( (unsigned int)wlan_objmgr_unregister_vdev_create_handler(
                       0x28u,
                       (__int64)wlan_mlo_mgr_vdev_created_notification,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25) )
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to unregister vdev create handler",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_mlo_mgr_deinit");
  v26 = wlan_objmgr_unregister_vdev_destroy_handler(
          0x28u,
          (__int64)wlan_mlo_mgr_vdev_destroyed_notification,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53);
  if ( v26 )
  {
    v27 = "%s: Failed to unregister vdev delete handler";
    goto LABEL_18;
  }
  return v26;
}
