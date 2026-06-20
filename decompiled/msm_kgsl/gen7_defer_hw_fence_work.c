__int64 __fastcall gen7_defer_hw_fence_work(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x23
  unsigned int v5; // w22
  int v11; // w8

  v1 = a1 - 2328;
  v3 = a1 - 1624;
  mutex_lock(a1 - 2328);
  rt_mutex_lock(a1 - 13688);
  raw_spin_lock(v3);
  _X21 = *(unsigned int **)(a1 - 1592);
  v5 = *(_DWORD *)(a1 - 1584);
  raw_spin_unlock(v3);
  if ( _X21 )
  {
    if ( (unsigned int)process_hw_fence_deferred_ctxt(a1 - 24776, _X21, v5) )
    {
      gen7_hwsched_fault(a1 - 24776, 32);
    }
    else
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v11 = __ldxr(_X21);
      while ( __stlxr(v11 - 1, _X21) );
      if ( v11 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X21);
      }
      else if ( v11 <= 0 )
      {
        refcount_warn_saturate(_X21, 3);
      }
      adreno_active_count_put(a1 - 24776);
      disable_hw_fence_throttle((_QWORD *)(a1 - 24776), 0);
    }
  }
  rt_mutex_unlock(a1 - 13688);
  return mutex_unlock(v1);
}
