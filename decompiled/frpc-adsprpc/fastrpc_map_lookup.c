__int64 __fastcall fastrpc_map_lookup(__int64 a1, unsigned int a2, unsigned __int64 a3, int a4, __int64 **a5, char a6)
{
  unsigned __int64 v11; // x20
  unsigned int v12; // w23
  unsigned __int64 v13; // x0
  __int64 *v14; // x8
  unsigned int v17; // w9
  unsigned int v18; // w23
  unsigned int v24; // w10
  __int64 *v25; // x24

  if ( a4 == 6 )
  {
    v11 = a3;
    if ( !a3 )
      return (unsigned int)-2;
  }
  else
  {
    v13 = dma_buf_get(a2);
    v11 = v13;
    if ( v13 >= 0xFFFFFFFFFFFFF001LL )
      return (unsigned int)v13;
  }
  raw_spin_lock(a1 + 320);
  v14 = *(__int64 **)(a1 + 16);
  if ( v14 == (__int64 *)(a1 + 16) )
    goto LABEL_7;
  while ( v14[4] != v11 || *((_DWORD *)v14 + 6) != a2 )
  {
    v14 = (__int64 *)*v14;
    if ( v14 == (__int64 *)(a1 + 16) )
      goto LABEL_7;
  }
  if ( (a6 & 1) != 0 )
  {
    if ( v14 )
    {
      _X0 = (unsigned int *)(v14 + 14);
      v17 = *((_DWORD *)v14 + 28);
      if ( v17 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v24 = __ldxr(_X0);
          while ( v24 == v17 && __stxr(v17 + 1, _X0) );
          v18 = v17;
          if ( v24 == v17 )
            break;
          v18 = 0;
          v17 = v24;
        }
        while ( v24 );
      }
      else
      {
        v18 = 0;
      }
      if ( (((v18 + 1) | v18) & 0x80000000) != 0 )
      {
        v25 = v14;
        refcount_warn_saturate(_X0, 0);
        v14 = v25;
        if ( v18 )
          goto LABEL_27;
      }
      else if ( v18 )
      {
        goto LABEL_27;
      }
    }
LABEL_7:
    v12 = -2;
    goto LABEL_8;
  }
LABEL_27:
  v12 = 0;
  *a5 = v14;
LABEL_8:
  raw_spin_unlock(a1 + 320);
  if ( a4 != 6 )
    dma_buf_put(v11);
  return v12;
}
