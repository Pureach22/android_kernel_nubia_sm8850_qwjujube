unsigned int *__fastcall kref_put(unsigned int *result, __int64 (*a2)(void))
{
  int v7; // w8

  __asm { PRFM            #0x11, [X0] }
  do
    v7 = __ldxr(result);
  while ( __stlxr(v7 - 1, result) );
  if ( v7 == 1 )
  {
    __dmb(9u);
    if ( *((_DWORD *)a2 - 1) != -2006492174 )
      __break(0x8221u);
    return (unsigned int *)a2();
  }
  else if ( v7 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
