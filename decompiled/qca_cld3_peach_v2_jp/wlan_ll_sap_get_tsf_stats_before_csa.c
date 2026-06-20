__int64 __fastcall wlan_ll_sap_get_tsf_stats_before_csa(
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
  unsigned int v10; // w20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21

  if ( a1 && a2 )
  {
    v10 = *(unsigned __int8 *)(a2 + 104);
    result = ll_lt_sap_get_tsf_stats_for_csa();
    if ( (_DWORD)result )
    {
      v20 = result;
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: vdev %d get next_sp_start_tsf and curr_tsf failed",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_ll_sap_get_tsf_stats_before_csa",
        v10);
      wlan_ll_sap_notify_chan_switch_started();
      wlan_ll_sap_send_continue_vdev_restart();
      return v20;
    }
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: psoc or vdev is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_ll_sap_get_tsf_stats_before_csa");
    return 16;
  }
  return result;
}
