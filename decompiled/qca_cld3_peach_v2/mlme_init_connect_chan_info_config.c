__int64 __fastcall mlme_init_connect_chan_info_config(
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
  __int64 v9; // x0
  __int64 v10; // x19

  v9 = *(_QWORD *)(a1 + 536);
  if ( v9 )
  {
    v10 = v9 + 20480;
    *(_QWORD *)(v9 + 24248) = 0x800000008LL;
    wlan_mlme_update_ch_width_from_ap();
    *(_QWORD *)(v10 + 3780) = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlme_init_connect_chan_info_config");
    return 16;
  }
}
