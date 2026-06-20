__int64 __fastcall mlme_vdev_obj_destroy_handler(
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
  __int64 cmpt_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x20
  __int64 v21; // x21
  __int64 v22; // x1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2

  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 2u, "%s:  VDEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "mlme_vdev_obj_destroy_handler");
    return 16;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj )
  {
    v32 = "%s: VDEV MLME component object is NULL";
    goto LABEL_9;
  }
  v19 = *(_QWORD *)(a1 + 152);
  if ( !v19 || (v20 = *(_QWORD *)(v19 + 80)) == 0 )
  {
    v32 = "%s: PSOC object is NULL";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v32, v11, v12, v13, v14, v15, v16, v17, v18, "mlme_vdev_obj_destroy_handler");
    return 0;
  }
  v21 = cmpt_obj;
  timer_delete_sync(cmpt_obj + 936);
  wlan_cm_deinit(v21, v22);
  mlme_vdev_sm_destroy(v21);
  mlme_vdev_ops_ext_hdl_destroy();
  wlan_objmgr_vdev_component_obj_detach(a1, 0, v21);
  wlan_minidump_remove(v23, v24, v25, v26, v27, v28, v29, v30, v21, 1008, v20);
  _qdf_mem_free(v21);
  return 0;
}
