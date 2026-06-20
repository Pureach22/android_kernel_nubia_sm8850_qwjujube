__int64 __fastcall lim_update_omn_ie_ch_width(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev legacy private object is NULL",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "lim_update_omn_ie_ch_width");
  *(_DWORD *)(ext_hdl + 24252) = a2;
  return wlan_mlme_update_ch_width_from_ap(ext_hdl, 1);
}
