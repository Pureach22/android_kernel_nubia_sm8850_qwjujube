__int64 __fastcall hdd_is_roaming_in_progress(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x22
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x28
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  __int64 v33; // x8
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x21
  __int64 v44; // x8
  __int64 v45; // x8
  unsigned int *v46; // x8
  unsigned int v47; // w10
  __int64 v48; // x8
  unsigned int v55; // w9
  __int64 result; // x0
  _QWORD *v57; // x1
  __int64 v58; // x9
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  unsigned int *v61; // x9
  unsigned int v62; // w12
  __int64 v63; // x9
  __int64 v65; // x0
  __int64 v66; // x20
  __int64 v67; // x9
  unsigned __int64 v68; // x8
  __int64 v69; // x9
  unsigned int *v70; // x9
  unsigned int v71; // w12
  __int64 v72; // x9
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  _QWORD *v90; // x20
  unsigned int v92; // w9
  unsigned int v94; // w9
  _QWORD v95[2]; // [xsp+0h] [xbp-10h] BYREF

  v95[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_is_roaming_in_progress");
    goto LABEL_49;
  }
  if ( !policy_mgr_is_sta_active_connection_exists(*a1) )
  {
LABEL_49:
    result = 0;
    goto LABEL_50;
  }
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
  v95[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v95);
  if ( (_DWORD)v11 || (v57 = (_QWORD *)v95[0], v12 = v95[0] - 8LL, v95[0] == 8) )
  {
    v12 = 0;
LABEL_9:
    v13 = 0;
    goto LABEL_10;
  }
  v58 = *(__int64 *)((char *)&off_18 + v95[0]);
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
      v90 = v57;
      preempt_schedule_notrace(v11);
      v57 = v90;
    }
  }
  _X8 = (unsigned int *)v57 + 13173;
  __asm { PRFM            #0x11, [X8] }
  do
    v92 = __ldxr(_X8);
  while ( __stxr(v92 + 1, _X8) );
  v95[0] = 0;
  v65 = qdf_list_peek_next(a1 + 6, v57, v95);
  if ( (_DWORD)v65 )
    goto LABEL_9;
  v66 = v95[0];
  v13 = v95[0] - 8LL;
  if ( v95[0] != 8 )
  {
    v67 = *(__int64 *)((char *)&off_18 + v95[0]);
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
    _X8 = (unsigned int *)(v66 + 52692);
    __asm { PRFM            #0x11, [X8] }
    do
      v94 = __ldxr(_X8);
    while ( __stxr(v94 + 1, _X8) );
  }
LABEL_10:
  v14 = a1[5];
  if ( (v14 & 1) != 0 )
  {
    a1[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v12 )
      goto LABEL_12;
    goto LABEL_49;
  }
  raw_spin_unlock(a1 + 4);
  if ( !v12 )
    goto LABEL_49;
LABEL_12:
  v23 = _ReadStatusReg(SP_EL0);
  while ( *(_DWORD *)(v12 + 40) || (*(_QWORD *)(v12 + 1640) & 1) == 0 || v12 == -52832 )
  {
LABEL_17:
    hdd_adapter_dev_put_debug(v12, 0x2Cu, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
      if ( v13 )
        goto LABEL_21;
LABEL_14:
      v32 = 0;
      v12 = 0;
      v33 = a1[5];
      if ( (v33 & 1) == 0 )
        goto LABEL_15;
LABEL_41:
      a1[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_49;
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
      if ( !v13 )
        goto LABEL_14;
LABEL_21:
      v95[0] = 0;
      v34 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v95);
      v32 = v95[0] - 8LL;
      if ( (_DWORD)v34 )
        v43 = 0;
      else
        v43 = v95[0] - 8LL;
      if ( v13 == v43 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v13, 0x2Cu, v24, v25, v26, v27, v28, v29, v30, v31);
        goto LABEL_14;
      }
      if ( v43 )
      {
        v44 = *(_QWORD *)(v43 + 32);
        if ( v44 )
        {
          ++*(_DWORD *)(v23 + 16);
          v45 = *(_QWORD *)(v44 + 1320);
          v46 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v45);
          do
            v47 = __ldxr(v46);
          while ( __stxr(v47 + 1, v46) );
          v48 = *(_QWORD *)(v23 + 16) - 1LL;
          *(_DWORD *)(v23 + 16) = v48;
          if ( !v48 || !*(_QWORD *)(v23 + 16) )
            preempt_schedule_notrace(v34);
        }
        _X8 = (unsigned int *)(v43 + 52700);
        __asm { PRFM            #0x11, [X8] }
        do
          v55 = __ldxr(_X8);
        while ( __stxr(v55 + 1, _X8) );
      }
      else
      {
        v32 = 0;
      }
      v12 = v13;
      v33 = a1[5];
      if ( (v33 & 1) != 0 )
        goto LABEL_41;
LABEL_15:
      raw_spin_unlock(a1 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_49;
    }
  }
  while ( (*(_QWORD *)(v12 + 57248) & 1) == 0
       || (sme_roaming_in_progress(a1[2], *(unsigned __int8 *)(v12 + 52840)) & 1) == 0 )
  {
    if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v12 - *(_DWORD *)(v12 + 52832)) >> 4))
      || (*(_QWORD *)(v12 + 1640) & 1) == 0 )
    {
      goto LABEL_17;
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Roaming is in progress on:vdev_id:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_is_roaming_in_progress",
    *(unsigned __int8 *)(v12 + 52840));
  hdd_adapter_dev_put_debug(v12, 0x2Cu, v74, v75, v76, v77, v78, v79, v80, v81);
  if ( v13 )
    hdd_adapter_dev_put_debug(v13, 0x2Cu, v82, v83, v84, v85, v86, v87, v88, v89);
  result = 1;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
