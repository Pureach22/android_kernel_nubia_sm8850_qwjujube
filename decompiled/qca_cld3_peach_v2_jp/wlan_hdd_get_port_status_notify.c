__int64 __fastcall wlan_hdd_get_port_status_notify(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x0
  _DWORD *v25; // x22
  __int64 v26; // x21
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x25
  unsigned __int64 v37; // x26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x28
  __int64 v47; // x8
  int v48; // w4
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x22
  __int64 v59; // x8
  __int64 v60; // x8
  unsigned int *v61; // x8
  unsigned int v62; // w10
  __int64 v63; // x8
  unsigned int v70; // w9
  _QWORD *v72; // x1
  __int64 v73; // x9
  unsigned __int64 v74; // x8
  __int64 v75; // x9
  unsigned int *v76; // x9
  unsigned int v77; // w12
  __int64 v78; // x9
  __int64 v80; // x0
  __int64 v81; // x23
  __int64 v82; // x9
  unsigned __int64 v83; // x8
  __int64 v84; // x9
  unsigned int *v85; // x9
  unsigned int v86; // w12
  __int64 v87; // x9
  __int64 v89; // x19
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  _QWORD *v106; // x21
  unsigned int v108; // w9
  unsigned int v110; // w9
  _QWORD v111[2]; // [xsp+0h] [xbp-10h] BYREF

  v111[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"wlan_hdd_get_port_status_notify", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: HDD CTX is NUll",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_hdd_get_port_status_notify");
    goto LABEL_47;
  }
  if ( a10 == 1 )
  {
    v22 = context;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(context + 4);
    }
    else
    {
      raw_spin_lock_bh(context + 4);
      v22[5] |= 1uLL;
    }
    v111[0] = 0;
    v24 = qdf_list_peek_front(v22 + 6, v111);
    if ( (_DWORD)v24 || (v72 = (_QWORD *)v111[0], v25 = (_DWORD *)(v111[0] - 8LL), v111[0] == 8) )
    {
      v25 = nullptr;
    }
    else
    {
      v73 = *(__int64 *)((char *)&off_18 + v111[0]);
      if ( v73 )
      {
        v74 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v74 + 16);
        v75 = *(_QWORD *)(v73 + 1320);
        v76 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v75);
        do
          v77 = __ldxr(v76);
        while ( __stxr(v77 + 1, v76) );
        v78 = *(_QWORD *)(v74 + 16) - 1LL;
        *(_DWORD *)(v74 + 16) = v78;
        if ( !v78 || !*(_QWORD *)(v74 + 16) )
        {
          v106 = v72;
          preempt_schedule_notrace(v24);
          v72 = v106;
        }
      }
      _X8 = (unsigned int *)v72 + 13193;
      __asm { PRFM            #0x11, [X8] }
      do
        v108 = __ldxr(_X8);
      while ( __stxr(v108 + 1, _X8) );
      v111[0] = 0;
      v80 = qdf_list_peek_next(v22 + 6, v72, v111);
      if ( !(_DWORD)v80 )
      {
        v81 = v111[0];
        v26 = v111[0] - 8LL;
        if ( v111[0] != 8 )
        {
          v82 = *(__int64 *)((char *)&off_18 + v111[0]);
          if ( v82 )
          {
            v83 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v83 + 16);
            v84 = *(_QWORD *)(v82 + 1320);
            v85 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v84);
            do
              v86 = __ldxr(v85);
            while ( __stxr(v86 + 1, v85) );
            v87 = *(_QWORD *)(v83 + 16) - 1LL;
            *(_DWORD *)(v83 + 16) = v87;
            if ( !v87 || !*(_QWORD *)(v83 + 16) )
              preempt_schedule_notrace(v80);
          }
          _X8 = (unsigned int *)(v81 + 52772);
          __asm { PRFM            #0x11, [X8] }
          do
            v110 = __ldxr(_X8);
          while ( __stxr(v110 + 1, _X8) );
        }
        goto LABEL_10;
      }
    }
    v26 = 0;
LABEL_10:
    v27 = v22[5];
    if ( (v27 & 1) != 0 )
    {
      v22[5] = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v22 + 4);
      if ( !v25 )
        goto LABEL_47;
    }
    else
    {
      raw_spin_unlock(v22 + 4);
      if ( !v25 )
        goto LABEL_47;
    }
    v36 = 1;
    v37 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( !v25[10] )
      {
        v48 = *(_DWORD *)(a11 + 8);
        if ( v48 == v25[14349] )
        {
          v36 = 0;
          goto LABEL_67;
        }
        if ( v48 == v25[14351] )
          goto LABEL_67;
        if ( v48 == v25[14353] )
        {
          v36 = 2;
          goto LABEL_67;
        }
        if ( v48 == v25[14355] )
        {
          v36 = 3;
          goto LABEL_67;
        }
        if ( v48 == v25[14357] )
        {
          v36 = 4;
LABEL_67:
          v89 = (__int64)&v25[2 * v36 + 14349];
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Remove port_id %u",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_hdd_get_port_status_notify");
          *(_DWORD *)v89 = 0;
          *(_BYTE *)(v89 + 4) = 0;
          hdd_adapter_dev_put_debug((__int64)v25, 0x40u, v90, v91, v92, v93, v94, v95, v96, v97);
          if ( v26 )
            hdd_adapter_dev_put_debug(v26, 0x40u, v98, v99, v100, v101, v102, v103, v104, v105);
          break;
        }
      }
      hdd_adapter_dev_put_debug((__int64)v25, 0x40u, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v37 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v22 + 4);
        if ( v26 )
          goto LABEL_26;
LABEL_14:
        v46 = 0;
        v25 = nullptr;
        v47 = v22[5];
        if ( (v47 & 1) == 0 )
          goto LABEL_15;
LABEL_39:
        v22[5] = v47 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v22 + 4);
        v26 = v46;
        if ( !v25 )
          break;
      }
      else
      {
        raw_spin_lock_bh(v22 + 4);
        v22[5] |= 1uLL;
        if ( !v26 )
          goto LABEL_14;
LABEL_26:
        v111[0] = 0;
        v49 = qdf_list_peek_next(v22 + 6, (_QWORD *)(v26 + 8), v111);
        v46 = v111[0] - 8LL;
        if ( (_DWORD)v49 )
          v58 = 0;
        else
          v58 = v111[0] - 8LL;
        if ( v26 == v58 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v26, 0x40u, v38, v39, v40, v41, v42, v43, v44, v45);
          goto LABEL_14;
        }
        if ( v58 )
        {
          v59 = *(_QWORD *)(v58 + 32);
          if ( v59 )
          {
            ++*(_DWORD *)(v37 + 16);
            v60 = *(_QWORD *)(v59 + 1320);
            v61 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v60);
            do
              v62 = __ldxr(v61);
            while ( __stxr(v62 + 1, v61) );
            v63 = *(_QWORD *)(v37 + 16) - 1LL;
            *(_DWORD *)(v37 + 16) = v63;
            if ( !v63 || !*(_QWORD *)(v37 + 16) )
              preempt_schedule_notrace(v49);
          }
          _X8 = (unsigned int *)(v58 + 52780);
          __asm { PRFM            #0x11, [X8] }
          do
            v70 = __ldxr(_X8);
          while ( __stxr(v70 + 1, _X8) );
        }
        else
        {
          v46 = 0;
        }
        v25 = (_DWORD *)v26;
        v47 = v22[5];
        if ( (v47 & 1) != 0 )
          goto LABEL_39;
LABEL_15:
        raw_spin_unlock(v22 + 4);
        v26 = v46;
        if ( !v25 )
          break;
      }
    }
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return 0;
}
