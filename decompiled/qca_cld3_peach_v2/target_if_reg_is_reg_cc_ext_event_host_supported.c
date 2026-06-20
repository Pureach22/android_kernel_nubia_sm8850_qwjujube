bool __fastcall target_if_reg_is_reg_cc_ext_event_host_supported(
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
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 2128);
    if ( v11 )
      return *(_QWORD *)(v11 + 872) != 0;
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: tx_ops is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_regulatory_get_tx_ops",
    v9,
    v10);
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: reg_tx_ops is NULL",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "target_if_reg_is_reg_cc_ext_event_host_supported");
  return 0;
}
