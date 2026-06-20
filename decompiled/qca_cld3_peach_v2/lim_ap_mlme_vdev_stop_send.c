__int64 __fastcall lim_ap_mlme_vdev_stop_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  if ( a11 )
  {
    if ( *(_WORD *)(a11 + 7184) )
    {
      v13 = *(_QWORD *)(a11 + 8608);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Remove puncture from reg: bitmap 0x%x",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "lim_remove_puncture");
      wlan_reg_remove_puncture(*(_QWORD *)(v13 + 21632), v14, v15, v16, v17, v18, v19, v20, v21);
    }
    if ( *(_DWORD *)(a11 + 88) == 6 )
      return lim_send_vdev_stop(a11);
    v22 = *(_QWORD *)(a1 + 520);
    if ( *(_DWORD *)(v22 + 16) == 1 )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(v22, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
        return lim_send_vdev_stop(a11);
      v22 = *(_QWORD *)(a1 + 520);
    }
    mlme_set_notify_co_located_ap_update_rnr(v22, 1, a2, a3, a4, a5, a6, a7, a8, a9);
    lim_ap_mlme_vdev_rnr_notify(a11, v23, v24, v25, v26, v27, v28, v29, v30);
    lim_configure_fd_for_existing_6ghz_sap(a11, 0);
    return lim_send_vdev_stop(a11);
  }
  qdf_trace_msg(0x35u, 2u, "%s: data is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "lim_ap_mlme_vdev_stop_send");
  return 4;
}
