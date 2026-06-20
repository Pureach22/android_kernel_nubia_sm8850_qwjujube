__int64 __fastcall hdd_lpass_notify_connect(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  if ( (*(_BYTE *)(result + 2696) & 1) == 0 )
  {
    v9 = result;
    result = cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9);
    if ( (result & 4) == 0 )
    {
      *(_BYTE *)(v9 + 2696) = 1;
      return wlan_hdd_send_status_pkg(v9, v9 + 80, 1, 1);
    }
  }
  return result;
}
