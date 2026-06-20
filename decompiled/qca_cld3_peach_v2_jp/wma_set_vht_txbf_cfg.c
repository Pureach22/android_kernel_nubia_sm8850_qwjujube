_QWORD *__fastcall wma_set_vht_txbf_cfg(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  result = _cds_get_context(54, (__int64)"wma_set_vht_txbf_cfg", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    result = (_QWORD *)wma_vdev_set_param(
                         *result,
                         a2,
                         45,
                         *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2623LL)
                       | (2 * *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2668LL))
                       | (4 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2622LL)));
    if ( (_DWORD)result )
      return (_QWORD *)qdf_trace_msg(
                         0x36u,
                         2u,
                         "%s: failed to set VHT TXBF(status = %d)",
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         "wma_set_vht_txbf_cfg",
                         (unsigned int)result);
  }
  return result;
}
