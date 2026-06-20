__int64 __fastcall hdd_sysfs_set_vdev_0(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_sysfs_set_vdev",
    "WMA_VDEV_TXRX_FWSTATS_RESET_CMDID",
    a2);
  v12 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 122885, a2, 1);
  if ( v12 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set firmware, errno %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_sysfs_set_vdev",
      v12);
  return v12;
}
