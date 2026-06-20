__int64 __fastcall icnss_block_shutdown(__int64 result)
{
  unsigned __int64 v7; // x10
  unsigned __int64 v10; // x11

  if ( penv )
  {
    if ( (result & 1) != 0 )
    {
      _X9 = (unsigned __int64 *)(penv + 1832);
      __asm { PRFM            #0x11, [X9] }
      do
        v7 = __ldxr(_X9);
      while ( __stxr(v7 | 0x20000, _X9) );
      *(_DWORD *)(penv + 3088) = 0;
    }
    else
    {
      _X9 = (unsigned __int64 *)(penv + 1832);
      __asm { PRFM            #0x11, [X9] }
      do
        v10 = __ldxr(_X9);
      while ( __stxr(v10 & 0xFFFFFFFFFFFDFFFFLL, _X9) );
      return complete(penv + 3088);
    }
  }
  return result;
}
