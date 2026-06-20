__int64 __fastcall wma_set_wlm_latency_level(
        _QWORD *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: set latency level %d, fw wlm_latency_flags 0x%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_set_wlm_latency_level",
    *a2,
    *((unsigned int *)a2 + 1));
  result = wmi_unified_wlm_latency_level_cmd(*a1, a2);
  if ( (_DWORD)result )
  {
    v21 = result;
    qdf_trace_msg(
      0x36u,
      3u,
      "%s: Failed to set latency level",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_set_wlm_latency_level");
    return v21;
  }
  return result;
}
