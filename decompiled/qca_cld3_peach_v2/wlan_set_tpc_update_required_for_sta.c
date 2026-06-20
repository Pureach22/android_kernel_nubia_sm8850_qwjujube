__int64 __fastcall wlan_set_tpc_update_required_for_sta(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 )
  {
    v13 = *(_QWORD *)(v10 + 80);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 2800);
      if ( v14 )
      {
        v15 = *(_QWORD *)(v14 + 16);
        if ( v15 )
        {
          if ( (wmi_service_enabled(v15, 0x150u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
            return 0;
        }
      }
    }
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 1 )
    {
      *(_BYTE *)(ext_hdl + 24568) = a2 & 1;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Set change scc power as %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_set_tpc_update_required_for_sta",
        a2 & 1);
      return 0;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid mode %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_set_tpc_update_required_for_sta");
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_set_tpc_update_required_for_sta");
    return 4;
  }
}
