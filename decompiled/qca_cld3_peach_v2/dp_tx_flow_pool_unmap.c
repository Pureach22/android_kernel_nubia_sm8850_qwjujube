__int64 __fastcall dp_tx_flow_pool_unmap(
        __int64 a1,
        char a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0

  if ( a2 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_flow_pool_unmap");
  v11 = *(_QWORD *)(a1 + 72);
  if ( !v11 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_flow_pool_unmap");
  else
    return dp_tx_flow_pool_unmap_handler(v11, a3, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
