__int64 __fastcall nan_vdev_obj_destroyed_notification(
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
  int v18; // w8
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  unsigned int v29; // w19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_vdev_delete_notif called",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "nan_vdev_obj_destroyed_notification");
  v18 = *(_DWORD *)(a1 + 16);
  if ( v18 != 11 && v18 != 16 )
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: not a ndi vdev. do nothing",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "nan_vdev_obj_destroyed_notification");
    return 0;
  }
  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", v10, v11, v12, v13, v14, v15, v16, v17, "nan_get_vdev_priv_obj");
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_10:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan_obj is NULL",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "nan_vdev_obj_destroyed_notification");
    return 5;
  }
  v28 = comp_private_obj;
  v29 = wlan_objmgr_vdev_component_obj_detach(a1, 0xFu, comp_private_obj);
  if ( v29 )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan_obj detach failed",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "nan_vdev_obj_destroyed_notification");
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_obj deleted with status %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "nan_vdev_obj_destroyed_notification",
    v29);
  _qdf_mem_free(v28);
  return v29;
}
