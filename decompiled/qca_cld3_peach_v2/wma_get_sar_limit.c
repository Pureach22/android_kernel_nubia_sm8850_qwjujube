__int64 __fastcall wma_get_sar_limit(__int64 *a1, void *a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19

  if ( (unsigned int)_wma_validate_handle(a1, "wma_get_sar_limit") )
    return 4;
  v14 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v14, (__int64)"wma_get_sar_limit", v6, v7, v8, v9, v10, v11, v12, v13) )
    return 4;
  sar_callback = a2;
  sar_context = a3;
  result = wmi_unified_get_sar_limit_cmd(v14);
  if ( (_DWORD)result )
  {
    v24 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wmi_unified_get_sar_limit_cmd() error: %u",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_get_sar_limit",
      (unsigned int)result);
    sar_callback = nullptr;
    return v24;
  }
  return result;
}
