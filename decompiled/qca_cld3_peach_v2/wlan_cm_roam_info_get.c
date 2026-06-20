__int64 __fastcall wlan_cm_roam_info_get(
        __int64 a1,
        _QWORD *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( ext_hdl )
  {
    if ( *(_DWORD *)(ext_hdl + 23600) )
    {
      *a2 = *(_QWORD *)(ext_hdl + 23592) + 1840LL * a3;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Enhanced roam stats not supported",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_cm_roam_info_get");
      return 11;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_cm_roam_info_get");
    return 4;
  }
}
