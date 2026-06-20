__int64 __fastcall rhltable_remove(__int64 *a1, unsigned __int64 *a2, __int64 a3)
{
  unsigned int v3; // w24
  __int64 (__fastcall *v5)(char *, __int64, __int64); // x26
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x23
  unsigned int v9; // w22
  char *v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  unsigned int v13; // w0
  __int64 v14; // x1
  __int64 v15; // x8
  unsigned __int64 v17; // x28
  unsigned __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x22
  unsigned __int64 v27; // x9
  unsigned __int64 *v28; // x8
  unsigned __int64 *v29; // x10
  unsigned __int64 *v30; // x9
  char v31; // w25
  __int64 v32; // x8
  __int64 v33; // x2
  __int64 (__fastcall *v34)(char *, __int64, __int64); // x8
  __int64 v35; // x1
  char *v36; // x0
  unsigned __int64 v38; // x8
  unsigned __int64 *v39; // x22
  unsigned __int64 v40; // x9
  __int64 v41; // x8
  unsigned __int64 v42; // x8
  __int64 v43; // x8
  unsigned __int64 v46; // x9
  unsigned int v49; // w10
  __int64 v50; // [xsp+8h] [xbp-8h]

  v3 = *(unsigned __int16 *)(a3 + 2);
  v5 = *(__int64 (__fastcall **)(char *, __int64, __int64))(a3 + 24);
  v50 = *(unsigned __int16 *)(a3 + 4);
  _rcu_read_lock(a1, a2);
  v7 = *a1;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v10 = (char *)a2 - *((unsigned __int16 *)a1 + 11);
    if ( v5 )
    {
      v11 = v3;
      if ( !v3 )
        v11 = *((unsigned __int16 *)a1 + 9);
      v12 = *(unsigned int *)(v7 + 8);
      if ( *((_DWORD *)v5 - 1) != 1342709798 )
        __break(0x823Au);
      v13 = v5(v10, v11, v12);
    }
    else
    {
      v33 = *(unsigned int *)(v7 + 8);
      v34 = (__int64 (__fastcall *)(char *, __int64, __int64))a1[4];
      v35 = *((unsigned int *)a1 + 2);
      v36 = &v10[v50];
      if ( *((_DWORD *)v34 - 1) != 1342709798 )
        __break(0x8228u);
      v13 = v34(v36, v35, v33);
    }
    v14 = (*(_DWORD *)v7 - 1) & v13;
    if ( *(_DWORD *)(v7 + 4) )
    {
      _X0 = _rht_bucket_nested(v7, v14);
      if ( !_X0 )
      {
LABEL_2:
        v9 = -2;
        goto LABEL_3;
      }
    }
    else
    {
      v15 = v7 + 8LL * (unsigned int)v14;
      _X0 = v15 + 64;
      if ( v15 == -64 )
        goto LABEL_2;
    }
    v17 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    ++*(_DWORD *)(StatusReg + 16);
    for ( ; (*(_QWORD *)_X0 & 1) != 0; ++*(_DWORD *)(StatusReg + 16) )
    {
LABEL_16:
      v25 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v25;
      if ( !v25 || !*(_QWORD *)(StatusReg + 16) )
      {
        v26 = _X0;
        preempt_schedule();
        _X0 = v26;
      }
      do
        __yield();
      while ( (*(_QWORD *)_X0 & 1) != 0 );
    }
    __asm { PRFM            #0x11, [X0] }
    do
      v24 = __ldaxr((unsigned __int64 *)_X0);
    while ( __stxr(v24 | 1, (unsigned __int64 *)_X0) );
    if ( (v24 & 1) != 0 )
      goto LABEL_16;
    v27 = _X0 | 1;
    if ( (*(_QWORD *)_X0 & 0xFFFFFFFFFFFFFFFELL) != 0 )
      v27 = *(_QWORD *)_X0 & 0xFFFFFFFFFFFFFFFELL;
    if ( (v27 & 1) != 0 )
    {
LABEL_33:
      v31 = 0;
      v9 = -2;
      goto LABEL_45;
    }
    if ( (unsigned __int64 *)v27 == a2 )
      break;
    while ( 1 )
    {
      v28 = (unsigned __int64 *)v27;
      v29 = (unsigned __int64 *)v27;
      do
      {
        v30 = v29;
        v29 = (unsigned __int64 *)v29[1];
      }
      while ( v29 && v29 != a2 );
      if ( v29 )
        break;
      v27 = *v28;
      if ( (*v28 & 1) != 0 )
        goto LABEL_33;
      if ( (unsigned __int64 *)v27 == a2 )
        goto LABEL_49;
    }
    v9 = 0;
    v31 = 1;
    v30[1] = v29[1];
LABEL_45:
    __asm { PRFM            #0x11, [X0] }
    do
      v38 = __ldxr((unsigned __int64 *)_X0);
    while ( __stlxr(v38 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X0) );
    v32 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v32;
    if ( !v32 || !*(_QWORD *)(StatusReg + 16) )
      _X0 = preempt_schedule();
    _WriteStatusReg(DAIF, v17);
    if ( (v31 & 1) != 0 )
      goto LABEL_68;
LABEL_3:
    v7 = *(_QWORD *)(v7 + 48);
    if ( !v7 )
      goto LABEL_69;
  }
  v28 = nullptr;
LABEL_49:
  v39 = *(unsigned __int64 **)(v27 + 8);
  v40 = *a2;
  if ( v39 )
  {
    *v39 = v40;
    v40 = (unsigned __int64)v39;
  }
  if ( v28 )
  {
    atomic_store(v40, v28);
    __asm { PRFM            #0x11, [X0] }
    do
      v46 = __ldxr((unsigned __int64 *)_X0);
    while ( __stlxr(v46 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X0) );
    v41 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v41;
    if ( !v41 || !*(_QWORD *)(StatusReg + 16) )
      _X0 = preempt_schedule();
    _WriteStatusReg(DAIF, v17);
    if ( !v39 )
      goto LABEL_74;
  }
  else
  {
    if ( (v40 & 1) != 0 )
      v42 = 0;
    else
      v42 = v40;
    atomic_store(v42, (unsigned __int64 *)_X0);
    v43 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v43;
    if ( !v43 || !*(_QWORD *)(StatusReg + 16) )
      _X0 = preempt_schedule();
    _WriteStatusReg(DAIF, v17);
    if ( !v39 )
    {
LABEL_74:
      _X8 = (unsigned int *)a1 + 37;
      __asm { PRFM            #0x11, [X8] }
      do
        v49 = __ldxr(_X8);
      while ( __stxr(v49 - 1, _X8) );
      if ( *((_BYTE *)a1 + 30) == 1
        && *((_DWORD *)a1 + 37) < 3 * *(_DWORD *)v7 / 0xAu
        && *(_DWORD *)v7 > (unsigned int)*((unsigned __int16 *)a1 + 14) )
      {
        _X0 = queue_work_on(32, system_wq, a1 + 8);
      }
    }
  }
LABEL_68:
  v9 = 0;
LABEL_69:
  _rcu_read_unlock(_X0);
  return v9;
}
