__int64 __fastcall wlan_mlme_is_chain_mask_supported(__int64 a1)
{
  __int64 result; // x0
  _BYTE *v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v3 = (_BYTE *)result;
    if ( (wlan_mlme_configure_chain_mask_supported(a1) & 1) != 0 )
    {
      if ( *v3 == 3 && v3[1] == 3 )
        return 1;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: txchainmask1x1 %d rxchainmask1x1 %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_mlme_is_chain_mask_supported");
    }
    return 0;
  }
  return result;
}
