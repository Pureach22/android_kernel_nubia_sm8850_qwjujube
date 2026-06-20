__int64 __fastcall wlan_objmgr_vdev_mlo_dev_ctxt_attach(
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
  __int64 v9; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v9 = *(_QWORD *)(a1 + 152);
  if ( v9 && *(_QWORD *)(v9 + 80) )
    return 0;
  qdf_trace_msg(
    0x57u,
    2u,
    "%s: Failed to get psoc",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_objmgr_vdev_mlo_dev_ctxt_attach");
  wlan_objmgr_vdev_obj_delete(a1, v12, v13, v14, v15, v16, v17, v18, v19);
  return 16;
}
