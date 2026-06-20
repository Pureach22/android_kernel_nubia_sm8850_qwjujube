__int64 __fastcall wlan_hdd_is_roaming_in_progress(
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
  char is_roaming_in_progress; // w0

  if ( a1 )
  {
    is_roaming_in_progress = hdd_is_roaming_in_progress(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is null", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_is_roaming_in_progress");
    is_roaming_in_progress = 0;
  }
  return is_roaming_in_progress & 1;
}
