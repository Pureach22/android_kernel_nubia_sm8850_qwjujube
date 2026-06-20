void *__fastcall dp_clear_cfr_dbg_stats(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8

  if ( a2 )
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: dp pdev is NULL",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "dp_clear_cfr_dbg_stats");
  v10 = *(_QWORD *)(a1 + 72);
  if ( !v10 )
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: dp pdev is NULL",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "dp_clear_cfr_dbg_stats");
  else
    return qdf_mem_set((void *)(v10 + 94208), 0x68u, 0);
}
