__int64 __fastcall wma_wake_reason_ap_assoc_lost(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20

  if ( a2 )
  {
    v10 = *a2;
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: Beacon miss indication on vdev %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_wake_reason_ap_assoc_lost",
      *(unsigned int *)(*a2 + 4));
    wma_beacon_miss_handler(a1, *(unsigned int *)(v10 + 4), *(unsigned int *)(v10 + 12));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: AP Assoc Lost event data is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_wake_reason_ap_assoc_lost");
    return 4294967274LL;
  }
}
