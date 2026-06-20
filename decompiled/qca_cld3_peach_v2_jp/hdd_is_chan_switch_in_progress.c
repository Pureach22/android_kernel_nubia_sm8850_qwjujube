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
  unsigned __int64 v23; // x24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x25
  __int64 v33; // x8
  __int64 vdev_by_user; // x0
  __int64 v35; // x26
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x21
  __int64 v54; // x8
  __int64 v55; // x8
  unsigned int *v56; // x8
  unsigned int v57; // w10
  __int64 v58; // x8
  unsigned int v65; // w9
  _QWORD *v66; // x1
  __int64 v67; // x9
  unsigned __int64 v68; // x8
  __int64 v69; // x9
  unsigned int *v70; // x9
  unsigned int v71; // w12
  __int64 v72; // x9
  __int64 v74; // x0
  __int64 v75; // x22
  __int64 v76; // x9
  unsigned __int64 v77; // x8
  __int64 v78; // x9
  unsigned int *v79; // x9
  unsigned int v80; // w12
  __int64 v81; // x9
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 result; // x0
  _QWORD *v100; // x20
  unsigned int v102; // w9
  unsigned int v104; // w9
  _QWORD v105[2]; // [xsp+0h] [xbp-10h] BYREF

  v105[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v105[0] = 0;
  v11 = qdf_list_peek_front(v9 + 6, v105);
  if ( (_DWORD)v11 || (v66 = (_QWORD *)v105[0], v12 = v105[0] - 8LL, v105[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v67 = *(__int64 *)((char *)&off_18 + v105[0]);
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
    {
      v100 = v66;
      preempt_schedule_notrace(v11);
      v66 = v100;
    }
  }
  _X8 = (unsigned int *)v66 + 13141;
  __asm { PRFM            #0x11, [X8] }
  do
    v102 = __ldxr(_X8);
  while ( __stxr(v102 + 1, _X8) );
  v105[0] = 0;
  v74 = qdf_list_peek_next(v9 + 6, v66, v105);
  if ( (_DWORD)v74 )
    goto LABEL_7;
  v75 = v105[0];
  v13 = v105[0] - 8LL;
  if ( v105[0] != 8 )
  {
    v76 = *(__int64 *)((char *)&off_18 + v105[0]);
    if ( v76 )
    {
      v77 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v77 + 16);
      v78 = *(_QWORD *)(v76 + 1320);
      v79 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v78);
      do
        v80 = __ldxr(v79);
      while ( __stxr(v80 + 1, v79) );
      v81 = *(_QWORD *)(v77 + 16) - 1LL;
      *(_DWORD *)(v77 + 16) = v81;
      if ( !v81 || !*(_QWORD *)(v77 + 16) )
        preempt_schedule_notrace(v74);
    }
    _X8 = (unsigned int *)(v75 + 52564);
    __asm { PRFM            #0x11, [X8] }
    do
      v104 = __ldxr(_X8);
    while ( __stxr(v104 + 1, _X8) );
  }
LABEL_8:
  v14 = v9[5];
  if ( (v14 & 1) != 0 )
  {
    v9[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 4);
    if ( v12 )
      goto LABEL_10;
LABEL_66:
    result = 0;
    goto LABEL_67;
  }
  raw_spin_unlock(v9 + 4);
  if ( !v12 )
    goto LABEL_66;
LABEL_10:
  v23 = _ReadStatusReg(SP_EL0);
  while ( (*(_DWORD *)(v12 + 40) | 2) != 3 || (*(_QWORD *)(v12 + 1640) & 1) == 0 || v12 == -52832 )
  {
LABEL_22:
    hdd_adapter_dev_put_debug(v12, 0xCu, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v9 + 4);
      if ( v13 )
        goto LABEL_26;
LABEL_12:
      v32 = 0;
      v12 = 0;
      v33 = v9[5];
      if ( (v33 & 1) == 0 )
        goto LABEL_13;
LABEL_39:
      v9[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v9 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_66;
    }
    else
    {
      raw_spin_lock_bh(v9 + 4);
      v9[5] |= 1uLL;
      if ( !v13 )
        goto LABEL_12;
LABEL_26:
      v105[0] = 0;
      v44 = qdf_list_peek_next(v9 + 6, (_QWORD *)(v13 + 8), v105);
      v32 = v105[0] - 8LL;
      if ( (_DWORD)v44 )
        v53 = 0;
      else
        v53 = v105[0] - 8LL;
      if ( v13 == v53 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v13, 0xCu, v24, v25, v26, v27, v28, v29, v30, v31);
        goto LABEL_12;
      }
      if ( v53 )
      {
        v54 = *(_QWORD *)(v53 + 32);
        if ( v54 )
        {
          ++*(_DWORD *)(v23 + 16);
          v55 = *(_QWORD *)(v54 + 1320);
          v56 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v55);
          do
            v57 = __ldxr(v56);
          while ( __stxr(v57 + 1, v56) );
          v58 = *(_QWORD *)(v23 + 16) - 1LL;
          *(_DWORD *)(v23 + 16) = v58;
          if ( !v58 || !*(_QWORD *)(v23 + 16) )
            preempt_schedule_notrace(v44);
        }
        _X8 = (unsigned int *)(v53 + 52572);
        __asm { PRFM            #0x11, [X8] }
        do
          v65 = __ldxr(_X8);
        while ( __stxr(v65 + 1, _X8) );
      }
      else
      {
        v32 = 0;
      }
      v12 = v13;
      v33 = v9[5];
      if ( (v33 & 1) != 0 )
        goto LABEL_39;
LABEL_13:
      raw_spin_unlock(v9 + 4);
      v13 = v32;
      if ( !v12 )
        goto LABEL_66;
    }
  }
  while ( 1 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(v12 + 52832, 6, "hdd_is_chan_switch_in_progress");
    if ( !vdev_by_user )
      goto LABEL_20;
    v35 = vdev_by_user;
    if ( !(unsigned int)wlan_vdev_is_restart_progress(vdev_by_user) )
      break;
    _hdd_objmgr_put_vdev_by_user(v35, 6, "hdd_is_chan_switch_in_progress");
    if ( *(_DWORD *)(v12 + 55180) )
      goto LABEL_62;
LABEL_20:
    if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v12 - *(_DWORD *)(v12 + 52832)) >> 4))
      || (*(_QWORD *)(v12 + 1640) & 1) == 0 )
    {
      goto LABEL_22;
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev: %d restart in progress",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "hdd_is_chan_switch_in_progress",
    *(unsigned __int8 *)(v35 + 104));
  _hdd_objmgr_put_vdev_by_user(v35, 6, "hdd_is_chan_switch_in_progress");
LABEL_62:
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
    *(unsigned __int8 *)(v12 + 52840));
  hdd_adapter_dev_put_debug(v12, 0xCu, v83, v84, v85, v86, v87, v88, v89, v90);
  if ( v13 )
    hdd_adapter_dev_put_debug(v13, 0xCu, v91, v92, v93, v94, v95, v96, v97, v98);
  result = 1;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
