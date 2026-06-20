__int64 __fastcall wlan_ser_is_vdev_queue_enabled(__int64 a1)
{
  __int64 vdev_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  vdev_obj = wlan_serialization_get_vdev_obj(a1);
  if ( vdev_obj )
  {
    v10 = *(_BYTE *)(wlan_serialization_get_vdev_queue_obj(vdev_obj, 1) + 48) ^ 1;
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_vdev_obj",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_ser_is_vdev_queue_enabled");
    v10 = 0;
  }
  return v10 & 1;
}
