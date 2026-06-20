__int64 __fastcall adreno_ib_destroy_obj_list(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  int v10; // w8

  if ( result )
  {
    v1 = result;
    if ( *(int *)(result + 8) >= 1 )
    {
      v2 = 0;
      v3 = 24;
      do
      {
        _X0 = *(unsigned int **)(*(_QWORD *)v1 + v3);
        if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v10 = __ldxr(_X0);
          while ( __stlxr(v10 - 1, _X0) );
          if ( v10 == 1 )
          {
            __dmb(9u);
            kgsl_mem_entry_destroy();
          }
          else if ( v10 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        ++v2;
        v3 += 32;
      }
      while ( v2 < *(int *)(v1 + 8) );
    }
    vfree(*(_QWORD *)v1);
    return kfree(v1);
  }
  return result;
}
