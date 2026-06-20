__int64 __fastcall retire_timestamp_only(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x2
  unsigned __int64 v13; // x9
  unsigned int v16; // w9

  v1 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(v1 + 40);
  kgsl_sharedmem_writel(*(_QWORD *)(v3 + 40), 40LL * *(unsigned int *)(v1 + 4), *(unsigned int *)(a1 + 20));
  kgsl_sharedmem_writel(*(_QWORD *)(v3 + 40), 40LL * *(unsigned int *)(v1 + 4) + 8, *(unsigned int *)(a1 + 20));
  v4 = *(_QWORD *)(*(_QWORD *)(v1 + 24) + 8LL);
  if ( v4 )
    v5 = *(unsigned int *)(v4 + 112);
  else
    v5 = 0;
  msm_perf_events_update(
    0,
    3,
    v5,
    *(unsigned int *)(v1 + 4),
    *(unsigned int *)(a1 + 20),
    (*(_QWORD *)(a1 + 24) >> 8) & 1LL);
  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 24LL) + 384LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 24LL) + 488LL) + 44LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 + 1, _X8) );
  }
  return kgsl_process_event_group(v3, v1 + 64);
}
