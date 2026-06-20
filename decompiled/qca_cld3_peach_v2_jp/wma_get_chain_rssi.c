__int64 __fastcall wma_get_chain_rssi(
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
  __int64 v21; // x8
  __int64 result; // x0

  if ( a1 )
  {
    v12 = wmi_buf_alloc_fl(*a1, 0x50u, "wma_get_chain_rssi", 0x22C4u);
    if ( v12 )
    {
      v21 = *(_QWORD *)(v12 + 224);
      *(_QWORD *)v21 = 42598476;
      *(_DWORD *)(v21 + 72) = *(_DWORD *)a2;
      *(_DWORD *)(v21 + 76) = *(unsigned __int16 *)(a2 + 4);
      result = wmi_unified_cmd_send_fl(
                 *a1,
                 v12,
                 0x50u,
                 0x402Cu,
                 "wma_get_chain_rssi",
                 0x22D4u,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20);
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
      "wma_get_chain_rssi");
    return 4;
  }
  return result;
}
