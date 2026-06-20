void *__fastcall wlan_t2lm_clear_ongoing_negotiation(
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
  __int64 v9; // x19
  void *result; // x0

  v9 = *(_QWORD *)(a1 + 784);
  if ( !v9 )
    return (void *)qdf_trace_msg(
                     0x99u,
                     2u,
                     "%s: ml peer is null",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "wlan_t2lm_clear_ongoing_negotiation");
  result = qdf_mem_set((void *)(v9 + 384), 0x9Cu, 0);
  *(_BYTE *)(v9 + 380) = 0;
  *(_QWORD *)(v9 + 540) = 0x8700000000LL;
  *(_DWORD *)(v9 + 376) = 0;
  *(_DWORD *)(v9 + 384) = 4;
  *(_DWORD *)(v9 + 436) = 4;
  *(_DWORD *)(v9 + 488) = 4;
  return result;
}
