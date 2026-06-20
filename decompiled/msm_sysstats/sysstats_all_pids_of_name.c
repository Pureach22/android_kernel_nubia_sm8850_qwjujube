__int64 __fastcall sysstats_all_pids_of_name(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x23
  __int64 active; // x24
  _WORD *v6; // x0
  char *v7; // x22
  size_t v8; // x25
  char *v9; // x0
  const char *v10; // x21
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 tgid; // x22
  __int64 v14; // x25
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x27
  __int64 v19; // x0
  __int64 v20; // x28
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned __int64 v25; // x8
  int v31; // w8
  int v33; // w8
  unsigned __int64 v34; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  active = task_active_pid_ns(StatusReg);
  v6 = (_WORD *)nla_find(*(_QWORD *)(a2 + 8) + 20LL, (unsigned int)(**(_DWORD **)(a2 + 8) - 20), 3);
  if ( !v6 )
    return *(unsigned int *)(a1 + 112);
  v7 = (char *)(v6 + 2);
  v8 = *v6 == 4 ? 0LL : (unsigned __int16)(*v6 - 4) - (unsigned __int64)(v7[(unsigned __int16)(*v6 - 4) - 1] == 0);
  v9 = (char *)_kmalloc_noprof(v8 + 1, 3264);
  v10 = v9;
  if ( !v9 )
    return *(unsigned int *)(a1 + 112);
  memcpy(v9, v7, v8);
  v11 = *(unsigned int *)(a2 + 80);
  v10[v8] = 0;
  tgid = next_tgid(active, v11, 0);
  if ( !v12 )
    goto LABEL_29;
  v14 = v12;
  while ( strcmp((const char *)(v14 + 2320), v10) )
  {
LABEL_8:
    v15 = next_tgid(active, (unsigned int)(tgid + 1) | tgid & 0xFFFFFFFF00000000LL, v14);
    v14 = v16;
    tgid = v15;
    if ( !v16 )
      goto LABEL_29;
  }
  v17 = genlmsg_put(
          a1,
          *(unsigned int *)(*(_QWORD *)a2 + 52LL),
          *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
          &family,
          0,
          5);
  if ( !v17 )
  {
    _X0 = (unsigned int *)(v14 + 64);
    __asm { PRFM            #0x11, [X0] }
    do
      v31 = __ldxr(_X0);
    while ( __stlxr(v31 - 1, _X0) );
    if ( v31 == 1 )
    {
      __dmb(9u);
      _put_task_struct(v14);
    }
    else if ( v31 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    goto LABEL_29;
  }
  v18 = v17;
  v19 = nla_reserve(a1, 5, 8);
  if ( v19 )
  {
    v20 = v19;
    *(_QWORD *)(v19 + 4) = 0;
    _rcu_read_lock(v19);
    v21 = task_active_pid_ns(StatusReg);
    v22 = _task_pid_nr_ns(v14, 0, v21);
    *(_QWORD *)(v20 + 4) = (int)v22;
    _rcu_read_unlock(v22);
    *(_DWORD *)(v18 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v18 - 20);
    goto LABEL_8;
  }
  _X0 = (unsigned int *)(v14 + 64);
  __asm { PRFM            #0x11, [X0] }
  do
    v33 = __ldxr(_X0);
  while ( __stlxr(v33 - 1, _X0) );
  if ( v33 == 1 )
  {
    __dmb(9u);
    _put_task_struct(v14);
    v25 = v18 - 20;
    if ( v18 == 20 )
      goto LABEL_29;
  }
  else if ( v33 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
    v25 = v18 - 20;
    if ( v18 == 20 )
      goto LABEL_29;
  }
  else
  {
    v25 = v18 - 20;
    if ( v18 == 20 )
      goto LABEL_29;
  }
  v34 = *(_QWORD *)(a1 + 224);
  if ( v34 > v25 )
  {
    __break(0x800u);
    v34 = *(_QWORD *)(a1 + 224);
  }
  skb_trim(a1, (unsigned int)(v25 - v34));
LABEL_29:
  *(_QWORD *)(a2 + 80) = (unsigned int)tgid;
  kfree(v10);
  return *(unsigned int *)(a1 + 112);
}
