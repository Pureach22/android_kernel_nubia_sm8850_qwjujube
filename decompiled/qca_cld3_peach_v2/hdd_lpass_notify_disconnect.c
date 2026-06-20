__int64 __fastcall hdd_lpass_notify_disconnect(
        _BYTE *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  a1[2696] = 0;
  return wlan_hdd_send_status_pkg(a1, (__int64)(a1 + 80), 1, 0, a2, a3, a4, a5, a6, a7, a8, a9);
}
