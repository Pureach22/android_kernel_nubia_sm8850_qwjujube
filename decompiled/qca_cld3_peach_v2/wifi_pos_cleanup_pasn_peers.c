__int64 __fastcall wifi_pos_cleanup_pasn_peers(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 vdev_priv_obj; // x0

  qdf_trace_msg(
    0x25u,
    8u,
    "%s: Iterate and delete PASN peers",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wifi_pos_cleanup_pasn_peers");
  v12 = wlan_objmgr_iterate_obj_list(a1, 3, wifi_pos_delete_objmgr_ranging_peer, a2, 0, 0xDu);
  if ( v12 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Delete objmgr peers failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_cleanup_pasn_peers");
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a2);
  if ( vdev_priv_obj )
    *(_BYTE *)(vdev_priv_obj + 12264) = 0;
  return v12;
}
