__int64 __fastcall hdd_sysfs_thermal_cfg_destroy(
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
  if ( a1 )
    return sysfs_remove_file_ns(a1, &thermal_cfg_attribute, 0);
  else
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: could not get driver kobject!",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_sysfs_thermal_cfg_destroy");
}
