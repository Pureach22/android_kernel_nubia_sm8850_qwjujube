__int64 __fastcall hdd_sysfs_pm_cinfo_create(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = sysfs_create_file_ns(a1, &pm_cinfo_attribute, 0);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to create pktlog sysfs entry",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "hdd_sysfs_pm_cinfo_create");
  return result;
}
