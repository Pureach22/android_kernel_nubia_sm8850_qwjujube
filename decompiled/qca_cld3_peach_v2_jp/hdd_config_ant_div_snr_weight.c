__int64 __fastcall hdd_config_ant_div_snr_weight(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x9
  __int64 result; // x0
  int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19

  v12 = a2[45];
  v13 = a2[46];
  v14 = a2[47];
  if ( !v12 && !v13 && !v14 )
    return 0;
  if ( v12 && v13 && v14 )
  {
    v17 = (unsigned __int16)((unsigned __int8)*(_DWORD *)(v13 + 4) << 8)
        | ((unsigned __int8)*(_DWORD *)(v12 + 4) << 16)
        | *(unsigned __int8 *)(v14 + 4);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ant div set weight: %x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_ant_div_snr_weight",
      v17 | 0x20000000u,
      v10,
      v11);
    result = wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 146, v17 | 0x20000000u, 2);
    if ( (_DWORD)result )
    {
      v26 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set ant div weight, %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_config_ant_div_snr_weight",
        (unsigned int)result);
      return v26;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_ant_div_snr_weight",
      v10,
      v11);
    return 4294967274LL;
  }
  return result;
}
