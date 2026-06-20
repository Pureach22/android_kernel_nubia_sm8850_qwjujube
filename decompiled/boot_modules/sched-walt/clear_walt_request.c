unsigned int *__usercall clear_walt_request@<X0>(unsigned int *result@<X0>, __int64 a2@<X8>)
{
  char *v2; // x19
  _QWORD *v3; // x20
  __int64 v4; // x21
  char *v5; // x22
  __int64 v6; // x9
  __int64 v7; // x20
  unsigned __int64 v10; // x10
  unsigned __int64 v17; // x10
  int v19; // w8

  if ( (unsigned int)result >= 0x20 )
    goto LABEL_11;
  v3 = &_per_cpu_offset;
  a2 = *((_QWORD *)&_per_cpu_offset + (unsigned int)result);
  v2 = (char *)&runqueues + a2;
  v6 = *(unsigned int *)((char *)&runqueues + a2 + 3632);
  if ( (unsigned int)v6 > 0x1F )
    goto LABEL_11;
  v4 = *((_QWORD *)&_per_cpu_offset + v6);
  v5 = (char *)&walt_rq;
  a2 += (__int64)&walt_rq;
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(a2 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    if ( !*(_QWORD *)&v5[v4] )
      break;
    result = (unsigned int *)raw_spin_lock_irqsave(v2);
    if ( !*(_QWORD *)&v5[v4] )
    {
      *((_DWORD *)v2 + 894) = 0;
      return (unsigned int *)raw_spin_unlock_irqrestore(v2, result);
    }
    a2 = *((unsigned int *)v2 + 895);
    if ( (unsigned int)a2 < 0x20 )
    {
      _X8 = (unsigned __int64 *)&v5[v3[a2] + 80];
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      v7 = *(_QWORD *)&v5[v4];
      *(_QWORD *)&v5[v4] = 0;
      *((_DWORD *)v2 + 894) = 0;
      result = (unsigned int *)raw_spin_unlock_irqrestore(v2, result);
      if ( v7 )
      {
        result = (unsigned int *)(v7 + 64);
        __asm { PRFM            #0x11, [X0] }
        do
          v19 = __ldxr(result);
        while ( __stlxr(v19 - 1, result) );
        if ( v19 == 1 )
        {
          __dmb(9u);
          return (unsigned int *)_put_task_struct(v7);
        }
        else if ( v19 <= 0 )
        {
          return (unsigned int *)refcount_warn_saturate();
        }
      }
      return result;
    }
LABEL_11:
    __break(0x5512u);
  }
  return result;
}
