__int64 __fastcall hdd_sysfs_dp_trace_create(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int file_ns; // w19
  const char *v27; // x2

  if ( !a1 )
  {
    file_ns = -22;
    v27 = "%s: could not get driver kobject!";
    goto LABEL_9;
  }
  if ( (unsigned int)sysfs_create_file_ns(a1, &dp_trace_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dp_trace sysfs file",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_sysfs_dp_trace_create");
  if ( (unsigned int)sysfs_create_file_ns(a1, &dump_dp_trace_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dump_dp_trace sysfs file",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_sysfs_dp_trace_create");
  file_ns = sysfs_create_file_ns(a1, &clear_dp_trace_attribute, 0);
  if ( file_ns )
  {
    v27 = "%s: could not create clear_dp_trace sysfs file";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v27, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_dp_trace_create");
  }
  return file_ns;
}
