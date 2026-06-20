__int64 __fastcall retire_timestamp(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x2
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 result; // x0
  unsigned __int64 v17; // x9
  unsigned int v20; // w9

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(v2 + 40);
  v4 = *(_QWORD *)(v2 + 1536);
  kgsl_sharedmem_writel(*(_QWORD *)(v3 + 40), 40LL * *(unsigned int *)(v2 + 4), *(unsigned int *)(a1 + 20));
  kgsl_sharedmem_writel(*(_QWORD *)(v3 + 40), 40LL * *(unsigned int *)(v2 + 4) + 8, *(unsigned int *)(a1 + 20));
  *(_DWORD *)(v2 + 1544) = *(_DWORD *)(a1 + 20);
  kgsl_process_event_group(v3, v2 + 64);
  v5 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 8LL);
  if ( v5 )
    v6 = *(unsigned int *)(v5 + 112);
  else
    v6 = 0;
  msm_perf_events_update(
    0,
    3,
    v6,
    *(unsigned int *)(v2 + 4),
    *(unsigned int *)(a1 + 20),
    (*(_QWORD *)(a1 + 24) >> 8) & 1LL);
  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 24) + 384LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 + 1, _X8) );
    _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 488LL) + 44LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 + 1, _X8) );
  }
  adreno_get_rptr(v4);
  log_kgsl_cmdbatch_retired_event(
    *(unsigned int *)(v2 + 4),
    *(unsigned int *)(a1 + 20),
    *(unsigned int *)(v2 + 8),
    *(_QWORD *)(a1 + 24),
    0,
    0);
  result = kgsl_drawobj_destroy(a1, v7, v8, v9);
  _ReadStatusReg(SP_EL0);
  return result;
}
