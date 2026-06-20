__int64 __fastcall hdd_reset_all_adapters(
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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x25
  __int64 v32; // x8
  const char *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 vdev_by_user; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x25
  __int64 v52; // x1
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int64 v67; // x9
  __int64 *v68; // x28
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x22
  __int64 v79; // x8
  __int64 v80; // x8
  unsigned int *v81; // x8
  unsigned int v82; // w10
  __int64 v83; // x8
  unsigned int v86; // w9
  _QWORD *v87; // x1
  __int64 v88; // x9
  unsigned __int64 v89; // x8
  __int64 v90; // x9
  unsigned int *v91; // x9
  unsigned int v92; // w12
  __int64 v93; // x9
  __int64 v95; // x0
  __int64 v96; // x20
  __int64 v97; // x9
  unsigned __int64 v98; // x8
  __int64 v99; // x9
  unsigned int *v100; // x9
  unsigned int v101; // w12
  __int64 v102; // x9
  _QWORD *v105; // x20
  unsigned int v107; // w9
  unsigned int v109; // w9
  unsigned __int64 v110; // [xsp+8h] [xbp-28h]
  __int64 *v111; // [xsp+10h] [xbp-20h]
  _BYTE v112[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v113[2]; // [xsp+20h] [xbp-10h] BYREF

  v113[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v112[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_reset_all_adapters");
  wlan_mlme_get_sap_internal_restart(*a1, v112);
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
  v113[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v113);
  if ( (_DWORD)v11 || (v87 = (_QWORD *)v113[0], v12 = v113[0] - 8LL, v113[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v88 = *(__int64 *)((char *)&off_18 + v113[0]);
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
    {
      v105 = v87;
      preempt_schedule_notrace(v11);
      v87 = v105;
    }
  }
  _X8 = (unsigned int *)(v87 + 6573);
  __asm { PRFM            #0x11, [X8] }
  do
    v107 = __ldxr(_X8);
  while ( __stxr(v107 + 1, _X8) );
  v113[0] = 0;
  v95 = qdf_list_peek_next(a1 + 6, v87, v113);
  if ( (_DWORD)v95 )
    goto LABEL_7;
  v96 = v113[0];
  v13 = v113[0] - 8LL;
  if ( v113[0] != 8 )
  {
    v97 = *(__int64 *)((char *)&off_18 + v113[0]);
    if ( v97 )
    {
      v98 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v98 + 16);
      v99 = *(_QWORD *)(v97 + 1320);
      v100 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v99);
      do
        v101 = __ldxr(v100);
      while ( __stxr(v101 + 1, v100) );
      v102 = *(_QWORD *)(v98 + 16) - 1LL;
      *(_DWORD *)(v98 + 16) = v102;
      if ( !v102 || !*(_QWORD *)(v98 + 16) )
        preempt_schedule_notrace(v95);
    }
    _X8 = (unsigned int *)(v96 + 52584);
    __asm { PRFM            #0x11, [X8] }
    do
      v109 = __ldxr(_X8);
    while ( __stxr(v109 + 1, _X8) );
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
      v110 = _ReadStatusReg(SP_EL0);
      v111 = a1 + 4;
      while ( 1 )
      {
        v33 = qdf_opmode_str(*(_DWORD *)(v12 + 40));
        vdev_by_user = qdf_trace_msg(
                         0x33u,
                         4u,
                         "%s: [SSR] reset adapter with device mode %s(%d)",
                         v34,
                         v35,
                         v36,
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         "hdd_reset_all_adapters",
                         v33,
                         *(unsigned int *)(v12 + 40));
        if ( (*(_QWORD *)(v12 + 1640) & 1) != 0 && v12 != -52832 )
        {
          do
          {
            if ( (*(_DWORD *)(v12 + 40) | 2) == 2 )
            {
              hdd_send_twt_del_all_sessions_to_userspace(v12 + 52832);
              vdev_by_user = _hdd_objmgr_get_vdev_by_user(v12 + 52832, 87, "hdd_reset_all_adapters");
              if ( vdev_by_user )
              {
                v51 = vdev_by_user;
                hdd_notify_tdls_reset_adapter();
                vdev_by_user = _hdd_objmgr_put_vdev_by_user(v51, 87, "hdd_reset_all_adapters");
              }
            }
            if ( v112[0] == 1 && *(_DWORD *)(v12 + 40) == 1 )
            {
              hdd_medium_assess_ssr_enable_flag(vdev_by_user);
              v52 = 1;
            }
            else
            {
              v52 = 4;
            }
            wlan_hdd_netif_queue_control(v12, v52, 1);
            if ( (*(_BYTE *)(v12 + 42092) & 4) != 0 )
              wlan_hdd_netif_queue_control(v12, 2, 2);
            hdd_reset_scan_operation(v12 + 52832);
            if ( (*(_QWORD *)(v12 + 1624) & 2) != 0 )
            {
              hdd_wmm_adapter_close(v12);
              _X8 = (unsigned __int64 *)(v12 + 1624);
              __asm { PRFM            #0x11, [X8] }
              do
                v67 = __ldxr(_X8);
              while ( __stxr(v67 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Flush any mgmt references held by peer",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "hdd_reset_all_adapters");
            vdev_by_user = hdd_stop_adapter(a1, v12);
          }
          while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v12 - *(_DWORD *)(v12 + 52832)) >> 4))
               && (*(_QWORD *)(v12 + 1640) & 1) != 0 );
        }
        hdd_adapter_dev_put_debug(v12, 0x11u, v43, v44, v45, v46, v47, v48, v49, v50);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v110 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v110 + 16) & 0xFF00) != 0 )
        {
          v68 = a1 + 4;
          raw_spin_lock(v111);
          if ( v13 )
            goto LABEL_36;
LABEL_12:
          v31 = 0;
          v12 = 0;
          v32 = a1[5];
          if ( (v32 & 1) == 0 )
            goto LABEL_13;
LABEL_49:
          a1[5] = v32 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v68);
          v13 = v31;
          if ( !v12 )
            break;
        }
        else
        {
          v68 = a1 + 4;
          raw_spin_lock_bh(v111);
          a1[5] |= 1uLL;
          if ( !v13 )
            goto LABEL_12;
LABEL_36:
          v113[0] = 0;
          v69 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v113);
          v31 = v113[0] - 8LL;
          if ( (_DWORD)v69 )
            v78 = 0;
          else
            v78 = v113[0] - 8LL;
          if ( v13 == v78 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x11u, v23, v24, v25, v26, v27, v28, v29, v30);
            goto LABEL_12;
          }
          if ( v78 )
          {
            v79 = *(_QWORD *)(v78 + 32);
            if ( v79 )
            {
              ++*(_DWORD *)(v110 + 16);
              v80 = *(_QWORD *)(v79 + 1320);
              v81 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v80);
              do
                v82 = __ldxr(v81);
              while ( __stxr(v82 + 1, v81) );
              v83 = *(_QWORD *)(v110 + 16) - 1LL;
              *(_DWORD *)(v110 + 16) = v83;
              if ( !v83 || !*(_QWORD *)(v110 + 16) )
                preempt_schedule_notrace(v69);
            }
            _X8 = (unsigned int *)(v78 + 52592);
            __asm { PRFM            #0x11, [X8] }
            do
              v86 = __ldxr(_X8);
            while ( __stxr(v86 + 1, _X8) );
          }
          else
          {
            v31 = 0;
          }
          v12 = v13;
          v32 = a1[5];
          if ( (v32 & 1) != 0 )
            goto LABEL_49;
LABEL_13:
          raw_spin_unlock(v68);
          v13 = v31;
          if ( !v12 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_reset_all_adapters");
  _ReadStatusReg(SP_EL0);
  return 0;
}
