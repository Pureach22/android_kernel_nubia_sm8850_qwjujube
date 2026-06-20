__int64 __fastcall hdd_get_adapter(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x8
  unsigned __int64 v9; // x25
  __int64 v10; // x28
  __int64 v11; // x8
  int v12; // w28
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x8
  __int64 v24; // x8
  unsigned int *v25; // x8
  unsigned int v26; // w10
  __int64 v27; // x8
  unsigned int v34; // w9
  _QWORD *v35; // x1
  __int64 v36; // x9
  unsigned __int64 v37; // x8
  __int64 v38; // x9
  unsigned int *v39; // x9
  unsigned int v40; // w12
  __int64 v41; // x9
  __int64 v43; // x0
  __int64 v44; // x23
  __int64 v45; // x9
  unsigned __int64 v46; // x8
  __int64 v47; // x9
  unsigned int *v48; // x9
  unsigned int v49; // w12
  __int64 v50; // x9
  _QWORD *v53; // x22
  unsigned int v55; // w9
  unsigned int v57; // w9
  _QWORD v58[2]; // [xsp+0h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v58[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v58);
  if ( (_DWORD)v5 || (v35 = (_QWORD *)v58[0], v6 = v58[0] - 8LL, v58[0] == 8) )
  {
    v6 = 0;
  }
  else
  {
    v36 = *(__int64 *)((char *)&off_18 + v58[0]);
    if ( v36 )
    {
      v37 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v37 + 16);
      v38 = *(_QWORD *)(v36 + 1320);
      v39 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v38);
      do
        v40 = __ldxr(v39);
      while ( __stxr(v40 + 1, v39) );
      v41 = *(_QWORD *)(v37 + 16) - 1LL;
      *(_DWORD *)(v37 + 16) = v41;
      if ( !v41 || !*(_QWORD *)(v37 + 16) )
      {
        v53 = v35;
        preempt_schedule_notrace(v5);
        v35 = v53;
      }
    }
    _X8 = (unsigned int *)(v35 + 6577);
    __asm { PRFM            #0x11, [X8] }
    do
      v55 = __ldxr(_X8);
    while ( __stxr(v55 + 1, _X8) );
    v58[0] = 0;
    v43 = qdf_list_peek_next((_QWORD *)(a1 + 48), v35, v58);
    if ( !(_DWORD)v43 )
    {
      v44 = v58[0];
      v7 = v58[0] - 8LL;
      if ( v58[0] != 8 )
      {
        v45 = *(__int64 *)((char *)&off_18 + v58[0]);
        if ( v45 )
        {
          v46 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v46 + 16);
          v47 = *(_QWORD *)(v45 + 1320);
          v48 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v47);
          do
            v49 = __ldxr(v48);
          while ( __stxr(v49 + 1, v48) );
          v50 = *(_QWORD *)(v46 + 16) - 1LL;
          *(_DWORD *)(v46 + 16) = v50;
          if ( !v50 || !*(_QWORD *)(v46 + 16) )
            preempt_schedule_notrace(v43);
        }
        _X8 = (unsigned int *)(v44 + 52616);
        __asm { PRFM            #0x11, [X8] }
        do
          v57 = __ldxr(_X8);
        while ( __stxr(v57 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v7 = 0;
LABEL_8:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( !v6 )
      goto LABEL_56;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( !v6 )
      goto LABEL_56;
  }
  v9 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v12 = *(_DWORD *)(v6 + 40);
    hdd_adapter_dev_put_debug(v6, 25);
    if ( v12 == a2 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_19;
LABEL_12:
      v10 = 0;
      v6 = 0;
      v11 = *(_QWORD *)(a1 + 40);
      if ( (v11 & 1) == 0 )
        goto LABEL_13;
LABEL_32:
      *(_QWORD *)(a1 + 40) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v10;
      if ( !v6 )
        goto LABEL_56;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_19:
      v58[0] = 0;
      v13 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v58);
      v10 = v58[0] - 8LL;
      if ( (_DWORD)v13 )
        v22 = 0;
      else
        v22 = v58[0] - 8LL;
      if ( v7 == v22 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 25);
        goto LABEL_12;
      }
      if ( v22 )
      {
        v23 = *(_QWORD *)(v22 + 32);
        if ( v23 )
        {
          ++*(_DWORD *)(v9 + 16);
          v24 = *(_QWORD *)(v23 + 1320);
          v25 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v24);
          do
            v26 = __ldxr(v25);
          while ( __stxr(v26 + 1, v25) );
          v27 = *(_QWORD *)(v9 + 16) - 1LL;
          *(_DWORD *)(v9 + 16) = v27;
          if ( !v27 || !*(_QWORD *)(v9 + 16) )
            preempt_schedule_notrace(v13);
        }
        _X8 = (unsigned int *)(v22 + 52624);
        __asm { PRFM            #0x11, [X8] }
        do
          v34 = __ldxr(_X8);
        while ( __stxr(v34 + 1, _X8) );
      }
      else
      {
        v10 = 0;
      }
      v6 = v7;
      v11 = *(_QWORD *)(a1 + 40);
      if ( (v11 & 1) != 0 )
        goto LABEL_32;
LABEL_13:
      raw_spin_unlock(a1 + 32);
      v7 = v10;
      if ( !v6 )
        goto LABEL_56;
    }
  }
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 25);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v6;
}
