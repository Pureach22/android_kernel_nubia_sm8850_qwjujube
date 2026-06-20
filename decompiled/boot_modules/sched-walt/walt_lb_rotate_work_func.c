__int64 __usercall walt_lb_rotate_work_func@<X0>(__int64 result@<X0>, _BYTE *a2@<X8>)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x19
  _QWORD *v4; // x22
  __int64 v5; // x3
  __int64 v6; // x2
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v11; // x0
  char *v12; // x20
  char *v13; // x21
  int v20; // w9
  int v22; // w9
  unsigned __int64 StatusReg; // x23
  __int64 v25; // x9
  unsigned __int64 v28; // x11
  unsigned __int64 v31; // x10

  v5 = *(unsigned int *)(result + 48);
  if ( (unsigned int)v5 >= 0x20 )
    goto LABEL_22;
  v6 = *(unsigned int *)(result + 52);
  v3 = result;
  if ( (unsigned int)v6 > 0x1F )
    goto LABEL_22;
  v4 = &_per_cpu_offset;
  v7 = *((_QWORD *)&_per_cpu_offset + v5);
  v8 = *((_QWORD *)&_per_cpu_offset + v6);
  migrate_swap(*(_QWORD *)(result + 32), *(_QWORD *)(result + 40));
  v9 = *(_QWORD *)(v3 + 32);
  _X0 = (unsigned int *)(v9 + 64);
  __asm { PRFM            #0x11, [X0] }
  do
    v20 = __ldxr(_X0);
  while ( __stlxr(v20 - 1, _X0) );
  if ( v20 == 1 )
  {
    __dmb(9u);
    _put_task_struct(v9);
  }
  else if ( v20 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  v11 = *(_QWORD *)(v3 + 40);
  v12 = (char *)&runqueues + v7;
  v13 = (char *)&runqueues + v8;
  _X8 = (unsigned int *)(v11 + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stlxr(v22 - 1, _X8) );
  if ( v22 == 1 )
  {
    __dmb(9u);
    _put_task_struct(v11);
  }
  else if ( v22 <= 0 )
  {
    refcount_warn_saturate(v11 + 64, 3);
  }
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  double_rq_lock(v12, v13);
  *((_DWORD *)v13 + 894) = 0;
  *((_DWORD *)v12 + 894) = 0;
  if ( v12 != v13 )
    raw_spin_rq_unlock(v13);
  result = raw_spin_rq_unlock(v12);
  _WriteStatusReg(DAIF, StatusReg);
  a2 = (_BYTE *)*(unsigned int *)(v3 + 48);
  if ( (unsigned int)a2 >= 0x20 )
    goto LABEL_22;
  v25 = *((_QWORD *)&_per_cpu_offset + (_QWORD)a2);
  a2 = walt_rq;
  v2 = (unsigned __int64)&walt_rq[v25];
  while ( 1 )
  {
    _X9 = (unsigned __int64 *)(v2 + 80);
    __asm { PRFM            #0x11, [X9] }
    do
      v28 = __ldxr(_X9);
    while ( __stxr(v28 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
    v2 = *(unsigned int *)(v3 + 52);
    if ( (unsigned int)v2 < 0x20 )
      break;
LABEL_22:
    __break(0x5512u);
  }
  _X8 = (unsigned __int64 *)&a2[v4[v2] + 80];
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  return result;
}
