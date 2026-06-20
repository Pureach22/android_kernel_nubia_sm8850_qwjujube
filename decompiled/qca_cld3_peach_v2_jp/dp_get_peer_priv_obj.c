__int64 __fastcall dp_get_peer_priv_obj(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = wlan_objmgr_peer_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
  {
    qdf_trace_msg(0x45u, 2u, "%s: peer is null", v2, v3, v4, v5, v6, v7, v8, v9, "dp_get_peer_priv_obj");
    return 0;
  }
  return result;
}
