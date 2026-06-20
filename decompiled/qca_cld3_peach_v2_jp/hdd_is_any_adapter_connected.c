__int64 __fastcall hdd_is_any_adapter_connected(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x26
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x24
  __int64 v25; // x8
  int v26; // w8
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned int *v39; // x8
  unsigned int v40; // w10
  __int64 v41; // x8
  unsigned int v48; // w9
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 result; // x0
  _QWORD *v58; // x1
  __int64 v59; // x9
  unsigned __int64 v60; // x8
  __int64 v61; // x9
  unsigned int *v62; // x9
  unsigned int v63; // w12
  __int64 v64; // x9
  __int64 v66; // x0
  __int64 v67; // x22
  __int64 v68; // x9
  unsigned __int64 v69; // x8
  __int64 v70; // x9
  unsigned int *v71; // x9
  unsigned int v72; // w12
  __int64 v73; // x9
  _QWORD *v75; // x20
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
  if ( (_DWORD)v3 || (v58 = (_QWORD *)v80[0], v4 = v80[0] - 8LL, v80[0] == 8) )
  {
    v4 = 0;
LABEL_7:
    v5 = 0;
    goto LABEL_8;
  }
  v59 = *(__int64 *)((char *)&off_18 + v80[0]);
  if ( v59 )
  {
    v60 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v60 + 16);
    v61 = *(_QWORD *)(v59 + 1320);
    v62 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v61);
    do
      v63 = __ldxr(v62);
    while ( __stxr(v63 + 1, v62) );
    v64 = *(_QWORD *)(v60 + 16) - 1LL;
    *(_DWORD *)(v60 + 16) = v64;
    if ( !v64 || !*(_QWORD *)(v60 + 16) )
    {
      v75 = v58;
      preempt_schedule_notrace(v3);
      v58 = v75;
    }
  }
  _X8 = (unsigned int *)(v58 + 6586);
  __asm { PRFM            #0x11, [X8] }
  do
    v77 = __ldxr(_X8);
  while ( __stxr(v77 + 1, _X8) );
  v80[0] = 0;
  v66 = qdf_list_peek_next((_QWORD *)(a1 + 48), v58, v80);
  if ( (_DWORD)v66 )
    goto LABEL_7;
  v67 = v80[0];
  v5 = v80[0] - 8LL;
  if ( v80[0] != 8 )
  {
    v68 = *(__int64 *)((char *)&off_18 + v80[0]);
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
        preempt_schedule_notrace(v66);
    }
    _X8 = (unsigned int *)(v67 + 52688);
    __asm { PRFM            #0x11, [X8] }
    do
      v79 = __ldxr(_X8);
    while ( __stxr(v79 + 1, _X8) );
  }
LABEL_8:
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v4 )
      goto LABEL_10;
LABEL_69:
    result = 0;
    goto LABEL_70;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v4 )
    goto LABEL_69;
LABEL_10:
  v15 = _ReadStatusReg(SP_EL0);
  while ( (*(_QWORD *)(v4 + 1640) & 1) == 0 || v4 == -52832 )
  {
LABEL_26:
    hdd_adapter_dev_put_debug(v4, 0x2Bu, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v15 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v5 )
        goto LABEL_30;
LABEL_12:
      v24 = 0;
      v4 = 0;
      v25 = *(_QWORD *)(a1 + 40);
      if ( (v25 & 1) == 0 )
        goto LABEL_13;
LABEL_43:
      *(_QWORD *)(a1 + 40) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v5 = v24;
      if ( !v4 )
        goto LABEL_69;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v5 )
        goto LABEL_12;
LABEL_30:
      v80[0] = 0;
      v27 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v5 + 8), v80);
      v24 = v80[0] - 8LL;
      if ( (_DWORD)v27 )
        v36 = 0;
      else
        v36 = v80[0] - 8LL;
      if ( v5 == v36 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v5, 0x2Bu, v16, v17, v18, v19, v20, v21, v22, v23);
        goto LABEL_12;
      }
      if ( v36 )
      {
        v37 = *(_QWORD *)(v36 + 32);
        if ( v37 )
        {
          ++*(_DWORD *)(v15 + 16);
          v38 = *(_QWORD *)(v37 + 1320);
          v39 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v38);
          do
            v40 = __ldxr(v39);
          while ( __stxr(v40 + 1, v39) );
          v41 = *(_QWORD *)(v15 + 16) - 1LL;
          *(_DWORD *)(v15 + 16) = v41;
          if ( !v41 || !*(_QWORD *)(v15 + 16) )
            preempt_schedule_notrace(v27);
        }
        _X8 = (unsigned int *)(v36 + 52696);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 + 1, _X8) );
      }
      else
      {
        v24 = 0;
      }
      v4 = v5;
      v25 = *(_QWORD *)(a1 + 40);
      if ( (v25 & 1) != 0 )
        goto LABEL_43;
LABEL_13:
      raw_spin_unlock(a1 + 32);
      v5 = v24;
      if ( !v4 )
        goto LABEL_69;
    }
  }
  while ( 1 )
  {
    v26 = *(_DWORD *)(v4 + 40);
    if ( (v26 & 0xFFFFFFFD) == 0 )
    {
      if ( hdd_cm_is_vdev_associated((_DWORD *)(v4 + 52832)) )
        goto LABEL_50;
      v26 = *(_DWORD *)(v4 + 40);
    }
    if ( (v26 & 0xFFFFFFFD) != 1 )
      break;
    if ( *(_BYTE *)(v4 + 53089) == 1 )
      goto LABEL_50;
LABEL_24:
    if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v4 - *(_DWORD *)(v4 + 52832)) >> 4))
      || (*(_QWORD *)(v4 + 1640) & 1) == 0 )
    {
      goto LABEL_26;
    }
  }
  if ( v26 != 11 || !hdd_cm_is_vdev_associated((_DWORD *)(v4 + 52832)) )
    goto LABEL_24;
LABEL_50:
  hdd_adapter_dev_put_debug(v4, 0x2Bu, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( v5 )
    hdd_adapter_dev_put_debug(v5, 0x2Bu, v49, v50, v51, v52, v53, v54, v55, v56);
  result = 1;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
