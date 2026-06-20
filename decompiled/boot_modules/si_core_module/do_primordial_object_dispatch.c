__int64 __fastcall do_primordial_object_dispatch(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w8
  __int64 v9; // x10
  unsigned int v11; // w21
  unsigned __int64 v15; // x20
  unsigned int v16; // w8
  int v17; // w21
  __int64 v18; // x8
  int v19; // w10
  __int64 i; // x9
  int v21; // w9
  unsigned int v27; // w9
  _DWORD *v28; // x8
  unsigned int v29; // w19
  unsigned int v30; // [xsp+Ch] [xbp-4h]

  if ( a3 == 1 )
    return 0;
  if ( a3 == 2 )
  {
    v8 = 0;
    do
      v9 = 24LL * v8++;
    while ( *(_DWORD *)(a4 + v9) );
    if ( v8 == 2 && *(_DWORD *)a4 == 1 )
    {
      msleep(**(unsigned int **)(a4 + 8));
      return 0;
    }
    return 4294967274LL;
  }
  v11 = a1;
  _X0 = (unsigned int *)_rcu_read_lock(a1, a2, a3, a4, a5, a6, a7, a8);
  v15 = primordial_object;
  if ( (unsigned __int64)primordial_object < 2 )
    goto LABEL_13;
  _X0 = (unsigned int *)(primordial_object + 8);
  v16 = *(_DWORD *)(primordial_object + 8);
  if ( v16 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v27 = __ldxr(_X0);
      while ( v27 == v16 && __stxr(v16 + 1, _X0) );
      if ( v27 == v16 )
        break;
      v16 = v27;
    }
    while ( v27 );
  }
  if ( (((v16 + 1) | v16) & 0x80000000) != 0 )
  {
    v30 = v16;
    _X0 = (unsigned int *)refcount_warn_saturate(_X0, 0);
    if ( !v30 )
      goto LABEL_13;
  }
  else if ( !v16 )
  {
LABEL_13:
    _rcu_read_unlock(_X0);
    goto LABEL_14;
  }
  _rcu_read_unlock(_X0);
  if ( !v15 )
  {
LABEL_14:
    printk(&unk_B3CA, "do_primordial_object_dispatch");
    v17 = -1;
    v18 = a4;
    while ( 1 )
    {
      v19 = *(_DWORD *)(a4 + 24LL * ++v17);
      if ( !v19 )
        break;
      if ( v19 == 3 )
      {
        for ( i = v17; ; i = v17 )
        {
          put_si_object(*(_QWORD *)(v18 + 24 * i + 8));
          v18 = a4;
          while ( 1 )
          {
            v21 = *(_DWORD *)(a4 + 24LL * ++v17);
            if ( v21 == 3 )
              break;
            if ( !v21 )
              return 4294967274LL;
          }
        }
      }
    }
    return 4294967274LL;
  }
  printk(&unk_B39A, "do_primordial_object_dispatch");
  v28 = *(_DWORD **)(*(_QWORD *)(v15 + 24) + 16LL);
  if ( *(v28 - 1) != -784462101 )
    __break(0x8228u);
  v29 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, __int64, __int64))v28)(v11, v15, a3, a4);
  put_si_object(v15);
  return v29;
}
