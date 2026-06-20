__int64 __fastcall hdd_sysfs_mem_stats_create(
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
  const char *v10; // x2
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !a1 )
  {
    v10 = "%s: Could not get wlan kobject!";
    goto LABEL_5;
  }
  if ( (unsigned int)sysfs_create_file_ns(a1, &mem_stats_attribute, 0) )
  {
    v10 = "%s: Failed to create sysfs file wlan_mem_stats";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_mem_stats_create");
    return 4294967274LL;
  }
  if ( !(unsigned int)sysfs_create_file_ns(a1, &mem_dp_stats_attribute, 0) )
  {
    qdf_mem_stats_init();
    return 0;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to create sysfs file wlan_dp_mem_stats",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "hdd_sysfs_mem_stats_create");
  sysfs_remove_file_ns(a1, &mem_stats_attribute, 0);
  return 4294967274LL;
}
