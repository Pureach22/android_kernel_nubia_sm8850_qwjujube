__int64 __fastcall fastrpc_free_user(_QWORD *a1)
{
  unsigned int *v2; // x20
  unsigned int *v3; // x22
  unsigned int *v4; // x25
  unsigned int **v5; // x8
  unsigned int *v6; // x9
  int v13; // w8
  unsigned int *v14; // x20
  unsigned int *v15; // x25
  unsigned int **v16; // x8
  unsigned int *v17; // x9
  int v20; // w8
  __int64 v21; // x0
  _QWORD *v22; // x0
  _QWORD *v23; // x21
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0

  v3 = (unsigned int *)(a1 + 6);
  v2 = (unsigned int *)a1[6];
  if ( v2 != (unsigned int *)(a1 + 6) )
  {
    do
    {
      v4 = *(unsigned int **)v2;
      raw_spin_lock(a1 + 40);
      v5 = *((unsigned int ***)v2 + 1);
      if ( *v5 == v2 && (v6 = *(unsigned int **)v2, *(unsigned int **)(*(_QWORD *)v2 + 8LL) == v2) )
      {
        *((_QWORD *)v6 + 1) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *(_QWORD *)v2 = 0xDEAD000000000100LL;
      *((_QWORD *)v2 + 1) = 0xDEAD000000000122LL;
      raw_spin_unlock(a1 + 40);
      _X0 = v2 + 26;
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( __stlxr(v13 - 1, _X0) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        fastrpc_context_free();
      }
      else if ( v13 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      v2 = v4;
    }
    while ( v4 != v3 );
  }
  v14 = (unsigned int *)a1[4];
  if ( v14 != (unsigned int *)(a1 + 4) )
  {
    do
    {
      v15 = *(unsigned int **)v14;
      raw_spin_lock(a1 + 40);
      v16 = *((unsigned int ***)v14 + 1);
      if ( *v16 == v14 && (v17 = *(unsigned int **)v14, *(unsigned int **)(*(_QWORD *)v14 + 8LL) == v14) )
      {
        *((_QWORD *)v17 + 1) = v16;
        *v16 = v17;
      }
      else
      {
        _list_del_entry_valid_or_report(v14);
      }
      *(_QWORD *)v14 = 0xDEAD000000000100LL;
      *((_QWORD *)v14 + 1) = 0xDEAD000000000122LL;
      raw_spin_unlock(a1 + 40);
      _X0 = v14 + 26;
      __asm { PRFM            #0x11, [X0] }
      do
        v20 = __ldxr(_X0);
      while ( __stlxr(v20 - 1, _X0) );
      if ( v20 == 1 )
      {
        __dmb(9u);
        fastrpc_context_free();
      }
      else if ( v20 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      v14 = v15;
    }
    while ( v15 != (unsigned int *)(a1 + 4) );
  }
  v21 = a1[20];
  if ( v21 )
  {
    fastrpc_buf_free(v21, 0);
    a1[20] = 0;
  }
  mutex_lock(a1 + 41);
  v22 = (_QWORD *)a1[2];
  if ( v22 != a1 + 2 )
  {
    do
    {
      v23 = (_QWORD *)*v22;
      _fastrpc_free_map();
      v22 = v23;
    }
    while ( v23 != a1 + 2 );
  }
  mutex_unlock(a1 + 41);
  fastrpc_buf_list_free(a1, a1 + 8, 0);
  v24 = a1[21];
  if ( v24 )
  {
    fastrpc_buf_free(v24, 0);
    a1[21] = 0;
  }
  v25 = a1[25];
  if ( v25 )
  {
    fastrpc_buf_free(v25, 0);
    a1[25] = 0;
  }
  v26 = a1[24];
  if ( v26 )
  {
    kfree(v26);
    a1[24] = 0;
  }
  return fastrpc_buf_list_free(a1, a1 + 10, 1);
}
