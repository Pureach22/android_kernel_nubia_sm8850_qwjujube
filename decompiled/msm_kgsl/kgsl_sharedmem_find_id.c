unsigned int *__fastcall kgsl_sharedmem_find_id(__int64 a1, unsigned int a2)
{
  unsigned int *v4; // x0
  unsigned int v6; // w8
  unsigned int v7; // w9
  unsigned int v13; // w10
  unsigned int v15; // [xsp+Ch] [xbp-4h]

  raw_spin_lock(a1 + 32);
  v4 = (unsigned int *)idr_find(a1 + 40, a2);
  _X20 = v4;
  if ( v4 )
  {
    if ( v4[66] || (unsigned __int64)v4 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_15;
    v6 = *v4;
    if ( *v4 )
    {
      do
      {
        __asm { PRFM            #0x11, [X20] }
        do
          v13 = __ldxr(v4);
        while ( v13 == v6 && __stxr(v6 + 1, v4) );
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
      v15 = v7;
      refcount_warn_saturate(v4, 0);
      if ( v15 )
        goto LABEL_16;
      goto LABEL_15;
    }
    if ( !v7 )
LABEL_15:
      _X20 = nullptr;
  }
LABEL_16:
  raw_spin_unlock(a1 + 32);
  return _X20;
}
