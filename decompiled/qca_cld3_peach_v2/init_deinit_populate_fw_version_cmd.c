__int64 init_deinit_populate_fw_version_cmd()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  if ( (unsigned int)wmi_unified_save_fw_version_cmd() )
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to save fw version",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "init_deinit_populate_fw_version_cmd");
  return 0;
}
