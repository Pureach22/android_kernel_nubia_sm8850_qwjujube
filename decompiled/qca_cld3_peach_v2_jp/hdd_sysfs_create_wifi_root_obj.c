__int64 __fastcall hdd_sysfs_create_wifi_root_obj(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  const char *v8; // x2
  unsigned int v9; // w1
  __int64 result; // x0

  if ( wifi_kobject )
  {
    v8 = "%s: wifi kobj already created";
LABEL_5:
    v9 = 8;
    return qdf_trace_msg(0x33u, v9, v8, a1, a2, a3, a4, a5, a6, a7, a8, "hdd_sysfs_create_wifi_root_obj");
  }
  wifi_kobject = pld_get_wifi_kobj();
  if ( wifi_kobject )
  {
    v8 = "%s: wifi_kobject created by platform";
    goto LABEL_5;
  }
  result = kobject_create_and_add("wifi", 0);
  wifi_kobject = result;
  if ( !result )
  {
    v8 = "%s: could not allocate wifi kobject";
    v9 = 2;
    return qdf_trace_msg(0x33u, v9, v8, a1, a2, a3, a4, a5, a6, a7, a8, "hdd_sysfs_create_wifi_root_obj");
  }
  return result;
}
