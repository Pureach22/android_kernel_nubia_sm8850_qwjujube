__int64 __fastcall fastrpc_map_put(__int64 result)
{
  int v7; // w9

  if ( result )
  {
    _X8 = (unsigned int *)(result + 112);
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr(_X8);
    while ( __stlxr(v7 - 1, _X8) );
    if ( v7 == 1 )
    {
      __dmb(9u);
      return _fastrpc_free_map(result);
    }
    else if ( v7 <= 0 )
    {
      return refcount_warn_saturate(result + 112, 3);
    }
  }
  return result;
}
