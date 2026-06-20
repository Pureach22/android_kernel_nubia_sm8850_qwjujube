__int64 __fastcall wma_update_tx_send_params(
        unsigned __int64 *a1,
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a2 > 0xB )
  {
    __break(1u);
    return cdp_display_stats(a1);
  }
  else
  {
    *a1 = *a1 & 0xFFE07FFFF00000FFLL
        | (256LL << rate_mcs[4 * a2]) & 0xFFF00
        | (((1LL << rate_pream[4 * a2]) & 0x1F) << 47)
        | 0x100000;
    return qdf_trace_msg(
             0x36u,
             8u,
             "%s: rate_id: %d, mcs: %0x, nss: %0x, preamble: %0x",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_update_tx_send_params",
             v10,
             v11);
  }
}
