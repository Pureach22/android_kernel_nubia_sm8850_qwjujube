__int64 __fastcall gen8_defer_hw_fence_work(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x23
  unsigned int v5; // w22
  int v11; // w8

  v1 = a1 - 2384;
  v3 = a1 - 1680;
  mutex_lock(a1 - 2384);
  rt_mutex_lock(a1 - 13744);
  raw_spin_lock(v3);
  _X21 = *(unsigned int **)(a1 - 1648);
  v5 = *(_DWORD *)(a1 - 1640);
  raw_spin_unlock(v3);
  if ( _X21 )
  {
    if ( (unsigned int)process_hw_fence_deferred_ctxt_0(a1 - 24832, _X21, v5) )
    {
      gen8_hwsched_fault(a1 - 24832, 32);
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
      adreno_active_count_put(a1 - 24832);
      disable_hw_fence_throttle_0((_QWORD *)(a1 - 24832), 0);
    }
  }
  rt_mutex_unlock(a1 - 13744);
  return mutex_unlock(v1);
}
