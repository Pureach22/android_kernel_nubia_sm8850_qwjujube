__int64 __fastcall wma_unified_fw_profiling_cmd(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21

  result = wmi_unified_fw_profiling_data_cmd();
  if ( (_DWORD)result )
  {
    v15 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: enable cmd Failed for id %d value %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wma_unified_fw_profiling_cmd",
      a3,
      a4);
    return v15;
  }
  return result;
}
