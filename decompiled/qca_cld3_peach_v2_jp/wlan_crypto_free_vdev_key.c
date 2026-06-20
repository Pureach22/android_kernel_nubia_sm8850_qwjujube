__int64 __fastcall wlan_crypto_free_vdev_key(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
    return wlan_crypto_free_key(comp_private_obj + 288, v2, v3, v4, v5, v6, v7, v8, v9);
  else
    return qdf_trace_msg(0x1Cu, 2u, "%s: crypto_priv NULL", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_crypto_free_vdev_key");
}
