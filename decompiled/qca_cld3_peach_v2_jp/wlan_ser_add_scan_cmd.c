__int64 __fastcall wlan_ser_add_scan_cmd(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return wlan_serialization_add_cmd_to_pdev_queue(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
