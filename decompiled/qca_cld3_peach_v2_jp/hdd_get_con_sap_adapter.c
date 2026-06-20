__int64 __fastcall hdd_get_con_sap_adapter(__int64 a1, char a2)
{
  __int64 v3; // x25
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
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  __int64 v39; // x8
  __int64 v40; // x8
  unsigned int *v41; // x8
  unsigned int v42; // w10
  __int64 v43; // x8
  unsigned int v49; // w9
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _QWORD *v59; // x1
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned int *v63; // x9
  unsigned int v64; // w12
  __int64 v65; // x9
  __int64 v67; // x0
  __int64 v68; // x20
  __int64 v69; // x9
  unsigned __int64 v70; // x8
  __int64 v71; // x9
  unsigned int *v72; // x9
  unsigned int v73; // w12
  __int64 v74; // x9
  _QWORD *v76; // x20
  unsigned int v78; // w9
  unsigned int v80; // w9
  _QWORD v82[2]; // [xsp+10h] [xbp-10h] BYREF

  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v3 + 32);
  }
  else
  {
    raw_spin_lock_bh(v3 + 32);
    *(_QWORD *)(v3 + 40) |= 1uLL;
  }
  v82[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(v3 + 48), v82);
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
        v76 = v59;
        preempt_schedule_notrace(v5);
        v59 = v76;
      }
    }
    _X8 = (unsigned int *)v59 + 13171;
    __asm { PRFM            #0x11, [X8] }
    do
      v78 = __ldxr(_X8);
    while ( __stxr(v78 + 1, _X8) );
    v82[0] = 0;
    v67 = qdf_list_peek_next((_QWORD *)(v3 + 48), v59, v82);
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
        _X8 = (unsigned int *)(v68 + 52684);
        __asm { PRFM            #0x11, [X8] }
        do
          v80 = __ldxr(_X8);
        while ( __stxr(v80 + 1, _X8) );
      }
      goto LABEL_8;
    }
  }
  v7 = 0;
LABEL_8:
  v8 = *(_QWORD *)(v3 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(v3 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v3 + 32);
    if ( !v6 )
      goto LABEL_52;
  }
  else
  {
    raw_spin_unlock(v3 + 32);
    if ( !v6 )
      goto LABEL_52;
  }
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    _ZF = (*(_DWORD *)(v6 + 40) | 2) != 3 || v6 == a1;
    if ( !_ZF && (*(_QWORD *)(v6 + 1640) & 1) != 0 && v6 != -52832 )
      break;
LABEL_19:
    hdd_adapter_dev_put_debug(v6, 0x2Au, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v3 + 32);
      if ( v7 )
        goto LABEL_23;
LABEL_12:
      v26 = 0;
      v6 = 0;
      v27 = *(_QWORD *)(v3 + 40);
      if ( (v27 & 1) == 0 )
        goto LABEL_13;
LABEL_43:
      *(_QWORD *)(v3 + 40) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v3 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_52;
    }
    else
    {
      raw_spin_lock_bh(v3 + 32);
      *(_QWORD *)(v3 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_23:
      v82[0] = 0;
      v29 = qdf_list_peek_next((_QWORD *)(v3 + 48), (_QWORD *)(v7 + 8), v82);
      v26 = v82[0] - 8LL;
      if ( (_DWORD)v29 )
        v38 = 0;
      else
        v38 = v82[0] - 8LL;
      if ( v7 == v38 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v7, 0x2Au, v18, v19, v20, v21, v22, v23, v24, v25);
        goto LABEL_12;
      }
      if ( v38 )
      {
        v39 = *(_QWORD *)(v38 + 32);
        if ( v39 )
        {
          ++*(_DWORD *)(v17 + 16);
          v40 = *(_QWORD *)(v39 + 1320);
          v41 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v40);
          do
            v42 = __ldxr(v41);
          while ( __stxr(v42 + 1, v41) );
          v43 = *(_QWORD *)(v17 + 16) - 1LL;
          *(_DWORD *)(v17 + 16) = v43;
          if ( !v43 || !*(_QWORD *)(v17 + 16) )
            preempt_schedule_notrace(v29);
        }
        _X8 = (unsigned int *)(v38 + 52692);
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
      v27 = *(_QWORD *)(v3 + 40);
      if ( (v27 & 1) != 0 )
        goto LABEL_43;
LABEL_13:
      raw_spin_unlock(v3 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_52;
    }
  }
  if ( (a2 & 1) != 0 )
  {
    while ( (*(_QWORD *)(v6 + 57248) & 2) == 0 )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v6 - *(_DWORD *)(v6 + 52832)) >> 4))
        || (*(_QWORD *)(v6 + 1640) & 1) == 0 )
      {
        goto LABEL_19;
      }
    }
  }
  hdd_adapter_dev_put_debug(v6, 0x2Au, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x2Au, v50, v51, v52, v53, v54, v55, v56, v57);
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return v6;
}
