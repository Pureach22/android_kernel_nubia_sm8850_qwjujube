__int64 __fastcall wlan_crypto_get_default_key_idx(__int64 a1, char a2)
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

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
  {
    if ( (a2 & 1) != 0 )
      return *(unsigned __int8 *)(comp_private_obj + 421);
    else
      return *(unsigned __int8 *)(comp_private_obj + 420);
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
      "wlan_crypto_get_default_key_idx");
    return 16;
  }
}
