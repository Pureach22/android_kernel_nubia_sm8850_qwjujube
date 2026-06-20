__int64 __fastcall hdd_get_con_sap_adapter(__int64 a1, char a2)
{
  __int64 v3; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x20
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v17; // x26
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
  __int64 v45; // x9
  unsigned int v46; // w9
  __int64 v47; // x10
  __int64 v48; // x11
  __int64 v49; // x9
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
  _QWORD *v81; // x20
  unsigned int v83; // w9
  unsigned int v85; // w9
  _QWORD v87[2]; // [xsp+10h] [xbp-10h] BYREF

  v87[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v87[0] = 0;
  v5 = qdf_list_peek_front((_QWORD *)(v3 + 48), v87);
  if ( (_DWORD)v5 || (v64 = (_QWORD *)v87[0], v6 = v87[0] - 8LL, v87[0] == 8) )
  {
    v6 = 0;
  }
  else
  {
    v65 = *(__int64 *)((char *)&off_18 + v87[0]);
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
    _X8 = (unsigned int *)v64 + 13171;
    __asm { PRFM            #0x11, [X8] }
    do
      v83 = __ldxr(_X8);
    while ( __stxr(v83 + 1, _X8) );
    v87[0] = 0;
    v72 = qdf_list_peek_next((_QWORD *)(v3 + 48), v64, v87);
    if ( !(_DWORD)v72 )
    {
      v73 = v87[0];
      v7 = v87[0] - 8LL;
      if ( v87[0] != 8 )
      {
        v74 = *(__int64 *)((char *)&off_18 + v87[0]);
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
        _X8 = (unsigned int *)(v73 + 52684);
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
  v8 = *(_QWORD *)(v3 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(v3 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v3 + 32);
    if ( !v6 )
      goto LABEL_60;
  }
  else
  {
    raw_spin_unlock(v3 + 32);
    if ( !v6 )
      goto LABEL_60;
  }
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_DWORD *)(v6 + 40) | 2) == 3 && v6 != a1 )
    {
      if ( (*(_QWORD *)(v6 + 1640) & 1) != 0 )
      {
        v45 = v6 + 52840;
        if ( v6 != -52840 )
          break;
      }
      if ( (*(_QWORD *)(v6 + 1640) & 2) != 0 )
      {
        v45 = v6 + 58928;
        if ( v6 != -58928 )
          break;
      }
      if ( (*(_QWORD *)(v6 + 1640) & 4) != 0 )
      {
        v45 = v6 + 65016;
        if ( v6 != -65016 )
          break;
      }
    }
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
LABEL_51:
      *(_QWORD *)(v3 + 40) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v3 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_60;
    }
    else
    {
      raw_spin_lock_bh(v3 + 32);
      *(_QWORD *)(v3 + 40) |= 1uLL;
      if ( !v7 )
        goto LABEL_12;
LABEL_23:
      v87[0] = 0;
      v29 = qdf_list_peek_next((_QWORD *)(v3 + 48), (_QWORD *)(v7 + 8), v87);
      v26 = v87[0] - 8LL;
      if ( (_DWORD)v29 )
        v38 = 0;
      else
        v38 = v87[0] - 8LL;
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
          v54 = __ldxr(_X8);
        while ( __stxr(v54 + 1, _X8) );
      }
      else
      {
        v26 = 0;
      }
      v6 = v7;
      v27 = *(_QWORD *)(v3 + 40);
      if ( (v27 & 1) != 0 )
        goto LABEL_51;
LABEL_13:
      raw_spin_unlock(v3 + 32);
      v7 = v26;
      if ( !v6 )
        goto LABEL_60;
    }
  }
  if ( (a2 & 1) != 0 )
  {
    while ( (*(_QWORD *)(v45 + 5968) & 2) == 0 )
    {
      v46 = 73 * ((unsigned int)(v45 - *(_DWORD *)v45 - 52840) >> 3) + 1;
      if ( (unsigned __int8)v46 <= 2u )
      {
        v47 = (unsigned __int8)v46;
        v45 = 0;
        v48 = v6 + 52840 + 6088LL * (unsigned int)v47;
        do
        {
          if ( v45 )
            break;
          v49 = *(_QWORD *)(v6 + 1640) >> v47++;
          v45 = (v49 << 63 >> 63) & v48;
          v48 += 6088;
        }
        while ( v47 != 3 );
        if ( v45 )
          continue;
      }
      goto LABEL_19;
    }
  }
  hdd_adapter_dev_put_debug(v6, 0x2Au, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x2Au, v55, v56, v57, v58, v59, v60, v61, v62);
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v6;
}
