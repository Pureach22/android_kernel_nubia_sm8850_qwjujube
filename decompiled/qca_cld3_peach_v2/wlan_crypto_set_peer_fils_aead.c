__int64 __fastcall wlan_crypto_set_peer_fils_aead(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  const char *v12; // x2

  if ( a1 )
  {
    result = wlan_objmgr_peer_get_comp_private_obj(a1, 14);
    if ( result )
    {
      *(_BYTE *)(result + 424) = a2;
      return result;
    }
    v12 = "%s: crypto_priv NULL";
  }
  else
  {
    v12 = "%s: Invalid Input";
  }
  return qdf_trace_msg(0x1Cu, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_set_peer_fils_aead");
}
