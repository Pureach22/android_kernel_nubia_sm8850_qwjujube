__int64 __fastcall wma_set_rx_blocksize(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0

  if ( a2 )
  {
    if ( a1 )
    {
      v12 = wmi_buf_alloc_fl(*a1, 0x14u, "wma_set_rx_blocksize", 0x229Cu);
      if ( v12 )
      {
        v21 = *(_DWORD **)(v12 + 224);
        v22 = v12;
        *v21 = 36438032;
        v21[1] = *(_DWORD *)a2;
        v21[4] = *(_DWORD *)(a2 + 12);
        v21[2] = *(_DWORD *)(a2 + 4);
        v21[3] = *(unsigned __int16 *)(a2 + 8);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: rx aggr blocksize: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wma_set_rx_blocksize");
        result = wmi_unified_cmd_send_fl(
                   *a1,
                   v22,
                   0x14u,
                   0x6015u,
                   "wma_set_rx_blocksize",
                   0x22B0u,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30);
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
        "wma_set_rx_blocksize");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: invalid pointer", a3, a4, a5, a6, a7, a8, a9, a10, "wma_set_rx_blocksize");
    return 4;
  }
  return result;
}
