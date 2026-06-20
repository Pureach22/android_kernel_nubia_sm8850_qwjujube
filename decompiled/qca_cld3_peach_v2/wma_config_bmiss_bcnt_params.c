__int64 __fastcall wma_config_bmiss_bcnt_params(
        unsigned int a1,
        unsigned int a2,
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
  _QWORD *context; // x0
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19

  context = _cds_get_context(54, (__int64)"wma_config_bmiss_bcnt_params", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4;
  result = wma_roam_scan_bmiss_cnt(context, a2, a3, a1);
  if ( (_DWORD)result )
  {
    v24 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to set Bmiss Param",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_config_bmiss_bcnt_params");
    return v24;
  }
  return result;
}
