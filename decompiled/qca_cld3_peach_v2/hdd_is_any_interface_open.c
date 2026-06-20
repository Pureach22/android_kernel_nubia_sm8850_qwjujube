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
  __int64 v14; // x25
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x27
  __int64 v25; // x9
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  __int64 v36; // x21
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned int *v39; // x8
  unsigned int v40; // w10
  __int64 v41; // x8
  unsigned int v43; // w9
  __int64 v44; // x10
  __int64 v45; // x11
  __int64 v46; // x9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  unsigned int v61; // w9
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  _QWORD *v70; // x1
  __int64 v71; // x9
  unsigned __int64 v72; // x8
  __int64 v73; // x9
  unsigned int *v74; // x9
  unsigned int v75; // w12
  __int64 v76; // x9
  __int64 v78; // x0
  __int64 v79; // x20
  __int64 v80; // x9
  unsigned __int64 v81; // x8
  __int64 v82; // x9
  unsigned int *v83; // x9
  unsigned int v84; // w12
  __int64 v85; // x9
  _QWORD *v87; // x20
  unsigned int v89; // w9
  unsigned int v91; // w9
  _QWORD v92[2]; // [xsp+0h] [xbp-10h] BYREF

  v92[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
    goto LABEL_77;
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
  v92[0] = 0;
  v12 = qdf_list_peek_front((_QWORD *)(a1 + 48), v92);
  if ( (_DWORD)v12 || (v70 = (_QWORD *)v92[0], v13 = v92[0] - 8LL, v92[0] == 8) )
  {
    v13 = 0;
LABEL_9:
    v14 = 0;
    goto LABEL_10;
  }
  v71 = *(__int64 *)((char *)&off_18 + v92[0]);
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
      v87 = v70;
      preempt_schedule_notrace(v12);
      v70 = v87;
    }
  }
  _X8 = (unsigned int *)v70 + 13147;
  __asm { PRFM            #0x11, [X8] }
  do
    v89 = __ldxr(_X8);
  while ( __stxr(v89 + 1, _X8) );
  v92[0] = 0;
  v78 = qdf_list_peek_next((_QWORD *)(a1 + 48), v70, v92);
  if ( (_DWORD)v78 )
    goto LABEL_9;
  v79 = v92[0];
  v14 = v92[0] - 8LL;
  if ( v92[0] != 8 )
  {
    v80 = *(__int64 *)((char *)&off_18 + v92[0]);
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
    _X8 = (unsigned int *)(v79 + 52588);
    __asm { PRFM            #0x11, [X8] }
    do
      v91 = __ldxr(_X8);
    while ( __stxr(v91 + 1, _X8) );
  }
LABEL_10:
  v15 = *(_QWORD *)(a1 + 40);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v13 )
      goto LABEL_12;
LABEL_76:
    result = 0;
    goto LABEL_77;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v13 )
    goto LABEL_76;
LABEL_12:
  v24 = _ReadStatusReg(SP_EL0);
  while ( (*(_QWORD *)(v13 + 1624) & 4) == 0 )
  {
    if ( (*(_QWORD *)(v13 + 1640) & 1) != 0 )
    {
      v25 = v13 + 52840;
      goto LABEL_37;
    }
    v25 = v13 + 58928;
    if ( v13 != -58928 && (*(_QWORD *)(v13 + 1640) & 2) != 0
      || (v25 = v13 + 65016, v13 != -65016) && (*(_QWORD *)(v13 + 1640) & 4) != 0 )
    {
LABEL_37:
      while ( (*(_QWORD *)(v25 + 5968) & 1) == 0 )
      {
        v43 = 73 * ((unsigned int)(v25 - *(_DWORD *)v25 - 52840) >> 3) + 1;
        if ( (unsigned __int8)v43 <= 2u )
        {
          v44 = (unsigned __int8)v43;
          v25 = 0;
          v45 = v13 + 52840 + 6088LL * (unsigned int)v44;
          do
          {
            if ( v25 )
              break;
            v46 = *(_QWORD *)(v13 + 1640) >> v44++;
            v25 = (v46 << 63 >> 63) & v45;
            v45 += 6088;
          }
          while ( v44 != 3 );
          if ( v25 )
            continue;
        }
        goto LABEL_19;
      }
      break;
    }
LABEL_19:
    hdd_adapter_dev_put_debug(v13, 0x12u, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v24 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( !v14 )
        goto LABEL_44;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v14 )
        goto LABEL_44;
    }
    v92[0] = 0;
    v26 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v14 + 8), v92);
    v35 = v92[0] - 8LL;
    if ( (_DWORD)v26 )
      v36 = 0;
    else
      v36 = v92[0] - 8LL;
    if ( v14 == v36 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Validation failed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_validate_next_adapter");
      hdd_adapter_dev_put_debug(v14, 0x12u, v47, v48, v49, v50, v51, v52, v53, v54);
LABEL_44:
      v35 = 0;
      v13 = 0;
      v55 = *(_QWORD *)(a1 + 40);
      if ( (v55 & 1) != 0 )
        goto LABEL_50;
      goto LABEL_45;
    }
    if ( v36 )
    {
      v37 = *(_QWORD *)(v36 + 32);
      if ( v37 )
      {
        ++*(_DWORD *)(v24 + 16);
        v38 = *(_QWORD *)(v37 + 1320);
        v39 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v38);
        do
          v40 = __ldxr(v39);
        while ( __stxr(v40 + 1, v39) );
        v41 = *(_QWORD *)(v24 + 16) - 1LL;
        *(_DWORD *)(v24 + 16) = v41;
        if ( !v41 || !*(_QWORD *)(v24 + 16) )
          preempt_schedule_notrace(v26);
      }
      _X8 = (unsigned int *)(v36 + 52596);
      __asm { PRFM            #0x11, [X8] }
      do
        v61 = __ldxr(_X8);
      while ( __stxr(v61 + 1, _X8) );
    }
    else
    {
      v35 = 0;
    }
    v13 = v14;
    v55 = *(_QWORD *)(a1 + 40);
    if ( (v55 & 1) != 0 )
    {
LABEL_50:
      *(_QWORD *)(a1 + 40) = v55 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      goto LABEL_46;
    }
LABEL_45:
    raw_spin_unlock(a1 + 32);
LABEL_46:
    result = 0;
    v14 = v35;
    if ( !v13 )
      goto LABEL_77;
  }
  hdd_adapter_dev_put_debug(v13, 0x12u, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( v14 )
    hdd_adapter_dev_put_debug(v14, 0x12u, v62, v63, v64, v65, v66, v67, v68, v69);
  result = 1;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
