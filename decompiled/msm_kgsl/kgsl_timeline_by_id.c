__int64 __fastcall kgsl_timeline_by_id(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  unsigned int v6; // w9
  unsigned int v7; // w20
  unsigned int v13; // w10
  __int64 v14; // x20
  __int64 v16; // x22

  raw_spin_lock(a1 + 13400);
  v4 = idr_find(a1 + 13376, a2);
  if ( v4 )
  {
    _X8 = (unsigned int *)(v4 + 32);
    v6 = *(_DWORD *)(v4 + 32);
    if ( v6 )
    {
      do
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr(_X8);
        while ( v13 == v6 && __stxr(v6 + 1, _X8) );
        v7 = v6;
        if ( v13 == v6 )
          break;
        v7 = 0;
        v6 = v13;
      }
      while ( v13 );
    }
    else
    {
      v7 = 0;
    }
    if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
    {
      v16 = v4;
      refcount_warn_saturate(v4 + 32, 0);
      v4 = v16;
    }
    if ( v7 )
      v14 = v4;
    else
      v14 = 0;
  }
  else
  {
    v14 = 0;
  }
  raw_spin_unlock(a1 + 13400);
  return v14;
}
