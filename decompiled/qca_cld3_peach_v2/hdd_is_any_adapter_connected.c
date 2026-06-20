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
  unsigned __int64 v15; // x28
  __int64 v16; // x24
  int v17; // w8
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x24
  __int64 v31; // x21
  __int64 v32; // x8
  __int64 v33; // x8
  unsigned int *v34; // x8
  unsigned int v35; // w10
  __int64 v36; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  unsigned int v52; // w9
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  _QWORD *v62; // x1
  __int64 v63; // x9
  unsigned __int64 v64; // x8
  __int64 v65; // x9
  unsigned int *v66; // x9
  unsigned int v67; // w12
  __int64 v68; // x9
  __int64 v70; // x0
  __int64 v71; // x22
  __int64 v72; // x9
  unsigned __int64 v73; // x8
  __int64 v74; // x9
  unsigned int *v75; // x9
  unsigned int v76; // w12
  __int64 v77; // x9
  _QWORD *v79; // x20
  unsigned int v81; // w9
  unsigned int v83; // w9
  _QWORD v84[2]; // [xsp+0h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v84[0] = 0;
  v3 = qdf_list_peek_front((_QWORD *)(a1 + 48), v84);
  if ( (_DWORD)v3 || (v62 = (_QWORD *)v84[0], v4 = v84[0] - 8LL, v84[0] == 8) )
  {
    v4 = 0;
LABEL_7:
    v5 = 0;
    goto LABEL_8;
  }
  v63 = *(__int64 *)((char *)&off_18 + v84[0]);
  if ( v63 )
  {
    v64 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v64 + 16);
    v65 = *(_QWORD *)(v63 + 1320);
    v66 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v65);
    do
      v67 = __ldxr(v66);
    while ( __stxr(v67 + 1, v66) );
    v68 = *(_QWORD *)(v64 + 16) - 1LL;
    *(_DWORD *)(v64 + 16) = v68;
    if ( !v68 || !*(_QWORD *)(v64 + 16) )
    {
      v79 = v62;
      preempt_schedule_notrace(v3);
      v62 = v79;
    }
  }
  _X8 = (unsigned int *)(v62 + 6586);
  __asm { PRFM            #0x11, [X8] }
  do
    v81 = __ldxr(_X8);
  while ( __stxr(v81 + 1, _X8) );
  v84[0] = 0;
  v70 = qdf_list_peek_next((_QWORD *)(a1 + 48), v62, v84);
  if ( (_DWORD)v70 )
    goto LABEL_7;
  v71 = v84[0];
  v5 = v84[0] - 8LL;
  if ( v84[0] != 8 )
  {
    v72 = *(__int64 *)((char *)&off_18 + v84[0]);
    if ( v72 )
    {
      v73 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v73 + 16);
      v74 = *(_QWORD *)(v72 + 1320);
      v75 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v74);
      do
        v76 = __ldxr(v75);
      while ( __stxr(v76 + 1, v75) );
      v77 = *(_QWORD *)(v73 + 16) - 1LL;
      *(_DWORD *)(v73 + 16) = v77;
      if ( !v77 || !*(_QWORD *)(v73 + 16) )
        preempt_schedule_notrace(v70);
    }
    _X8 = (unsigned int *)(v71 + 52688);
    __asm { PRFM            #0x11, [X8] }
    do
      v83 = __ldxr(_X8);
    while ( __stxr(v83 + 1, _X8) );
  }
LABEL_8:
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v4 )
      goto LABEL_10;
LABEL_79:
    result = 0;
    goto LABEL_80;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v4 )
    goto LABEL_79;
LABEL_10:
  v15 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_QWORD *)(v4 + 1640) & 1) != 0 )
    {
      v16 = v4 + 52840;
      if ( v4 != -52840 )
        break;
    }
    if ( (*(_QWORD *)(v4 + 1640) & 2) != 0 )
    {
      v16 = v4 + 58928;
      if ( v4 != -58928 )
        break;
    }
    if ( (*(_QWORD *)(v4 + 1640) & 4) != 0 )
    {
      v16 = v4 + 65016;
      if ( v4 != -65016 )
        break;
    }
LABEL_32:
    hdd_adapter_dev_put_debug(v4, 0x2Bu, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v15 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( !v5 )
        goto LABEL_48;
LABEL_36:
      v84[0] = 0;
      v21 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v5 + 8), v84);
      v30 = v84[0] - 8LL;
      if ( (_DWORD)v21 )
        v31 = 0;
      else
        v31 = v84[0] - 8LL;
      if ( v5 == v31 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v5, 0x2Bu, v38, v39, v40, v41, v42, v43, v44, v45);
        goto LABEL_48;
      }
      if ( v31 )
      {
        v32 = *(_QWORD *)(v31 + 32);
        if ( v32 )
        {
          ++*(_DWORD *)(v15 + 16);
          v33 = *(_QWORD *)(v32 + 1320);
          v34 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v33);
          do
            v35 = __ldxr(v34);
          while ( __stxr(v35 + 1, v34) );
          v36 = *(_QWORD *)(v15 + 16) - 1LL;
          *(_DWORD *)(v15 + 16) = v36;
          if ( !v36 || !*(_QWORD *)(v15 + 16) )
            preempt_schedule_notrace(v21);
        }
        _X8 = (unsigned int *)(v31 + 52696);
        __asm { PRFM            #0x11, [X8] }
        do
          v52 = __ldxr(_X8);
        while ( __stxr(v52 + 1, _X8) );
      }
      else
      {
        v30 = 0;
      }
      v4 = v5;
      v46 = *(_QWORD *)(a1 + 40);
      if ( (v46 & 1) != 0 )
        goto LABEL_53;
LABEL_49:
      raw_spin_unlock(a1 + 32);
      v5 = v30;
      if ( !v4 )
        goto LABEL_79;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( v5 )
        goto LABEL_36;
LABEL_48:
      v30 = 0;
      v4 = 0;
      v46 = *(_QWORD *)(a1 + 40);
      if ( (v46 & 1) == 0 )
        goto LABEL_49;
LABEL_53:
      *(_QWORD *)(a1 + 40) = v46 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v5 = v30;
      if ( !v4 )
        goto LABEL_79;
    }
  }
  while ( 1 )
  {
    v17 = *(_DWORD *)(v4 + 40);
    if ( (v17 & 0xFFFFFFFD) == 0 )
    {
      if ( hdd_cm_is_vdev_associated((_DWORD *)v16) )
        goto LABEL_60;
      v17 = *(_DWORD *)(v4 + 40);
    }
    if ( (v17 & 0xFFFFFFFD) != 1 )
      break;
    if ( *(_BYTE *)(v16 + 257) == 1 )
      goto LABEL_60;
LABEL_27:
    if ( (unsigned __int8)(73 * ((unsigned int)(v16 - *(_DWORD *)v16 - 52840) >> 3) + 1) <= 2u )
    {
      v18 = (unsigned __int8)(73 * ((unsigned int)(v16 - *(_DWORD *)v16 - 52840) >> 3) + 1);
      v16 = 0;
      v19 = v4 + 52840 + 6088LL * (unsigned int)v18;
      do
      {
        if ( v16 )
          break;
        v20 = *(_QWORD *)(v4 + 1640) >> v18++;
        v16 = (v20 << 63 >> 63) & v19;
        v19 += 6088;
      }
      while ( v18 != 3 );
      if ( v16 )
        continue;
    }
    goto LABEL_32;
  }
  if ( v17 != 11 || !hdd_cm_is_vdev_associated((_DWORD *)v16) )
    goto LABEL_27;
LABEL_60:
  hdd_adapter_dev_put_debug(v4, 0x2Bu, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( v5 )
    hdd_adapter_dev_put_debug(v5, 0x2Bu, v53, v54, v55, v56, v57, v58, v59, v60);
  result = 1;
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
