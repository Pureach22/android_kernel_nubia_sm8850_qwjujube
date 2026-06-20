__int64 *__fastcall cvp_get_inst(__int64 a1, __int64 *a2)
{
  __int64 *v2; // x19
  __int64 v5; // x0
  __int64 *v6; // x9
  unsigned int v7; // w10
  unsigned int v9; // w20
  unsigned int v15; // w11
  __int64 *v17; // [xsp+8h] [xbp-8h]

  v2 = nullptr;
  if ( a1 && a2 )
  {
    mutex_lock(a1);
    v5 = a1;
    v6 = (__int64 *)(a1 + 280);
    do
    {
      v6 = (__int64 *)*v6;
      if ( v6 == (__int64 *)(a1 + 280) )
        goto LABEL_15;
    }
    while ( v6 != a2 );
    if ( !v6[40] )
    {
LABEL_15:
      v2 = nullptr;
      goto LABEL_22;
    }
    v7 = *((_DWORD *)v6 + 3706);
    _X8 = (unsigned int *)(v6 + 1853);
    if ( v7 )
    {
      do
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v15 = __ldxr(_X8);
        while ( v15 == v7 && __stxr(v7 + 1, _X8) );
        v9 = v7;
        if ( v15 == v7 )
          break;
        v9 = 0;
        v7 = v15;
      }
      while ( v15 );
    }
    else
    {
      v9 = 0;
    }
    if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
    {
      v17 = v6;
      refcount_warn_saturate(v6 + 1853, 0);
      v6 = v17;
      v5 = a1;
    }
    if ( v9 )
      v2 = v6;
    else
      v2 = nullptr;
LABEL_22:
    mutex_unlock(v5);
  }
  return v2;
}
