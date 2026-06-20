__int64 __fastcall dp_mon_ops_register_cmn_2_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8

  v11 = *(_QWORD *)(result + 416);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: tx 2.0 ops registration failed",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_ops_register_cmn_2_0",
             v9,
             v10);
  *(_QWORD *)(v11 + 672) = dp_mon_filter_alloc_2_0;
  *(_QWORD *)(v11 + 680) = dp_mon_filter_dealloc_2_0;
  return result;
}
