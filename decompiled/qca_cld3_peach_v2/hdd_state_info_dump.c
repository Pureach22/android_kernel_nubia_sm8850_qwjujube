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
  __int64 v30; // x13
  __int64 v31; // x8
  __int64 v32; // x23
  int v33; // w19
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
  __int64 v50; // x8
  _DWORD *v51; // x27
  int v52; // w0
  int v53; // w19
  int v54; // w0
  int v55; // w0
  __int64 v56; // x8
  __int64 v57; // x9
  __int64 v58; // x10
  _QWORD *v59; // x27
  __int64 v60; // x8
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x11
  __int64 v71; // x24
  __int64 v72; // x8
  __int64 v73; // x8
  unsigned int *v74; // x8
  unsigned int v75; // w10
  __int64 v76; // x8
  unsigned int v83; // w9
  _QWORD *v84; // x1
  __int64 v85; // x9
  unsigned __int64 v86; // x8
  __int64 v87; // x9
  unsigned int *v88; // x9
  unsigned int v89; // w12
  __int64 v90; // x9
  __int64 v92; // x0
  __int64 v93; // x19
  __int64 v94; // x9
  unsigned __int64 v95; // x8
  __int64 v96; // x9
  unsigned int *v97; // x9
  unsigned int v98; // w12
  __int64 v99; // x9
  _QWORD *v101; // x19
  unsigned int v103; // w9
  unsigned int v105; // w9
  _QWORD *v106; // [xsp+0h] [xbp-30h]
  unsigned __int64 v107; // [xsp+8h] [xbp-28h]
  _QWORD *v108; // [xsp+10h] [xbp-20h]
  __int64 v109; // [xsp+18h] [xbp-18h]
  _QWORD v110[2]; // [xsp+20h] [xbp-10h] BYREF

  v110[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  result = _cds_get_context(51, (__int64)"hdd_state_info_dump", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    goto LABEL_71;
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
  v110[0] = 0;
  v28 = qdf_list_peek_front(v22 + 6, v110);
  if ( (_DWORD)v28 || (v84 = (_QWORD *)v110[0], v29 = v110[0] - 8LL, v110[0] == 8) )
  {
    v29 = 0;
  }
  else
  {
    v85 = *(__int64 *)((char *)&off_18 + v110[0]);
    if ( v85 )
    {
      v86 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v86 + 16);
      v87 = *(_QWORD *)(v85 + 1320);
      v88 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v87);
      do
        v89 = __ldxr(v88);
      while ( __stxr(v89 + 1, v88) );
      v90 = *(_QWORD *)(v86 + 16) - 1LL;
      *(_DWORD *)(v86 + 16) = v90;
      if ( !v90 || !*(_QWORD *)(v86 + 16) )
      {
        v101 = v84;
        preempt_schedule_notrace(v28);
        v84 = v101;
      }
    }
    _X8 = (unsigned int *)v84 + 13167;
    __asm { PRFM            #0x11, [X8] }
    do
      v103 = __ldxr(_X8);
    while ( __stxr(v103 + 1, _X8) );
    v110[0] = 0;
    v92 = qdf_list_peek_next(v22 + 6, v84, v110);
    if ( !(_DWORD)v92 )
    {
      v93 = v110[0];
      v30 = v110[0] - 8LL;
      if ( v110[0] != 8 )
      {
        v94 = *(__int64 *)((char *)&off_18 + v110[0]);
        if ( v94 )
        {
          v95 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v95 + 16);
          v96 = *(_QWORD *)(v94 + 1320);
          v97 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v96);
          do
            v98 = __ldxr(v97);
          while ( __stxr(v98 + 1, v97) );
          v99 = *(_QWORD *)(v95 + 16) - 1LL;
          *(_DWORD *)(v95 + 16) = v99;
          if ( !v99 || !*(_QWORD *)(v95 + 16) )
          {
            preempt_schedule_notrace(v92);
            v30 = v93 - 8;
          }
        }
        _X8 = (unsigned int *)(v93 + 52668);
        __asm { PRFM            #0x11, [X8] }
        do
          v105 = __ldxr(_X8);
        while ( __stxr(v105 + 1, _X8) );
      }
      goto LABEL_9;
    }
  }
  v30 = 0;
LABEL_9:
  v31 = v22[5];
  v32 = v30;
  v33 = v26 + v24;
  if ( (v31 & 1) != 0 )
  {
    v22[5] = v31 & 0xFFFFFFFFFFFFFFFELL;
    result = (_QWORD *)raw_spin_unlock_bh(v22 + 4);
    v106 = a1;
    if ( v29 )
      goto LABEL_11;
  }
  else
  {
    result = (_QWORD *)raw_spin_unlock(v22 + 4);
    v106 = a1;
    if ( v29 )
    {
LABEL_11:
      v107 = _ReadStatusReg(SP_EL0);
      v108 = v22;
      while ( 1 )
      {
        v109 = v32;
        if ( (*(_QWORD *)(v29 + 1640) & 1) != 0 && (v51 = (_DWORD *)(v29 + 52840), v29 != -52840)
          || (*(_QWORD *)(v29 + 1640) & 2) != 0 && (v51 = (_DWORD *)(v29 + 58928), v29 != -58928)
          || (*(_QWORD *)(v29 + 1640) & 4) != 0 && (v51 = (_DWORD *)(v29 + 65016), v29 != -65016) )
        {
          do
          {
            scnprintf(
              v12 + (unsigned __int16)v33,
              *a2 - (unsigned __int64)(unsigned __int16)v33,
              "\n device name: %s",
              (const char *)(*(_QWORD *)(v29 + 32) + 296LL));
            v53 = v33 + v52;
            v34 = scnprintf(
                    v12 + (unsigned __int16)v53,
                    *a2 - (unsigned __int64)(unsigned __int16)v53,
                    "\n device_mode: %d",
                    *(_DWORD *)(v29 + 40));
            v33 = v53 + v54;
            if ( (*(_DWORD *)(v29 + 40) | 2) == 2 )
            {
              v34 = scnprintf(
                      v12 + (unsigned __int16)v33,
                      *a2 - (unsigned __int64)(unsigned __int16)v33,
                      "\n conn_state: %d",
                      v51[76]);
              v33 += v55;
            }
            if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v51 - *v51 - 52840) >> 3) + 1) > 2u )
              break;
            v56 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v51 - *v51 - 52840) >> 3) + 1);
            v51 = nullptr;
            v57 = v29 + 52840 + 6088LL * (unsigned int)v56;
            do
            {
              if ( v51 )
                break;
              v58 = *(_QWORD *)(v29 + 1640) >> v56++;
              v51 = (_DWORD *)((v58 << 63 >> 63) & v57);
              v57 += 6088;
            }
            while ( v56 != 3 );
          }
          while ( v51 );
        }
        hdd_adapter_dev_put_debug(v29, 0x26u, v34, v35, v36, v37, v38, v39, v40, v41);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v107 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v107 + 16) & 0xFF00) != 0 )
        {
          v59 = v108;
          raw_spin_lock(v108 + 4);
          v60 = v32;
          if ( v32 )
            goto LABEL_34;
LABEL_13:
          v32 = 0;
          v29 = 0;
          v50 = v59[5];
          if ( (v50 & 1) == 0 )
            goto LABEL_14;
LABEL_47:
          v59[5] = v50 & 0xFFFFFFFFFFFFFFFELL;
          result = (_QWORD *)raw_spin_unlock_bh(v59 + 4);
          if ( !v29 )
            break;
        }
        else
        {
          v59 = v108;
          raw_spin_lock_bh(v108 + 4);
          v108[5] |= 1uLL;
          v60 = v32;
          if ( !v32 )
            goto LABEL_13;
LABEL_34:
          v110[0] = 0;
          v61 = qdf_list_peek_next(v59 + 6, (_QWORD *)(v60 + 8), v110);
          v70 = v32;
          v32 = v110[0] - 8LL;
          if ( (_DWORD)v61 )
            v71 = 0;
          else
            v71 = v110[0] - 8LL;
          if ( v109 == v71 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v109, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49);
            goto LABEL_13;
          }
          if ( v71 )
          {
            v72 = *(_QWORD *)(v71 + 32);
            if ( v72 )
            {
              ++*(_DWORD *)(v107 + 16);
              v73 = *(_QWORD *)(v72 + 1320);
              v74 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v73);
              do
                v75 = __ldxr(v74);
              while ( __stxr(v75 + 1, v74) );
              v76 = *(_QWORD *)(v107 + 16) - 1LL;
              *(_DWORD *)(v107 + 16) = v76;
              if ( !v76 || !*(_QWORD *)(v107 + 16) )
              {
                preempt_schedule_notrace(v61);
                v70 = v109;
              }
            }
            _X8 = (unsigned int *)(v71 + 52676);
            __asm { PRFM            #0x11, [X8] }
            do
              v83 = __ldxr(_X8);
            while ( __stxr(v83 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v29 = v70;
          v50 = v59[5];
          if ( (v50 & 1) != 0 )
            goto LABEL_47;
LABEL_14:
          result = (_QWORD *)raw_spin_unlock(v59 + 4);
          if ( !v29 )
            break;
        }
      }
    }
  }
  *a2 -= v33;
  *v106 += (unsigned __int16)v33;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
