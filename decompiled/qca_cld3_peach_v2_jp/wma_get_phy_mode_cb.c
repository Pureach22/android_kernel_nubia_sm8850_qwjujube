_QWORD *__fastcall wma_get_phy_mode_cb(
        unsigned int a1,
        unsigned int a2,
        _DWORD *a3,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *result; // x0

  context = _cds_get_context(53, (__int64)"wma_get_phy_mode_cb", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    result = wma_chan_phy_mode(a1, a2, *(_DWORD *)(context[1] + 5748LL));
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: MAC context is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "wma_get_phy_mode_cb");
    result = nullptr;
  }
  *a3 = (_DWORD)result;
  return result;
}
