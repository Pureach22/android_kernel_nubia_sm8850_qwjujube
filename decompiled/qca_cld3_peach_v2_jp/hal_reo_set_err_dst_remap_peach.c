__int64 __fastcall hal_reo_set_err_dst_remap_peach(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  hal_write32_mb_1(a1, 10715192, 0);
  v2 = hal_read32_mb_1(a1, 10715192);
  qdf_trace_msg(
    0x46u,
    5u,
    "%s: HWIO_REO_R0_ERROR_DESTINATION_MAPPING_IX_0 0x%x",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "hal_reo_set_err_dst_remap_peach",
    v2);
  hal_write32_mb_1(a1, 10715196, 0);
  v11 = hal_read32_mb_1(a1, 10715196);
  return qdf_trace_msg(
           0x46u,
           5u,
           "%s: HWIO_REO_R0_ERROR_DESTINATION_MAPPING_IX_1 0x%x",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "hal_reo_set_err_dst_remap_peach",
           v11);
}
