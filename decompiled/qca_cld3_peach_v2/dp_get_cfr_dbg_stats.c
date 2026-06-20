void *__fastcall dp_get_cfr_dbg_stats(
        __int64 a1,
        char a2,
        void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8

  if ( a2 )
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: pdev is NULL",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "dp_get_cfr_dbg_stats");
  v11 = *(_QWORD *)(a1 + 72);
  if ( !v11 )
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: pdev is NULL",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "dp_get_cfr_dbg_stats");
  else
    return qdf_mem_copy(a3, (const void *)(v11 + 94208), 0x68u);
}
