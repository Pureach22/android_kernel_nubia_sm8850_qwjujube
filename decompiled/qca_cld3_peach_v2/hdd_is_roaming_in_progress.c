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
  __int64 v13; // x23
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x22
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
  __int64 v50; // x26
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x10
  unsigned int v59; // w9
  __int64 result; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  _QWORD *v77; // x1
  __int64 v78; // x9
  unsigned __int64 v79; // x8
  __int64 v80; // x9
  unsigned int *v81; // x9
  unsigned int v82; // w12
  __int64 v83; // x9
  __int64 v85; // x0
  __int64 v86; // x20
  __int64 v87; // x9
  unsigned __int64 v88; // x8
  __int64 v89; // x9
  unsigned int *v90; // x9
  unsigned int v91; // w12
  __int64 v92; // x9
  _QWORD *v94; // x20
  unsigned int v96; // w9
  unsigned int v98; // w9
  _QWORD v99[2]; // [xsp+0h] [xbp-10h] BYREF

  v99[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_is_roaming_in_progress");
    goto LABEL_57;
  }
  if ( !policy_mgr_is_sta_active_connection_exists(*a1) )
  {
LABEL_57:
    result = 0;
    goto LABEL_58;
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
  v99[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v99);
  if ( (_DWORD)v11 || (v77 = (_QWORD *)v99[0], v12 = v99[0] - 8LL, v99[0] == 8) )
  {
    v12 = 0;
LABEL_9:
    v13 = 0;
    goto LABEL_10;
  }
  v78 = *(__int64 *)((char *)&off_18 + v99[0]);
  if ( v78 )
  {
    v79 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v79 + 16);
    v80 = *(_QWORD *)(v78 + 1320);
    v81 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v80);
    do
      v82 = __ldxr(v81);
    while ( __stxr(v82 + 1, v81) );
    v83 = *(_QWORD *)(v79 + 16) - 1LL;
    *(_DWORD *)(v79 + 16) = v83;
    if ( !v83 || !*(_QWORD *)(v79 + 16) )
    {
      v94 = v77;
      preempt_schedule_notrace(v11);
      v77 = v94;
    }
  }
  _X8 = (unsigned int *)v77 + 13173;
  __asm { PRFM            #0x11, [X8] }
  do
    v96 = __ldxr(_X8);
  while ( __stxr(v96 + 1, _X8) );
  v99[0] = 0;
  v85 = qdf_list_peek_next(a1 + 6, v77, v99);
  if ( (_DWORD)v85 )
    goto LABEL_9;
  v86 = v99[0];
  v13 = v99[0] - 8LL;
  if ( v99[0] != 8 )
  {
    v87 = *(__int64 *)((char *)&off_18 + v99[0]);
    if ( v87 )
    {
      v88 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v88 + 16);
      v89 = *(_QWORD *)(v87 + 1320);
      v90 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v89);
      do
        v91 = __ldxr(v90);
      while ( __stxr(v91 + 1, v90) );
      v92 = *(_QWORD *)(v88 + 16) - 1LL;
      *(_DWORD *)(v88 + 16) = v92;
      if ( !v92 || !*(_QWORD *)(v88 + 16) )
        preempt_schedule_notrace(v85);
    }
    _X8 = (unsigned int *)(v86 + 52692);
    __asm { PRFM            #0x11, [X8] }
    do
      v98 = __ldxr(_X8);
    while ( __stxr(v98 + 1, _X8) );
  }
LABEL_10:
  v14 = a1[5];
  if ( (v14 & 1) != 0 )
  {
    a1[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v12 )
      goto LABEL_12;
    goto LABEL_57;
  }
  raw_spin_unlock(a1 + 4);
  if ( !v12 )
    goto LABEL_57;
LABEL_12:
  v23 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !*(_DWORD *)(v12 + 40) )
    {
      if ( (*(_QWORD *)(v12 + 1640) & 1) != 0 )
      {
        v50 = v12 + 52840;
        if ( v12 != -52840 )
          break;
      }
      if ( (*(_QWORD *)(v12 + 1640) & 2) != 0 )
      {
        v50 = v12 + 58928;
        if ( v12 != -58928 )
          break;
      }
      if ( (*(_QWORD *)(v12 + 1640) & 4) != 0 )
      {
        v50 = v12 + 65016;
        if ( v12 != -65016 )
          break;
      }
    }
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
LABEL_49:
      a1[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_57;
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
      if ( !v13 )
        goto LABEL_14;
LABEL_21:
      v99[0] = 0;
      v34 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v99);
      v32 = v99[0] - 8LL;
      if ( (_DWORD)v34 )
        v43 = 0;
      else
        v43 = v99[0] - 8LL;
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
          v59 = __ldxr(_X8);
        while ( __stxr(v59 + 1, _X8) );
      }
      else
      {
        v32 = 0;
      }
      v12 = v13;
      v33 = a1[5];
      if ( (v33 & 1) != 0 )
        goto LABEL_49;
LABEL_15:
      raw_spin_unlock(a1 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_57;
    }
  }
  while ( (*(_QWORD *)(v50 + 5968) & 1) == 0 || (sme_roaming_in_progress(a1[2], *(unsigned __int8 *)(v50 + 8)) & 1) == 0 )
  {
    if ( (unsigned __int8)(73 * ((unsigned int)(v50 - *(_DWORD *)v50 - 52840) >> 3) + 1) <= 2u )
    {
      v51 = (unsigned __int8)(73 * ((unsigned int)(v50 - *(_DWORD *)v50 - 52840) >> 3) + 1);
      v50 = 0;
      v52 = v12 + 52840 + 6088LL * (unsigned int)v51;
      do
      {
        if ( v50 )
          break;
        v53 = *(_QWORD *)(v12 + 1640) >> v51++;
        v50 = (v53 << 63 >> 63) & v52;
        v52 += 6088;
      }
      while ( v51 != 3 );
      if ( v50 )
        continue;
    }
    goto LABEL_17;
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
    *(unsigned __int8 *)(v50 + 8));
  hdd_adapter_dev_put_debug(v12, 0x2Cu, v61, v62, v63, v64, v65, v66, v67, v68);
  if ( v13 )
    hdd_adapter_dev_put_debug(v13, 0x2Cu, v69, v70, v71, v72, v73, v74, v75, v76);
  result = 1;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
