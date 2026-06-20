__int64 __fastcall wlan_serialization_purge_all_pdev_cmd(
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
  __int64 pdev_obj; // x0
  __int64 v11; // x20
  const char *v13; // x2

  if ( a1 )
  {
    pdev_obj = wlan_serialization_get_pdev_obj(a1);
    if ( pdev_obj )
    {
      v11 = pdev_obj;
      wlan_ser_cancel_scan_cmd(pdev_obj, a1, 0, 0, 0, 0);
      wlan_ser_cancel_scan_cmd(v11, a1, 0, 0, 0, 1);
      wlan_ser_cancel_non_scan_cmd(v11, a1, 0, 0, 1, 0, 0);
      return wlan_ser_cancel_non_scan_cmd(v11, a1, 0, 0, 1, 1, 0);
    }
    v13 = "%s: invalid ser_pdev_obj";
  }
  else
  {
    v13 = "%s: NULL pdev";
  }
  return qdf_trace_msg(0x4Cu, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_purge_all_pdev_cmd");
}
