__int64 __fastcall hdd_get_link_info_by_vdev(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x26
  __int64 v8; // x8
  unsigned __int64 v9; // x28
  __int64 v10; // x9
  unsigned int v11; // w9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 v25; // x22
  __int64 v26; // x8
  __int64 v27; // x8
  unsigned int *v28; // x8
  unsigned int v29; // w10
  __int64 v30; // x8
  __int64 v32; // x8
  __int64 result; // x0
  unsigned int v39; // w9
  __int64 v40; // x19
  _QWORD *v41; // x1
  __int64 v42; // x9
  unsigned __int64 v43; // x8
  __int64 v44; // x9
  unsigned int *v45; // x9
  unsigned int v46; // w12
  __int64 v47; // x9
  __int64 v49; // x0
  __int64 v50; // x21
  __int64 v51; // x9
  unsigned __int64 v52; // x8
  __int64 v53; // x9
  unsigned int *v54; // x9
  unsigned int v55; // w12
  __int64 v56; // x9
  _QWORD *v58; // x21
  unsigned int v60; // w9
  unsigned int v62; // w9
  _QWORD v63[2]; // [xsp+0h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 255 )
    goto LABEL_74;
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
  v63[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v63);
  if ( (_DWORD)v5 || (v41 = (_QWORD *)v63[0], v6 = v63[0] - 8LL, v63[0] == 8) )
  {
    v6 = 0;
LABEL_8:
    v7 = 0;
    goto LABEL_9;
  }
  v42 = *(__int64 *)((char *)&off_18 + v63[0]);
  if ( v42 )
  {
    v43 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v43 + 16);
    v44 = *(_QWORD *)(v42 + 1320);
    v45 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v44);
    do
      v46 = __ldxr(v45);
    while ( __stxr(v46 + 1, v45) );
    v47 = *(_QWORD *)(v43 + 16) - 1LL;
    *(_DWORD *)(v43 + 16) = v47;
    if ( !v47 || !*(_QWORD *)(v43 + 16) )
    {
      v58 = v41;
      preempt_schedule_notrace(v5);
      v41 = v58;
    }
  }
  _X8 = (unsigned int *)v41 + 13151;
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr(_X8);
  while ( __stxr(v60 + 1, _X8) );
  v63[0] = 0;
  v49 = qdf_list_peek_next((_QWORD *)(a1 + 48), v41, v63);
  if ( (_DWORD)v49 )
    goto LABEL_8;
  v50 = v63[0];
  v7 = v63[0] - 8LL;
  if ( v63[0] != 8 )
  {
    v51 = *(__int64 *)((char *)&off_18 + v63[0]);
    if ( v51 )
    {
      v52 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v52 + 16);
      v53 = *(_QWORD *)(v51 + 1320);
      v54 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v53);
      do
        v55 = __ldxr(v54);
      while ( __stxr(v55 + 1, v54) );
      v56 = *(_QWORD *)(v52 + 16) - 1LL;
      *(_DWORD *)(v52 + 16) = v56;
      if ( !v56 || !*(_QWORD *)(v52 + 16) )
        preempt_schedule_notrace(v49);
    }
    _X8 = (unsigned int *)(v50 + 52604);
    __asm { PRFM            #0x11, [X8] }
    do
      v62 = __ldxr(_X8);
    while ( __stxr(v62 + 1, _X8) );
  }
LABEL_9:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v6 )
      goto LABEL_11;
LABEL_74:
    result = 0;
    goto LABEL_75;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v6 )
    goto LABEL_74;
LABEL_11:
  v9 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_QWORD *)(v6 + 1640) & 1) != 0 )
    {
      v10 = v6 + 52840;
      if ( v6 != -52840 )
        break;
    }
    if ( (*(_QWORD *)(v6 + 1640) & 2) != 0 )
    {
      v10 = v6 + 58928;
      if ( v6 != -58928 )
        break;
    }
    if ( (*(_QWORD *)(v6 + 1640) & 4) != 0 )
    {
      v10 = v6 + 65016;
      if ( v6 != -65016 )
        break;
    }
LABEL_26:
    hdd_adapter_dev_put_debug(v6, 22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( !v7 )
        goto LABEL_42;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_42;
    }
    v63[0] = 0;
    v15 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v63);
    v24 = v63[0] - 8LL;
    if ( (_DWORD)v15 )
      v25 = 0;
    else
      v25 = v63[0] - 8LL;
    if ( v7 == v25 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Validation failed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_validate_next_adapter");
      hdd_adapter_dev_put_debug(v7, 22);
LABEL_42:
      v24 = 0;
      v6 = 0;
      v32 = *(_QWORD *)(a1 + 40);
      if ( (v32 & 1) != 0 )
        goto LABEL_48;
      goto LABEL_43;
    }
    if ( v25 )
    {
      v26 = *(_QWORD *)(v25 + 32);
      if ( v26 )
      {
        ++*(_DWORD *)(v9 + 16);
        v27 = *(_QWORD *)(v26 + 1320);
        v28 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v27);
        do
          v29 = __ldxr(v28);
        while ( __stxr(v29 + 1, v28) );
        v30 = *(_QWORD *)(v9 + 16) - 1LL;
        *(_DWORD *)(v9 + 16) = v30;
        if ( !v30 || !*(_QWORD *)(v9 + 16) )
          preempt_schedule_notrace(v15);
      }
      _X8 = (unsigned int *)(v25 + 52612);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 + 1, _X8) );
    }
    else
    {
      v24 = 0;
    }
    v6 = v7;
    v32 = *(_QWORD *)(a1 + 40);
    if ( (v32 & 1) != 0 )
    {
LABEL_48:
      *(_QWORD *)(a1 + 40) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      goto LABEL_44;
    }
LABEL_43:
    raw_spin_unlock(a1 + 32);
LABEL_44:
    result = 0;
    v7 = v24;
    if ( !v6 )
      goto LABEL_75;
  }
  while ( *(unsigned __int8 *)(v10 + 8) != a2 )
  {
    v11 = 73 * ((unsigned int)(v10 - *(_DWORD *)v10 - 52840) >> 3) + 1;
    if ( (unsigned __int8)v11 <= 2u )
    {
      v12 = (unsigned __int8)v11;
      v10 = 0;
      v13 = v6 + 52840 + 6088LL * (unsigned int)v12;
      do
      {
        if ( v10 )
          break;
        v14 = *(_QWORD *)(v6 + 1640) >> v12++;
        v10 = (v14 << 63 >> 63) & v13;
        v13 += 6088;
      }
      while ( v12 != 3 );
      if ( v10 )
        continue;
    }
    goto LABEL_26;
  }
  v40 = v10;
  hdd_adapter_dev_put_debug(v6, 22);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 22);
  result = v40;
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
