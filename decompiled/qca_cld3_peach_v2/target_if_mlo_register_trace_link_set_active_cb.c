__int64 __fastcall target_if_mlo_register_trace_link_set_active_cb(
        __int64 result,
        __int64 a2,
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
  __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( result && (v12 = *(_QWORD *)(result + 2136)) != 0 )
  {
    *(_QWORD *)(v12 + 1304) = a2;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_ops is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_mlo_get_rx_ops",
      v10,
      v11);
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: mlo_rx_ops null",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "target_if_mlo_register_trace_link_set_active_cb");
  }
  return result;
}
