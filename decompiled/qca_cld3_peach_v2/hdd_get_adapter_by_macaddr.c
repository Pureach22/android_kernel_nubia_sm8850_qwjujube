__int64 __fastcall hdd_get_adapter_by_macaddr(__int64 a1, const void *a2)
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
  _DWORD *v17; // x28
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
  __int64 v30; // x22
  __int64 *v31; // x21
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
  __int64 *v62; // x1
  __int64 v63; // x9
  unsigned __int64 v64; // x8
  __int64 v65; // x9
  unsigned int *v66; // x9
  unsigned int v67; // w12
  __int64 v68; // x9
  __int64 v70; // x0
  __int64 *v71; // x22
  __int64 v72; // x9
  unsigned __int64 v73; // x8
  __int64 v74; // x9
  unsigned int *v75; // x9
  unsigned int v76; // w12
  __int64 v77; // x9
  __int64 *v79; // x22
  unsigned int v81; // w9
  unsigned int v83; // w9
  unsigned __int64 v84; // [xsp+0h] [xbp-20h]
  __int64 *v85; // [xsp+8h] [xbp-18h] BYREF
  int v86; // [xsp+10h] [xbp-10h] BYREF
  __int16 v87; // [xsp+14h] [xbp-Ch]
  __int64 v88; // [xsp+18h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = 0;
  v86 = 0;
  if ( !(unsigned int)qdf_mem_cmp(a2, &v86, 6u) )
  {
    v6 = 0;
    goto LABEL_58;
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
  v85 = nullptr;
  v5 = qdf_list_peek_front((_QWORD *)(a1 + 48), &v85);
  if ( (_DWORD)v5 || (v62 = v85, v6 = (__int64)(v85 - 1), v85 == &qword_8) )
  {
    v6 = 0;
  }
  else
  {
    v63 = *(__int64 *)((char *)&off_18 + (_QWORD)v85);
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
        preempt_schedule_notrace(v5);
        v62 = v79;
      }
    }
    _X8 = (unsigned int *)(v62 + 6575);
    __asm { PRFM            #0x11, [X8] }
    do
      v81 = __ldxr(_X8);
    while ( __stxr(v81 + 1, _X8) );
    v85 = nullptr;
    v70 = qdf_list_peek_next((_QWORD *)(a1 + 48), v62, &v85);
    if ( !(_DWORD)v70 )
    {
      v71 = v85;
      v7 = (__int64)(v85 - 1);
      if ( v85 != &qword_8 )
      {
        v72 = *(__int64 *)((char *)&off_18 + (_QWORD)v85);
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
        _X8 = (unsigned int *)(v71 + 6575);
        __asm { PRFM            #0x11, [X8] }
        do
          v83 = __ldxr(_X8);
        while ( __stxr(v83 + 1, _X8) );
      }
      goto LABEL_9;
    }
  }
  v7 = 0;
LABEL_9:
  v8 = *(_QWORD *)(a1 + 40);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( !v6 )
      goto LABEL_58;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( !v6 )
      goto LABEL_58;
  }
  v84 = _ReadStatusReg(SP_EL0);
  while ( (unsigned int)qdf_mem_cmp((const void *)(v6 + 1617), a2, 6u) )
  {
    if ( (*(_QWORD *)(v6 + 1640) & 1) != 0 && (v17 = (_DWORD *)(v6 + 52840), v6 != -52840)
      || (*(_QWORD *)(v6 + 1640) & 2) != 0 && (v17 = (_DWORD *)(v6 + 58928), v6 != -58928)
      || (*(_QWORD *)(v6 + 1640) & 4) != 0 && (v17 = (_DWORD *)(v6 + 65016), v6 != -65016) )
    {
      while ( (unsigned int)qdf_mem_cmp(v17 + 18, a2, 6u) )
      {
        if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v17 - *v17 - 52840) >> 3) + 1) <= 2u )
        {
          v18 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v17 - *v17 - 52840) >> 3) + 1);
          v17 = nullptr;
          v19 = v6 + 52840 + 6088LL * (unsigned int)v18;
          do
          {
            if ( v17 )
              break;
            v20 = *(_QWORD *)(v6 + 1640) >> v18++;
            v17 = (_DWORD *)((v20 << 63 >> 63) & v19);
            v19 += 6088;
          }
          while ( v18 != 3 );
          if ( v17 )
            continue;
        }
        goto LABEL_27;
      }
      break;
    }
LABEL_27:
    hdd_adapter_dev_put_debug(v6, 0x15u, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v84 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v84 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
      if ( !v7 )
        goto LABEL_43;
LABEL_31:
      v85 = nullptr;
      v21 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v7 + 8), &v85);
      v30 = (__int64)(v85 - 1);
      if ( (_DWORD)v21 )
        v31 = nullptr;
      else
        v31 = v85 - 1;
      if ( (__int64 *)v7 == v31 )
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
        hdd_adapter_dev_put_debug(v7, 0x15u, v38, v39, v40, v41, v42, v43, v44, v45);
        goto LABEL_43;
      }
      if ( v31 )
      {
        v32 = v31[4];
        if ( v32 )
        {
          ++*(_DWORD *)(v84 + 16);
          v33 = *(_QWORD *)(v32 + 1320);
          v34 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v33);
          do
            v35 = __ldxr(v34);
          while ( __stxr(v35 + 1, v34) );
          v36 = *(_QWORD *)(v84 + 16) - 1LL;
          *(_DWORD *)(v84 + 16) = v36;
          if ( !v36 || !*(_QWORD *)(v84 + 16) )
            preempt_schedule_notrace(v21);
        }
        _X8 = (unsigned int *)(v31 + 6576);
        __asm { PRFM            #0x11, [X8] }
        do
          v52 = __ldxr(_X8);
        while ( __stxr(v52 + 1, _X8) );
      }
      else
      {
        v30 = 0;
      }
      v6 = v7;
      v46 = *(_QWORD *)(a1 + 40);
      if ( (v46 & 1) != 0 )
        goto LABEL_48;
LABEL_44:
      raw_spin_unlock(a1 + 32);
      v7 = v30;
      if ( !v6 )
        goto LABEL_58;
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      if ( v7 )
        goto LABEL_31;
LABEL_43:
      v30 = 0;
      v6 = 0;
      v46 = *(_QWORD *)(a1 + 40);
      if ( (v46 & 1) == 0 )
        goto LABEL_44;
LABEL_48:
      *(_QWORD *)(a1 + 40) = v46 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      v7 = v30;
      if ( !v6 )
        goto LABEL_58;
    }
  }
  hdd_adapter_dev_put_debug(v6, 0x15u, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( v7 )
    hdd_adapter_dev_put_debug(v7, 0x15u, v53, v54, v55, v56, v57, v58, v59, v60);
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v6;
}
