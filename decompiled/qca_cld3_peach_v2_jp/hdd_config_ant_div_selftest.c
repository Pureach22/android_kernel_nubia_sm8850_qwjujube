__int64 __fastcall hdd_config_ant_div_selftest(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v10 = *(_DWORD *)(a2 + 4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: antdiv_selftest: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_ant_div_selftest",
    v10);
  v12 = wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 129, v10, 2);
  if ( v12 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set selftest, %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_config_ant_div_selftest",
      v12);
  return v12;
}
