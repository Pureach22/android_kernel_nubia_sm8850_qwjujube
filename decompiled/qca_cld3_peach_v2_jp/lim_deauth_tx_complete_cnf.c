__int64 __fastcall lim_deauth_tx_complete_cnf(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w21

  qdf_trace_msg(0x35u, 8u, "%s: tx_success: %d", a4, a5, a6, a7, a8, a9, a10, a11, "lim_deauth_tx_complete_cnf", a2);
  if ( a3 )
    v13 = *(unsigned __int8 *)(a3 + 10);
  else
    v13 = 255;
  _qdf_mem_free(a3);
  return lim_send_deauth_cnf(a1, v13);
}
