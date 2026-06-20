unsigned int *__fastcall kgsl_syncsource_get(__int64 a1, int a2)
{
  unsigned int v5; // w8
  unsigned int v6; // w21
  unsigned int v12; // w9
  unsigned int *v13; // x20
  unsigned int *v15; // x20

  raw_spin_lock(a1 + 368);
  _X0 = (unsigned int *)idr_find(a1 + 344, a2);
  if ( _X0 )
  {
    v5 = *_X0;
    if ( *_X0 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v12 = __ldxr(_X0);
        while ( v12 == v5 && __stxr(v5 + 1, _X0) );
        v6 = v5;
        if ( v12 == v5 )
          break;
        v6 = 0;
        v5 = v12;
      }
      while ( v12 );
    }
    else
    {
      v6 = 0;
    }
    if ( (((v6 + 1) | v6) & 0x80000000) != 0 )
    {
      v15 = _X0;
      refcount_warn_saturate(_X0, 0);
      _X0 = v15;
    }
    if ( v6 )
      v13 = _X0;
    else
      v13 = nullptr;
  }
  else
  {
    v13 = nullptr;
  }
  raw_spin_unlock(a1 + 368);
  return v13;
}
