__int64 __fastcall hal_rx_get_ppdu_id_be(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x20

  v8 = jiffies;
  if ( hal_rx_get_ppdu_id_be___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x46u,
      1u,
      "%s: PPDU_ID is not subscribed check build flags",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "hal_rx_get_ppdu_id_be");
    hal_rx_get_ppdu_id_be___last_ticks = v8;
  }
  return 0;
}
