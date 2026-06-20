__int64 __fastcall adreno_hwsched_retire_cmdobj(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x9
  __int64 v6; // x2
  __int64 v7; // x8
  __int64 v8; // x3
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned __int64 v19; // x9
  unsigned int v22; // w9
  int v24; // w8

  v2 = *(_QWORD *)(a2 + 8);
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
    *(unsigned int *)(a2 + 20),
    (*(_QWORD *)(a2 + 24) >> 8) & 1LL);
  if ( (*(_BYTE *)(a2 + 25) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL) + 384LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 + 1, _X8) );
    _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL) + 488LL) + 44LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 + 1, _X8) );
  }
  v7 = *(_QWORD *)(a2 + 8);
  v8 = *(unsigned int *)(a2 + 20);
  v9 = *(unsigned int *)(v7 + 4);
  v10 = *(unsigned int *)(v7 + 8);
  if ( *(_QWORD *)(a1 + 1928) == a2 )
  {
    *(_QWORD *)(a1 + 1928) = 0;
    if ( a2 )
    {
      _X0 = (unsigned int *)(a2 + 32);
      __asm { PRFM            #0x11, [X0] }
      do
        v24 = __ldxr(_X0);
      while ( __stlxr(v24 - 1, _X0) );
      if ( v24 == 1 )
      {
        __dmb(9u);
        kgsl_drawobj_destroy_object(_X0);
      }
      else if ( v24 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
  }
  return kgsl_drawobj_destroy(a2, v9, v10, v8);
}
