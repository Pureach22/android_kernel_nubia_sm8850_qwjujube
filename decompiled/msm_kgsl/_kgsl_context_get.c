unsigned int *__fastcall kgsl_context_get(unsigned int *result)
{
  unsigned int v1; // w8
  unsigned int v2; // w19
  unsigned int v8; // w9

  if ( result )
  {
    v1 = *result;
    if ( *result )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v8 = __ldxr(result);
        while ( v8 == v1 && __stxr(v1 + 1, result) );
        v2 = v1;
        if ( v8 == v1 )
          break;
        v2 = 0;
        v1 = v8;
      }
      while ( v8 );
    }
    else
    {
      v2 = 0;
    }
    if ( (((v2 + 1) | v2) & 0x80000000) != 0 )
      refcount_warn_saturate(result, 0);
    return (unsigned int *)(v2 != 0);
  }
  return result;
}
