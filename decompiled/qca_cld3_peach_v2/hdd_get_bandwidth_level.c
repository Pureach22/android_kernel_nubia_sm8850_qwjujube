__int64 *__fastcall hdd_get_bandwidth_level(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *result; // x0

  result = _cds_get_context(51, (__int64)"hdd_get_bandwidth_level", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
    return (__int64 *)ucfg_dp_get_current_throughput_level(*result);
  return result;
}
