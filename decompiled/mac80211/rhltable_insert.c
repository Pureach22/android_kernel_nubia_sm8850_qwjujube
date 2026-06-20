__int64 __fastcall rhltable_insert(__int64 *a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v5; // x25
  unsigned int v6; // w21
  _DWORD *v7; // x24
  __int64 (__fastcall *v8)(__int64 **, unsigned __int64); // x26
  const void *v9; // x22
  __int64 v10; // x23
  unsigned __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x8
  unsigned __int64 StatusReg; // x25
  unsigned __int64 v23; // x12
  unsigned __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x27
  unsigned __int64 v28; // x28
  unsigned __int64 *v29; // x21
  int v30; // w25
  unsigned __int64 v31; // x1
  unsigned __int64 v32; // x19
  __int64 v33; // x8
  bool v34; // cc
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned int inserted; // w19
  unsigned __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x2
  __int64 (__fastcall *v43)(__int64, __int64, __int64); // x8
  __int64 v44; // x0
  __int64 v45; // x1
  unsigned int v49; // w9
  unsigned __int64 v51; // x9
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // [xsp+8h] [xbp-28h]
  unsigned __int64 v55; // [xsp+10h] [xbp-20h]
  __int64 *v56; // [xsp+18h] [xbp-18h] BYREF
  const void *v57; // [xsp+20h] [xbp-10h]
  __int64 v58; // [xsp+28h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int16 *)(a3 + 4);
  v6 = *(unsigned __int16 *)(a3 + 2);
  v7 = *(_DWORD **)(a3 + 24);
  v8 = *(__int64 (__fastcall **)(__int64 **, unsigned __int64))(a3 + 32);
  v9 = (const void *)(a2 - *((unsigned __int16 *)a1 + 11) + v5);
  v56 = a1;
  v57 = v9;
  _rcu_read_lock(a1, a2);
  v10 = *a1;
  v11 = a2 - *((unsigned __int16 *)a1 + 11);
  if ( v7 )
  {
    if ( !v6 )
      v6 = *((unsigned __int16 *)a1 + 9);
    v12 = *(unsigned int *)(v10 + 8);
    if ( *(v7 - 1) != 1342709798 )
      __break(0x8238u);
    v13 = ((__int64 (__fastcall *)(unsigned __int64, _QWORD, __int64))v7)(v11, v6, v12);
  }
  else
  {
    v42 = *(unsigned int *)(v10 + 8);
    v43 = (__int64 (__fastcall *)(__int64, __int64, __int64))a1[4];
    v44 = v11 + v5;
    v45 = *((unsigned int *)a1 + 2);
    if ( *((_DWORD *)v43 - 1) != 1342709798 )
      __break(0x8228u);
    v13 = v43(v44, v45, v42);
  }
  v14 = (*(_DWORD *)v10 - 1) & (unsigned int)v13;
  if ( !*(_DWORD *)(v10 + 4) )
  {
    v15 = v10 + 8LL * (unsigned int)v14;
    _X24 = v15 + 64;
    if ( v15 != -64 )
      goto LABEL_9;
LABEL_67:
    inserted = -12;
LABEL_68:
    _rcu_read_unlock(v13);
    goto LABEL_69;
  }
  v13 = rht_bucket_nested_insert(a1, v10, v14);
  _X24 = v13;
  if ( !v13 )
    goto LABEL_67;
LABEL_9:
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v23 + 16);
  if ( (*(_QWORD *)_X24 & 1) != 0 )
    goto LABEL_13;
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X24] }
    do
      v25 = __ldaxr((unsigned __int64 *)_X24);
    while ( __stxr(v25 | 1, (unsigned __int64 *)_X24) );
    if ( (v25 & 1) == 0 )
      break;
    do
    {
LABEL_13:
      v26 = *(_QWORD *)(v23 + 16) - 1LL;
      *(_DWORD *)(v23 + 16) = v26;
      if ( !v26 || !*(_QWORD *)(v23 + 16) )
      {
        v27 = v23;
        v13 = preempt_schedule();
        v23 = v27;
      }
      do
        __yield();
      while ( (*(_QWORD *)_X24 & 1) != 0 );
      ++*(_DWORD *)(v23 + 16);
    }
    while ( (*(_QWORD *)_X24 & 1) != 0 );
  }
  if ( *(_QWORD *)(v10 + 48) )
    goto LABEL_52;
  if ( (*(_QWORD *)_X24 & 0xFFFFFFFFFFFFFFFELL) != 0 )
    v28 = *(_QWORD *)_X24 & 0xFFFFFFFFFFFFFFFELL;
  else
    v28 = _X24 | 1;
  if ( (v28 & 1) == 0 )
  {
    v54 = v23;
    v55 = StatusReg;
    v29 = nullptr;
    v30 = 16;
    do
    {
      if ( v9 )
      {
        v31 = v28 - *((unsigned __int16 *)a1 + 11);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != -2113640079 )
            __break(0x823Au);
          v13 = v8(&v56, v31);
          if ( !(_DWORD)v13 )
          {
LABEL_32:
            *(_QWORD *)(a2 + 8) = v28;
            *(_QWORD *)a2 = *(_QWORD *)v28;
            if ( v29 )
            {
              atomic_store(a2, v29);
              v32 = v55;
              __asm { PRFM            #0x11, [X24] }
              do
                v51 = __ldxr((unsigned __int64 *)_X24);
              while ( __stlxr(v51 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X24) );
              v33 = *(_QWORD *)(v54 + 16) - 1LL;
              *(_DWORD *)(v54 + 16) = v33;
              if ( v33 && *(_QWORD *)(v54 + 16) )
                goto LABEL_61;
            }
            else
            {
              if ( (a2 & 1) != 0 )
                v40 = 0;
              else
                v40 = a2;
              atomic_store(v40, (unsigned __int64 *)_X24);
              v32 = v55;
              v41 = *(_QWORD *)(v54 + 16) - 1LL;
              *(_DWORD *)(v54 + 16) = v41;
              if ( v41 && *(_QWORD *)(v54 + 16) )
                goto LABEL_61;
            }
            v13 = preempt_schedule();
LABEL_61:
            _WriteStatusReg(DAIF, v32);
            goto LABEL_62;
          }
        }
        else
        {
          v13 = bcmp((const void *)(v31 + *((unsigned __int16 *)v56 + 10)), v57, *((unsigned __int16 *)v56 + 9));
          if ( !(_DWORD)v13 )
            goto LABEL_32;
        }
      }
      --v30;
      v29 = (unsigned __int64 *)v28;
      v28 = *(_QWORD *)v28;
    }
    while ( (v28 & 1) == 0 );
    v34 = v30 < 1;
    v23 = v54;
    StatusReg = v55;
    if ( v34 )
      goto LABEL_52;
  }
  if ( *((_DWORD *)a1 + 37) >= *((_DWORD *)a1 + 3) )
  {
    v13 = (__int64)rht_unlock((unsigned __int64 *)_X24, StatusReg);
    inserted = -7;
    goto LABEL_68;
  }
  if ( *((_DWORD *)a1 + 37) <= *(_DWORD *)v10 || (unsigned int)(*((_DWORD *)a1 + 6) - 1) < *(_DWORD *)v10 )
  {
    v35 = *(_QWORD *)_X24 & 0xFFFFFFFFFFFFFFFELL;
    if ( !v35 )
      v35 = _X24 | 1;
    *(_QWORD *)a2 = v35;
    *(_QWORD *)(a2 + 8) = 0;
    _X8 = (unsigned int *)a1 + 37;
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 + 1, _X8) );
    if ( (a2 & 1) != 0 )
      v36 = 0;
    else
      v36 = a2;
    atomic_store(v36, (unsigned __int64 *)_X24);
    v37 = *(_QWORD *)(v23 + 16) - 1LL;
    *(_DWORD *)(v23 + 16) = v37;
    if ( !v37 || !*(_QWORD *)(v23 + 16) )
      v13 = preempt_schedule();
    _WriteStatusReg(DAIF, StatusReg);
    if ( *((_DWORD *)a1 + 37) > (unsigned int)(3 * (*(_DWORD *)v10 >> 2))
      && (unsigned int)(*((_DWORD *)a1 + 6) - 1) >= *(_DWORD *)v10 )
    {
      v13 = queue_work_on(32, system_wq, a1 + 8);
    }
LABEL_62:
    inserted = 0;
    goto LABEL_68;
  }
LABEL_52:
  __asm { PRFM            #0x11, [X24] }
  do
    v53 = __ldxr((unsigned __int64 *)_X24);
  while ( __stlxr(v53 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X24) );
  v38 = *(_QWORD *)(v23 + 16) - 1LL;
  *(_DWORD *)(v23 + 16) = v38;
  if ( !v38 || !*(_QWORD *)(v23 + 16) )
    v13 = preempt_schedule();
  _WriteStatusReg(DAIF, StatusReg);
  _rcu_read_unlock(v13);
  inserted = rhashtable_insert_slow(a1, v9, a2);
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return inserted;
}
