__int64 __fastcall wlan_hdd_set_roaming_state(unsigned __int8 *a1, unsigned int a2, char a3)
{
  int v3; // w25
  __int64 *v4; // x24
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x21
  __int64 v10; // x8
  unsigned __int64 v11; // x27
  __int64 v12; // x23
  __int64 v13; // x8
  unsigned int v14; // w23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
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
  __int64 v34; // x8
  unsigned int *v35; // x8
  unsigned int v36; // w10
  __int64 v37; // x8
  unsigned int v44; // w9
  _QWORD *v45; // x1
  __int64 v46; // x9
  unsigned __int64 v47; // x8
  __int64 v48; // x9
  unsigned int *v49; // x9
  unsigned int v50; // w12
  __int64 v51; // x9
  __int64 v53; // x0
  __int64 v54; // x19
  __int64 v55; // x9
  unsigned __int64 v56; // x8
  __int64 v57; // x9
  unsigned int *v58; // x9
  unsigned int v59; // w12
  __int64 v60; // x9
  _QWORD *v62; // x19
  unsigned int v64; // w9
  unsigned int v66; // w9
  _QWORD v69[2]; // [xsp+10h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[8];
  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  result = policy_mgr_is_sta_active_connection_exists(*v4);
  if ( (result & 1) == 0 )
    goto LABEL_65;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v4 + 4);
  }
  else
  {
    raw_spin_lock_bh(v4 + 4);
    v4[5] |= 1uLL;
  }
  v69[0] = 0;
  v7 = qdf_list_peek_front(v4 + 6, v69);
  if ( (_DWORD)v7 || (v45 = (_QWORD *)v69[0], v8 = v69[0] - 8LL, v69[0] == 8) )
  {
    v8 = 0;
LABEL_8:
    v9 = 0;
    goto LABEL_9;
  }
  v46 = *(__int64 *)((char *)&off_18 + v69[0]);
  if ( v46 )
  {
    v47 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v47 + 16);
    v48 = *(_QWORD *)(v46 + 1320);
    v49 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v48);
    do
      v50 = __ldxr(v49);
    while ( __stxr(v50 + 1, v49) );
    v51 = *(_QWORD *)(v47 + 16) - 1LL;
    *(_DWORD *)(v47 + 16) = v51;
    if ( !v51 || !*(_QWORD *)(v47 + 16) )
    {
      v62 = v45;
      preempt_schedule_notrace(v7);
      v45 = v62;
    }
  }
  _X8 = (unsigned int *)(v45 + 6584);
  __asm { PRFM            #0x11, [X8] }
  do
    v64 = __ldxr(_X8);
  while ( __stxr(v64 + 1, _X8) );
  v69[0] = 0;
  v53 = qdf_list_peek_next(v4 + 6, v45, v69);
  if ( (_DWORD)v53 )
    goto LABEL_8;
  v54 = v69[0];
  v9 = v69[0] - 8LL;
  if ( v69[0] != 8 )
  {
    v55 = *(__int64 *)((char *)&off_18 + v69[0]);
    if ( v55 )
    {
      v56 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v56 + 16);
      v57 = *(_QWORD *)(v55 + 1320);
      v58 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v57);
      do
        v59 = __ldxr(v58);
      while ( __stxr(v59 + 1, v58) );
      v60 = *(_QWORD *)(v56 + 16) - 1LL;
      *(_DWORD *)(v56 + 16) = v60;
      if ( !v60 || !*(_QWORD *)(v56 + 16) )
        preempt_schedule_notrace(v53);
    }
    _X8 = (unsigned int *)(v54 + 52672);
    __asm { PRFM            #0x11, [X8] }
    do
      v66 = __ldxr(_X8);
    while ( __stxr(v66 + 1, _X8) );
  }
LABEL_9:
  v10 = v4[5];
  if ( (v10 & 1) != 0 )
  {
    v4[5] = v10 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v4 + 4);
    if ( v8 )
      goto LABEL_11;
  }
  else
  {
    result = raw_spin_unlock(v4 + 4);
    if ( v8 )
    {
LABEL_11:
      v11 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (*(_QWORD *)(v8 + 1640) & 1) != 0 && v8 != -52832 )
        {
          do
          {
            v14 = *(unsigned __int8 *)(v8 + 52840);
            if ( v3 != v14 && !*(_DWORD *)(v8 + 40) && hdd_cm_is_vdev_associated((_DWORD *)(v8 + 52832)) )
            {
              if ( (a3 & 1) != 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: %d Enable roaming",
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  "wlan_hdd_set_roaming_state",
                  v14);
                sme_start_roaming(v4[2], v14, 43, a2);
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: %d Disable roaming",
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  "wlan_hdd_set_roaming_state",
                  v14);
                sme_stop_roaming(v4[2], v14, 48, a2);
              }
            }
          }
          while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v8 - *(_DWORD *)(v8 + 52832)) >> 4))
               && (*(_QWORD *)(v8 + 1640) & 1) != 0 );
        }
        hdd_adapter_dev_put_debug(v8, 39);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v11 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v4 + 4);
          if ( v9 )
            goto LABEL_29;
LABEL_13:
          v12 = 0;
          v8 = 0;
          v13 = v4[5];
          if ( (v13 & 1) == 0 )
            goto LABEL_14;
LABEL_42:
          v4[5] = v13 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(v4 + 4);
          v9 = v12;
          if ( !v8 )
            break;
        }
        else
        {
          raw_spin_lock_bh(v4 + 4);
          v4[5] |= 1uLL;
          if ( !v9 )
            goto LABEL_13;
LABEL_29:
          v69[0] = 0;
          v23 = qdf_list_peek_next(v4 + 6, (_QWORD *)(v9 + 8), v69);
          v12 = v69[0] - 8LL;
          if ( (_DWORD)v23 )
            v32 = 0;
          else
            v32 = v69[0] - 8LL;
          if ( v9 == v32 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v9, 39);
            goto LABEL_13;
          }
          if ( v32 )
          {
            v33 = *(_QWORD *)(v32 + 32);
            if ( v33 )
            {
              ++*(_DWORD *)(v11 + 16);
              v34 = *(_QWORD *)(v33 + 1320);
              v35 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v34);
              do
                v36 = __ldxr(v35);
              while ( __stxr(v36 + 1, v35) );
              v37 = *(_QWORD *)(v11 + 16) - 1LL;
              *(_DWORD *)(v11 + 16) = v37;
              if ( !v37 || !*(_QWORD *)(v11 + 16) )
                preempt_schedule_notrace(v23);
            }
            _X8 = (unsigned int *)(v32 + 52680);
            __asm { PRFM            #0x11, [X8] }
            do
              v44 = __ldxr(_X8);
            while ( __stxr(v44 + 1, _X8) );
          }
          else
          {
            v12 = 0;
          }
          v8 = v9;
          v13 = v4[5];
          if ( (v13 & 1) != 0 )
            goto LABEL_42;
LABEL_14:
          result = raw_spin_unlock(v4 + 4);
          v9 = v12;
          if ( !v8 )
            break;
        }
      }
    }
  }
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
