__int64 __fastcall wma_legacy_service_ready_event_handler(
        int a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 > 61 )
  {
    if ( a1 != 62 )
    {
      if ( a1 == 220 )
        return wma_rx_service_ready_ext2_event(a2);
      goto LABEL_8;
    }
    return wma_rx_service_ready_ext_event(a2, a3);
  }
  else
  {
    if ( a1 )
    {
      if ( a1 == 1 )
        return wma_rx_ready_event(a2, a3);
LABEL_8:
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Legacy callback invoked with invalid event_id:%d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wma_legacy_service_ready_event_handler");
      return 0;
    }
    return wma_rx_service_ready_event(a2, a3);
  }
}
