__int64 __fastcall hdd_set_recovery_in_progress(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        char a10)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a10 )
    result = cds_set_driver_state(8, a1, a2, a3, a4, a5, a6, a7, a8);
  else
    result = cds_clear_driver_state(8, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) == 0 )
  {
    result = (__int64)_cds_get_context(
                        51,
                        (__int64)"hdd_set_recovery_in_progress",
                        v11,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18);
    if ( result )
      return wlan_cfg80211_cleanup_scan_queue(*(_QWORD *)(result + 8), 0);
  }
  return result;
}
