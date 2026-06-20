__int64 __fastcall wlan_cp_stats_vdev_obj_destroy_handler(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x0
  void (__fastcall *v15)(_QWORD); // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v25; // x2

  if ( !a1 || (comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x1Bu)) == 0 )
  {
    v25 = "%s: vdev is NULL";
LABEL_13:
    qdf_trace_msg(0x62u, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_vdev_obj_destroy_handler");
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 152);
  if ( !v11
    || (v12 = comp_private_obj, (v13 = *(_QWORD *)(v11 + 80)) == 0)
    || (v14 = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x1Bu)) == 0 )
  {
    v25 = "%s: cp_stats context is NULL!";
    goto LABEL_13;
  }
  v15 = *(void (__fastcall **)(_QWORD))(v14 + 120);
  if ( v15 )
  {
    if ( *((_DWORD *)v15 - 1) != 227644975 )
      __break(0x8228u);
    v15(v12);
  }
  wlan_objmgr_vdev_component_obj_detach(a1, 0x1Bu, v12);
  _qdf_mem_free(v12);
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: vdev cp stats object detach",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_cp_stats_vdev_obj_destroy_handler");
  return 0;
}
