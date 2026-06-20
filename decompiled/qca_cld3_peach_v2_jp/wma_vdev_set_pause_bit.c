_QWORD *__fastcall wma_vdev_set_pause_bit(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  result = _cds_get_context(54, (__int64)"wma_vdev_set_pause_bit", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    if ( !(result[65] + 488LL * a1) )
      return (_QWORD *)qdf_trace_msg(
                         0x36u,
                         2u,
                         "%s: Interface is NULL",
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         "wma_vdev_set_pause_bit");
  }
  return result;
}
