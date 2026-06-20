int *__fastcall hdd_get_first_valid_adapter(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0
  int *v4; // x20
  __int64 v5; // x21
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x25
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x28
  __int64 v25; // x8
  int v26; // w28
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x20
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned int *v47; // x8
  unsigned int v48; // w10
  __int64 v49; // x8
  unsigned int v56; // w9
  _QWORD *v57; // x1
  __int64 v58; // x9
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  unsigned int *v61; // x9
  unsigned int v62; // w12
  __int64 v63; // x9
  __int64 v65; // x0
  __int64 v66; // x22
  __int64 v67; // x9
  unsigned __int64 v68; // x8
  __int64 v69; // x9
  unsigned int *v70; // x9
  unsigned int v71; // w12
  __int64 v72; // x9
  _QWORD *v75; // x21
  unsigned int v77; // w9
  unsigned int v79; // w9
  _QWORD v80[2]; // [xsp+0h] [xbp-10h] BYREF

  v80[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v80[0] = 0;
  v3 = qdf_list_peek_front((_QWORD *)(a1 + 48), v80);
  if ( (_DWORD)v3 || (v57 = (_QWORD *)v80[0], v4 = (int *)(v80[0] - 8LL), v80[0] == 8) )
  {
    v4 = nullptr;
  }
  else
  {
    v58 = *(__int64 *)((char *)&off_18 + v80[0]);
    if ( v58 )
    {
      v59 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v59 + 16);
      v60 = *(_QWORD *)(v58 + 1320);
      v61 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v60);
      do
        v62 = __ldxr(v61);
      while ( __stxr(v62 + 1, v61) );
      v63 = *(_QWORD *)(v59 + 16) - 1LL;
      *(_DWORD *)(v59 + 16) = v63;
      if ( !v63 || !*(_QWORD *)(v59 + 16) )
      {
        v75 = v57;
        preempt_schedule_notrace(v3);
        v57 = v75;
      }
    }
    _X8 = (unsigned int *)v57 + 13159;
    __asm { PRFM            #0x11, [X8] }
    do
      v77 = __ldxr(_X8);
    while ( __stxr(v77 + 1, _X8) );
    v80[0] = 0;
    v65 = qdf_list_peek_next((_QWORD *)(a1 + 48), v57, v80);
    if ( !(_DWORD)v65 )
    {
      v66 = v80[0];
      v5 = v80[0] - 8LL;
      if ( v80[0] != 8 )
      {
        v67 = *(__int64 *)((char *)&off_18 + v80[0]);
        if ( v67 )
        {
          v68 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v68 + 16);
          v69 = *(_QWORD *)(v67 + 1320);
          v70 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v69);
          do
            v71 = __ldxr(v70);
          while ( __stxr(v71 + 1, v70) );
          v72 = *(_QWORD *)(v68 + 16) - 1LL;
          *(_DWORD *)(v68 + 16) = v72;
          if ( !v72 || !*(_QWORD *)(v68 + 16) )
            preempt_schedule_notrace(v65);
        }
        _X8 = (unsigned int *)(v66 + 52636);
        __asm { PRFM            #0x11, [X8] }
        do
          v79 = __ldxr(_X8);
        while ( __stxr(v79 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v5 = 0;
LABEL_8:
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( !v4 )
      goto LABEL_56;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( !v4 )
      goto LABEL_56;
  }
  v15 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v26 = *v4;
    hdd_adapter_dev_put_debug((__int64)v4, 0x1Eu, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( v26 == 1885692259 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v15 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v5 )
        goto LABEL_19;
LABEL_12:
      v24 = 0;
      v4 = nullptr;
      v25 = *(_QWORD *)(a1 + 40);
      if ( (v25 & 1) == 0 )
        goto LABEL_13;
LABEL_32:
      *(_QWORD *)(a1 + 40) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v5 = v24;
      if ( !v4 )
        goto LABEL_56;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v5 )
        goto LABEL_12;
LABEL_19:
      v80[0] = 0;
      v35 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v5 + 8), v80);
      v24 = v80[0] - 8LL;
      if ( (_DWORD)v35 )
        v44 = 0;
      else
        v44 = v80[0] - 8LL;
      if ( v5 == v44 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v5, 0x1Eu, v16, v17, v18, v19, v20, v21, v22, v23);
        goto LABEL_12;
      }
      if ( v44 )
      {
        v45 = *(_QWORD *)(v44 + 32);
        if ( v45 )
        {
          ++*(_DWORD *)(v15 + 16);
          v46 = *(_QWORD *)(v45 + 1320);
          v47 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v46);
          do
            v48 = __ldxr(v47);
          while ( __stxr(v48 + 1, v47) );
          v49 = *(_QWORD *)(v15 + 16) - 1LL;
          *(_DWORD *)(v15 + 16) = v49;
          if ( !v49 || !*(_QWORD *)(v15 + 16) )
            preempt_schedule_notrace(v35);
        }
        _X8 = (unsigned int *)(v44 + 52644);
        __asm { PRFM            #0x11, [X8] }
        do
          v56 = __ldxr(_X8);
        while ( __stxr(v56 + 1, _X8) );
      }
      else
      {
        v24 = 0;
      }
      v4 = (int *)v5;
      v25 = *(_QWORD *)(a1 + 40);
      if ( (v25 & 1) != 0 )
        goto LABEL_32;
LABEL_13:
      raw_spin_unlock(a1 + 32);
      v5 = v24;
      if ( !v4 )
        goto LABEL_56;
    }
  }
  if ( v5 )
    hdd_adapter_dev_put_debug(v5, 0x1Eu, v27, v28, v29, v30, v31, v32, v33, v34);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v4;
}
