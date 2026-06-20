_QWORD *__fastcall wma_register_packetdump_callback(
        __int64 a1,
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
  _QWORD *result; // x0

  result = _cds_get_context(54, (__int64)"wma_register_packetdump_callback", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    result[473] = a1;
    result[474] = a2;
  }
  return result;
}
