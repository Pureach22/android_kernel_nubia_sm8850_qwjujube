__int64 __fastcall lim_disassoc_tx_complete_cnf(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(0x35u, 8u, "%s: tx_success: %d", a3, a4, a5, a6, a7, a8, a9, a10, "lim_disassoc_tx_complete_cnf", a2);
  lim_send_disassoc_cnf(a1);
  return 0;
}
