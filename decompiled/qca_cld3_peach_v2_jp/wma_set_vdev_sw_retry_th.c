__int64 __fastcall wma_set_vdev_sw_retry_th(
        unsigned int a1,
        unsigned __int8 a2,
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
  _QWORD *v15; // x22
  __int64 result; // x0

  context = _cds_get_context(54, (__int64)"wma_set_vdev_sw_retry_th", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 16;
  if ( !a2 )
    return 0;
  v15 = context;
  result = ((__int64 (*)(void))wma_set_sw_retry_by_qos)();
  if ( !(_DWORD)result )
  {
    result = wma_set_sw_retry_by_qos(v15, a1, a3, 1, a2);
    if ( !(_DWORD)result )
    {
      result = wma_set_sw_retry_by_qos(v15, a1, a3, 2, a2);
      if ( !(_DWORD)result )
      {
        result = wma_set_sw_retry_by_qos(v15, a1, a3, 3, a2);
        if ( !(_DWORD)result )
          return 0;
      }
    }
  }
  return result;
}
