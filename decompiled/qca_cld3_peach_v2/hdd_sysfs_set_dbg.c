__int64 __fastcall hdd_sysfs_set_dbg(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  qdf_trace_msg(0x33u, 8u, "%s: %s %d", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_sysfs_set_dbg", a3, a4);
  v15 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), a2, a4, 4);
  if ( v15 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set firmware, errno %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_sysfs_set_dbg",
      v15);
  return v15;
}
