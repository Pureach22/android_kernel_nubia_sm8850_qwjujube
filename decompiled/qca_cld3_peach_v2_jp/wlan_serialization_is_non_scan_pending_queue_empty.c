bool __fastcall wlan_serialization_is_non_scan_pending_queue_empty(__int64 a1)
{
  __int64 vdev_from_cmd; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 vdev_obj; // x0

  vdev_from_cmd = wlan_serialization_get_vdev_from_cmd(a1);
  if ( vdev_from_cmd )
  {
    vdev_obj = wlan_serialization_get_vdev_obj(vdev_from_cmd);
    return qdf_list_empty((_QWORD *)(vdev_obj + 24));
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: vdev object  is invalid",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_serialization_is_non_scan_pending_queue_empty");
    return 0;
  }
}
