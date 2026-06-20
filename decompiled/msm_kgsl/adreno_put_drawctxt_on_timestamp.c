__int64 __fastcall adreno_put_drawctxt_on_timestamp(__int64 result, unsigned int *a2, __int64 a3, unsigned int a4)
{
  int v10; // w8

  if ( a2 )
  {
    _X19 = a2;
    result = kgsl_add_event(result, a3 + 40, a4, drawctxt_switch_wait_callback, a2);
    if ( (_DWORD)result )
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v10 = __ldxr(_X19);
      while ( __stlxr(v10 - 1, _X19) );
      if ( v10 == 1 )
      {
        __dmb(9u);
        return kgsl_context_destroy(_X19);
      }
      else if ( v10 <= 0 )
      {
        return refcount_warn_saturate(_X19, 3);
      }
    }
  }
  return result;
}
