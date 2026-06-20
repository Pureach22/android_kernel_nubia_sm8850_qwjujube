__int64 __fastcall gen7_hwsched_disable_hw_fence_throttle(__int64 a1)
{
  unsigned int v3; // w21
  unsigned int v4; // w0
  unsigned int v5; // w20
  int v12; // w8

  if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 )
  {
    raw_spin_lock(a1 + 23152);
    _X20 = *(unsigned int **)(a1 + 23184);
    v3 = *(_DWORD *)(a1 + 23192);
    raw_spin_unlock(a1 + 23152);
    if ( _X20 )
    {
      v4 = process_hw_fence_deferred_ctxt(a1, _X20, v3);
      if ( v4 )
      {
        v5 = v4;
        gen7_hwsched_fault(a1, 14);
        return v5;
      }
      __asm { PRFM            #0x11, [X20] }
      do
        v12 = __ldxr(_X20);
      while ( __stlxr(v12 - 1, _X20) );
      if ( v12 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X20);
      }
      else if ( v12 <= 0 )
      {
        refcount_warn_saturate(_X20, 3);
      }
      adreno_active_count_put(a1);
    }
    disable_hw_fence_throttle(a1, 1);
  }
  return 0;
}
