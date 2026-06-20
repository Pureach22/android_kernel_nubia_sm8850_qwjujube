__int64 __fastcall wlan_crypto_set_peer_param(__int64 a1, int a2, unsigned int a3)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
    return wlan_crypto_set_param(comp_private_obj, a2, a3, v6, v7, v8, v9, v10, v11, v12, v13);
  qdf_trace_msg(
    0x1Cu,
    2u,
    "%s: crypto_priv NULL",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_crypto_peer_get_comp_params");
  qdf_trace_msg(0x1Cu, 2u, "%s: crypto_priv NULL", v15, v16, v17, v18, v19, v20, v21, v22, "wlan_crypto_set_peer_param");
  return 4;
}
