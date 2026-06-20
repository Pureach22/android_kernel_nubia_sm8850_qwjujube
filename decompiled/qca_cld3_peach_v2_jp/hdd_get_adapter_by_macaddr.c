__int64 __fastcall hdd_get_adapter_by_macaddr(__int64 a1, const void *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x28
  __int64 v8; // x8
  unsigned __int64 v9; // x26
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 *v37; // x21
  __int64 v38; // x8
  __int64 v39; // x8
  unsigned int *v40; // x8
  unsigned int v41; // w10
  __int64 v42; // x8
  unsigned int v49; // w9
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 *v59; // x1
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned int *v63; // x9
  unsigned int v64; // w12
  __int64 v65; // x9
  __int64 v67; // x0
  __int64 *v68; // x22
  __int64 v69; // x9
  unsigned __int64 v70; // x8
  __int64 v71; // x9
  unsigned int *v72; // x9
  unsigned int v73; // w12
  __int64 v74; // x9
  __int64 *v76; // x22
  unsigned int v78; // w9
  unsigned int v80; // w9
  __int64 *v81; // [xsp+8h] [xbp-18h] BYREF
  int v82; // [xsp+10h] [xbp-10h] BYREF
  __int16 v83; // [xsp+14h] [xbp-Ch]
  __int64 v84; // [xsp+18h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v82 = 0;
  if ( !(unsigned int)qdf_mem_cmp(a2, &v82, 6u) )
  {
    v6 = 0;
    goto LABEL_48;
  }
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
  v81 = nullptr;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), &v81);
  if ( (_DWORD)v5 || (v59 = v81, v6 = (__int64)(v81 - 1), v81 == &qword_8) )
  {
    v6 = 0;
  }
  else
  {
    v60 = *(__int64 *)((char *)&off_18 + (_QWORD)v81);
    if ( v60 )
    {
      v61 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v61 + 16);
      v62 = *(_QWORD *)(v60 + 1320);
      v63 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v62);
      do
        v64 = __ldxr(v63);
      while ( __stxr(v64 + 1, v63) );
      v65 = *(_QWORD *)(v61 + 16) - 1LL;
      *(_DWORD *)(v61 + 16) = v65;
      if ( !v65 || !*(_QWORD *)(v61 + 16) )
      {
        v76 = v59;
        preempt_schedule_notrace(v5);
        v59 = v76;
      }
    }
    _X8 = (unsigned int *)(v59 + 6575);
    __asm { PRFM            #0x11, [X8] }
    do
      v78 = __ldxr(_X8);
    while ( __stxr(v78 + 1, _X8) );
    v81 = nullptr;
    v67 = qdf_list_peek_next((_QWORD *)(a1 + 48), v59, &v81);
    if ( !(_DWORD)v67 )
    {
      v68 = v81;
      v7 = (__int64)(v81 - 1);
      if ( v81 != &qword_8 )
      {
        v69 = *(__int64 *)((char *)&off_18 + (_QWORD)v81);
        if ( v69 )
        {
          v70 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v70 + 16);
          v71 = *(_QWORD *)(v69 + 1320);
          v72 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v71);
          do
            v73 = __ldxr(v72);
          while ( __stxr(v73 + 1, v72) );
          v74 = *(_QWORD *)(v70 + 16) - 1LL;
          *(_DWORD *)(v70 + 16) = v74;
          if ( !v74 || !*(_QWORD *)(v70 + 16) )
            preempt_schedule_notrace(v67);
        }
        _X8 = (unsigned int *)(v68 + 6575);
        __asm { PRFM            #0x11, [X8] }
        do
          v80 = __ldxr(_X8);
        while ( __stxr(v80 + 1, _X8) );
      }
      goto LABEL_9;
    }
  }
  v7 = 0;
LABEL_9:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( !v6 )
      goto LABEL_48;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( !v6 )
      goto LABEL_48;
  }
  v9 = _ReadStatusReg(SP_EL0);
  while ( (unsigned int)qdf_mem_cmp((const void *)(v6 + 1617), a2, 6u) )
  {
    if ( (*(_QWORD *)(v6 + 1640) & 1) != 0 && v6 != -52832 )
    {
      while ( (unsigned int)qdf_mem_cmp((const void *)(v6 + 52904), a2, 6u) )
      {
        if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v6 - *(_DWORD *)(v6 + 52832)) >> 4))
          || (*(_QWORD *)(v6 + 1640) & 1) == 0 )
        {
          goto LABEL_22;
        }
      }
      break;
    }
LABEL_22:
    hdd_adapter_dev_put_debug(v6, 0x15u, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_26;
LABEL_14:
      v18 = 0;
      v6 = 0;
      v19 = *(_QWORD *)(a1 + 40);
      if ( (v19 & 1) == 0 )
        goto LABEL_15;
LABEL_39:
      *(_QWORD *)(a1 + 40) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v18;
      if ( !v6 )
        goto LABEL_48;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_14;
LABEL_26:
      v81 = nullptr;
      v28 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), &v81);
      v18 = (__int64)(v81 - 1);
      if ( (_DWORD)v28 )
        v37 = nullptr;
      else
        v37 = v81 - 1;
      if ( (__int64 *)v7 == v37 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0x15u, v10, v11, v12, v13, v14, v15, v16, v17);
        goto LABEL_14;
      }
      if ( v37 )
      {
        v38 = v37[4];
        if ( v38 )
        {
          ++*(_DWORD *)(v9 + 16);
          v39 = *(_QWORD *)(v38 + 1320);
          v40 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v39);
          do
            v41 = __ldxr(v40);
          while ( __stxr(v41 + 1, v40) );
          v42 = *(_QWORD *)(v9 + 16) - 1LL;
          *(_DWORD *)(v9 + 16) = v42;
          if ( !v42 || !*(_QWORD *)(v9 + 16) )
            preempt_schedule_notrace(v28);
        }
        _X8 = (unsigned int *)(v37 + 6576);
        __asm { PRFM            #0x11, [X8] }
        do
          v49 = __ldxr(_X8);
        while ( __stxr(v49 + 1, _X8) );
      }
      else
      {
        v18 = 0;
      }
      v6 = v7;
      v19 = *(_QWORD *)(a1 + 40);
      if ( (v19 & 1) != 0 )
        goto LABEL_39;
LABEL_15:
      raw_spin_unlock(a1 + 32);
      v7 = v18;
      if ( !v6 )
        goto LABEL_48;
    }
  }
  hdd_adapter_dev_put_debug(v6, 0x15u, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x15u, v50, v51, v52, v53, v54, v55, v56, v57);
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v6;
}
