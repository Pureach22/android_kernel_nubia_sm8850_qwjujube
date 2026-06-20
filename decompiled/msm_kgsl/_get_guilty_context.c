unsigned int *__fastcall get_guilty_context(__int64 a1)
{
  unsigned int v3; // w8
  unsigned int v4; // w24
  unsigned int v10; // w9
  unsigned int *v11; // x20
  unsigned __int64 v14; // x8
  unsigned int *v15; // x20
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_read_lock(a1 + 11208);
  v17 = 0;
  for ( _X0 = (unsigned int *)idr_get_next(a1 + 11184, &v17); _X0; _X0 = (unsigned int *)idr_get_next(a1 + 11184, &v17) )
  {
    _X9 = (unsigned __int64 *)(_X0 + 8);
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr(_X9);
    while ( __stlxr(v14 & 0xFFFFFFFFFFFDFFFFLL, _X9) );
    __dmb(0xBu);
    if ( (v14 & 0x20000) != 0 )
    {
      v3 = *_X0;
      if ( *_X0 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v10 = __ldxr(_X0);
          while ( v10 == v3 && __stxr(v3 + 1, _X0) );
          v4 = v3;
          if ( v10 == v3 )
            break;
          v4 = 0;
          v3 = v10;
        }
        while ( v10 );
      }
      else
      {
        v4 = 0;
      }
      if ( (((v4 + 1) | v4) & 0x80000000) != 0 )
      {
        v11 = _X0;
        refcount_warn_saturate(_X0, 0);
        _X0 = v11;
        if ( v4 )
          break;
      }
      else if ( v4 )
      {
        break;
      }
    }
    ++v17;
  }
  v15 = _X0;
  raw_read_unlock(a1 + 11208);
  _ReadStatusReg(SP_EL0);
  return v15;
}
