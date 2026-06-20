__int64 __fastcall hdd_get_link_info_by_link_addr(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x27
  __int64 v7; // x22
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v17; // x26
  __int64 v18; // x8
  __int64 v19; // x11
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  __int64 v31; // x27
  __int64 v32; // x8
  __int64 v33; // x8
  unsigned int *v34; // x8
  unsigned int v35; // w10
  __int64 v36; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 result; // x0
  unsigned int v52; // w9
  __int64 v53; // x19
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _QWORD *v62; // x1
  __int64 v63; // x9
  unsigned __int64 v64; // x8
  __int64 v65; // x9
  unsigned int *v66; // x9
  unsigned int v67; // w12
  __int64 v68; // x9
  __int64 v70; // x0
  __int64 v71; // x21
  __int64 v72; // x9
  unsigned __int64 v73; // x8
  __int64 v74; // x9
  unsigned int *v75; // x9
  unsigned int v76; // w12
  __int64 v77; // x9
  _QWORD *v79; // x21
  unsigned int v81; // w9
  unsigned int v83; // w9
  _QWORD v84[3]; // [xsp+8h] [xbp-18h] BYREF

  v84[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !(*(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4)) )
    goto LABEL_68;
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
  v84[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v84);
  if ( (_DWORD)v5 || (v62 = (_QWORD *)v84[0], v6 = v84[0] - 8LL, v84[0] == 8) )
  {
    v6 = 0;
LABEL_9:
    v7 = 0;
    goto LABEL_10;
  }
  v63 = *(__int64 *)((char *)&off_18 + v84[0]);
  if ( v63 )
  {
    v64 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v64 + 16);
    v65 = *(_QWORD *)(v63 + 1320);
    v66 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v65);
    do
      v67 = __ldxr(v66);
    while ( __stxr(v67 + 1, v66) );
    v68 = *(_QWORD *)(v64 + 16) - 1LL;
    *(_DWORD *)(v64 + 16) = v68;
    if ( !v68 || !*(_QWORD *)(v64 + 16) )
    {
      v79 = v62;
      preempt_schedule_notrace(v5);
      v62 = v79;
    }
  }
  _X8 = (unsigned int *)(v62 + 6575);
  __asm { PRFM            #0x11, [X8] }
  do
    v81 = __ldxr(_X8);
  while ( __stxr(v81 + 1, _X8) );
  v84[0] = 0;
  v70 = qdf_list_peek_next((_QWORD *)(a1 + 48), v62, v84);
  if ( (_DWORD)v70 )
    goto LABEL_9;
  v71 = v84[0];
  v7 = v84[0] - 8LL;
  if ( v84[0] != 8 )
  {
    v72 = *(__int64 *)((char *)&off_18 + v84[0]);
    if ( v72 )
    {
      v73 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v73 + 16);
      v74 = *(_QWORD *)(v72 + 1320);
      v75 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v74);
      do
        v76 = __ldxr(v75);
      while ( __stxr(v76 + 1, v75) );
      v77 = *(_QWORD *)(v73 + 16) - 1LL;
      *(_DWORD *)(v73 + 16) = v77;
      if ( !v77 || !*(_QWORD *)(v73 + 16) )
        preempt_schedule_notrace(v70);
    }
    _X8 = (unsigned int *)(v71 + 52600);
    __asm { PRFM            #0x11, [X8] }
    do
      v83 = __ldxr(_X8);
    while ( __stxr(v83 + 1, _X8) );
  }
LABEL_10:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v6 )
      goto LABEL_12;
LABEL_68:
    result = 0;
    goto LABEL_69;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v6 )
    goto LABEL_68;
LABEL_12:
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v18 = v6 + 52832;
    if ( v6 != -52832 )
      break;
LABEL_20:
    hdd_adapter_dev_put_debug(v6, 0x15u, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( !v7 )
        goto LABEL_36;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_36;
    }
    v84[0] = 0;
    v21 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v84);
    v30 = v84[0] - 8LL;
    if ( (_DWORD)v21 )
      v31 = 0;
    else
      v31 = v84[0] - 8LL;
    if ( v7 == v31 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Validation failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_validate_next_adapter");
      hdd_adapter_dev_put_debug(v7, 0x15u, v38, v39, v40, v41, v42, v43, v44, v45);
LABEL_36:
      v30 = 0;
      v6 = 0;
      v46 = *(_QWORD *)(a1 + 40);
      if ( (v46 & 1) != 0 )
        goto LABEL_42;
      goto LABEL_37;
    }
    if ( v31 )
    {
      v32 = *(_QWORD *)(v31 + 32);
      if ( v32 )
      {
        ++*(_DWORD *)(v17 + 16);
        v33 = *(_QWORD *)(v32 + 1320);
        v34 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v33);
        do
          v35 = __ldxr(v34);
        while ( __stxr(v35 + 1, v34) );
        v36 = *(_QWORD *)(v17 + 16) - 1LL;
        *(_DWORD *)(v17 + 16) = v36;
        if ( !v36 || !*(_QWORD *)(v17 + 16) )
          preempt_schedule_notrace(v21);
      }
      _X8 = (unsigned int *)(v31 + 52608);
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 + 1, _X8) );
    }
    else
    {
      v30 = 0;
    }
    v6 = v7;
    v46 = *(_QWORD *)(a1 + 40);
    if ( (v46 & 1) != 0 )
    {
LABEL_42:
      *(_QWORD *)(a1 + 40) = v46 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      goto LABEL_38;
    }
LABEL_37:
    raw_spin_unlock(a1 + 32);
LABEL_38:
    result = 0;
    v7 = v30;
    if ( !v6 )
      goto LABEL_69;
  }
  v19 = 0;
  while ( *(_DWORD *)a2 != *(_DWORD *)(v18 + 72) || *(unsigned __int16 *)(a2 + 4) != *(unsigned __int16 *)(v18 + 76) )
  {
    v19 -= 4528;
    v18 += 4528;
    if ( v19 )
      goto LABEL_20;
  }
  v53 = v18;
  hdd_adapter_dev_put_debug(v6, 0x15u, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x15u, v54, v55, v56, v57, v58, v59, v60, v61);
  result = v53;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
