_QWORD *__fastcall hdd_state_info_dump(
        _QWORD *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  _QWORD *result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x27
  int v23; // w0
  int v24; // w25
  int v25; // w0
  int v26; // w26
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x0
  __int64 v29; // x24
  __int64 v30; // x23
  __int64 v31; // x8
  int v32; // w19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x25
  __int64 v50; // x8
  int v51; // w0
  int v52; // w19
  int v53; // w0
  int v54; // w0
  _QWORD *v55; // x27
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x24
  __int64 v66; // x8
  __int64 v67; // x8
  unsigned int *v68; // x8
  unsigned int v69; // w10
  __int64 v70; // x8
  unsigned int v77; // w9
  _QWORD *v78; // x1
  __int64 v79; // x9
  unsigned __int64 v80; // x8
  __int64 v81; // x9
  unsigned int *v82; // x9
  unsigned int v83; // w12
  __int64 v84; // x9
  __int64 v86; // x0
  __int64 v87; // x19
  __int64 v88; // x9
  unsigned __int64 v89; // x8
  __int64 v90; // x9
  unsigned int *v91; // x9
  unsigned int v92; // w12
  __int64 v93; // x9
  _QWORD *v95; // x19
  unsigned int v97; // w9
  unsigned int v99; // w9
  _QWORD *v100; // [xsp+8h] [xbp-28h]
  unsigned __int64 v101; // [xsp+10h] [xbp-20h]
  _QWORD *v102; // [xsp+18h] [xbp-18h]
  _QWORD v103[2]; // [xsp+20h] [xbp-10h] BYREF

  v103[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  result = _cds_get_context(51, (__int64)"hdd_state_info_dump", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    goto LABEL_62;
  v22 = result;
  qdf_trace_msg(0x33u, 8u, "%s: size of buffer: %d", v14, v15, v16, v17, v18, v19, v20, v21, "hdd_state_info_dump", *a2);
  scnprintf(v12, *a2, "\n is_wiphy_suspended %d", *((unsigned __int8 *)v22 + 488));
  v24 = v23;
  scnprintf(
    v12 + (unsigned __int16)v23,
    *a2 - (unsigned __int64)(unsigned __int16)v23,
    "\n is_scheduler_suspended %d",
    *((unsigned __int8 *)v22 + 184));
  v26 = v25;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v22 + 4);
  }
  else
  {
    raw_spin_lock_bh(v22 + 4);
    v22[5] |= 1uLL;
  }
  v103[0] = 0;
  v28 = qdf_list_peek_front(v22 + 6, v103);
  if ( (_DWORD)v28 || (v78 = (_QWORD *)v103[0], v29 = v103[0] - 8LL, v103[0] == 8) )
  {
    v29 = 0;
  }
  else
  {
    v79 = *(__int64 *)((char *)&off_18 + v103[0]);
    if ( v79 )
    {
      v80 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v80 + 16);
      v81 = *(_QWORD *)(v79 + 1320);
      v82 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v81);
      do
        v83 = __ldxr(v82);
      while ( __stxr(v83 + 1, v82) );
      v84 = *(_QWORD *)(v80 + 16) - 1LL;
      *(_DWORD *)(v80 + 16) = v84;
      if ( !v84 || !*(_QWORD *)(v80 + 16) )
      {
        v95 = v78;
        preempt_schedule_notrace(v28);
        v78 = v95;
      }
    }
    _X8 = (unsigned int *)v78 + 13167;
    __asm { PRFM            #0x11, [X8] }
    do
      v97 = __ldxr(_X8);
    while ( __stxr(v97 + 1, _X8) );
    v103[0] = 0;
    v86 = qdf_list_peek_next(v22 + 6, v78, v103);
    if ( !(_DWORD)v86 )
    {
      v87 = v103[0];
      v30 = v103[0] - 8LL;
      if ( v103[0] != 8 )
      {
        v88 = *(__int64 *)((char *)&off_18 + v103[0]);
        if ( v88 )
        {
          v89 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v89 + 16);
          v90 = *(_QWORD *)(v88 + 1320);
          v91 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v90);
          do
            v92 = __ldxr(v91);
          while ( __stxr(v92 + 1, v91) );
          v93 = *(_QWORD *)(v89 + 16) - 1LL;
          *(_DWORD *)(v89 + 16) = v93;
          if ( !v93 || !*(_QWORD *)(v89 + 16) )
            preempt_schedule_notrace(v86);
        }
        _X8 = (unsigned int *)(v87 + 52668);
        __asm { PRFM            #0x11, [X8] }
        do
          v99 = __ldxr(_X8);
        while ( __stxr(v99 + 1, _X8) );
      }
      goto LABEL_9;
    }
  }
  v30 = 0;
LABEL_9:
  v31 = v22[5];
  v32 = v26 + v24;
  if ( (v31 & 1) != 0 )
  {
    v22[5] = v31 & 0xFFFFFFFFFFFFFFFELL;
    result = (_QWORD *)raw_spin_unlock_bh(v22 + 4);
    v100 = a1;
    if ( v29 )
      goto LABEL_11;
  }
  else
  {
    result = (_QWORD *)raw_spin_unlock(v22 + 4);
    v100 = a1;
    if ( v29 )
    {
LABEL_11:
      v101 = _ReadStatusReg(SP_EL0);
      v102 = v22;
      while ( 1 )
      {
        if ( (*(_QWORD *)(v29 + 1640) & 1) != 0 && v29 != -52832 )
        {
          do
          {
            scnprintf(
              v12 + (unsigned __int16)v32,
              *a2 - (unsigned __int64)(unsigned __int16)v32,
              "\n device name: %s",
              (const char *)(*(_QWORD *)(v29 + 32) + 296LL));
            v52 = v32 + v51;
            v33 = scnprintf(
                    v12 + (unsigned __int16)v52,
                    *a2 - (unsigned __int64)(unsigned __int16)v52,
                    "\n device_mode: %d",
                    *(_DWORD *)(v29 + 40));
            v32 = v52 + v53;
            if ( (*(_DWORD *)(v29 + 40) | 2) == 2 )
            {
              v33 = scnprintf(
                      v12 + (unsigned __int16)v32,
                      *a2 - (unsigned __int64)(unsigned __int16)v32,
                      "\n conn_state: %d",
                      *(_DWORD *)(v29 + 53128));
              v32 += v54;
            }
          }
          while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v29 - *(_DWORD *)(v29 + 52832)) >> 4))
               && (*(_QWORD *)(v29 + 1640) & 1) != 0 );
        }
        hdd_adapter_dev_put_debug(v29, 0x26u, v33, v34, v35, v36, v37, v38, v39, v40);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v101 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v101 + 16) & 0xFF00) != 0 )
        {
          v55 = v102;
          raw_spin_lock(v102 + 4);
          if ( v30 )
            goto LABEL_25;
LABEL_13:
          v49 = 0;
          v29 = 0;
          v50 = v55[5];
          if ( (v50 & 1) == 0 )
            goto LABEL_14;
LABEL_38:
          v55[5] = v50 & 0xFFFFFFFFFFFFFFFELL;
          result = (_QWORD *)raw_spin_unlock_bh(v55 + 4);
          v30 = v49;
          if ( !v29 )
            break;
        }
        else
        {
          v55 = v102;
          raw_spin_lock_bh(v102 + 4);
          v102[5] |= 1uLL;
          if ( !v30 )
            goto LABEL_13;
LABEL_25:
          v103[0] = 0;
          v56 = qdf_list_peek_next(v55 + 6, (_QWORD *)(v30 + 8), v103);
          v49 = v103[0] - 8LL;
          if ( (_DWORD)v56 )
            v65 = 0;
          else
            v65 = v103[0] - 8LL;
          if ( v30 == v65 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v30, 0x26u, v41, v42, v43, v44, v45, v46, v47, v48);
            goto LABEL_13;
          }
          if ( v65 )
          {
            v66 = *(_QWORD *)(v65 + 32);
            if ( v66 )
            {
              ++*(_DWORD *)(v101 + 16);
              v67 = *(_QWORD *)(v66 + 1320);
              v68 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v67);
              do
                v69 = __ldxr(v68);
              while ( __stxr(v69 + 1, v68) );
              v70 = *(_QWORD *)(v101 + 16) - 1LL;
              *(_DWORD *)(v101 + 16) = v70;
              if ( !v70 || !*(_QWORD *)(v101 + 16) )
                preempt_schedule_notrace(v56);
            }
            _X8 = (unsigned int *)(v65 + 52676);
            __asm { PRFM            #0x11, [X8] }
            do
              v77 = __ldxr(_X8);
            while ( __stxr(v77 + 1, _X8) );
          }
          else
          {
            v49 = 0;
          }
          v29 = v30;
          v50 = v55[5];
          if ( (v50 & 1) != 0 )
            goto LABEL_38;
LABEL_14:
          result = (_QWORD *)raw_spin_unlock(v55 + 4);
          v30 = v49;
          if ( !v29 )
            break;
        }
      }
    }
  }
  *a2 -= v32;
  *v100 += (unsigned __int16)v32;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
