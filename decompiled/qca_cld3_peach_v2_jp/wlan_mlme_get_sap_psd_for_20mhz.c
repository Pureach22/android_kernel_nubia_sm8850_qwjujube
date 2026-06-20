__int64 __fastcall wlan_mlme_get_sap_psd_for_20mhz(
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
  __int64 ext_hdl; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ext_hdl )
  {
    if ( *(_DWORD *)(a1 + 16) == 1 )
      return *(unsigned __int8 *)(ext_hdl + 24484);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid opmode %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_mlme_get_sap_psd_for_20mhz");
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_mlme_get_sap_psd_for_20mhz");
  }
  return 0;
}
