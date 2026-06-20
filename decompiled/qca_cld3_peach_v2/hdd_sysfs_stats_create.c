__int64 __fastcall hdd_sysfs_stats_create(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19

  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dump_stats) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dump_stats sysfs file",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "hdd_sysfs_stats_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_clear_stats) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create clear_stats sysfs file",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_sysfs_stats_create");
  result = device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_stats);
  if ( (_DWORD)result )
  {
    v27 = result;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create stats sysfs file",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_sysfs_stats_create");
    return v27;
  }
  return result;
}
