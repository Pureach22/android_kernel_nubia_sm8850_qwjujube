__int64 __fastcall wlan_cp_stats_peer_obj_destroy_handler(
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
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x20
  __int64 v15; // x0
  void (__fastcall *v16)(_QWORD); // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v26; // x2

  if ( !a1 || (comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 0x1Bu)) == 0 )
  {
    v26 = "%s: peer is NULL";
LABEL_14:
    qdf_trace_msg(0x62u, 2u, v26, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_peer_obj_destroy_handler");
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 96);
  if ( !v11
    || (v12 = *(_QWORD *)(v11 + 216)) == 0
    || (v13 = *(_QWORD *)(v12 + 80)) == 0
    || (v14 = comp_private_obj, (v15 = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x1Bu)) == 0) )
  {
    v26 = "%s: cp_stats context is NULL!";
    goto LABEL_14;
  }
  v16 = *(void (__fastcall **)(_QWORD))(v15 + 136);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != 1742559037 )
      __break(0x8228u);
    v16(v14);
  }
  wlan_objmgr_peer_component_obj_detach(a1, 0x1Bu, v14);
  _qdf_mem_free(v14);
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: peer cp stats object detached",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_cp_stats_peer_obj_destroy_handler");
  return 0;
}
