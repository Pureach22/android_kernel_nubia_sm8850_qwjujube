__int64 __fastcall wma_vdev_obss_detection_info_handler(
        __int64 *a1,
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
  __int64 v12; // x0
  unsigned int *v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  if ( a2 )
  {
    v12 = _qdf_mem_malloc(0x14u, "wma_vdev_obss_detection_info_handler", 6385);
    if ( !v12 )
      return 4294967284LL;
    v13 = (unsigned int *)v12;
    if ( (unsigned int)wmi_unified_extract_obss_detection_info(*a1, a2, v12) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to extract obss info",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_vdev_obss_detection_info_handler");
    }
    else
    {
      if ( (wma_is_vdev_valid(*v13, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      {
        wma_send_msg(a1, 4522, v13, 0);
        return 0;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid vdev id %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wma_vdev_obss_detection_info_handler",
        *v13);
    }
    _qdf_mem_free((__int64)v13);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid obss_detection_info event buffer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_vdev_obss_detection_info_handler");
  }
  return 4294967274LL;
}
