void __fastcall mem_buf_vmperm_gh_notifier(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x19
  unsigned int v8; // w8
  unsigned int v9; // w20
  unsigned int v15; // w9
  void (*v17)(void); // x8
  int v19; // w9

  if ( a2 != 1360003090 )
    return;
  v4 = *a4;
  _rcu_read_lock();
  v5 = xa_load(&vmperm_xa, v4);
  if ( !v5 )
    goto LABEL_19;
  v6 = v5;
  _X0 = *(unsigned int **)(v5 + 160);
  v8 = *_X0;
  if ( *_X0 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr(_X0);
      while ( v15 == v8 && __stxr(v8 + 1, _X0) );
      v9 = v8;
      if ( v15 == v8 )
        break;
      v9 = 0;
      v8 = v15;
    }
    while ( v15 );
  }
  else
  {
    v9 = 0;
  }
  if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X0, 0);
    if ( v9 )
      goto LABEL_14;
LABEL_19:
    _rcu_read_unlock();
    return;
  }
  if ( !v9 )
    goto LABEL_19;
LABEL_14:
  _rcu_read_unlock();
  mem_buf_vmperm_try_reclaim(v6, 1);
  v17 = *(void (**)(void))(v6 + 152);
  _X0 = *(unsigned int **)(v6 + 160);
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr(_X0);
  while ( __stlxr(v19 - 1, _X0) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    if ( *((_DWORD *)v17 - 1) != -2006492174 )
      __break(0x8228u);
    v17();
  }
  else if ( v19 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
}
