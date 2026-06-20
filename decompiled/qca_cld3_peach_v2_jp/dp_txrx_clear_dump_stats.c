__int64 __fastcall dp_txrx_clear_dump_stats(
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
        char a11)
{
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: soc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_txrx_clear_dump_stats");
    return 4;
  }
  if ( a11 == 29 )
  {
    wlan_dp_lapb_clear_stats();
    return 0;
  }
  if ( a11 == 28 )
  {
    dp_pdev_clear_tx_delay_stats();
    return 0;
  }
  if ( a11 != 3 )
    return 4;
  dp_txrx_clear_tso_stats();
  return 0;
}
