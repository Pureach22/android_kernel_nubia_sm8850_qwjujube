__int64 __fastcall kgsl_event_worker(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int64 v4; // x2
  void (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x3
  int v15; // w8

  v1 = *(_QWORD *)(a1 - 56);
  if ( v1 )
    v3 = *(unsigned int *)(v1 + 4);
  else
    v3 = 0;
  log_kgsl_fire_event(
    v3,
    *(unsigned int *)(a1 - 48),
    *(unsigned int *)(a1 + 40),
    (unsigned int)(jiffies - *(_DWORD *)(a1 - 8)),
    (unsigned int)(jiffies - *(_DWORD *)(a1 - 8)),
    *(_QWORD *)(a1 - 40));
  v5 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 40);
  v4 = *(_QWORD *)(a1 - 32);
  v6 = *(_QWORD *)(a1 - 64);
  v7 = *(_QWORD *)(a1 + 48);
  v8 = *(unsigned int *)(a1 + 40);
  if ( *((_DWORD *)v5 - 1) != 280452656 )
    __break(0x8228u);
  v5(v6, v7, v4, v8);
  _X0 = *(unsigned int **)(a1 - 56);
  if ( _X0 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v15 = __ldxr(_X0);
    while ( __stlxr(v15 - 1, _X0) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X0);
    }
    else if ( v15 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return kmem_cache_free(events_cache, a1 - 64);
}
