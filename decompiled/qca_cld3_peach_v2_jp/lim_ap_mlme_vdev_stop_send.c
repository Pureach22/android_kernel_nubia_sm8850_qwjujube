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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a11 )
  {
    if ( *(_DWORD *)(a11 + 88) != 6 )
    {
      mlme_set_notify_co_located_ap_update_rnr(*(_QWORD *)(a1 + 504), 1, a2, a3, a4, a5, a6, a7, a8, a9);
      lim_ap_mlme_vdev_rnr_notify(a11, v12, v13, v14, v15, v16, v17, v18, v19);
      lim_configure_fd_for_existing_6ghz_sap(a11, 0);
    }
    return lim_send_vdev_stop(a11);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: data is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "lim_ap_mlme_vdev_stop_send");
    return 4;
  }
}
