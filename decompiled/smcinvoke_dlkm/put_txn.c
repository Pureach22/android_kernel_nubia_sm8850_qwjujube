__int64 __fastcall put_txn(__int64 result)
{
  __int64 v2; // x20
  __int64 i; // x21
  int v4; // w9
  int v5; // w8
  __int64 v7; // x8
  int v13; // w8

  _X19 = result;
  __asm { PRFM            #0x11, [X19] }
  do
    v13 = __ldxr((unsigned int *)result);
  while ( __stlxr(v13 - 1, (unsigned int *)result) );
  if ( v13 == 1 )
  {
    __dmb(9u);
    v2 = *(_QWORD *)(result + 24);
    if ( v2 )
    {
      for ( i = 0; ; ++i )
      {
        v4 = 0;
        do
          v5 = v4;
        while ( *(_DWORD *)(v2 + 24LL * v4++) );
        if ( i >= v5 )
          break;
        v7 = v2 + 24 * i;
        if ( (unsigned int)(*(_DWORD *)v7 - 1) <= 1 )
          kfree(*(_QWORD *)(v7 + 8));
      }
      kfree(v2);
    }
    kfree(*(_QWORD *)(_X19 + 48));
    return kfree(_X19);
  }
  else if ( v13 <= 0 )
  {
    return refcount_warn_saturate(result, 3);
  }
  return result;
}
