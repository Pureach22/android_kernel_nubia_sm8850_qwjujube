__int64 __fastcall wlan_crypto_peer_obj_create_handler(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  __int64 v15; // x0

  if ( !a1 )
    return 4;
  v2 = _qdf_mem_malloc(0x1C0u, "wlan_crypto_peer_obj_create_handler", 652);
  if ( !v2 )
    return 2;
  v3 = (_QWORD *)v2;
  v4 = wlan_objmgr_peer_component_obj_attach(a1, 14, v2, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: peer obj failed status %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_crypto_peer_obj_create_handler",
      v4);
    _qdf_mem_free((__int64)v3);
    return v13;
  }
  else
  {
    v3[1] = 0;
    v3[2] = 0;
    *v3 = 0;
    v15 = *(_QWORD *)(a1 + 96);
    if ( *(_QWORD *)(v15 + 176) != a1 )
      wlan_crypto_set_peer_wep_keys(v15, a1, v5, v6, v7, v8, v9, v10, v11, v12);
    return 0;
  }
}
