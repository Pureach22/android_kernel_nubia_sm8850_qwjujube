__int64 __fastcall drawobj_add_sync_timestamp(_QWORD *a1, __int64 a2, unsigned int *a3)
{
  __int64 v6; // x19
  __int64 v7; // x0
  unsigned int v9; // w24
  unsigned int v15; // w8
  unsigned int v16; // w2
  unsigned __int64 v18; // x8
  unsigned int *v19; // x24
  unsigned __int64 v20; // x9
  __int64 v21; // x8
  unsigned int v22; // w10
  __int64 result; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x8
  unsigned int v27; // w21
  __int64 v29; // x1
  unsigned int v31; // w8
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  int v39; // w8
  unsigned int v40; // w20
  int v42; // w8
  void (__fastcall *v43)(_QWORD); // x8
  unsigned int v44; // w20
  int v46; // w8

  _ReadStatusReg(SP_EL0);
  v6 = *a3;
  raw_read_lock(a1 + 1401);
  v7 = idr_find(a1 + 1398, v6);
  if ( !v7 || (_X19 = (unsigned int *)v7, (*(_QWORD *)(v7 + 32) & 2) != 0) )
  {
    raw_read_unlock(a1 + 1401);
LABEL_28:
    result = 4294967274LL;
    goto LABEL_29;
  }
  v9 = *(_DWORD *)v7;
  if ( *(_DWORD *)v7 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v15 = __ldxr((unsigned int *)v7);
      while ( v15 == v9 && __stxr(v9 + 1, (unsigned int *)v7) );
      if ( v15 == v9 )
        break;
      v9 = v15;
    }
    while ( v15 );
  }
  if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
    refcount_warn_saturate(v7, 0);
  raw_read_unlock(a1 + 1401);
  if ( !v9 )
    goto LABEL_28;
  if ( _X19 != *(unsigned int **)(a2 + 8)
    || (kgsl_readtimestamp((__int64)a1), (v16 = a3[1]) == 0)
    || (v16 & 0x80000000) != 0 && ((v16 ^ 0x80000000) <= 0x80000000 || (v16 ^ 0x80000000) + 0x80000000 >= 0x80000001) )
  {
    _X23 = (unsigned int *)(a2 + 32);
    __asm { PRFM            #0x11, [X23] }
    do
      v31 = __ldxr(_X23);
    while ( __stxr(v31 + 1, _X23) );
    if ( v31 )
    {
      if ( (((v31 + 1) | v31) & 0x80000000) == 0 )
        goto LABEL_20;
      v29 = 1;
    }
    else
    {
      v29 = 2;
    }
    refcount_warn_saturate(a2 + 32, v29);
LABEL_20:
    v18 = *(unsigned int *)(a2 + 64);
    v19 = (unsigned int *)(*(_QWORD *)(a2 + 56) + 120LL * (unsigned int)v18);
    *(_DWORD *)(a2 + 64) = v18 + 1;
    v20 = v18 >> 6;
    *(_QWORD *)v19 = (unsigned int)v18;
    v21 = 1LL << v18;
    *((_QWORD *)v19 + 1) = a2;
    *((_QWORD *)v19 + 2) = _X19;
    v22 = a3[1];
    *((_QWORD *)v19 + 5) = a1;
    v19[6] = v22;
    _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v20);
    __asm { PRFM            #0x11, [X9] }
    do
      v34 = __ldxr(_X9);
    while ( __stxr(v34 | v21, _X9) );
    result = kgsl_add_event(a1, _X19 + 16, a3[1], drawobj_sync_func, v19);
    if ( !(_DWORD)result )
    {
      result = 0;
      goto LABEL_29;
    }
    v24 = *v19;
    v25 = v24 >> 6;
    v26 = 1LL << v24;
    _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v25);
    __asm { PRFM            #0x11, [X9] }
    do
      v37 = __ldxr(_X9);
    while ( __stxr(v37 & ~v26, _X9) );
    if ( a2 )
    {
      __asm { PRFM            #0x11, [X23] }
      do
        v39 = __ldxr(_X23);
      while ( __stlxr(v39 - 1, _X23) );
      if ( v39 == 1 )
      {
        __dmb(9u);
        v27 = result;
        _X0 = *(unsigned int **)(a2 + 8);
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v42 = __ldxr(_X0);
          while ( __stlxr(v42 - 1, _X0) );
          if ( v42 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy((__int64)_X0);
          }
          else if ( v42 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v43 = *(void (__fastcall **)(_QWORD))(a2 + 48);
        if ( *((_DWORD *)v43 - 1) != 287870130 )
          __break(0x8228u);
        v43(a2);
        result = v27;
      }
      else if ( v39 <= 0 )
      {
        v40 = result;
        refcount_warn_saturate(_X23, 3);
        result = v40;
      }
    }
    goto LABEL_56;
  }
  dev_err(*a1, "Cannot create syncpoint for future timestamp %d (current %d)\n", v16, 0);
  result = 4294967274LL;
LABEL_56:
  __asm { PRFM            #0x11, [X19] }
  do
    v46 = __ldxr(_X19);
  while ( __stlxr(v46 - 1, _X19) );
  if ( v46 == 1 )
  {
    __dmb(9u);
    v44 = result;
    kgsl_context_destroy((__int64)_X19);
  }
  else
  {
    if ( v46 > 0 )
      goto LABEL_29;
    v44 = result;
    refcount_warn_saturate(_X19, 3);
  }
  result = v44;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
