__int64 __fastcall wma_send_obss_detection_cfg(
        __int64 a1,
        _DWORD *a2,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  if ( *a2 >= (unsigned int)*(unsigned __int16 *)(a1 + 162) )
  {
    v20 = "%s: Invalid vdev_id: %d";
    return qdf_trace_msg(0x36u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_obss_detection_cfg");
  }
  if ( (wma_is_vdev_up((unsigned int)*a2) & 1) == 0 )
  {
    v20 = "%s: vdev %d is not up skipping obss detection req";
    return qdf_trace_msg(0x36u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_obss_detection_cfg");
  }
  result = wmi_unified_send_obss_detection_cfg_cmd(*(_QWORD *)a1);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to send obss detection cfg",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wma_send_obss_detection_cfg");
  return result;
}
