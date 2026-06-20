__int64 __fastcall adreno_hwsched_hw_syncobj_destroy(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  unsigned __int64 v6; // x22
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned __int64 v16; // x9
  int v18; // w8
  unsigned int v19; // w22
  __int64 v20; // x9
  int v23; // w8

  if ( *(_DWORD *)(a1 + 64) )
  {
    v5 = 0;
    v6 = 0;
    _X20 = (unsigned int *)(a1 + 32);
    do
    {
      v8 = *(_QWORD *)(a1 + 56) + v5;
      if ( *(_DWORD *)(v8 + 4) == 1 )
      {
        kgsl_sync_fence_async_cancel(*(_QWORD *)(v8 + 32));
        v9 = 1LL << v6;
        _X10 = (unsigned __int64 *)(a1 + 72 + 8 * (v6 >> 6));
        __asm { PRFM            #0x11, [X10] }
        do
          v16 = __ldxr(_X10);
        while ( __stlxr(v16 & ~v9, _X10) );
        __dmb(0xBu);
        if ( a1 )
        {
          if ( (v16 & v9) != 0 )
          {
            __asm { PRFM            #0x11, [X20] }
            do
              v18 = __ldxr(_X20);
            while ( __stlxr(v18 - 1, _X20) );
            if ( v18 == 1 )
            {
              __dmb(9u);
              kgsl_drawobj_destroy_object(a1 + 32);
            }
            else if ( v18 <= 0 )
            {
              refcount_warn_saturate(a1 + 32, 3);
            }
          }
        }
      }
      ++v6;
      v5 += 120;
    }
    while ( v6 < *(unsigned int *)(a1 + 64) );
  }
  if ( *(_DWORD *)(a1 + 136) )
  {
    v19 = 0;
    do
    {
      _X0 = *(unsigned int **)(*(_QWORD *)(a1 + 144) + 16LL * (int)v19 + 8);
      if ( _X0 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v23 = __ldxr(_X0);
        while ( __stlxr(v23 - 1, _X0) );
        if ( v23 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy(_X0);
        }
        else if ( v23 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      v20 = *(_QWORD *)(a1 + 144) + 16LL * (int)v19++;
      *(_QWORD *)(v20 + 8) = 0;
    }
    while ( v19 < *(_DWORD *)(a1 + 136) );
  }
  return kgsl_drawobj_destroy(a1, a2, a3, a4);
}
