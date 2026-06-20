__int64 __fastcall hdd_abort_non_sap_scan_all_adapters(
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
  __int64 v12; // x21
  __int64 v13; // x23
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x26
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  __int64 v33; // x8
  unsigned int v34; // w8
  bool v35; // cc
  int v36; // w8
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x21
  __int64 v48; // x8
  __int64 v49; // x8
  unsigned int *v50; // x8
  unsigned int v51; // w10
  __int64 v52; // x8
  unsigned int v58; // w9
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
  _QWORD *v77; // x20
  unsigned int v79; // w9
  unsigned int v81; // w9
  _QWORD v82[2]; // [xsp+0h] [xbp-10h] BYREF

  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_abort_non_sap_scan_all_adapters");
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
  v82[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v82);
  if ( (_DWORD)v11 || (v59 = (_QWORD *)v82[0], v12 = v82[0] - 8LL, v82[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
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
      preempt_schedule_notrace(v11);
      v59 = v77;
    }
  }
  _X8 = (unsigned int *)v59 + 13157;
  __asm { PRFM            #0x11, [X8] }
  do
    v79 = __ldxr(_X8);
  while ( __stxr(v79 + 1, _X8) );
  v82[0] = 0;
  v67 = qdf_list_peek_next(a1 + 6, v59, v82);
  if ( (_DWORD)v67 )
    goto LABEL_7;
  v68 = v82[0];
  v13 = v82[0] - 8LL;
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
    _X8 = (unsigned int *)(v68 + 52628);
    __asm { PRFM            #0x11, [X8] }
    do
      v81 = __ldxr(_X8);
    while ( __stxr(v81 + 1, _X8) );
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
        v34 = *(_DWORD *)(v12 + 40);
        v35 = v34 > 7;
        v36 = (1 << v34) & 0x8D;
        _ZF = v35 || v36 == 0;
        if ( !_ZF && (*(_QWORD *)(v12 + 1640) & 1) != 0 && v12 != -52832 )
        {
          do
            wlan_abort_scan(a1[1], -1, *(unsigned __int8 *)(v12 + 52840), 0xFFFFFFFF, 1);
          while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v12 - *(_DWORD *)(v12 + 52832)) >> 4))
               && (*(_QWORD *)(v12 + 1640) & 1) != 0 );
        }
        hdd_adapter_dev_put_debug(v12, 0x1Cu, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
          if ( v13 )
            goto LABEL_26;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = a1[5];
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_39:
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
LABEL_26:
          v82[0] = 0;
          v38 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v82);
          v32 = v82[0] - 8LL;
          if ( (_DWORD)v38 )
            v47 = 0;
          else
            v47 = v82[0] - 8LL;
          if ( v13 == v47 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x1Cu, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v47 )
          {
            v48 = *(_QWORD *)(v47 + 32);
            if ( v48 )
            {
              ++*(_DWORD *)(v23 + 16);
              v49 = *(_QWORD *)(v48 + 1320);
              v50 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v49);
              do
                v51 = __ldxr(v50);
              while ( __stxr(v51 + 1, v50) );
              v52 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v52;
              if ( !v52 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v38);
            }
            _X8 = (unsigned int *)(v47 + 52636);
            __asm { PRFM            #0x11, [X8] }
            do
              v58 = __ldxr(_X8);
            while ( __stxr(v58 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = a1[5];
          if ( (v33 & 1) != 0 )
            goto LABEL_39;
LABEL_13:
          raw_spin_unlock(a1 + 4);
          v13 = v32;
          if ( !v12 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_abort_non_sap_scan_all_adapters");
  _ReadStatusReg(SP_EL0);
  return 0;
}
