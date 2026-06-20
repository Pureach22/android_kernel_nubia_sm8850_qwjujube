__int64 __fastcall hdd_deinit_all_adapters(
        __int64 a1,
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
  __int64 v12; // x26
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x26
  __int64 v68; // x8
  __int64 v69; // x8
  unsigned int *v70; // x8
  unsigned int v71; // w10
  __int64 v72; // x8
  unsigned int v79; // w9
  _QWORD *v80; // x1
  __int64 v81; // x9
  unsigned __int64 v82; // x8
  __int64 v83; // x9
  unsigned int *v84; // x9
  unsigned int v85; // w12
  __int64 v86; // x9
  __int64 v88; // x0
  __int64 v89; // x20
  __int64 v90; // x9
  unsigned __int64 v91; // x8
  __int64 v92; // x9
  unsigned int *v93; // x9
  unsigned int v94; // w12
  __int64 v95; // x9
  __int64 result; // x0
  _QWORD *v98; // x20
  unsigned int v100; // w9
  unsigned int v102; // w9
  _QWORD v103[2]; // [xsp+0h] [xbp-10h] BYREF

  v103[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_deinit_all_adapters");
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
  v103[0] = 0;
  v11 = qdf_list_peek_front((_QWORD *)(a1 + 48), v103);
  if ( (_DWORD)v11 || (v80 = (_QWORD *)v103[0], v12 = v103[0] - 8LL, v103[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v81 = *(__int64 *)((char *)&off_18 + v103[0]);
  if ( v81 )
  {
    v82 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v82 + 16);
    v83 = *(_QWORD *)(v81 + 1320);
    v84 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v83);
    do
      v85 = __ldxr(v84);
    while ( __stxr(v85 + 1, v84) );
    v86 = *(_QWORD *)(v82 + 16) - 1LL;
    *(_DWORD *)(v82 + 16) = v86;
    if ( !v86 || !*(_QWORD *)(v82 + 16) )
    {
      v98 = v80;
      preempt_schedule_notrace(v11);
      v80 = v98;
    }
  }
  _X8 = (unsigned int *)(v80 + 6572);
  __asm { PRFM            #0x11, [X8] }
  do
    v100 = __ldxr(_X8);
  while ( __stxr(v100 + 1, _X8) );
  v103[0] = 0;
  v88 = qdf_list_peek_next((_QWORD *)(a1 + 48), v80, v103);
  if ( (_DWORD)v88 )
    goto LABEL_7;
  v89 = v103[0];
  v13 = v103[0] - 8LL;
  if ( v103[0] != 8 )
  {
    v90 = *(__int64 *)((char *)&off_18 + v103[0]);
    if ( v90 )
    {
      v91 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v91 + 16);
      v92 = *(_QWORD *)(v90 + 1320);
      v93 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v92);
      do
        v94 = __ldxr(v93);
      while ( __stxr(v94 + 1, v93) );
      v95 = *(_QWORD *)(v91 + 16) - 1LL;
      *(_DWORD *)(v91 + 16) = v95;
      if ( !v95 || !*(_QWORD *)(v91 + 16) )
        preempt_schedule_notrace(v88);
    }
    _X8 = (unsigned int *)(v89 + 52576);
    __asm { PRFM            #0x11, [X8] }
    do
      v102 = __ldxr(_X8);
    while ( __stxr(v102 + 1, _X8) );
  }
LABEL_8:
  v14 = *(_QWORD *)(a1 + 40);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v12 )
      goto LABEL_10;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( v12 )
    {
LABEL_10:
      v23 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter(%s)",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "hdd_deinit_adapter",
          *(_QWORD *)(v12 + 32) + 296LL);
        hdd_deinit_session(v12, v34, v35, v36, v37, v38, v39, v40, v41);
        qdf_trace_msg(0x33u, 8u, "%s: exit", v42, v43, v44, v45, v46, v47, v48, v49, "hdd_deinit_adapter");
        hdd_adapter_dev_put_debug(v12, 0xFu, v50, v51, v52, v53, v54, v55, v56, v57);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
          if ( v13 )
            goto LABEL_18;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = *(_QWORD *)(a1 + 40);
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_31:
          *(_QWORD *)(a1 + 40) = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 32);
          v13 = v32;
          if ( !v12 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
          if ( !v13 )
            goto LABEL_12;
LABEL_18:
          v103[0] = 0;
          v58 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v13 + 8), v103);
          v32 = v103[0] - 8LL;
          if ( (_DWORD)v58 )
            v67 = 0;
          else
            v67 = v103[0] - 8LL;
          if ( v13 == v67 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0xFu, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v67 )
          {
            v68 = *(_QWORD *)(v67 + 32);
            if ( v68 )
            {
              ++*(_DWORD *)(v23 + 16);
              v69 = *(_QWORD *)(v68 + 1320);
              v70 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v69);
              do
                v71 = __ldxr(v70);
              while ( __stxr(v71 + 1, v70) );
              v72 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v72;
              if ( !v72 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v58);
            }
            _X8 = (unsigned int *)(v67 + 52584);
            __asm { PRFM            #0x11, [X8] }
            do
              v79 = __ldxr(_X8);
            while ( __stxr(v79 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = *(_QWORD *)(a1 + 40);
          if ( (v33 & 1) != 0 )
            goto LABEL_31;
LABEL_13:
          raw_spin_unlock(a1 + 32);
          v13 = v32;
          if ( !v12 )
            break;
        }
      }
    }
  }
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_deinit_all_adapters");
  _ReadStatusReg(SP_EL0);
  return result;
}
