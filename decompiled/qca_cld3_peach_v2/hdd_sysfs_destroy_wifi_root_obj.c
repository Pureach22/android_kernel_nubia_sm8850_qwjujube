__int64 hdd_sysfs_destroy_wifi_root_obj()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 result; // x0

  if ( pld_get_wifi_kobj() )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: wifi_kobject created by platform",
               v0,
               v1,
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               "hdd_sysfs_destroy_wifi_root_obj");
    wifi_kobject = 0;
  }
  else if ( wifi_kobject )
  {
    result = kobject_put();
    wifi_kobject = 0;
  }
  else
  {
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: could not get wifi kobject!",
             v0,
             v1,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             "hdd_sysfs_destroy_wifi_root_obj");
  }
  return result;
}
