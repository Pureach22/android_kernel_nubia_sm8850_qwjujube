__int64 *__fastcall wlan_cm_update_scan_mlme_info(
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
  __int64 *result; // x0

  result = (__int64 *)cm_get_cm_ctx_fl(
                        a1,
                        (__int64)"wlan_cm_update_scan_mlme_info",
                        0x5Fu,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10);
  if ( result )
    return (__int64 *)cm_update_scan_mlme_info(result, a2);
  return result;
}
