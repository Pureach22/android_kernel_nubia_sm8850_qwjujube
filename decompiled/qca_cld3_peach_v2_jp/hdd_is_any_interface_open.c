__int64 __fastcall hdd_is_any_interface_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x27
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  __int64 v34; // x8
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x21
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned int *v47; // x8
  unsigned int v48; // w10
  __int64 v49; // x8
  unsigned int v56; // w9
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  _QWORD *v65; // x1
  __int64 v66; // x9
  unsigned __int64 v67; // x8
  __int64 v68; // x9
  unsigned int *v69; // x9
  unsigned int v70; // w12
  __int64 v71; // x9
  __int64 v73; // x0
  __int64 v74; // x20
  __int64 v75; // x9
  unsigned __int64 v76; // x8
  __int64 v77; // x9
  unsigned int *v78; // x9
  unsigned int v79; // w12
  __int64 v80; // x9
  _QWORD *v82; // x20
  unsigned int v84; // w9
  unsigned int v86; // w9
  _QWORD v87[2]; // [xsp+0h] [xbp-10h] BYREF

  v87[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( curr_con_mode == 5 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: FTM mode, don't close the module",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_is_any_interface_open");
    result = 1;
    goto LABEL_66;
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
  v87[0] = 0;
  v12 = qdf_list_peek_front((_QWORD *)(a1 + 48), v87);
  if ( (_DWORD)v12 || (v65 = (_QWORD *)v87[0], v13 = v87[0] - 8LL, v87[0] == 8) )
  {
    v13 = 0;
LABEL_9:
    v14 = 0;
    goto LABEL_10;
  }
  v66 = *(__int64 *)((char *)&off_18 + v87[0]);
  if ( v66 )
  {
    v67 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v67 + 16);
    v68 = *(_QWORD *)(v66 + 1320);
    v69 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v68);
    do
      v70 = __ldxr(v69);
    while ( __stxr(v70 + 1, v69) );
    v71 = *(_QWORD *)(v67 + 16) - 1LL;
    *(_DWORD *)(v67 + 16) = v71;
    if ( !v71 || !*(_QWORD *)(v67 + 16) )
    {
      v82 = v65;
      preempt_schedule_notrace(v12);
      v65 = v82;
    }
  }
  _X8 = (unsigned int *)v65 + 13147;
  __asm { PRFM            #0x11, [X8] }
  do
    v84 = __ldxr(_X8);
  while ( __stxr(v84 + 1, _X8) );
  v87[0] = 0;
  v73 = qdf_list_peek_next((_QWORD *)(a1 + 48), v65, v87);
  if ( (_DWORD)v73 )
    goto LABEL_9;
  v74 = v87[0];
  v14 = v87[0] - 8LL;
  if ( v87[0] != 8 )
  {
    v75 = *(__int64 *)((char *)&off_18 + v87[0]);
    if ( v75 )
    {
      v76 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v76 + 16);
      v77 = *(_QWORD *)(v75 + 1320);
      v78 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v77);
      do
        v79 = __ldxr(v78);
      while ( __stxr(v79 + 1, v78) );
      v80 = *(_QWORD *)(v76 + 16) - 1LL;
      *(_DWORD *)(v76 + 16) = v80;
      if ( !v80 || !*(_QWORD *)(v76 + 16) )
        preempt_schedule_notrace(v73);
    }
    _X8 = (unsigned int *)(v74 + 52588);
    __asm { PRFM            #0x11, [X8] }
    do
      v86 = __ldxr(_X8);
    while ( __stxr(v86 + 1, _X8) );
  }
LABEL_10:
  v15 = *(_QWORD *)(a1 + 40);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v13 )
      goto LABEL_12;
LABEL_65:
    result = 0;
    goto LABEL_66;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v13 )
    goto LABEL_65;
LABEL_12:
  v24 = _ReadStatusReg(SP_EL0);
  while ( (*(_QWORD *)(v13 + 1624) & 4) == 0 )
  {
    if ( (*(_QWORD *)(v13 + 1640) & 1) != 0 )
    {
      while ( (*(_QWORD *)(v13 + 57248) & 1) == 0 )
      {
        if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v13 - *(_DWORD *)(v13 + 52832)) >> 4))
          || (*(_QWORD *)(v13 + 1640) & 1) == 0 )
        {
          goto LABEL_21;
        }
      }
      break;
    }
LABEL_21:
    hdd_adapter_dev_put_debug(v13, 0x12u, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v24 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v14 )
        goto LABEL_25;
LABEL_14:
      v33 = 0;
      v13 = 0;
      v34 = *(_QWORD *)(a1 + 40);
      if ( (v34 & 1) == 0 )
        goto LABEL_15;
LABEL_38:
      *(_QWORD *)(a1 + 40) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v14 = v33;
      if ( !v13 )
        goto LABEL_65;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v14 )
        goto LABEL_14;
LABEL_25:
      v87[0] = 0;
      v35 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v14 + 8), v87);
      v33 = v87[0] - 8LL;
      if ( (_DWORD)v35 )
        v44 = 0;
      else
        v44 = v87[0] - 8LL;
      if ( v14 == v44 )
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
        hdd_adapter_dev_put_debug(v14, 0x12u, v25, v26, v27, v28, v29, v30, v31, v32);
        goto LABEL_14;
      }
      if ( v44 )
      {
        v45 = *(_QWORD *)(v44 + 32);
        if ( v45 )
        {
          ++*(_DWORD *)(v24 + 16);
          v46 = *(_QWORD *)(v45 + 1320);
          v47 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v46);
          do
            v48 = __ldxr(v47);
          while ( __stxr(v48 + 1, v47) );
          v49 = *(_QWORD *)(v24 + 16) - 1LL;
          *(_DWORD *)(v24 + 16) = v49;
          if ( !v49 || !*(_QWORD *)(v24 + 16) )
            preempt_schedule_notrace(v35);
        }
        _X8 = (unsigned int *)(v44 + 52596);
        __asm { PRFM            #0x11, [X8] }
        do
          v56 = __ldxr(_X8);
        while ( __stxr(v56 + 1, _X8) );
      }
      else
      {
        v33 = 0;
      }
      v13 = v14;
      v34 = *(_QWORD *)(a1 + 40);
      if ( (v34 & 1) != 0 )
        goto LABEL_38;
LABEL_15:
      raw_spin_unlock(a1 + 32);
      v14 = v33;
      if ( !v13 )
        goto LABEL_65;
    }
  }
  hdd_adapter_dev_put_debug(v13, 0x12u, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( v14 )
    hdd_adapter_dev_put_debug(v14, 0x12u, v57, v58, v59, v60, v61, v62, v63, v64);
  result = 1;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
