__int64 __fastcall hdd_sysfs_direct_link_ut_destroy(
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
  __int64 *v9; // x8
  __int64 result; // x0

  v9 = *(__int64 **)(a1 + 24);
  if ( !v9 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: HDD context is NULL!",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_sysfs_direct_link_ut_destroy");
  result = cfg_psoc_get_values(*v9);
  if ( *(_BYTE *)(result + 4040) )
    return device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_direct_link_ut_cmd);
  return result;
}
