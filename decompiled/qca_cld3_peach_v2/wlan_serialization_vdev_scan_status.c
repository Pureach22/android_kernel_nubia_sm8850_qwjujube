__int64 __fastcall wlan_serialization_vdev_scan_status(__int64 a1)
{
  __int64 pdev_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  char is_cmd_in_vdev_list; // w21
  char v13; // w0
  unsigned int is_cmd_in_active_pending; // w19

  pdev_obj = wlan_serialization_get_pdev_obj(*(_QWORD *)(a1 + 216));
  if ( pdev_obj )
  {
    v11 = pdev_obj;
    wlan_serialization_acquire_lock(pdev_obj + 88);
    is_cmd_in_vdev_list = wlan_serialization_is_cmd_in_vdev_list(a1, v11, 0);
    v13 = wlan_serialization_is_cmd_in_vdev_list(a1, v11 + 24, 0);
    is_cmd_in_active_pending = wlan_serialization_is_cmd_in_active_pending(is_cmd_in_vdev_list & 1, v13 & 1);
    wlan_serialization_release_lock(v11 + 88);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_pdev_obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_vdev_scan_status");
    return 4;
  }
  return is_cmd_in_active_pending;
}
