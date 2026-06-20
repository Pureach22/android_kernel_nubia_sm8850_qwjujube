__int64 *__fastcall hdd_disable_rx_ol_in_concurrency(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *result; // x0

  result = _cds_get_context(51, (__int64)"hdd_disable_rx_ol_in_concurrency", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
    return (__int64 *)ucfg_dp_rx_handle_concurrency(*result, a1 & 1);
  return result;
}
