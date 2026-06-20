__int64 __fastcall adreno_hwsched_queue_context(__int64 a1, __int64 _X1)
{
  unsigned int v2; // w8
  unsigned int v3; // w19
  unsigned int v9; // w9
  unsigned int *v10; // x19
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v14; // x20
  __int64 v15; // x21
  unsigned __int64 StatusReg; // x21
  __int64 v17; // x22
  __int64 v18; // x0
  int v21; // w9

  if ( _X1 && (*(_QWORD *)(_X1 + 32) & 2) == 0 )
  {
    v2 = *(_DWORD *)_X1;
    if ( *(_DWORD *)_X1 )
    {
      do
      {
        __asm { PRFM            #0x11, [X1] }
        do
          v9 = __ldxr((unsigned int *)_X1);
        while ( v9 == v2 && __stxr(v2 + 1, (unsigned int *)_X1) );
        v3 = v2;
        if ( v9 == v2 )
          break;
        v3 = 0;
        v2 = v9;
      }
      while ( v9 );
    }
    else
    {
      v3 = 0;
    }
    if ( (((v3 + 1) | v3) & 0x80000000) != 0 )
    {
      v14 = a1;
      v15 = _X1;
      refcount_warn_saturate(_X1, 0);
      _X1 = v15;
      a1 = v14;
      if ( !v3 )
        return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    }
    else if ( !v3 )
    {
      return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    }
    v10 = (unsigned int *)_X1;
    v11 = a1;
    v12 = kmem_cache_alloc_noprof(jobs_cache_0, 2080);
    _X8 = v10;
    if ( v12 )
    {
      while ( 1 )
      {
        *(_QWORD *)(v12 + 8) = _X8;
        if ( _X8[2] < 0x11 )
          break;
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v17 = *(_QWORD *)(StatusReg + 80);
        v18 = jobs_cache_0;
        *(_QWORD *)(StatusReg + 80) = &hwsched_queue_context__alloc_tag;
        v12 = kmem_cache_alloc_noprof(v18, 2080);
        *(_QWORD *)(StatusReg + 80) = v17;
        _X8 = v10;
        if ( !v12 )
          goto LABEL_20;
      }
      llist_add_batch(v12);
    }
    else
    {
LABEL_20:
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stlxr(v21 - 1, _X8) );
      if ( v21 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X8);
      }
      else
      {
        a1 = v11;
        if ( v21 > 0 )
          return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
        refcount_warn_saturate(_X8, 3);
      }
    }
    a1 = v11;
  }
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
