__int64 __fastcall adreno_hwsched_log_profiling_info(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned int v7; // w23
  unsigned int v13; // w8
  __int64 result; // x0
  _QWORD *v15; // x8
  _QWORD *v16; // x23
  unsigned int v17; // w9
  unsigned int v18; // w10
  unsigned int v19; // w9
  unsigned int v20; // w10
  unsigned int v21; // w9
  int v23; // w8

  _ReadStatusReg(SP_EL0);
  v4 = *(unsigned int *)(a2 + 4);
  raw_read_lock(a1 + 11208);
  v5 = idr_find(a1 + 11184, v4);
  if ( !v5 || (_X19 = v5, (*(_QWORD *)(v5 + 32) & 2) != 0) )
  {
    result = raw_read_unlock(a1 + 11208);
  }
  else
  {
    v7 = *(_DWORD *)v5;
    if ( *(_DWORD *)v5 )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v13 = __ldxr((unsigned int *)v5);
        while ( v13 == v7 && __stxr(v7 + 1, (unsigned int *)v5) );
        if ( v13 == v7 )
          break;
        v7 = v13;
      }
      while ( v13 );
    }
    if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
      refcount_warn_saturate(v5, 0);
    result = raw_read_unlock(a1 + 11208);
    if ( v7 )
    {
      if ( (*(_DWORD *)(_X19 + 200) & 0x20000) == 0 )
        kgsl_work_period_update(a1, *(_QWORD *)(*(_QWORD *)(_X19 + 24) + 488LL));
      result = log_kgsl_cmdbatch_retired_event(
                 *(unsigned int *)(_X19 + 4),
                 *(unsigned int *)(a2 + 8),
                 *(unsigned int *)(_X19 + 8),
                 0,
                 *(_QWORD *)(a2 + 24),
                 *(_QWORD *)(a2 + 32));
      if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 )
      {
        raw_spin_lock(_X19 + 404);
        v15 = *(_QWORD **)(_X19 + 2072);
        if ( v15 != (_QWORD *)(_X19 + 2072) )
        {
          do
          {
            v16 = (_QWORD *)*v15;
            v17 = *((_DWORD *)v15 - 10);
            v18 = *(_DWORD *)(*(_QWORD *)(_X19 + 1648) + 12LL);
            if ( v17 != v18 )
            {
              if ( v17 > v18 && ((v17 - v18) & 0x80000000) == 0 )
                break;
              v19 = v17 ^ 0x80000000;
              v20 = v18 ^ 0x80000000;
              _CF = v19 >= v20;
              v21 = v19 - v20;
              if ( v21 != 0 && _CF && v21 < 0x80000001 )
                break;
            }
            adreno_hwsched_remove_hw_fence_entry(a1, v15 - 8);
            v15 = v16;
          }
          while ( v16 != (_QWORD *)(_X19 + 2072) );
        }
        result = raw_spin_unlock(_X19 + 404);
      }
      __asm { PRFM            #0x11, [X19] }
      do
        v23 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(v23 - 1, (unsigned int *)_X19) );
      if ( v23 == 1 )
      {
        __dmb(9u);
        result = kgsl_context_destroy(_X19);
      }
      else if ( v23 <= 0 )
      {
        result = refcount_warn_saturate(_X19, 3);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
