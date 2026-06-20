unsigned int *__fastcall kgsl_context_dump(unsigned int *result)
{
  unsigned int v1; // w8
  unsigned int v3; // w20
  unsigned int v9; // w9
  __int64 (*v10)(void); // x8
  int v12; // w8

  if ( result )
  {
    v1 = *result;
    _X19 = result;
    if ( *result )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v9 = __ldxr(result);
        while ( v9 == v1 && __stxr(v1 + 1, result) );
        v3 = v1;
        if ( v9 == v1 )
          break;
        v3 = 0;
        v1 = v9;
      }
      while ( v9 );
    }
    else
    {
      v3 = 0;
    }
    if ( (((v3 + 1) | v3) & 0x80000000) != 0 )
    {
      result = (unsigned int *)refcount_warn_saturate(result, 0);
      if ( !v3 )
        return result;
    }
    else if ( !v3 )
    {
      return result;
    }
    result = *((unsigned int **)_X19 + 5);
    if ( (*((_QWORD *)_X19 + 4) & 2) != 0 )
    {
      result = (unsigned int *)dev_err(*(_QWORD *)result, "  context[%u]: context detached\n", _X19[1]);
    }
    else
    {
      v10 = *(__int64 (**)(void))(*((_QWORD *)result + 1094) + 144LL);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 2043251089 )
          __break(0x8228u);
        result = (unsigned int *)v10();
      }
    }
    __asm { PRFM            #0x11, [X19] }
    do
      v12 = __ldxr(_X19);
    while ( __stlxr(v12 - 1, _X19) );
    if ( v12 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)kgsl_context_destroy(_X19);
    }
    else if ( v12 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(_X19, 3);
    }
  }
  return result;
}
