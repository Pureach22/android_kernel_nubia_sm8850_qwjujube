__int64 __fastcall hdd_config_ant_div_snr_diff(
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
  unsigned int v12; // w22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v10 = *(_DWORD *)(a2 + 4);
  qdf_trace_msg(0x33u, 8u, "%s: snr diff: %x", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_ant_div_snr_diff", v10);
  v12 = v10 & 0x1FFF | 0x8000000;
  qdf_trace_msg(0x33u, 8u, "%s: usrcfg: %x", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_config_ant_div_snr_diff", v12);
  v21 = wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 146, v12, 2);
  if ( v21 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set snr diff, %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_config_ant_div_snr_diff",
      v21);
  return v21;
}
