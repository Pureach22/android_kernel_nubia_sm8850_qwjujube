__int64 __fastcall wlan_mlme_get_cur_ch_width_update_from_ap(
        __int64 a1,
        _DWORD *a2,
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
  const char *v21; // x2

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
  {
    v21 = "%s: vdev legacy private object is NULL";
LABEL_7:
    qdf_trace_msg(0x68u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_mlme_get_cur_ch_width_update_from_ap");
    return 0;
  }
  if ( !a2 )
  {
    v21 = "%s: invalid cur_ch_width";
    goto LABEL_7;
  }
  if ( *(_BYTE *)(ext_hdl + 24256) == 1 )
  {
    *a2 = *(_DWORD *)(ext_hdl + 24252);
    return 1;
  }
  return 0;
}
