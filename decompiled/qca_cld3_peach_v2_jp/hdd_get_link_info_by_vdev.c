__int64 __fastcall hdd_get_link_info_by_vdev(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x27
  __int64 v8; // x8
  unsigned __int64 v9; // x26
  __int64 v10; // x21
  __int64 v11; // x8
  int v12; // w9
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x8
  __int64 v24; // x8
  unsigned int *v25; // x8
  unsigned int v26; // w10
  __int64 v27; // x8
  unsigned int v34; // w9
  __int64 result; // x0
  _QWORD *v36; // x1
  __int64 v37; // x9
  unsigned __int64 v38; // x8
  __int64 v39; // x9
  unsigned int *v40; // x9
  unsigned int v41; // w12
  __int64 v42; // x9
  __int64 v44; // x0
  __int64 v45; // x21
  __int64 v46; // x9
  unsigned __int64 v47; // x8
  __int64 v48; // x9
  unsigned int *v49; // x9
  unsigned int v50; // w12
  __int64 v51; // x9
  _QWORD *v53; // x21
  unsigned int v55; // w9
  unsigned int v57; // w9
  _QWORD v58[2]; // [xsp+0h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 255 )
    goto LABEL_66;
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
  if ( (_DWORD)v5 || (v36 = (_QWORD *)v58[0], v6 = v58[0] - 8LL, v58[0] == 8) )
  {
    v6 = 0;
LABEL_8:
    v7 = 0;
    goto LABEL_9;
  }
  v37 = *(__int64 *)((char *)&off_18 + v58[0]);
  if ( v37 )
  {
    v38 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v38 + 16);
    v39 = *(_QWORD *)(v37 + 1320);
    v40 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v39);
    do
      v41 = __ldxr(v40);
    while ( __stxr(v41 + 1, v40) );
    v42 = *(_QWORD *)(v38 + 16) - 1LL;
    *(_DWORD *)(v38 + 16) = v42;
    if ( !v42 || !*(_QWORD *)(v38 + 16) )
    {
      v53 = v36;
      preempt_schedule_notrace(v5);
      v36 = v53;
    }
  }
  _X8 = (unsigned int *)v36 + 13151;
  __asm { PRFM            #0x11, [X8] }
  do
    v55 = __ldxr(_X8);
  while ( __stxr(v55 + 1, _X8) );
  v58[0] = 0;
  v44 = qdf_list_peek_next((_QWORD *)(a1 + 48), v36, v58);
  if ( (_DWORD)v44 )
    goto LABEL_8;
  v45 = v58[0];
  v7 = v58[0] - 8LL;
  if ( v58[0] != 8 )
  {
    v46 = *(__int64 *)((char *)&off_18 + v58[0]);
    if ( v46 )
    {
      v47 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v47 + 16);
      v48 = *(_QWORD *)(v46 + 1320);
      v49 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v48);
      do
        v50 = __ldxr(v49);
      while ( __stxr(v50 + 1, v49) );
      v51 = *(_QWORD *)(v47 + 16) - 1LL;
      *(_DWORD *)(v47 + 16) = v51;
      if ( !v51 || !*(_QWORD *)(v47 + 16) )
        preempt_schedule_notrace(v44);
    }
    _X8 = (unsigned int *)(v45 + 52604);
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr(_X8);
    while ( __stxr(v57 + 1, _X8) );
  }
LABEL_9:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v6 )
      goto LABEL_11;
LABEL_66:
    result = 0;
    goto LABEL_67;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v6 )
    goto LABEL_66;
LABEL_11:
  v9 = _ReadStatusReg(SP_EL0);
  while ( (*(_QWORD *)(v6 + 1640) & 1) == 0 || v6 == -52832 )
  {
LABEL_22:
    hdd_adapter_dev_put_debug(v6, 22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_26;
LABEL_13:
      v10 = 0;
      v6 = 0;
      v11 = *(_QWORD *)(a1 + 40);
      if ( (v11 & 1) == 0 )
        goto LABEL_14;
LABEL_39:
      *(_QWORD *)(a1 + 40) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v10;
      if ( !v6 )
        goto LABEL_66;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_13;
LABEL_26:
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
        hdd_adapter_dev_put_debug(v7, 22);
        goto LABEL_13;
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
        _X8 = (unsigned int *)(v22 + 52612);
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
        goto LABEL_39;
LABEL_14:
      raw_spin_unlock(a1 + 32);
      v7 = v10;
      if ( !v6 )
        goto LABEL_66;
    }
  }
  v12 = *(unsigned __int8 *)(v6 + 52840);
  if ( v12 != a2 )
  {
    while ( (unsigned __int8)(19 * ((unsigned int)(v6 - *(_DWORD *)(v6 + 52832)) >> 4)) == 255
         && (*(_QWORD *)(v6 + 1640) & 1) != 0 )
    {
      if ( v12 == a2 )
        goto LABEL_46;
    }
    goto LABEL_22;
  }
LABEL_46:
  hdd_adapter_dev_put_debug(v6, 22);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 22);
  result = v6 + 52832;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
