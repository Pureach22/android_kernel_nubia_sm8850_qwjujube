__int64 __fastcall hdd_check_for_existing_macaddr(__int64 a1, const void *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x8
  unsigned __int64 v9; // x26
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x25
  __int64 v19; // x8
  int v20; // w25
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  __int64 v47; // x8
  __int64 v48; // x8
  unsigned int *v49; // x8
  unsigned int v50; // w10
  __int64 v51; // x8
  unsigned int v58; // w9
  _QWORD *v59; // x1
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned int *v63; // x9
  unsigned int v64; // w12
  __int64 v65; // x9
  __int64 v67; // x0
  __int64 v68; // x23
  __int64 v69; // x9
  unsigned __int64 v70; // x8
  __int64 v71; // x9
  unsigned int *v72; // x9
  unsigned int v73; // w12
  __int64 v74; // x9
  __int64 result; // x0
  _QWORD *v77; // x21
  unsigned int v79; // w9
  unsigned int v81; // w9
  _QWORD v82[2]; // [xsp+0h] [xbp-10h] BYREF

  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v82[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), v82);
  if ( (_DWORD)v5 || (v59 = (_QWORD *)v82[0], v6 = v82[0] - 8LL, v82[0] == 8) )
  {
    v6 = 0;
LABEL_7:
    v7 = 0;
    goto LABEL_8;
  }
  v60 = *(__int64 *)((char *)&off_18 + v82[0]);
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
    {
      v77 = v59;
      preempt_schedule_notrace(v5);
      v59 = v77;
    }
  }
  _X8 = (unsigned int *)v59 + 13143;
  __asm { PRFM            #0x11, [X8] }
  do
    v79 = __ldxr(_X8);
  while ( __stxr(v79 + 1, _X8) );
  v82[0] = 0;
  v67 = qdf_list_peek_next((_QWORD *)(a1 + 48), v59, v82);
  if ( (_DWORD)v67 )
    goto LABEL_7;
  v68 = v82[0];
  v7 = v82[0] - 8LL;
  if ( v82[0] != 8 )
  {
    v69 = *(__int64 *)((char *)&off_18 + v82[0]);
    if ( v69 )
    {
      v70 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v70 + 16);
      v71 = *(_QWORD *)(v69 + 1320);
      v72 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v71);
      do
        v73 = __ldxr(v72);
      while ( __stxr(v73 + 1, v72) );
      v74 = *(_QWORD *)(v70 + 16) - 1LL;
      *(_DWORD *)(v70 + 16) = v74;
      if ( !v74 || !*(_QWORD *)(v70 + 16) )
        preempt_schedule_notrace(v67);
    }
    _X8 = (unsigned int *)(v68 + 52572);
    __asm { PRFM            #0x11, [X8] }
    do
      v81 = __ldxr(_X8);
    while ( __stxr(v81 + 1, _X8) );
  }
LABEL_8:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v6 )
      goto LABEL_10;
LABEL_58:
    result = 0;
    goto LABEL_59;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v6 )
    goto LABEL_58;
LABEL_10:
  v9 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v20 = qdf_mem_cmp((const void *)(v6 + 1617), a2, 6u);
    hdd_adapter_dev_put_debug(v6, 0xEu, v21, v22, v23, v24, v25, v26, v27, v28);
    if ( !v20 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v9 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( v7 )
        goto LABEL_19;
LABEL_12:
      v18 = 0;
      v6 = 0;
      v19 = *(_QWORD *)(a1 + 40);
      if ( (v19 & 1) == 0 )
        goto LABEL_13;
LABEL_32:
      *(_QWORD *)(a1 + 40) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v18;
      if ( !v6 )
        goto LABEL_58;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_19:
      v82[0] = 0;
      v37 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), v82);
      v18 = v82[0] - 8LL;
      if ( (_DWORD)v37 )
        v46 = 0;
      else
        v46 = v82[0] - 8LL;
      if ( v7 == v46 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0xEu, v10, v11, v12, v13, v14, v15, v16, v17);
        goto LABEL_12;
      }
      if ( v46 )
      {
        v47 = *(_QWORD *)(v46 + 32);
        if ( v47 )
        {
          ++*(_DWORD *)(v9 + 16);
          v48 = *(_QWORD *)(v47 + 1320);
          v49 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v48);
          do
            v50 = __ldxr(v49);
          while ( __stxr(v50 + 1, v49) );
          v51 = *(_QWORD *)(v9 + 16) - 1LL;
          *(_DWORD *)(v9 + 16) = v51;
          if ( !v51 || !*(_QWORD *)(v9 + 16) )
            preempt_schedule_notrace(v37);
        }
        _X8 = (unsigned int *)(v46 + 52580);
        __asm { PRFM            #0x11, [X8] }
        do
          v58 = __ldxr(_X8);
        while ( __stxr(v58 + 1, _X8) );
      }
      else
      {
        v18 = 0;
      }
      v6 = v7;
      v19 = *(_QWORD *)(a1 + 40);
      if ( (v19 & 1) != 0 )
        goto LABEL_32;
LABEL_13:
      raw_spin_unlock(a1 + 32);
      v7 = v18;
      if ( !v6 )
        goto LABEL_58;
    }
  }
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0xEu, v29, v30, v31, v32, v33, v34, v35, v36);
  result = 16;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
