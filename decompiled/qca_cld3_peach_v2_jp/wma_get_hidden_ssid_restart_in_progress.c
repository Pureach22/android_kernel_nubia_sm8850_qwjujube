__int64 __fastcall wma_get_hidden_ssid_restart_in_progress(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
    LOBYTE(a1) = ap_mlme_is_hidden_ssid_restart_in_progress(*a1, a2, a3, a4, a5, a6, a7, a8, a9);
  return (unsigned __int8)a1 & 1;
}
