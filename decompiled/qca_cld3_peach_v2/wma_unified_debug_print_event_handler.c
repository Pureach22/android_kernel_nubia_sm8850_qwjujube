__int64 __fastcall wma_unified_debug_print_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8

  if ( a10 && *(_QWORD *)a10 )
  {
    v10 = *(_DWORD *)(a10 + 8);
    if ( v10 < 0x601 )
    {
      *(_BYTE *)(*(_QWORD *)a10 + v10 - 1) = 0;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: FIRMWARE:%s",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "wma_unified_debug_print_event_handler");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Received data len %d exceeds max value %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "wma_unified_debug_print_event_handler",
        v10,
        1536);
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Get NULL point message from FW",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wma_unified_debug_print_event_handler");
    return 4294967284LL;
  }
}
