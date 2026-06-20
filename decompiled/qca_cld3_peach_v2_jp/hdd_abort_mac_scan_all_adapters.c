__int64 __fastcall hdd_abort_mac_scan_all_adapters(
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
  __int64 v13; // x22
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x27
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
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x21
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned int *v47; // x8
  unsigned int v48; // w10
  __int64 v49; // x8
  unsigned int v56; // w9
  _QWORD *v57; // x1
  __int64 v58; // x9
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  unsigned int *v61; // x9
  unsigned int v62; // w12
  __int64 v63; // x9
  __int64 v65; // x0
  __int64 v66; // x20
  __int64 v67; // x9
  unsigned __int64 v68; // x8
  __int64 v69; // x9
  unsigned int *v70; // x9
  unsigned int v71; // w12
  __int64 v72; // x9
  _QWORD *v75; // x20
  unsigned int v77; // w9
  unsigned int v79; // w9
  _QWORD v80[2]; // [xsp+0h] [xbp-10h] BYREF

  v80[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_abort_mac_scan_all_adapters");
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
  v80[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v80);
  if ( (_DWORD)v11 || (v57 = (_QWORD *)v80[0], v12 = v80[0] - 8LL, v80[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v58 = *(__int64 *)((char *)&off_18 + v80[0]);
  if ( v58 )
  {
    v59 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v59 + 16);
    v60 = *(_QWORD *)(v58 + 1320);
    v61 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v60);
    do
      v62 = __ldxr(v61);
    while ( __stxr(v62 + 1, v61) );
    v63 = *(_QWORD *)(v59 + 16) - 1LL;
    *(_DWORD *)(v59 + 16) = v63;
    if ( !v63 || !*(_QWORD *)(v59 + 16) )
    {
      v75 = v57;
      preempt_schedule_notrace(v11);
      v57 = v75;
    }
  }
  _X8 = (unsigned int *)v57 + 13157;
  __asm { PRFM            #0x11, [X8] }
  do
    v77 = __ldxr(_X8);
  while ( __stxr(v77 + 1, _X8) );
  v80[0] = 0;
  v65 = qdf_list_peek_next(a1 + 6, v57, v80);
  if ( (_DWORD)v65 )
    goto LABEL_7;
  v66 = v80[0];
  v13 = v80[0] - 8LL;
  if ( v80[0] != 8 )
  {
    v67 = *(__int64 *)((char *)&off_18 + v80[0]);
    if ( v67 )
    {
      v68 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v68 + 16);
      v69 = *(_QWORD *)(v67 + 1320);
      v70 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v69);
      do
        v71 = __ldxr(v70);
      while ( __stxr(v71 + 1, v70) );
      v72 = *(_QWORD *)(v68 + 16) - 1LL;
      *(_DWORD *)(v68 + 16) = v72;
      if ( !v72 || !*(_QWORD *)(v68 + 16) )
        preempt_schedule_notrace(v65);
    }
    _X8 = (unsigned int *)(v66 + 52628);
    __asm { PRFM            #0x11, [X8] }
    do
      v79 = __ldxr(_X8);
    while ( __stxr(v79 + 1, _X8) );
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
        if ( (v34 < 4 || v34 == 7) && (*(_QWORD *)(v12 + 1640) & 1) != 0 && v12 != -52832 )
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
            goto LABEL_24;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = a1[5];
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_37:
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
LABEL_24:
          v80[0] = 0;
          v35 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v80);
          v32 = v80[0] - 8LL;
          if ( (_DWORD)v35 )
            v44 = 0;
          else
            v44 = v80[0] - 8LL;
          if ( v13 == v44 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x1Cu, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v44 )
          {
            v45 = *(_QWORD *)(v44 + 32);
            if ( v45 )
            {
              ++*(_DWORD *)(v23 + 16);
              v46 = *(_QWORD *)(v45 + 1320);
              v47 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v46);
              do
                v48 = __ldxr(v47);
              while ( __stxr(v48 + 1, v47) );
              v49 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v49;
              if ( !v49 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v35);
            }
            _X8 = (unsigned int *)(v44 + 52636);
            __asm { PRFM            #0x11, [X8] }
            do
              v56 = __ldxr(_X8);
            while ( __stxr(v56 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = a1[5];
          if ( (v33 & 1) != 0 )
            goto LABEL_37;
LABEL_13:
          raw_spin_unlock(a1 + 4);
          v13 = v32;
          if ( !v12 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_abort_mac_scan_all_adapters");
  _ReadStatusReg(SP_EL0);
  return 0;
}
