__int64 __fastcall wifi_pos_get_pasn_peer_count(__int64 a1)
{
  __int64 vdev_priv_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a1);
  if ( vdev_priv_obj )
    return *(unsigned __int8 *)(vdev_priv_obj + 12264);
  qdf_trace_msg(
    0x25u,
    2u,
    "%s: Wifi pos vdev priv obj is null",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "wifi_pos_get_pasn_peer_count");
  return 0;
}
