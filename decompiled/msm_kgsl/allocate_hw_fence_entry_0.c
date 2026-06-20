__int64 __fastcall allocate_hw_fence_entry_0(__int64 a1, unsigned int *a2, _QWORD *a3)
{
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w22
  unsigned int v14; // w9
  __int64 v15; // x0
  __int64 v16; // x22
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x12
  int v20; // w9
  int v21; // w8
  int v23; // w8

  _X19 = a2;
  if ( (kgsl_hw_fence_tx_slot_available() & 1) == 0 )
    return 0;
  result = 0;
  if ( _X19[522] - 84 >= 0xFFFFFFAB && _X19 )
  {
    v7 = *_X19;
    if ( *_X19 )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v14 = __ldxr(_X19);
        while ( v14 == v7 && __stxr(v7 + 1, _X19) );
        v8 = v7;
        if ( v14 == v7 )
          break;
        v8 = 0;
        v7 = v14;
      }
      while ( v14 );
    }
    else
    {
      v8 = 0;
    }
    if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
    {
      refcount_warn_saturate(_X19, 0);
      if ( !v8 )
        return 0;
    }
    else if ( !v8 )
    {
      return 0;
    }
    v15 = kmem_cache_alloc_noprof(*(_QWORD *)(a1 + 22920), 2336);
    if ( v15 )
    {
      *(_QWORD *)(v15 + 48) = a3;
      *(_QWORD *)(v15 + 56) = _X19;
      v16 = v15;
      *(_DWORD *)v15 = 151;
      if ( !(unsigned int)kgsl_hw_fence_create(a1, a3) )
      {
        v17 = a3[4];
        v18 = a3[5];
        v19 = a3[13];
        v20 = *(_DWORD *)(*(_QWORD *)(v16 + 56) + 4LL);
        ++_X19[522];
        v21 = *(_DWORD *)(a1 + 23432);
        *(_DWORD *)(v16 + 8) = v20;
        *(_QWORD *)(v16 + 16) = v17;
        *(_QWORD *)(v16 + 24) = v18;
        *(_DWORD *)(a1 + 23432) = v21 + 1;
        *(_QWORD *)(v16 + 40) = v19;
        *(_QWORD *)(v16 + 64) = v16 + 64;
        *(_QWORD *)(v16 + 72) = v16 + 64;
        *(_QWORD *)(v16 + 80) = v16 + 80;
        *(_QWORD *)(v16 + 88) = v16 + 80;
        return v16;
      }
      kmem_cache_free(*(_QWORD *)(a1 + 22920), v16);
      __asm { PRFM            #0x11, [X19] }
      do
        v23 = __ldxr(_X19);
      while ( __stlxr(v23 - 1, _X19) );
      if ( v23 != 1 )
        goto LABEL_29;
    }
    else
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v23 = __ldxr(_X19);
      while ( __stlxr(v23 - 1, _X19) );
      if ( v23 != 1 )
      {
LABEL_29:
        if ( v23 <= 0 )
          refcount_warn_saturate(_X19, 3);
        return 0;
      }
    }
    __dmb(9u);
    kgsl_context_destroy_deferred(_X19);
    return 0;
  }
  return result;
}
