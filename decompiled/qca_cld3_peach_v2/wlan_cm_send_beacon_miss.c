__int64 *__fastcall wlan_cm_send_beacon_miss(
        unsigned __int8 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  result = _cds_get_context(54, (__int64)"wlan_cm_send_beacon_miss", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
    return (__int64 *)wma_beacon_miss_handler(result, a1, a2, v13, v14, v15, v16, v17, v18, v19, v20);
  return result;
}
