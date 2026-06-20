__int64 __fastcall hdd_stop_all_adapters(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x21
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x25
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x28
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x22
  __int64 v52; // x8
  __int64 v53; // x8
  unsigned int *v54; // x8
  unsigned int v55; // w10
  __int64 v56; // x8
  unsigned int v63; // w9
  _QWORD *v64; // x1
  __int64 v65; // x9
  unsigned __int64 v66; // x8
  __int64 v67; // x9
  unsigned int *v68; // x9
  unsigned int v69; // w12
  __int64 v70; // x9
  __int64 v72; // x0
  __int64 v73; // x23
  __int64 v74; // x9
  unsigned __int64 v75; // x8
  __int64 v76; // x9
  unsigned int *v77; // x9
  unsigned int v78; // w12
  __int64 v79; // x9
  _QWORD *v82; // x21
  unsigned int v84; // w9
  unsigned int v86; // w9
  _QWORD v87[2]; // [xsp+0h] [xbp-10h] BYREF

  v87[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_stop_all_adapters");
  ucfg_pre_cac_stop(*a1);
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
  v87[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v87);
  if ( (_DWORD)v11 || (v64 = (_QWORD *)v87[0], v12 = v87[0] - 8LL, v87[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
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
      v82 = v64;
      preempt_schedule_notrace(v11);
      v64 = v82;
    }
  }
  _X8 = (unsigned int *)v64 + 13145;
  __asm { PRFM            #0x11, [X8] }
  do
    v84 = __ldxr(_X8);
  while ( __stxr(v84 + 1, _X8) );
  v87[0] = 0;
  v72 = qdf_list_peek_next(a1 + 6, v64, v87);
  if ( (_DWORD)v72 )
    goto LABEL_7;
  v73 = v87[0];
  v13 = v87[0] - 8LL;
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
    _X8 = (unsigned int *)(v73 + 52580);
    __asm { PRFM            #0x11, [X8] }
    do
      v86 = __ldxr(_X8);
    while ( __stxr(v86 + 1, _X8) );
  }
LABEL_8:
  v14 = a1[5];
  if ( (v14 & 1) != 0 )
  {
    a1[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v12 )
      goto LABEL_10;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( v12 )
    {
LABEL_10:
      v23 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        hdd_stop_adapter(a1, v12);
        hdd_adapter_dev_put_debug(v12, 0x10u, v34, v35, v36, v37, v38, v39, v40, v41);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
          if ( v13 )
            goto LABEL_18;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = a1[5];
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_31:
          a1[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 4);
          v13 = v32;
          if ( !v12 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 4);
          a1[5] |= 1uLL;
          if ( !v13 )
            goto LABEL_12;
LABEL_18:
          v87[0] = 0;
          v42 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v87);
          v32 = v87[0] - 8LL;
          if ( (_DWORD)v42 )
            v51 = 0;
          else
            v51 = v87[0] - 8LL;
          if ( v13 == v51 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x10u, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v51 )
          {
            v52 = *(_QWORD *)(v51 + 32);
            if ( v52 )
            {
              ++*(_DWORD *)(v23 + 16);
              v53 = *(_QWORD *)(v52 + 1320);
              v54 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v53);
              do
                v55 = __ldxr(v54);
              while ( __stxr(v55 + 1, v54) );
              v56 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v56;
              if ( !v56 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v42);
            }
            _X8 = (unsigned int *)(v51 + 52588);
            __asm { PRFM            #0x11, [X8] }
            do
              v63 = __ldxr(_X8);
            while ( __stxr(v63 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = a1[5];
          if ( (v33 & 1) != 0 )
            goto LABEL_31;
LABEL_13:
          raw_spin_unlock(a1 + 4);
          v13 = v32;
          if ( !v12 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_stop_all_adapters");
  _ReadStatusReg(SP_EL0);
  return 0;
}
