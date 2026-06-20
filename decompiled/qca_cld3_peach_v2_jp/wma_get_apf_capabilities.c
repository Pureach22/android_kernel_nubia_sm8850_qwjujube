__int64 __fastcall wma_get_apf_capabilities(__int64 *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_get_apf_capabilities") )
    return 4;
  v10 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v10, (__int64)"wma_get_apf_capabilities", v2, v3, v4, v5, v6, v7, v8, v9) )
    return 4;
  if ( (wmi_service_enabled(v10, 0x6Du, v11, v12, v13, v14, v15, v16, v17, v18) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: APF cababilities feature bit not enabled",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_get_apf_capabilities");
    return 16;
  }
  v28 = wmi_buf_alloc_fl(v10, 8u, "wma_get_apf_capabilities", 0x135Cu);
  if ( !v28 )
    return 2;
  **(_DWORD **)(v28 + 224) = 29097988;
  result = wmi_unified_cmd_send_fl(
             v10,
             v28,
             8u,
             0x36001u,
             "wma_get_apf_capabilities",
             0x1368u,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
