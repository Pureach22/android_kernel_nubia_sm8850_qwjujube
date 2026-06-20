unsigned __int64 __fastcall kgsl_sharedmem_free_bind_op(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x8
  unsigned int v12; // w9
  int v14; // w8
  int v17; // w8

  if ( result )
  {
    v1 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(int *)(result + 16) >= 1 )
      {
        v2 = 0;
        v3 = 24;
        do
        {
          v4 = *(_QWORD *)(*(_QWORD *)(v1 + 8) + v3);
          if ( v4 )
          {
            _X8 = (unsigned int *)(v4 + 372);
            __asm { PRFM            #0x11, [X8] }
            do
              v12 = __ldxr(_X8);
            while ( __stxr(v12 - 1, _X8) );
          }
          _X0 = *(unsigned int **)(*(_QWORD *)(v1 + 8) + v3);
          if ( _X0 )
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v14 = __ldxr(_X0);
            while ( __stlxr(v14 - 1, _X0) );
            if ( v14 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy_deferred(_X0);
            }
            else if ( v14 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          ++v2;
          v3 += 32;
        }
        while ( v2 < *(int *)(v1 + 16) );
      }
      _X0 = *(unsigned int **)v1;
      if ( *(_QWORD *)v1 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v17 = __ldxr(_X0);
        while ( __stlxr(v17 - 1, _X0) );
        if ( v17 == 1 )
        {
          __dmb(9u);
          kgsl_mem_entry_destroy_deferred(_X0);
        }
        else if ( v17 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      kvfree(*(_QWORD *)(v1 + 8));
      return kfree(v1);
    }
  }
  return result;
}
