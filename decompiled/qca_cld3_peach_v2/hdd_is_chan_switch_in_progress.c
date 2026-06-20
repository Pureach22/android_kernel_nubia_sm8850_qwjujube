__int64 __fastcall hdd_is_chan_switch_in_progress(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  _QWORD *v9; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x25
  __int64 vdev_by_user; // x0
  __int64 v25; // x26
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  _QWORD *v37; // x19
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x25
  __int64 v48; // x19
  __int64 v49; // x8
  __int64 v50; // x8
  unsigned int *v51; // x8
  unsigned int v52; // w10
  __int64 v53; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  unsigned int v69; // w9
  _QWORD *v70; // x1
  __int64 v71; // x9
  unsigned __int64 v72; // x8
  __int64 v73; // x9
  unsigned int *v74; // x9
  unsigned int v75; // w12
  __int64 v76; // x9
  __int64 v78; // x0
  __int64 v79; // x19
  __int64 v80; // x9
  unsigned __int64 v81; // x8
  __int64 v82; // x9
  unsigned int *v83; // x9
  unsigned int v84; // w12
  __int64 v85; // x9
  __int64 result; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  _QWORD *v104; // x19
  unsigned int v106; // w9
  unsigned int v108; // w9
  unsigned __int64 v109; // [xsp+0h] [xbp-20h]
  _QWORD *v110; // [xsp+8h] [xbp-18h]
  _QWORD v111[2]; // [xsp+10h] [xbp-10h] BYREF

  v111[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_is_chan_switch_in_progress", a1, a2, a3, a4, a5, a6, a7, a8);
  v9 = context;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(context + 4);
  }
  else
  {
    raw_spin_lock_bh(context + 4);
    v9[5] |= 1uLL;
  }
  v111[0] = 0;
  v11 = qdf_list_peek_front(v9 + 6, v111);
  v110 = v9;
  if ( (_DWORD)v11 || (v70 = (_QWORD *)v111[0], v12 = v111[0] - 8LL, v111[0] == 8) )
  {
    v12 = 0;
    goto LABEL_7;
  }
  v71 = *(__int64 *)((char *)&off_18 + v111[0]);
  if ( v71 )
  {
    v72 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v72 + 16);
    v73 = *(_QWORD *)(v71 + 1320);
    v74 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v73);
    do
      v75 = __ldxr(v74);
    while ( __stxr(v75 + 1, v74) );
    v76 = *(_QWORD *)(v72 + 16) - 1LL;
    *(_DWORD *)(v72 + 16) = v76;
    if ( !v76 || !*(_QWORD *)(v72 + 16) )
    {
      v104 = v70;
      preempt_schedule_notrace(v11);
      v70 = v104;
      v9 = v110;
    }
  }
  _X8 = (unsigned int *)v70 + 13141;
  __asm { PRFM            #0x11, [X8] }
  do
    v106 = __ldxr(_X8);
  while ( __stxr(v106 + 1, _X8) );
  v111[0] = 0;
  v78 = qdf_list_peek_next(v9 + 6, v70, v111);
  if ( (_DWORD)v78 )
  {
LABEL_7:
    v13 = 0;
    v14 = v9[5];
    if ( (v14 & 1) != 0 )
      goto LABEL_71;
LABEL_8:
    raw_spin_unlock(v9 + 4);
    if ( !v12 )
    {
LABEL_72:
      result = 0;
      goto LABEL_77;
    }
    goto LABEL_9;
  }
  v79 = v111[0];
  v13 = v111[0] - 8LL;
  if ( v111[0] != 8 )
  {
    v80 = *(__int64 *)((char *)&off_18 + v111[0]);
    if ( v80 )
    {
      v81 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v81 + 16);
      v82 = *(_QWORD *)(v80 + 1320);
      v83 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v82);
      do
        v84 = __ldxr(v83);
      while ( __stxr(v84 + 1, v83) );
      v85 = *(_QWORD *)(v81 + 16) - 1LL;
      *(_DWORD *)(v81 + 16) = v85;
      if ( !v85 || !*(_QWORD *)(v81 + 16) )
        preempt_schedule_notrace(v78);
    }
    _X8 = (unsigned int *)(v79 + 52564);
    __asm { PRFM            #0x11, [X8] }
    do
      v108 = __ldxr(_X8);
    while ( __stxr(v108 + 1, _X8) );
  }
  v9 = v110;
  v14 = v110[5];
  if ( (v14 & 1) == 0 )
    goto LABEL_8;
LABEL_71:
  v9[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v9 + 4);
  if ( !v12 )
    goto LABEL_72;
LABEL_9:
  v109 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_DWORD *)(v12 + 40) | 2) == 3 )
    {
      if ( (*(_QWORD *)(v12 + 1640) & 1) != 0 )
      {
        v23 = v12 + 52840;
        if ( v12 != -52840 )
          break;
      }
      if ( (*(_QWORD *)(v12 + 1640) & 2) != 0 )
      {
        v23 = v12 + 58928;
        if ( v12 != -58928 )
          break;
      }
      if ( (*(_QWORD *)(v12 + 1640) & 4) != 0 )
      {
        v23 = v12 + 65016;
        if ( v12 != -65016 )
          break;
      }
    }
LABEL_27:
    hdd_adapter_dev_put_debug(v12, 0xCu, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v109 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v109 + 16) & 0xFF00) != 0 )
    {
      v37 = v110;
      raw_spin_lock(v110 + 4);
      if ( v13 )
        goto LABEL_31;
LABEL_49:
      v47 = 0;
      v12 = 0;
      v63 = v37[5];
      if ( (v63 & 1) != 0 )
        goto LABEL_50;
LABEL_46:
      raw_spin_unlock(v37 + 4);
      v13 = v47;
      if ( !v12 )
        goto LABEL_72;
    }
    else
    {
      v37 = v110;
      raw_spin_lock_bh(v110 + 4);
      v110[5] |= 1uLL;
      if ( !v13 )
        goto LABEL_49;
LABEL_31:
      v111[0] = 0;
      v38 = qdf_list_peek_next(v37 + 6, (_QWORD *)(v13 + 8), v111);
      v47 = v111[0] - 8LL;
      if ( (_DWORD)v38 )
        v48 = 0;
      else
        v48 = v111[0] - 8LL;
      if ( v13 == v48 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v13, 0xCu, v55, v56, v57, v58, v59, v60, v61, v62);
        v47 = 0;
        v12 = 0;
      }
      else
      {
        if ( v48 )
        {
          v49 = *(_QWORD *)(v48 + 32);
          if ( v49 )
          {
            ++*(_DWORD *)(v109 + 16);
            v50 = *(_QWORD *)(v49 + 1320);
            v51 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v50);
            do
              v52 = __ldxr(v51);
            while ( __stxr(v52 + 1, v51) );
            v53 = *(_QWORD *)(v109 + 16) - 1LL;
            *(_DWORD *)(v109 + 16) = v53;
            if ( !v53 || !*(_QWORD *)(v109 + 16) )
              preempt_schedule_notrace(v38);
          }
          _X8 = (unsigned int *)(v48 + 52572);
          __asm { PRFM            #0x11, [X8] }
          do
            v69 = __ldxr(_X8);
          while ( __stxr(v69 + 1, _X8) );
        }
        else
        {
          v47 = 0;
        }
        v12 = v13;
      }
      v37 = v110;
      v63 = v110[5];
      if ( (v63 & 1) == 0 )
        goto LABEL_46;
LABEL_50:
      v37[5] = v63 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v37 + 4);
      v13 = v47;
      if ( !v12 )
        goto LABEL_72;
    }
  }
  while ( 1 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(v23, 6, "hdd_is_chan_switch_in_progress");
    if ( !vdev_by_user )
      goto LABEL_22;
    v25 = vdev_by_user;
    if ( !(unsigned int)wlan_vdev_is_restart_progress(vdev_by_user) )
      break;
    _hdd_objmgr_put_vdev_by_user(v25, 6, "hdd_is_chan_switch_in_progress");
    if ( *(_DWORD *)(v23 + 2620) )
      goto LABEL_74;
LABEL_22:
    if ( (unsigned __int8)(73 * ((unsigned int)(v23 - *(_DWORD *)v23 - 52840) >> 3) + 1) <= 2u )
    {
      v34 = (unsigned __int8)(73 * ((unsigned int)(v23 - *(_DWORD *)v23 - 52840) >> 3) + 1);
      v23 = 0;
      v35 = v12 + 52840 + 6088LL * (unsigned int)v34;
      do
      {
        if ( v23 )
          break;
        v36 = *(_QWORD *)(v12 + 1640) >> v34++;
        v23 = (v36 << 63 >> 63) & v35;
        v35 += 6088;
      }
      while ( v34 != 3 );
      if ( v23 )
        continue;
    }
    goto LABEL_27;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev: %d restart in progress",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "hdd_is_chan_switch_in_progress",
    *(unsigned __int8 *)(v25 + 168));
  _hdd_objmgr_put_vdev_by_user(v25, 6, "hdd_is_chan_switch_in_progress");
LABEL_74:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: channel switch progress for vdev_id %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_is_chan_switch_in_progress",
    *(unsigned __int8 *)(v23 + 8),
    v109);
  hdd_adapter_dev_put_debug(v12, 0xCu, v88, v89, v90, v91, v92, v93, v94, v95);
  if ( v13 )
    hdd_adapter_dev_put_debug(v13, 0xCu, v96, v97, v98, v99, v100, v101, v102, v103);
  result = 1;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
