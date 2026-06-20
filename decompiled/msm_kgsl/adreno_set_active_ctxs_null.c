__int64 __fastcall adreno_set_active_ctxs_null(__int64 result)
{
  __int64 v1; // x19
  int v2; // w21
  unsigned int **v3; // x22
  __int64 v4; // x8
  int v11; // w8

  if ( *(int *)(result + 19632) >= 1 )
  {
    v1 = result;
    v2 = 0;
    v3 = (unsigned int **)(result + 14528);
    do
    {
      _X0 = *v3;
      if ( *v3 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v11 = __ldxr(_X0);
        while ( __stlxr(v11 - 1, _X0) );
        if ( v11 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy();
        }
        else if ( v11 <= 0 )
        {
          refcount_warn_saturate();
        }
      }
      v4 = *((int *)v3 - 37);
      *v3 = nullptr;
      result = kgsl_sharedmem_writel(*(_QWORD *)(v1 + 48), (32 * v4) | 0xC, 0);
      ++v2;
      v3 += 165;
    }
    while ( v2 < *(_DWORD *)(v1 + 19632) );
  }
  return result;
}
