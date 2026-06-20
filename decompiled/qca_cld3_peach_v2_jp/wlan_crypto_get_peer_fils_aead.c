__int64 __fastcall wlan_crypto_get_peer_fils_aead(
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
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
      return *(unsigned __int8 *)(comp_private_obj + 424);
    v11 = "%s: crypto_priv NULL";
  }
  else
  {
    v11 = "%s: Invalid Input";
  }
  qdf_trace_msg(0x1Cu, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_get_peer_fils_aead");
  return 0;
}
