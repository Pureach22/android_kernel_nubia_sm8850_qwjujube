__int64 __fastcall lim_ap_mlme_vdev_restart_send(
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
  char is_hidden_ssid_restart_in_progress; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0

  if ( a11 )
  {
    is_hidden_ssid_restart_in_progress = ap_mlme_is_hidden_ssid_restart_in_progress(
                                           *(_QWORD *)(a1 + 520),
                                           a2,
                                           a3,
                                           a4,
                                           a5,
                                           a6,
                                           a7,
                                           a8,
                                           a9);
    v21 = *(_QWORD *)(a11 + 8608);
    if ( (is_hidden_ssid_restart_in_progress & 1) != 0 )
      lim_send_vdev_restart(v13, v14, v15, v16, v17, v18, v19, v20, v21, a11);
    else
      lim_send_switch_chnl_params(v21, a11, v13, v14, v15, v16, v17, v18, v19, v20);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: data is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "lim_ap_mlme_vdev_restart_send");
    return 4;
  }
}
