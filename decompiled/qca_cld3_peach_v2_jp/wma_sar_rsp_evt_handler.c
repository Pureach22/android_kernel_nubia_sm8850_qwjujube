__int64 __fastcall wma_sar_rsp_evt_handler(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: handle:%pK event:%pK len:%u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_sar_rsp_evt_handler",
    a1,
    a2,
    a3);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_sar_rsp_evt_handler") )
    return 4;
  v22 = *a1;
  if ( (unsigned int)_wmi_validate_handle(
                       v22,
                       (__int64)"wma_sar_rsp_evt_handler",
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21) )
    return 4;
  result = wmi_unified_extract_sar2_result_event(v22, a2, a3);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Event extract failure: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_sar_rsp_evt_handler",
      (unsigned int)result);
    return 4294967274LL;
  }
  return result;
}
