__int64 __fastcall hdd_sysfs_dp_stc_destroy(
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
  if ( !a1 )
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
             "hdd_sysfs_dp_stc_destroy");
  sysfs_remove_file_ns(a1, &dp_stc_logmask_attribute, 0);
  sysfs_remove_file_ns(a1, &dp_stc_c_table_attribute, 0);
  sysfs_remove_file_ns(a1, &dp_stc_s_table_attribute, 0);
  sysfs_remove_file_ns(a1, &dp_stc_active_traffic_map_attribute, 0);
  return sysfs_remove_file_ns(a1, &dp_stc_tx_aft_attribute, 0);
}
