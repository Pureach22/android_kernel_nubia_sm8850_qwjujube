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
  __int64 v13; // x26
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
  __int64 v35; // x24
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x10
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x21
  __int64 v49; // x8
  __int64 v50; // x8
  unsigned int *v51; // x8
  unsigned int v52; // w10
  __int64 v53; // x8
  unsigned int v60; // w9
  _QWORD *v61; // x1
  __int64 v62; // x9
  unsigned __int64 v63; // x8
  __int64 v64; // x9
  unsigned int *v65; // x9
  unsigned int v66; // w12
  __int64 v67; // x9
  __int64 v69; // x0
  __int64 v70; // x20
  __int64 v71; // x9
  unsigned __int64 v72; // x8
  __int64 v73; // x9
  unsigned int *v74; // x9
  unsigned int v75; // w12
  __int64 v76; // x9
  _QWORD *v79; // x20
  unsigned int v81; // w9
  unsigned int v83; // w9
  _QWORD v84[2]; // [xsp+0h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v84[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v84);
  if ( (_DWORD)v11 || (v61 = (_QWORD *)v84[0], v12 = v84[0] - 8LL, v84[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v62 = *(__int64 *)((char *)&off_18 + v84[0]);
  if ( v62 )
  {
    v63 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v63 + 16);
    v64 = *(_QWORD *)(v62 + 1320);
    v65 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v64);
    do
      v66 = __ldxr(v65);
    while ( __stxr(v66 + 1, v65) );
    v67 = *(_QWORD *)(v63 + 16) - 1LL;
    *(_DWORD *)(v63 + 16) = v67;
    if ( !v67 || !*(_QWORD *)(v63 + 16) )
    {
      v79 = v61;
      preempt_schedule_notrace(v11);
      v61 = v79;
    }
  }
  _X8 = (unsigned int *)v61 + 13157;
  __asm { PRFM            #0x11, [X8] }
  do
    v81 = __ldxr(_X8);
  while ( __stxr(v81 + 1, _X8) );
  v84[0] = 0;
  v69 = qdf_list_peek_next(a1 + 6, v61, v84);
  if ( (_DWORD)v69 )
    goto LABEL_7;
  v70 = v84[0];
  v13 = v84[0] - 8LL;
  if ( v84[0] != 8 )
  {
    v71 = *(__int64 *)((char *)&off_18 + v84[0]);
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
        preempt_schedule_notrace(v69);
    }
    _X8 = (unsigned int *)(v70 + 52628);
    __asm { PRFM            #0x11, [X8] }
    do
      v83 = __ldxr(_X8);
    while ( __stxr(v83 + 1, _X8) );
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
        if ( v34 <= 7 && ((1 << v34) & 0x8D) != 0 )
        {
          if ( (*(_QWORD *)(v12 + 1640) & 1) != 0 && (v35 = v12 + 52840, v12 != -52840)
            || (*(_QWORD *)(v12 + 1640) & 2) != 0 && (v35 = v12 + 58928, v12 != -58928)
            || (*(_QWORD *)(v12 + 1640) & 4) != 0 && (v35 = v12 + 65016, v12 != -65016) )
          {
            do
            {
              wlan_abort_scan(a1[1], -1, *(unsigned __int8 *)(v35 + 8), 0xFFFFFFFF, 1);
              if ( (unsigned __int8)(73 * ((unsigned int)(v35 - *(_DWORD *)v35 - 52840) >> 3) + 1) > 2u )
                break;
              v36 = (unsigned __int8)(73 * ((unsigned int)(v35 - *(_DWORD *)v35 - 52840) >> 3) + 1);
              v35 = 0;
              v37 = v12 + 52840 + 6088LL * (unsigned int)v36;
              do
              {
                if ( v35 )
                  break;
                v38 = *(_QWORD *)(v12 + 1640) >> v36++;
                v35 = (v38 << 63 >> 63) & v37;
                v37 += 6088;
              }
              while ( v36 != 3 );
            }
            while ( v35 );
          }
        }
        hdd_adapter_dev_put_debug(v12, 0x1Cu, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
          if ( v13 )
            goto LABEL_33;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = a1[5];
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_46:
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
LABEL_33:
          v84[0] = 0;
          v39 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v84);
          v32 = v84[0] - 8LL;
          if ( (_DWORD)v39 )
            v48 = 0;
          else
            v48 = v84[0] - 8LL;
          if ( v13 == v48 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x1Cu, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v48 )
          {
            v49 = *(_QWORD *)(v48 + 32);
            if ( v49 )
            {
              ++*(_DWORD *)(v23 + 16);
              v50 = *(_QWORD *)(v49 + 1320);
              v51 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v50);
              do
                v52 = __ldxr(v51);
              while ( __stxr(v52 + 1, v51) );
              v53 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v53;
              if ( !v53 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v39);
            }
            _X8 = (unsigned int *)(v48 + 52636);
            __asm { PRFM            #0x11, [X8] }
            do
              v60 = __ldxr(_X8);
            while ( __stxr(v60 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = a1[5];
          if ( (v33 & 1) != 0 )
            goto LABEL_46;
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
