__int64 __fastcall wma_set_rx_reorder_timeout_val(
        __int64 *a1,
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
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x19
  __int64 v23; // x6
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0

  if ( a2 )
  {
    if ( a1 )
    {
      v12 = wmi_buf_alloc_fl(*a1, 0x14u, "wma_set_rx_reorder_timeout_val", 0x226Eu);
      if ( v12 )
      {
        v21 = *(_QWORD *)(v12 + 224);
        v22 = v12;
        *(_DWORD *)v21 = 36372496;
        v23 = a2[1];
        *(_QWORD *)(v21 + 4) = *a2;
        *(_QWORD *)(v21 + 12) = v23;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: rx aggr record timeout: VO: %d, VI: %d, BE: %d, BK: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wma_set_rx_reorder_timeout_val");
        result = wmi_unified_cmd_send_fl(
                   *a1,
                   v22,
                   0x14u,
                   0x4023u,
                   "wma_set_rx_reorder_timeout_val",
                   0x2281u,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31);
        if ( (_DWORD)result )
        {
          wmi_buf_free();
          return 16;
        }
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid WMA handle (via %s)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "__wma_validate_handle",
        "wma_set_rx_reorder_timeout_val");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: invalid pointer", a3, a4, a5, a6, a7, a8, a9, a10, "wma_set_rx_reorder_timeout_val");
    return 4;
  }
  return result;
}
