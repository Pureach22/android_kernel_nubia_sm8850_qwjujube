__int64 __fastcall hdd_abort_ongoing_sta_connection(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  result = hdd_get_sta_connection_in_progress(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
    return wlan_hdd_cm_issue_disconnect(result, 1, 0);
  return result;
}
