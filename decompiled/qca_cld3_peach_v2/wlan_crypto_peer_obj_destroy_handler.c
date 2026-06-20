__int64 __fastcall wlan_crypto_peer_obj_destroy_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v21; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      v11 = comp_private_obj;
      v12 = wlan_objmgr_peer_component_obj_detach(a1, 14, comp_private_obj);
      wlan_crypto_free_key(v11 + 288, v12, v13, v14, v15, v16, v17, v18, v19);
      _qdf_mem_free(v11);
      return 0;
    }
    v21 = "%s: crypto_priv NULL";
  }
  else
  {
    v21 = "%s: Peer NULL";
  }
  qdf_trace_msg(0x1Cu, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_peer_obj_destroy_handler");
  return 4;
}
