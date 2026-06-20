__int64 __fastcall adreno_hwsched_remove_hw_fence_entry(__int64 a1, _QWORD *a2)
{
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  __int64 v7; // x10
  __int64 result; // x0
  int v14; // w8

  _X19 = (unsigned int *)a2[7];
  raw_spin_lock(a1 + 23152);
  --*(_DWORD *)(a1 + 23432);
  raw_spin_unlock(a1 + 23152);
  --_X19[522];
  kgsl_hw_fence_put(a2[6]);
  v5 = (_QWORD *)a2[9];
  v6 = a2 + 8;
  if ( (_QWORD *)*v5 == a2 + 8 && (v7 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    *(_QWORD *)(v7 + 8) = v5;
    *v5 = v7;
  }
  else
  {
    _list_del_entry_valid_or_report(a2 + 8);
  }
  a2[8] = a2 + 8;
  a2[9] = v6;
  result = kmem_cache_free(*(_QWORD *)(a1 + 22920), a2);
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v14 = __ldxr(_X19);
    while ( __stlxr(v14 - 1, _X19) );
    if ( v14 == 1 )
    {
      __dmb(9u);
      return kgsl_context_destroy_deferred(_X19);
    }
    else if ( v14 <= 0 )
    {
      return refcount_warn_saturate(_X19, 3);
    }
  }
  return result;
}
