__int64 __fastcall hdd_get_adapter_by_ifindex(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x22
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
  int v28; // w28
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
  __int64 v46; // x21
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
  _QWORD *v77; // x22
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
  }
  else
  {
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
    _X8 = (unsigned int *)(v59 + 6577);
    __asm { PRFM            #0x11, [X8] }
    do
      v79 = __ldxr(_X8);
    while ( __stxr(v79 + 1, _X8) );
    v82[0] = 0;
    v67 = qdf_list_peek_next((_QWORD *)(a1 + 48), v59, v82);
    if ( !(_DWORD)v67 )
    {
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
        _X8 = (unsigned int *)(v68 + 52616);
        __asm { PRFM            #0x11, [X8] }
        do
          v81 = __ldxr(_X8);
        while ( __stxr(v81 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v7 = 0;
LABEL_8:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( !v6 )
      goto LABEL_56;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( !v6 )
      goto LABEL_56;
  }
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v28 = *(_DWORD *)(*(_QWORD *)(v6 + 32) + 224LL);
    hdd_adapter_dev_put_debug(v6, 0x19u, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( v28 == a2 )
      break;
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
        goto LABEL_56;
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
      v26 = v82[0] - 8LL;
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
        hdd_adapter_dev_put_debug(v7, 0x19u, v18, v19, v20, v21, v22, v23, v24, v25);
        goto LABEL_12;
      }
      if ( v46 )
      {
        v47 = *(_QWORD *)(v46 + 32);
        if ( v47 )
        {
          ++*(_DWORD *)(v17 + 16);
          v48 = *(_QWORD *)(v47 + 1320);
          v49 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v48);
          do
            v50 = __ldxr(v49);
          while ( __stxr(v50 + 1, v49) );
          v51 = *(_QWORD *)(v17 + 16) - 1LL;
          *(_DWORD *)(v17 + 16) = v51;
          if ( !v51 || !*(_QWORD *)(v17 + 16) )
            preempt_schedule_notrace(v37);
        }
        _X8 = (unsigned int *)(v46 + 52624);
        __asm { PRFM            #0x11, [X8] }
        do
          v58 = __ldxr(_X8);
        while ( __stxr(v58 + 1, _X8) );
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
        goto LABEL_56;
    }
  }
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x19u, v29, v30, v31, v32, v33, v34, v35, v36);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v6;
}
