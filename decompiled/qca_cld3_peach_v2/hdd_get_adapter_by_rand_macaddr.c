__int64 __fastcall hdd_get_adapter_by_rand_macaddr(__int64 *a1, const void *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x27
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v17; // x28
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 v27; // x8
  unsigned int v28; // w8
  __int64 v29; // x23
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x10
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x21
  __int64 v43; // x8
  __int64 v44; // x8
  unsigned int *v45; // x8
  unsigned int v46; // w10
  __int64 v47; // x8
  unsigned int v54; // w9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  _QWORD *v64; // x1
  __int64 v65; // x9
  unsigned __int64 v66; // x8
  __int64 v67; // x9
  unsigned int *v68; // x9
  unsigned int v69; // w12
  __int64 v70; // x9
  __int64 v72; // x0
  __int64 v73; // x22
  __int64 v74; // x9
  unsigned __int64 v75; // x8
  __int64 v76; // x9
  unsigned int *v77; // x9
  unsigned int v78; // w12
  __int64 v79; // x9
  _QWORD *v81; // x22
  unsigned int v83; // w9
  unsigned int v85; // w9
  _QWORD v86[2]; // [xsp+0h] [xbp-10h] BYREF

  v86[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v86[0] = 0;
  v5 = qdf_list_peek_front(a1 + 6, v86);
  if ( (_DWORD)v5 || (v64 = (_QWORD *)v86[0], v6 = v86[0] - 8LL, v86[0] == 8) )
  {
    v6 = 0;
  }
  else
  {
    v65 = *(__int64 *)((char *)&off_18 + v86[0]);
    if ( v65 )
    {
      v66 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v66 + 16);
      v67 = *(_QWORD *)(v65 + 1320);
      v68 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v67);
      do
        v69 = __ldxr(v68);
      while ( __stxr(v69 + 1, v68) );
      v70 = *(_QWORD *)(v66 + 16) - 1LL;
      *(_DWORD *)(v66 + 16) = v70;
      if ( !v70 || !*(_QWORD *)(v66 + 16) )
      {
        v81 = v64;
        preempt_schedule_notrace(v5);
        v64 = v81;
      }
    }
    _X8 = (unsigned int *)v64 + 13149;
    __asm { PRFM            #0x11, [X8] }
    do
      v83 = __ldxr(_X8);
    while ( __stxr(v83 + 1, _X8) );
    v86[0] = 0;
    v72 = qdf_list_peek_next(a1 + 6, v64, v86);
    if ( !(_DWORD)v72 )
    {
      v73 = v86[0];
      v7 = v86[0] - 8LL;
      if ( v86[0] != 8 )
      {
        v74 = *(__int64 *)((char *)&off_18 + v86[0]);
        if ( v74 )
        {
          v75 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v75 + 16);
          v76 = *(_QWORD *)(v74 + 1320);
          v77 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v76);
          do
            v78 = __ldxr(v77);
          while ( __stxr(v78 + 1, v77) );
          v79 = *(_QWORD *)(v75 + 16) - 1LL;
          *(_DWORD *)(v75 + 16) = v79;
          if ( !v79 || !*(_QWORD *)(v75 + 16) )
            preempt_schedule_notrace(v72);
        }
        _X8 = (unsigned int *)(v73 + 52596);
        __asm { PRFM            #0x11, [X8] }
        do
          v85 = __ldxr(_X8);
        while ( __stxr(v85 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v7 = 0;
LABEL_8:
  v8 = a1[5];
  if ( (v8 & 1) != 0 )
  {
    a1[5] = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( !v6 )
      goto LABEL_56;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( !v6 )
      goto LABEL_56;
  }
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v28 = *(_DWORD *)(v6 + 40);
    if ( v28 <= 7 && ((1 << v28) & 0x85) != 0 )
    {
      if ( (*(_QWORD *)(v6 + 1640) & 1) != 0 )
      {
        v29 = v6 + 52840;
        if ( v6 != -52840 )
          break;
      }
      if ( (*(_QWORD *)(v6 + 1640) & 2) != 0 )
      {
        v29 = v6 + 58928;
        if ( v6 != -58928 )
          break;
      }
      if ( (*(_QWORD *)(v6 + 1640) & 4) != 0 )
      {
        v29 = v6 + 65016;
        if ( v6 != -65016 )
          break;
      }
    }
LABEL_30:
    hdd_adapter_dev_put_debug(v6, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
      if ( v7 )
        goto LABEL_34;
LABEL_12:
      v26 = 0;
      v6 = 0;
      v27 = a1[5];
      if ( (v27 & 1) == 0 )
        goto LABEL_13;
LABEL_47:
      a1[5] = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v7 = v26;
      if ( !v6 )
        goto LABEL_56;
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_34:
      v86[0] = 0;
      v33 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v7 + 8), v86);
      v26 = v86[0] - 8LL;
      if ( (_DWORD)v33 )
        v42 = 0;
      else
        v42 = v86[0] - 8LL;
      if ( v7 == v42 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0x14u, v18, v19, v20, v21, v22, v23, v24, v25);
        goto LABEL_12;
      }
      if ( v42 )
      {
        v43 = *(_QWORD *)(v42 + 32);
        if ( v43 )
        {
          ++*(_DWORD *)(v17 + 16);
          v44 = *(_QWORD *)(v43 + 1320);
          v45 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v44);
          do
            v46 = __ldxr(v45);
          while ( __stxr(v46 + 1, v45) );
          v47 = *(_QWORD *)(v17 + 16) - 1LL;
          *(_DWORD *)(v17 + 16) = v47;
          if ( !v47 || !*(_QWORD *)(v17 + 16) )
            preempt_schedule_notrace(v33);
        }
        _X8 = (unsigned int *)(v42 + 52604);
        __asm { PRFM            #0x11, [X8] }
        do
          v54 = __ldxr(_X8);
        while ( __stxr(v54 + 1, _X8) );
      }
      else
      {
        v26 = 0;
      }
      v6 = v7;
      v27 = a1[5];
      if ( (v27 & 1) != 0 )
        goto LABEL_47;
LABEL_13:
      raw_spin_unlock(a1 + 4);
      v7 = v26;
      if ( !v6 )
        goto LABEL_56;
    }
  }
  while ( (ucfg_p2p_check_random_mac(*a1, *(unsigned __int8 *)(v29 + 8), a2) & 1) == 0 )
  {
    if ( (unsigned __int8)(73 * ((unsigned int)(v29 - *(_DWORD *)v29 - 52840) >> 3) + 1) <= 2u )
    {
      v30 = (unsigned __int8)(73 * ((unsigned int)(v29 - *(_DWORD *)v29 - 52840) >> 3) + 1);
      v29 = 0;
      v31 = v6 + 52840 + 6088LL * (unsigned int)v30;
      do
      {
        if ( v29 )
          break;
        v32 = *(_QWORD *)(v6 + 1640) >> v30++;
        v29 = (v32 << 63 >> 63) & v31;
        v31 += 6088;
      }
      while ( v30 != 3 );
      if ( v29 )
        continue;
    }
    goto LABEL_30;
  }
  hdd_adapter_dev_put_debug(v6, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x14u, v55, v56, v57, v58, v59, v60, v61, v62);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v6;
}
