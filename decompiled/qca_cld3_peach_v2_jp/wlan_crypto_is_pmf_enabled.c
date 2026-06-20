__int64 __fastcall wlan_crypto_is_pmf_enabled(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 v15; // x0
  unsigned int v16; // w8
  const char *v17; // x3
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  result = 0;
  if ( !a1 || !a2 )
    return result;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    v17 = "wlan_crypto_vdev_get_comp_params";
LABEL_10:
    qdf_trace_msg(0x1Cu, 2u, "%s: crypto_priv NULL", v6, v7, v8, v9, v10, v11, v12, v13, v17);
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_crypto_is_pmf_enabled");
    return 0;
  }
  v14 = comp_private_obj;
  v15 = wlan_objmgr_peer_get_comp_private_obj(a2, 14);
  if ( !v15 )
  {
    v17 = "wlan_crypto_peer_get_comp_params";
    goto LABEL_10;
  }
  v16 = *(unsigned __int16 *)(v14 + 152);
  if ( (v16 & 0x80) != 0 && (*(_WORD *)(v15 + 152) & 0x80) != 0 )
    return 1;
  else
    return (v16 >> 6) & 1;
}
