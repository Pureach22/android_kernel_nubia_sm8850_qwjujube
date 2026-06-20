bool __fastcall wlan_crypto_is_htallowed(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  const char *v20; // x3
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int ucastciphers; // w0

  if ( !(a1 | a2) )
    goto LABEL_13;
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( !comp_private_obj )
    {
      v19 = "%s: crypto_priv NULL";
      v20 = "wlan_crypto_get_param";
LABEL_12:
      qdf_trace_msg(0x1Cu, 2u, v19, v11, v12, v13, v14, v15, v16, v17, v18, v20);
      goto LABEL_13;
    }
  }
  else
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a2, 14);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_priv NULL",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_crypto_peer_get_comp_params");
      v19 = "%s: crypto_params NULL";
      v20 = "wlan_crypto_get_peer_param";
      goto LABEL_12;
    }
  }
  ucastciphers = wlan_crypto_get_ucastciphers(comp_private_obj);
  if ( ucastciphers == -1 )
  {
LABEL_13:
    qdf_trace_msg(0x1Cu, 2u, "%s: Invalid params", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_is_htallowed");
    return 0;
  }
  if ( (ucastciphers & 1) != 0 )
    return 1;
  if ( (ucastciphers & 0x60A) == 2 )
    return (ucastciphers & 0x80) == 0;
  return 0;
}
