__int64 __fastcall hdd_sysfs_dp_stc_create(
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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int file_ns; // w19
  const char *v43; // x2

  if ( !a1 )
  {
    file_ns = -22;
    v43 = "%s: could not get driver kobject!";
    goto LABEL_13;
  }
  if ( (unsigned int)sysfs_create_file_ns(a1, &dp_stc_logmask_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create stc_logmask sysfs file",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_sysfs_dp_stc_create");
  if ( (unsigned int)sysfs_create_file_ns(a1, &dp_stc_c_table_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create stc_c_table sysfs file",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_sysfs_dp_stc_create");
  if ( (unsigned int)sysfs_create_file_ns(a1, &dp_stc_s_table_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create stc_s_table sysfs file",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_sysfs_dp_stc_create");
  if ( (unsigned int)sysfs_create_file_ns(a1, &dp_stc_active_traffic_map_attribute, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create stc_active_traffic_map sysfs file",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_sysfs_dp_stc_create");
  file_ns = sysfs_create_file_ns(a1, &dp_stc_tx_aft_attribute, 0);
  if ( file_ns )
  {
    v43 = "%s: could not create stc_tx_aft sysfs file";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v43, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_dp_stc_create");
  }
  return file_ns;
}
