__int64 __fastcall kgsl_timeline_get(__int64 result)
{
  unsigned int v2; // w9
  unsigned int v3; // w19
  unsigned int v9; // w10
  __int64 v10; // x20

  if ( result )
  {
    _X8 = (unsigned int *)(result + 32);
    v2 = *(_DWORD *)(result + 32);
    if ( v2 )
    {
      do
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v9 = __ldxr(_X8);
        while ( v9 == v2 && __stxr(v2 + 1, _X8) );
        v3 = v2;
        if ( v9 == v2 )
          break;
        v3 = 0;
        v2 = v9;
      }
      while ( v9 );
    }
    else
    {
      v3 = 0;
    }
    if ( (((v3 + 1) | v3) & 0x80000000) == 0 )
    {
      if ( v3 )
        return result;
      return 0;
    }
    v10 = result;
    refcount_warn_saturate(result + 32, 0);
    result = v10;
    if ( !v3 )
      return 0;
  }
  return result;
}
