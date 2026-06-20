unsigned __int64 __fastcall kgsl_drawobj_destroy(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  void (*v2)(void); // x8
  int v9; // w8
  int v11; // w8
  __int64 (__fastcall *v12)(_QWORD); // x8

  if ( result )
  {
    v1 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v2 = *(void (**)(void))(result + 40);
      if ( *((_DWORD *)v2 - 1) != 287870130 )
        __break(0x8228u);
      v2();
      result = v1 + 32;
      __asm { PRFM            #0x11, [X0] }
      do
        v9 = __ldxr((unsigned int *)result);
      while ( __stlxr(v9 - 1, (unsigned int *)result) );
      if ( v9 == 1 )
      {
        __dmb(9u);
        _X0 = *(unsigned int **)(v1 + 8);
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v11 = __ldxr(_X0);
          while ( __stlxr(v11 - 1, _X0) );
          if ( v11 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy((__int64)_X0);
          }
          else if ( v11 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v12 = *(__int64 (__fastcall **)(_QWORD))(v1 + 48);
        if ( *((_DWORD *)v12 - 1) != 287870130 )
          __break(0x8228u);
        return v12(v1);
      }
      else if ( v9 <= 0 )
      {
        return refcount_warn_saturate(result, 3);
      }
    }
  }
  return result;
}
