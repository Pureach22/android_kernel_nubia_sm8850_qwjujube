unsigned int *__fastcall kref_put(unsigned int *result)
{
  unsigned int *v1; // x19
  __int64 v2; // x20
  int v8; // w8
  unsigned __int64 v11; // x9

  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(result);
  while ( __stlxr(v8 - 1, result) );
  if ( v8 == 1 )
  {
    __dmb(9u);
    v1 = result - 6;
    if ( *(_BYTE *)(*((_QWORD *)result - 2) + 25LL) == 10 )
    {
      _X8 = (unsigned __int64 *)(*(_QWORD *)v1 + 120LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 + 1, _X8) );
    }
    v2 = *((_QWORD *)result - 2);
    bio_end_io_acct_remapped(v2, *((_QWORD *)result - 1), *(_QWORD *)(v2 + 8));
    bio_endio(v2);
    return (unsigned int *)kfree(v1);
  }
  else if ( v8 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
