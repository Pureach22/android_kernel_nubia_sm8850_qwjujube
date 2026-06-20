__int64 __fastcall kgsl_context_get_owner(__int64 *a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int v6; // w23
  unsigned int v12; // w8
  __int64 v13; // x20
  __int64 result; // x0
  int v16; // w8

  v2 = *a1;
  raw_read_lock(*a1 + 11208);
  _X0 = idr_find(v2 + 11184, a2);
  if ( !_X0 || (*(_QWORD *)(_X0 + 32) & 2) != 0 )
  {
    raw_read_unlock(v2 + 11208);
  }
  else
  {
    v6 = *(_DWORD *)_X0;
    if ( *(_DWORD *)_X0 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v12 = __ldxr((unsigned int *)_X0);
        while ( v12 == v6 && __stxr(v6 + 1, (unsigned int *)_X0) );
        if ( v12 == v6 )
          break;
        v6 = v12;
      }
      while ( v12 );
    }
    v13 = _X0;
    if ( (((v6 + 1) | v6) & 0x80000000) != 0 )
      refcount_warn_saturate(_X0, 0);
    raw_read_unlock(v2 + 11208);
    if ( v6 )
    {
      result = v13;
      if ( *(__int64 **)(v13 + 16) == a1 )
        return result;
      __asm { PRFM            #0x11, [X0] }
      do
        v16 = __ldxr((unsigned int *)v13);
      while ( __stlxr(v16 - 1, (unsigned int *)v13) );
      if ( v16 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(v13);
      }
      else if ( v16 <= 0 )
      {
        refcount_warn_saturate(v13, 3);
      }
    }
  }
  return 0;
}
