__int64 __fastcall adreno_hwsched_drain_and_idle(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x22
  int v4; // w8
  __int64 v5; // x23
  unsigned int v7; // w20
  unsigned int v8; // w0
  unsigned int v9; // w8
  unsigned int v11; // w10
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 (__fastcall *v13)(_QWORD); // x8
  unsigned int v19; // w8

  result = adreno_drain(a1);
  if ( (_DWORD)result )
    return result;
  v3 = jiffies;
  if ( !a1[1389] )
  {
    __break(0x800u);
    return 4294967261LL;
  }
  v4 = *((_DWORD *)a1 + 2780);
  v5 = *(_QWORD *)(a1[1783] + 40LL);
  if ( v4 != 32 && v4 != 2 )
    return 0;
  _X24 = (unsigned int *)a1 + 5103;
  __asm { PRFM            #0x11, [X24] }
  do
    v19 = __ldxr(_X24);
  while ( __stxr(v19 + 1, _X24) );
  rt_mutex_unlock(a1 + 1386);
  kthread_flush_worker(a1[3050]);
  __dmb(9u);
  if ( *((_DWORD *)a1 + 6112) )
  {
    v7 = -35;
  }
  else
  {
    v8 = wait_for_completion_timeout(a1 + 2850, 5000);
    if ( v8 )
    {
      if ( (v8 & 0x80000000) != 0 )
      {
        v7 = v8;
        dev_err(*a1, "hwsched halt failed %d\n", v8);
      }
      else
      {
        v7 = 0;
      }
    }
    else
    {
      _warn_printk("hwsched halt timeout\n");
      __break(0x800u);
      v7 = -110;
    }
    __dmb(9u);
    if ( *((_DWORD *)a1 + 6112) )
      v7 = -35;
  }
  rt_mutex_lock(a1 + 1386);
  v9 = *_X24;
  result = v7;
  while ( (int)(v9 - 1) >= 0 )
  {
    __asm { PRFM            #0x11, [X24] }
    while ( 1 )
    {
      v11 = __ldxr(_X24);
      if ( v11 != v9 )
        break;
      if ( !__stlxr(v9 - 1, _X24) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v11 == v9;
    v9 = v11;
    if ( _ZF )
      goto LABEL_27;
  }
  _warn_printk("GPU halt refcount unbalanced\n");
  result = v7;
  __break(0x800u);
LABEL_27:
  if ( !(_DWORD)result )
  {
    while ( 1 )
    {
      __dmb(9u);
      if ( *((_DWORD *)a1 + 6112) )
        break;
      v12 = *(__int64 (__fastcall **)(_QWORD))(v5 + 120);
      if ( *((_DWORD *)v12 - 1) != -1780529452 )
        __break(0x8228u);
      if ( (v12(a1) & 1) != 0 )
        return 0;
      if ( jiffies - v3 - 5000 >= 0 )
      {
        __dmb(9u);
        if ( *((_DWORD *)a1 + 6112) )
          return 4294967261LL;
        v13 = *(__int64 (__fastcall **)(_QWORD))(v5 + 120);
        if ( *((_DWORD *)v13 - 1) != -1780529452 )
          __break(0x8228u);
        if ( (v13(a1) & 1) != 0 )
          return 0;
        else
          return 4294967186LL;
      }
    }
    return 4294967261LL;
  }
  return result;
}
