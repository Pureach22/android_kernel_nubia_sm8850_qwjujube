__int64 __fastcall wifi_pos_vdev_created_notification(__int64 a1)
{
  __int64 v2; // x0
  _BYTE *v3; // x19
  unsigned int v4; // w0
  unsigned int v5; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v2 = _qdf_mem_malloc(0x2FECu, "wifi_pos_vdev_created_notification", 1129);
  if ( !v2 )
    return 2;
  v3 = (_BYTE *)v2;
  v4 = wlan_objmgr_vdev_component_obj_attach(a1, 9u, v2, 0);
  if ( v4 )
  {
    v5 = v4;
    _qdf_mem_free((__int64)v3);
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Wifi pos vdev attach failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wifi_pos_vdev_created_notification");
    return v5;
  }
  else
  {
    wifi_pos_init_11az_context(v3);
    return 0;
  }
}
