__int64 __fastcall wlan_serialization_vdev_destroy_handler(__int64 a1)
{
  __int64 vdev_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w20
  __int64 v13; // x8
  __int64 v14; // x2

  vdev_obj = wlan_serialization_get_vdev_obj(a1);
  if ( vdev_obj )
  {
    v11 = vdev_obj;
    v12 = wlan_objmgr_vdev_component_obj_detach(a1, 2u, vdev_obj);
    wlan_serialization_cleanup_vdev_timers(a1);
    wlan_serialization_destroy_vdev_list(v11 + 24);
    wlan_serialization_destroy_vdev_list(v11);
    v13 = *(_QWORD *)(a1 + 216);
    if ( v13 )
      v14 = *(_QWORD *)(v13 + 80);
    else
      v14 = 0;
    wlan_minidump_remove(v11, 56, v14, 59, "wlan_ser_vdev_obj");
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: ser_vdev_obj NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_vdev_destroy_handler");
    return 4;
  }
  return v12;
}
