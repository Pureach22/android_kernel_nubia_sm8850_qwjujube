__int64 __fastcall hdd_adapter_get_by_reference(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 v18; // x25
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x28
  __int64 v28; // x8
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  __int64 v39; // x8
  __int64 v40; // x8
  unsigned int *v41; // x8
  unsigned int v42; // w10
  __int64 v43; // x8
  unsigned int v50; // w9
  _QWORD *v51; // x1
  __int64 v52; // x9
  unsigned __int64 v53; // x8
  __int64 v54; // x9
  unsigned int *v55; // x9
  unsigned int v56; // w12
  __int64 v57; // x9
  __int64 v59; // x0
  __int64 v60; // x23
  __int64 v61; // x9
  unsigned __int64 v62; // x8
  __int64 v63; // x9
  unsigned int *v64; // x9
  unsigned int v65; // w12
  __int64 v66; // x9
  __int64 v68; // x9
  unsigned __int64 v69; // x8
  __int64 v70; // x9
  unsigned int *v71; // x9
  unsigned int v72; // w12
  __int64 v73; // x9
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  _QWORD *v83; // x22
  unsigned int v85; // w9
  unsigned int v87; // w9
  _QWORD v88[2]; // [xsp+0h] [xbp-10h] BYREF

  v88[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v88[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v88);
  if ( (_DWORD)v5 || (v51 = (_QWORD *)v88[0], v6 = v88[0] - 8LL, v88[0] == 8) )
  {
    v6 = 0;
  }
  else
  {
    v52 = *(__int64 *)((char *)&off_18 + v88[0]);
    if ( v52 )
    {
      v53 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v53 + 16);
      v54 = *(_QWORD *)(v52 + 1320);
      v55 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v54);
      do
        v56 = __ldxr(v55);
      while ( __stxr(v56 + 1, v55) );
      v57 = *(_QWORD *)(v53 + 16) - 1LL;
      *(_DWORD *)(v53 + 16) = v57;
      if ( !v57 || !*(_QWORD *)(v53 + 16) )
      {
        v83 = v51;
        preempt_schedule_notrace(v5);
        v51 = v83;
      }
    }
    _X8 = (unsigned int *)(v51 + 6576);
    __asm { PRFM            #0x11, [X8] }
    do
      v85 = __ldxr(_X8);
    while ( __stxr(v85 + 1, _X8) );
    v88[0] = 0;
    v59 = qdf_list_peek_next((_QWORD *)(a1 + 48), v51, v88);
    if ( !(_DWORD)v59 )
    {
      v60 = v88[0];
      v7 = v88[0] - 8LL;
      if ( v88[0] != 8 )
      {
        v61 = *(__int64 *)((char *)&off_18 + v88[0]);
        if ( v61 )
        {
          v62 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v62 + 16);
          v63 = *(_QWORD *)(v61 + 1320);
          v64 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v63);
          do
            v65 = __ldxr(v64);
          while ( __stxr(v65 + 1, v64) );
          v66 = *(_QWORD *)(v62 + 16) - 1LL;
          *(_DWORD *)(v62 + 16) = v66;
          if ( !v66 || !*(_QWORD *)(v62 + 16) )
            preempt_schedule_notrace(v59);
        }
        _X8 = (unsigned int *)(v60 + 52608);
        __asm { PRFM            #0x11, [X8] }
        do
          v87 = __ldxr(_X8);
        while ( __stxr(v87 + 1, _X8) );
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
    v9 = raw_spin_unlock_bh(a1 + 32);
    if ( !v6 )
      goto LABEL_61;
  }
  else
  {
    v9 = raw_spin_unlock(a1 + 32);
    if ( !v6 )
      goto LABEL_61;
  }
  v18 = _ReadStatusReg(SP_EL0);
  while ( v6 != a2 )
  {
    hdd_adapter_dev_put_debug(v6, 0x17u, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v18 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_19;
LABEL_12:
      v27 = 0;
      v6 = 0;
      v28 = *(_QWORD *)(a1 + 40);
      if ( (v28 & 1) == 0 )
        goto LABEL_13;
LABEL_32:
      *(_QWORD *)(a1 + 40) = v28 & 0xFFFFFFFFFFFFFFFELL;
      v9 = raw_spin_unlock_bh(a1 + 32);
      v7 = v27;
      if ( !v6 )
        goto LABEL_61;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_19:
      v88[0] = 0;
      v29 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v88);
      v27 = v88[0] - 8LL;
      if ( (_DWORD)v29 )
        v38 = 0;
      else
        v38 = v88[0] - 8LL;
      if ( v7 == v38 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0x17u, v19, v20, v21, v22, v23, v24, v25, v26);
        goto LABEL_12;
      }
      if ( v38 )
      {
        v39 = *(_QWORD *)(v38 + 32);
        if ( v39 )
        {
          ++*(_DWORD *)(v18 + 16);
          v40 = *(_QWORD *)(v39 + 1320);
          v41 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v40);
          do
            v42 = __ldxr(v41);
          while ( __stxr(v42 + 1, v41) );
          v43 = *(_QWORD *)(v18 + 16) - 1LL;
          *(_DWORD *)(v18 + 16) = v43;
          if ( !v43 || !*(_QWORD *)(v18 + 16) )
            preempt_schedule_notrace(v29);
        }
        _X8 = (unsigned int *)(v38 + 52616);
        __asm { PRFM            #0x11, [X8] }
        do
          v50 = __ldxr(_X8);
        while ( __stxr(v50 + 1, _X8) );
      }
      else
      {
        v27 = 0;
      }
      v6 = v7;
      v28 = *(_QWORD *)(a1 + 40);
      if ( (v28 & 1) != 0 )
        goto LABEL_32;
LABEL_13:
      v9 = raw_spin_unlock(a1 + 32);
      v7 = v27;
      if ( !v6 )
        goto LABEL_61;
    }
  }
  v68 = *(_QWORD *)(v6 + 32);
  if ( v68 )
  {
    v69 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v69 + 16);
    v70 = *(_QWORD *)(v68 + 1320);
    v71 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v70);
    do
      v72 = __ldxr(v71);
    while ( __stxr(v72 + 1, v71) );
    v73 = *(_QWORD *)(v69 + 16) - 1LL;
    *(_DWORD *)(v69 + 16) = v73;
    if ( !v73 || !*(_QWORD *)(v69 + 16) )
      preempt_schedule_notrace(v9);
  }
  hdd_adapter_dev_put_debug(v6, 0x17u, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x17u, v74, v75, v76, v77, v78, v79, v80, v81);
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return v6;
}
