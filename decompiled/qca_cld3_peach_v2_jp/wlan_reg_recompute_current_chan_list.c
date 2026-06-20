__int64 __fastcall wlan_reg_recompute_current_chan_list(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21

  pdev_obj = reg_get_pdev_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    v21 = pdev_obj;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Recomputing the current channel list",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_reg_recompute_current_chan_list");
    reg_compute_pdev_current_chan_list(v21);
    return reg_send_scheduler_msg_nb(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_reg_recompute_current_chan_list");
    return 16;
  }
}
