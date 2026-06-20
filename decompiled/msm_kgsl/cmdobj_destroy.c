unsigned int *__fastcall cmdobj_destroy(unsigned int *result)
{
  unsigned int *v1; // x19
  unsigned int **v2; // x1
  unsigned int **v3; // x8
  unsigned int *v4; // x22
  unsigned int **v5; // x9
  unsigned int **v6; // x1
  unsigned int **v7; // x8
  unsigned int *v8; // x22
  unsigned int **v9; // x9
  unsigned int v16; // w10
  unsigned int v19; // w10
  int v21; // w8

  v1 = result;
  if ( (result[6] & 0x10) != 0 )
  {
    result = *((unsigned int **)result + 16);
    if ( result )
    {
      if ( (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v21 = __ldxr(result);
        while ( __stlxr(v21 - 1, result) );
        if ( v21 == 1 )
        {
          __dmb(9u);
          result = (unsigned int *)kgsl_mem_entry_destroy(result);
        }
        else if ( v21 <= 0 )
        {
          result = (unsigned int *)refcount_warn_saturate(result, 3);
        }
      }
    }
  }
  v2 = *((unsigned int ***)v1 + 11);
  if ( v2 != (unsigned int **)(v1 + 22) )
  {
    do
    {
      v4 = *v2;
      v3 = (unsigned int **)v2[1];
      if ( *v3 == (unsigned int *)v2 && *((unsigned int ***)v4 + 1) == v2 )
      {
        *((_QWORD *)v4 + 1) = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
        v2 = v5;
      }
      *v2 = (unsigned int *)v2;
      v2[1] = (unsigned int *)v2;
      result = (unsigned int *)kmem_cache_free(memobjs_cache, v2);
      v2 = (unsigned int **)v4;
    }
    while ( v4 != v1 + 22 );
  }
  v6 = *((unsigned int ***)v1 + 13);
  if ( v6 != (unsigned int **)(v1 + 26) )
  {
    do
    {
      v8 = *v6;
      v7 = (unsigned int **)v6[1];
      if ( *v7 == (unsigned int *)v6 && *((unsigned int ***)v8 + 1) == v6 )
      {
        *((_QWORD *)v8 + 1) = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
        v6 = v9;
      }
      *v6 = (unsigned int *)v6;
      v6[1] = (unsigned int *)v6;
      result = (unsigned int *)kmem_cache_free(memobjs_cache, v6);
      v6 = (unsigned int **)v8;
    }
    while ( v8 != v1 + 26 );
  }
  if ( (v1[4] & 1) != 0 )
  {
    _X8 = (unsigned int *)(*(_QWORD *)(*((_QWORD *)v1 + 1) + 24LL) + 496LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 - 1, _X8) );
    _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1 + 1) + 24LL) + 488LL) + 56LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 - 1, _X8) );
  }
  return result;
}
