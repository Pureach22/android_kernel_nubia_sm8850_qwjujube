__int64 __fastcall dp_fisa_config(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        unsigned __int8 **a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x0

  if ( a2 || (v12 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL for pdev_id %u", a5, a6, a7, a8, a9, a10, a11, a12, "dp_fisa_config", a2);
    return 4;
  }
  if ( a3 == 2 )
    return dp_htt_rx_flow_fst_setup(v12, *a4);
  if ( a3 != 1 )
  {
    if ( !a3 )
      return dp_htt_rx_fisa_config(v12, *a4);
    return 4;
  }
  return dp_htt_rx_flow_fse_operation(v12, *a4);
}
