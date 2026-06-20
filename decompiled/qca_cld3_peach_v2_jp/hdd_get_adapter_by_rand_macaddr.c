__int64 __fastcall hdd_get_adapter_by_rand_macaddr(__int64 *a1, const void *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x28
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v17; // x27
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 v27; // x8
  unsigned int v28; // w8
  bool v29; // cc
  int v30; // w8
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x21
  __int64 v42; // x8
  __int64 v43; // x8
  unsigned int *v44; // x8
  unsigned int v45; // w10
  __int64 v46; // x8
  unsigned int v52; // w9
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _QWORD *v62; // x1
  __int64 v63; // x9
  unsigned __int64 v64; // x8
  __int64 v65; // x9
  unsigned int *v66; // x9
  unsigned int v67; // w12
  __int64 v68; // x9
  __int64 v70; // x0
  __int64 v71; // x22
  __int64 v72; // x9
  unsigned __int64 v73; // x8
  __int64 v74; // x9
  unsigned int *v75; // x9
  unsigned int v76; // w12
  __int64 v77; // x9
  _QWORD *v79; // x22
  unsigned int v81; // w9
  unsigned int v83; // w9
  _QWORD v84[2]; // [xsp+0h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  v84[0] = 0;
  v5 = qdf_list_peek_front(a1 + 6, v84);
  if ( (_DWORD)v5 || (v62 = (_QWORD *)v84[0], v6 = v84[0] - 8LL, v84[0] == 8) )
  {
    v6 = 0;
  }
  else
  {
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
    _X8 = (unsigned int *)v62 + 13149;
    __asm { PRFM            #0x11, [X8] }
    do
      v81 = __ldxr(_X8);
    while ( __stxr(v81 + 1, _X8) );
    v84[0] = 0;
    v70 = qdf_list_peek_next(a1 + 6, v62, v84);
    if ( !(_DWORD)v70 )
    {
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
        _X8 = (unsigned int *)(v71 + 52596);
        __asm { PRFM            #0x11, [X8] }
        do
          v83 = __ldxr(_X8);
        while ( __stxr(v83 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v7 = 0;
LABEL_8:
  v8 = a1[5];
  if ( (v8 & 1) != 0 )
  {
    a1[5] = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( !v6 )
      goto LABEL_49;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( !v6 )
      goto LABEL_49;
  }
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v28 = *(_DWORD *)(v6 + 40);
    v29 = v28 > 7;
    v30 = (1 << v28) & 0x85;
    _ZF = v29 || v30 == 0;
    if ( !_ZF && (*(_QWORD *)(v6 + 1640) & 1) != 0 && v6 != -52832 )
      break;
LABEL_23:
    hdd_adapter_dev_put_debug(v6, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
      if ( v7 )
        goto LABEL_27;
LABEL_12:
      v26 = 0;
      v6 = 0;
      v27 = a1[5];
      if ( (v27 & 1) == 0 )
        goto LABEL_13;
LABEL_40:
      a1[5] = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v7 = v26;
      if ( !v6 )
        goto LABEL_49;
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_27:
      v84[0] = 0;
      v32 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v7 + 8), v84);
      v26 = v84[0] - 8LL;
      if ( (_DWORD)v32 )
        v41 = 0;
      else
        v41 = v84[0] - 8LL;
      if ( v7 == v41 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0x14u, v18, v19, v20, v21, v22, v23, v24, v25);
        goto LABEL_12;
      }
      if ( v41 )
      {
        v42 = *(_QWORD *)(v41 + 32);
        if ( v42 )
        {
          ++*(_DWORD *)(v17 + 16);
          v43 = *(_QWORD *)(v42 + 1320);
          v44 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v43);
          do
            v45 = __ldxr(v44);
          while ( __stxr(v45 + 1, v44) );
          v46 = *(_QWORD *)(v17 + 16) - 1LL;
          *(_DWORD *)(v17 + 16) = v46;
          if ( !v46 || !*(_QWORD *)(v17 + 16) )
            preempt_schedule_notrace(v32);
        }
        _X8 = (unsigned int *)(v41 + 52604);
        __asm { PRFM            #0x11, [X8] }
        do
          v52 = __ldxr(_X8);
        while ( __stxr(v52 + 1, _X8) );
      }
      else
      {
        v26 = 0;
      }
      v6 = v7;
      v27 = a1[5];
      if ( (v27 & 1) != 0 )
        goto LABEL_40;
LABEL_13:
      raw_spin_unlock(a1 + 4);
      v7 = v26;
      if ( !v6 )
        goto LABEL_49;
    }
  }
  while ( (ucfg_p2p_check_random_mac(*a1, *(unsigned __int8 *)(v6 + 52840), a2) & 1) == 0 )
  {
    if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v6 - *(_DWORD *)(v6 + 52832)) >> 4))
      || (*(_QWORD *)(v6 + 1640) & 1) == 0 )
    {
      goto LABEL_23;
    }
  }
  hdd_adapter_dev_put_debug(v6, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x14u, v53, v54, v55, v56, v57, v58, v59, v60);
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v6;
}
