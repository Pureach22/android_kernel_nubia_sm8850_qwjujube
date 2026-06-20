__int64 __fastcall wlan_cp_stats_pdev_obj_destroy_handler(
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
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  void (__fastcall *v14)(_QWORD); // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v24; // x2

  if ( !a1 || (comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Bu)) == 0 )
  {
    v24 = "%s: pdev is NULL";
LABEL_12:
    qdf_trace_msg(0x62u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_pdev_obj_destroy_handler");
    return 4;
  }
  v11 = comp_private_obj;
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 || (v13 = wlan_objmgr_psoc_get_comp_private_obj(v12, 0x1Bu)) == 0 )
  {
    v24 = "%s: cp_stats context is NULL!";
    goto LABEL_12;
  }
  v14 = *(void (__fastcall **)(_QWORD))(v13 + 104);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 747383827 )
      __break(0x8228u);
    v14(v11);
  }
  wlan_objmgr_pdev_component_obj_detach(a1, 0x1Bu, v11);
  _qdf_mem_free(v11);
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: pdev cp stats object detached",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlan_cp_stats_pdev_obj_destroy_handler");
  return 0;
}
