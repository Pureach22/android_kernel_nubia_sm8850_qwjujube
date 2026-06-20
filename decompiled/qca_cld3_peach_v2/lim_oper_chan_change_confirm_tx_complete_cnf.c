__int64 __fastcall lim_oper_chan_change_confirm_tx_complete_cnf(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11)
{
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tx_complete: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_oper_chan_change_confirm_tx_complete_cnf",
    a11);
  if ( a10 )
    _qdf_nbuf_free(a10);
  return 0;
}
