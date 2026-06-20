_QWORD *__fastcall wma_deregister_packetdump_callback(
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

  result = _cds_get_context(54, (__int64)"wma_deregister_packetdump_callback", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    result[474] = 0;
    result[473] = 0;
  }
  return result;
}
