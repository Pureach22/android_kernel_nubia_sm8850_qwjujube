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
  __int64 v11; // x23
  __int64 v12; // x8
  __int64 v13; // x28
  unsigned int v14; // w23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x22
  __int64 v36; // x8
  __int64 v37; // x8
  unsigned int *v38; // x8
  unsigned int v39; // w10
  __int64 v40; // x8
  unsigned int v47; // w9
  _QWORD *v48; // x1
  __int64 v49; // x9
  unsigned __int64 v50; // x8
  __int64 v51; // x9
  unsigned int *v52; // x9
  unsigned int v53; // w12
  __int64 v54; // x9
  __int64 v56; // x0
  __int64 v57; // x19
  __int64 v58; // x9
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  unsigned int *v61; // x9
  unsigned int v62; // w12
  __int64 v63; // x9
  _QWORD *v65; // x19
  unsigned int v67; // w9
  unsigned int v69; // w9
  unsigned __int64 v70; // [xsp+0h] [xbp-20h]
  _QWORD v73[2]; // [xsp+10h] [xbp-10h] BYREF

  v73[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[8];
  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  result = policy_mgr_is_sta_active_connection_exists(*v4);
  if ( (result & 1) == 0 )
    goto LABEL_74;
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
  v73[0] = 0;
  v7 = qdf_list_peek_front(v4 + 6, v73);
  if ( (_DWORD)v7 || (v48 = (_QWORD *)v73[0], v8 = v73[0] - 8LL, v73[0] == 8) )
  {
    v8 = 0;
LABEL_8:
    v9 = 0;
    goto LABEL_9;
  }
  v49 = *(__int64 *)((char *)&off_18 + v73[0]);
  if ( v49 )
  {
    v50 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v50 + 16);
    v51 = *(_QWORD *)(v49 + 1320);
    v52 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v51);
    do
      v53 = __ldxr(v52);
    while ( __stxr(v53 + 1, v52) );
    v54 = *(_QWORD *)(v50 + 16) - 1LL;
    *(_DWORD *)(v50 + 16) = v54;
    if ( !v54 || !*(_QWORD *)(v50 + 16) )
    {
      v65 = v48;
      preempt_schedule_notrace(v7);
      v48 = v65;
    }
  }
  _X8 = (unsigned int *)(v48 + 6584);
  __asm { PRFM            #0x11, [X8] }
  do
    v67 = __ldxr(_X8);
  while ( __stxr(v67 + 1, _X8) );
  v73[0] = 0;
  v56 = qdf_list_peek_next(v4 + 6, v48, v73);
  if ( (_DWORD)v56 )
    goto LABEL_8;
  v57 = v73[0];
  v9 = v73[0] - 8LL;
  if ( v73[0] != 8 )
  {
    v58 = *(__int64 *)((char *)&off_18 + v73[0]);
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
        preempt_schedule_notrace(v56);
    }
    _X8 = (unsigned int *)(v57 + 52672);
    __asm { PRFM            #0x11, [X8] }
    do
      v69 = __ldxr(_X8);
    while ( __stxr(v69 + 1, _X8) );
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
      v70 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (*(_QWORD *)(v8 + 1640) & 1) != 0 && (v13 = v8 + 52840, v8 != -52840)
          || (*(_QWORD *)(v8 + 1640) & 2) != 0 && (v13 = v8 + 58928, v8 != -58928)
          || (*(_QWORD *)(v8 + 1640) & 4) != 0 && (v13 = v8 + 65016, v8 != -65016) )
        {
          do
          {
            v14 = *(unsigned __int8 *)(v13 + 8);
            if ( v3 != v14 && !*(_DWORD *)(v8 + 40) && hdd_cm_is_vdev_associated((_DWORD *)v13) )
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
            if ( (unsigned __int8)(73 * ((unsigned int)(v13 - *(_DWORD *)v13 - 52840) >> 3) + 1) > 2u )
              break;
            v23 = (unsigned __int8)(73 * ((unsigned int)(v13 - *(_DWORD *)v13 - 52840) >> 3) + 1);
            v13 = 0;
            v24 = v8 + 52840 + 6088LL * (unsigned int)v23;
            do
            {
              if ( v13 )
                break;
              v25 = *(_QWORD *)(v8 + 1640) >> v23++;
              v13 = (v25 << 63 >> 63) & v24;
              v24 += 6088;
            }
            while ( v23 != 3 );
          }
          while ( v13 );
        }
        hdd_adapter_dev_put_debug(v8, 39);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v70 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v70 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v4 + 4);
          if ( v9 )
            goto LABEL_38;
LABEL_13:
          v11 = 0;
          v8 = 0;
          v12 = v4[5];
          if ( (v12 & 1) == 0 )
            goto LABEL_14;
LABEL_51:
          v4[5] = v12 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(v4 + 4);
          v9 = v11;
          if ( !v8 )
            break;
        }
        else
        {
          raw_spin_lock_bh(v4 + 4);
          v4[5] |= 1uLL;
          if ( !v9 )
            goto LABEL_13;
LABEL_38:
          v73[0] = 0;
          v26 = qdf_list_peek_next(v4 + 6, (_QWORD *)(v9 + 8), v73);
          v11 = v73[0] - 8LL;
          if ( (_DWORD)v26 )
            v35 = 0;
          else
            v35 = v73[0] - 8LL;
          if ( v9 == v35 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v9, 39);
            goto LABEL_13;
          }
          if ( v35 )
          {
            v36 = *(_QWORD *)(v35 + 32);
            if ( v36 )
            {
              ++*(_DWORD *)(v70 + 16);
              v37 = *(_QWORD *)(v36 + 1320);
              v38 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v37);
              do
                v39 = __ldxr(v38);
              while ( __stxr(v39 + 1, v38) );
              v40 = *(_QWORD *)(v70 + 16) - 1LL;
              *(_DWORD *)(v70 + 16) = v40;
              if ( !v40 || !*(_QWORD *)(v70 + 16) )
                preempt_schedule_notrace(v26);
            }
            _X8 = (unsigned int *)(v35 + 52680);
            __asm { PRFM            #0x11, [X8] }
            do
              v47 = __ldxr(_X8);
            while ( __stxr(v47 + 1, _X8) );
          }
          else
          {
            v11 = 0;
          }
          v8 = v9;
          v12 = v4[5];
          if ( (v12 & 1) != 0 )
            goto LABEL_51;
LABEL_14:
          result = raw_spin_unlock(v4 + 4);
          v9 = v11;
          if ( !v8 )
            break;
        }
      }
    }
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
