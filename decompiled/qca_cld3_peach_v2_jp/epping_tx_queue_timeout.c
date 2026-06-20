__int64 __fastcall epping_tx_queue_timeout(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  result = qdf_trace_msg(
             0x33u,
             2u,
             "%s: Transmission timeout occurred, adapter->started= %d",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "epping_tx_queue_timeout",
             *(unsigned __int8 *)(a1 + 2821));
  if ( *(_BYTE *)(a1 + 2821) == 1 )
    return netif_tx_wake_queue(*(_QWORD *)(a1 + 24));
  return result;
}
