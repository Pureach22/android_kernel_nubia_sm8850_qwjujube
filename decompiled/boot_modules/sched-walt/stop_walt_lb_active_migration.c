__int64 __usercall stop_walt_lb_active_migration@<X0>(char *a1@<X0>, unsigned __int64 a2@<X8>)
{
  __int64 v2; // x19
  char *v3; // x20
  char *v4; // x21
  __int64 v5; // x22
  _BYTE *v6; // x23
  char v7; // w25
  __int64 v8; // x27
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x9
  unsigned __int64 v15; // x10
  int v21; // w8

  v8 = *((unsigned int *)a1 + 895);
  if ( (unsigned int)v8 >= 0x20 )
    goto LABEL_24;
  v9 = *((unsigned int *)a1 + 908);
  v4 = a1;
  if ( (unsigned int)v9 > 0x1F )
    goto LABEL_24;
  v5 = *((_QWORD *)&_per_cpu_offset + v9);
  v6 = walt_rq;
  v3 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v8);
  v10 = raw_spin_lock_irq(a1);
  v2 = *(_QWORD *)&walt_rq[v5];
  v7 = 1;
  if ( ((_cpu_active_mask >> v9) & 1) != 0 )
  {
    v11 = 1LL << v8;
    if ( (_cpu_active_mask & (1LL << v8)) != 0 )
    {
      if ( v2 )
      {
        if ( (_DWORD)v9 != *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40)
          || !*((_DWORD *)v4 + 894)
          || *((_DWORD *)v4 + 1) < 2u )
        {
          goto LABEL_16;
        }
        if ( v3 == v4 )
        {
          __break(0x800u);
          return clear_reserved(v10);
        }
        if ( *(_DWORD *)(v2 + 144) == 1
          && !*(_DWORD *)(v2 + 48)
          && *(_DWORD *)(v2 + 40) == (_DWORD)v9
          && (_cpu_active_mask & v11) != 0
          && (**(_QWORD **)(v2 + 1376) & v11) != 0 )
        {
          walt_detach_task(v2, (__int64)v4, (__int64)v3);
          v7 = 0;
        }
        else
        {
LABEL_16:
          v7 = 1;
        }
      }
    }
  }
  a2 = *((unsigned int *)v4 + 895);
  *((_DWORD *)v4 + 894) = 0;
  if ( (unsigned int)a2 >= 0x20 )
LABEL_24:
    __break(0x5512u);
  else
    a2 = (unsigned __int64)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
  _X8 = (unsigned __int64 *)(a2 + 80);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  *(_QWORD *)&v6[v5] = 0;
  raw_spin_unlock(v4);
  if ( (v7 & 1) == 0 )
  {
    raw_spin_lock(v3);
    activate_task(v3, v2, 0);
    wakeup_preempt(v3, v2, 0);
    raw_spin_unlock(v3);
  }
  if ( v2 )
  {
    _X0 = (unsigned int *)(v2 + 64);
    __asm { PRFM            #0x11, [X0] }
    do
      v21 = __ldxr(_X0);
    while ( __stlxr(v21 - 1, _X0) );
    if ( v21 == 1 )
    {
      __dmb(9u);
      _put_task_struct(v2);
    }
    else if ( v21 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  __asm { MSR             DAIFClr, #3 }
  return 0;
}
