__int64 __fastcall wma_vdev_get_dtim_period(
        unsigned __int8 a1,
        _BYTE *a2,
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
  __int64 v13; // x8

  context = _cds_get_context(54, (__int64)"wma_vdev_get_dtim_period", a3, a4, a5, a6, a7, a8, a9, a10);
  *a2 = 0;
  if ( !context )
    return 16;
  v13 = context[65] + 488LL * a1;
  if ( !v13 )
    return 16;
  *a2 = *(_BYTE *)(v13 + 178);
  return 0;
}
