__int64 __fastcall hdd_sysfs_direct_link_ut_cmd_create(
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
  unsigned int file; // w19
  const char *v12; // x2

  v9 = *(__int64 **)(a1 + 24);
  if ( !v9 )
  {
    file = -22;
    v12 = "%s: HDD context is NULL!";
    goto LABEL_6;
  }
  if ( !*(_BYTE *)(cfg_psoc_get_values(*v9) + 4124) )
    return (unsigned int)-22;
  file = device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_direct_link_ut_cmd);
  if ( file )
  {
    v12 = "%s: could not create traffic_end_indication sysfs file";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_direct_link_ut_cmd_create");
  }
  return file;
}
