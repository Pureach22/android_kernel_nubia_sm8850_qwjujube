__int64 __fastcall wma_set_sta_sa_query_param(
        _QWORD *a1,
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  context = _cds_get_context(53, (__int64)"wma_set_sta_sa_query_param", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
    return wmi_unified_set_sta_sa_query_param_cmd(
             *a1,
             a2,
             *(unsigned __int8 *)(context[1] + 1043LL),
             *(unsigned __int16 *)(context[1] + 1044LL));
  else
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: mac context is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_set_sta_sa_query_param");
}
