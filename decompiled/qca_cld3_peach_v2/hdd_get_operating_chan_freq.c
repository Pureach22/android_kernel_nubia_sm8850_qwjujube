__int64 __fastcall hdd_get_operating_chan_freq(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v17; // x25
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x28
  __int64 v27; // x8
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  __int64 v38; // x8
  __int64 v39; // x8
  unsigned int *v40; // x8
  unsigned int v41; // w10
  __int64 v42; // x8
  unsigned int v49; // w9
  _QWORD *v50; // x1
  __int64 v51; // x9
  unsigned __int64 v52; // x8
  __int64 v53; // x9
  unsigned int *v54; // x9
  unsigned int v55; // w12
  __int64 v56; // x9
  __int64 v58; // x0
  __int64 v59; // x23
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned int *v63; // x9
  unsigned int v64; // w12
  __int64 v65; // x9
  __int64 v67; // x19
  int v68; // w9
  unsigned int v69; // w8
  unsigned int v70; // w19
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 result; // x0
  _QWORD *v80; // x21
  unsigned int v82; // w9
  unsigned int v84; // w9
  _QWORD v85[2]; // [xsp+0h] [xbp-10h] BYREF

  v85[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v85[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v85);
  if ( (_DWORD)v5 || (v50 = (_QWORD *)v85[0], v6 = v85[0] - 8LL, v85[0] == 8) )
  {
    v6 = 0;
LABEL_7:
    v7 = 0;
    goto LABEL_8;
  }
  v51 = *(__int64 *)((char *)&off_18 + v85[0]);
  if ( v51 )
  {
    v52 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v52 + 16);
    v53 = *(_QWORD *)(v51 + 1320);
    v54 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v53);
    do
      v55 = __ldxr(v54);
    while ( __stxr(v55 + 1, v54) );
    v56 = *(_QWORD *)(v52 + 16) - 1LL;
    *(_DWORD *)(v52 + 16) = v56;
    if ( !v56 || !*(_QWORD *)(v52 + 16) )
    {
      v80 = v50;
      preempt_schedule_notrace(v5);
      v50 = v80;
    }
  }
  _X8 = (unsigned int *)v50 + 13155;
  __asm { PRFM            #0x11, [X8] }
  do
    v82 = __ldxr(_X8);
  while ( __stxr(v82 + 1, _X8) );
  v85[0] = 0;
  v58 = qdf_list_peek_next((_QWORD *)(a1 + 48), v50, v85);
  if ( (_DWORD)v58 )
    goto LABEL_7;
  v59 = v85[0];
  v7 = v85[0] - 8LL;
  if ( v85[0] != 8 )
  {
    v60 = *(__int64 *)((char *)&off_18 + v85[0]);
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
        preempt_schedule_notrace(v58);
    }
    _X8 = (unsigned int *)(v59 + 52620);
    __asm { PRFM            #0x11, [X8] }
    do
      v84 = __ldxr(_X8);
    while ( __stxr(v84 + 1, _X8) );
  }
LABEL_8:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v6 )
      goto LABEL_10;
LABEL_69:
    result = 0;
    goto LABEL_70;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v6 )
    goto LABEL_69;
LABEL_10:
  v17 = _ReadStatusReg(SP_EL0);
  while ( *(_DWORD *)(v6 + 40) != a2 )
  {
    hdd_adapter_dev_put_debug(v6, 0x1Au, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_19;
LABEL_12:
      v26 = 0;
      v6 = 0;
      v27 = *(_QWORD *)(a1 + 40);
      if ( (v27 & 1) == 0 )
        goto LABEL_13;
LABEL_32:
      *(_QWORD *)(a1 + 40) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_69;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_19:
      v85[0] = 0;
      v28 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v85);
      v26 = v85[0] - 8LL;
      if ( (_DWORD)v28 )
        v37 = 0;
      else
        v37 = v85[0] - 8LL;
      if ( v7 == v37 )
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
        hdd_adapter_dev_put_debug(v7, 0x1Au, v18, v19, v20, v21, v22, v23, v24, v25);
        goto LABEL_12;
      }
      if ( v37 )
      {
        v38 = *(_QWORD *)(v37 + 32);
        if ( v38 )
        {
          ++*(_DWORD *)(v17 + 16);
          v39 = *(_QWORD *)(v38 + 1320);
          v40 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v39);
          do
            v41 = __ldxr(v40);
          while ( __stxr(v41 + 1, v40) );
          v42 = *(_QWORD *)(v17 + 16) - 1LL;
          *(_DWORD *)(v17 + 16) = v42;
          if ( !v42 || !*(_QWORD *)(v17 + 16) )
            preempt_schedule_notrace(v28);
        }
        _X8 = (unsigned int *)(v37 + 52628);
        __asm { PRFM            #0x11, [X8] }
        do
          v49 = __ldxr(_X8);
        while ( __stxr(v49 + 1, _X8) );
      }
      else
      {
        v26 = 0;
      }
      v6 = v7;
      v27 = *(_QWORD *)(a1 + 40);
      if ( (v27 & 1) != 0 )
        goto LABEL_32;
LABEL_13:
      raw_spin_unlock(a1 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_69;
    }
  }
  v67 = *(_QWORD *)(v6 + 52832);
  v68 = *(_DWORD *)(*(_QWORD *)v67 + 40LL);
  v69 = 0;
  if ( v68 > 1 )
  {
    if ( v68 != 2 )
    {
      if ( v68 != 3 )
        goto LABEL_65;
LABEL_60:
      if ( (*(_QWORD *)(v67 + 5968) & 2) != 0 )
      {
        v69 = *(_DWORD *)(v67 + 2424);
        goto LABEL_65;
      }
LABEL_64:
      v69 = 0;
      goto LABEL_65;
    }
LABEL_62:
    if ( hdd_cm_is_vdev_associated(*(_DWORD **)(v6 + 52832)) )
    {
      v69 = *(_DWORD *)(v67 + 700);
      goto LABEL_65;
    }
    goto LABEL_64;
  }
  if ( !v68 )
    goto LABEL_62;
  if ( v68 == 1 )
    goto LABEL_60;
LABEL_65:
  v70 = v69;
  hdd_adapter_dev_put_debug(v6, 0x1Au, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x1Au, v71, v72, v73, v74, v75, v76, v77, v78);
  result = v70;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
