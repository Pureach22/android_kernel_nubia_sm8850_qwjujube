__int64 __fastcall wlan_mlme_set_ap_oper_ch_width(
        __int64 a1,
        unsigned int a2,
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

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    *(_DWORD *)(ext_hdl + 24480) = a2;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: SAP oper ch_width: %d, vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_mlme_set_ap_oper_ch_width",
      a2,
      *(unsigned __int8 *)(a1 + 104));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev %d legacy private object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_mlme_set_ap_oper_ch_width",
      *(unsigned __int8 *)(a1 + 104));
    return 16;
  }
}
