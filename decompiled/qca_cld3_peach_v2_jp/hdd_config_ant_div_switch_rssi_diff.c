__int64 __fastcall hdd_config_ant_div_switch_rssi_diff(
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
  __int64 v10; // x9
  __int64 v11; // x8
  int v13; // w19
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  const char *v24; // x4

  v10 = *(_QWORD *)(a2 + 1024);
  v11 = *(_QWORD *)(a2 + 1032);
  if ( *(_OWORD *)(a2 + 1024) == 0 )
    return 0;
  if ( v10 && v11 )
  {
    v13 = *(_WORD *)(v11 + 4) & 0x1FFF | ((*(_WORD *)(v10 + 4) & 0x1FFF) << 13);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ant probe count: %x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_ant_div_switch_rssi_diff",
      v13 | 0x8000000u);
    result = wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 146, v13 | 0x8000000u, 2);
    if ( (_DWORD)result )
    {
      v23 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set ant probe count, %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_config_ant_div_switch_rssi_diff",
        (unsigned int)result);
      return v23;
    }
  }
  else
  {
    if ( v11 )
      v24 = "WLAN";
    else
      v24 = "BT";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_ant_div_switch_rssi_diff",
      v24);
    return 4294967274LL;
  }
  return result;
}
