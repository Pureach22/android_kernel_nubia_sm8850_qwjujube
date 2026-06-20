__int64 __fastcall wlan_vdev_mlme_sm_deliver_evt_sync(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  const char *v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( comp_private_obj )
      return mlme_vdev_sm_deliver_event(comp_private_obj, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    v17 = "%s:  MLME component object is NULL";
  }
  else
  {
    v17 = "%s: vdev is NULL";
  }
  qdf_trace_msg(0x68u, 2u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_vdev_mlme_get_cmpt_obj");
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev component object is NULL",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_vdev_mlme_sm_deliver_evt_sync");
  return 16;
}
