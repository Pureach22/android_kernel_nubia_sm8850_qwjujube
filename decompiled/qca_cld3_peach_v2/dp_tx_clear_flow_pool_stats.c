void *__fastcall dp_tx_clear_flow_pool_stats(
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
  if ( a1 )
    return qdf_mem_set((void *)(a1 + 12928), 6u, 0);
  else
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: soc is null",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "dp_tx_clear_flow_pool_stats");
}
