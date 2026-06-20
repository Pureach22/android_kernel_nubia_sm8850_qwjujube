__int64 __fastcall wlan_crypto_vdev_is_pmf_required(__int64 result)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( result )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 14);
    if ( comp_private_obj )
    {
      return (*(unsigned __int16 *)(comp_private_obj + 152) >> 6) & 1;
    }
    else
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_priv NULL",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "wlan_crypto_vdev_get_comp_params");
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_priv NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_crypto_vdev_is_pmf_required");
      return 0;
    }
  }
  return result;
}
