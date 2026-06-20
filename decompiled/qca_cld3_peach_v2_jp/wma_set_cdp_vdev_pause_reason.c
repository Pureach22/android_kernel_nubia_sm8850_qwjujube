_QWORD *__fastcall wma_set_cdp_vdev_pause_reason(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 (*v18)(void); // x8

  result = _cds_get_context(71, (__int64)"wma_set_cdp_vdev_pause_reason", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !result || !*result )
    return (_QWORD *)qdf_trace_msg(
                       0x89u,
                       8u,
                       "%s: invalid instance",
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       "cdp_fc_vdev_pause");
  v17 = *(_QWORD *)(*result + 120LL);
  if ( v17 )
  {
    v18 = *(__int64 (**)(void))(v17 + 48);
    if ( v18 )
    {
      if ( *((_DWORD *)v18 - 1) != 875705606 )
        __break(0x8228u);
      return (_QWORD *)v18();
    }
  }
  return result;
}
