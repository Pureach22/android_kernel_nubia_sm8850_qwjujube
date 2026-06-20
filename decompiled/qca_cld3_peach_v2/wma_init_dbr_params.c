__int64 __fastcall wma_init_dbr_params(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(61, (__int64)"wma_init_dbr_params", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
    return direct_buf_rx_target_attach(*(_QWORD *)(a1 + 24), context[320], *(_QWORD *)(a1 + 184));
  else
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: invalid hif context",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "wma_init_dbr_params");
}
