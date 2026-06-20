__int64 __fastcall wlan_set_sap_user_config_freq(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 ext_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 1 )
    {
      v21 = ext_hdl;
      *(_DWORD *)(v21 + 24564) = a2;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Cannot set user config freq for mode %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_set_sap_user_config_freq");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_set_sap_user_config_freq");
    return 4;
  }
}
