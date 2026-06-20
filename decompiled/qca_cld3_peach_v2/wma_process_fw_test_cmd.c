__int64 __fastcall wma_process_fw_test_cmd(__int64 *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_process_fw_test_cmd") )
    return 4;
  v10 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v10, (__int64)"wma_process_fw_test_cmd", v2, v3, v4, v5, v6, v7, v8, v9) )
    return 4;
  result = wmi_unified_fw_test_cmd(v10);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to issue fw test cmd",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_process_fw_test_cmd");
    return 16;
  }
  return result;
}
