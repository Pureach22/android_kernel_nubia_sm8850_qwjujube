bool __fastcall wlan_crypto_peer_has_auth_mode(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int authmode; // w8
  _BOOL8 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
  {
    authmode = wlan_crypto_get_authmode(comp_private_obj);
    result = (authmode & a2) != 0;
    if ( authmode != -1 )
      return result;
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_crypto_peer_get_comp_params");
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_params NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_crypto_get_peer_param");
  }
  return 0;
}
