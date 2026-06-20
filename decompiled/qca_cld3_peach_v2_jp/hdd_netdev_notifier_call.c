__int64 __fastcall hdd_netdev_notifier_call(
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
        __int64 *a11)
{
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *context; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *v46; // x0
  const char *v47; // x2
  unsigned __int8 *v48; // x10
  __int64 v49; // x7
  int v50; // w8
  int v51; // w9
  unsigned int v52; // w1
  _QWORD *v54; // x22
  __int64 adapter_by_iface_name; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v57; // x0
  __int64 v58; // x25
  __int64 v59; // x24
  __int64 v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int64 v69; // x28
  __int64 v70; // x8
  unsigned int v71; // w4
  __int64 v72; // x23
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x23
  __int64 v91; // x25
  __int64 v92; // x8
  __int64 v93; // x8
  unsigned int *v94; // x8
  unsigned int v95; // w10
  __int64 v96; // x8
  __int64 v98; // x8
  unsigned int v104; // w9
  _QWORD *v105; // x1
  __int64 v106; // x9
  unsigned __int64 v107; // x8
  __int64 v108; // x9
  unsigned int *v109; // x9
  unsigned int v110; // w12
  __int64 v111; // x9
  __int64 v113; // x0
  __int64 v114; // x23
  __int64 v115; // x9
  unsigned __int64 v116; // x8
  __int64 v117; // x9
  unsigned int *v118; // x9
  unsigned int v119; // w12
  __int64 v120; // x9
  __int64 v122; // x23
  __int64 v123; // x1
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 vdev_by_user; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x20
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  _QWORD *v150; // x23
  unsigned int v152; // w9
  unsigned int v154; // w9
  __int64 v155; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v156[2]; // [xsp+20h] [xbp-10h] BYREF

  v156[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a11;
  v155 = 0;
  if ( (*(_BYTE *)v12 & 2) == 0 )
    goto LABEL_3;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hdd_netdev_notifier_bridge_intf",
    v12 + 296);
  context = _cds_get_context(51, (__int64)"hdd_netdev_notifier_bridge_intf", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (unsigned int)_wlan_hdd_validate_context(context, "hdd_netdev_notifier_bridge_intf") )
    goto LABEL_3;
  v48 = *(unsigned __int8 **)(v12 + 1008);
  if ( v48 )
  {
    v49 = *v48;
    v50 = v48[1];
    v51 = v48[2];
    LODWORD(v48) = v48[5];
  }
  else
  {
    v51 = 0;
    v49 = 0;
    v50 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s New Net Device State = %lu, flags 0x%x bridge mac address: %02x:%02x:%02x:**:**:%02x",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "hdd_netdev_notifier_bridge_intf",
    v12 + 296,
    a10,
    *(unsigned int *)(v12 + 176),
    v49,
    v50,
    v51,
    (_DWORD)v48,
    v155);
  if ( !(unsigned int)qdf_mem_cmp(context + 1026, *(const void **)(v12 + 1008), 6u) )
    goto LABEL_3;
  if ( a10 != 8 )
  {
    if ( a10 == 6 )
    {
      *((_WORD *)context + 4106) = 0;
      *((_DWORD *)context + 2052) = 0;
      goto LABEL_3;
    }
    if ( a10 != 5 )
      goto LABEL_3;
  }
  qdf_mem_copy(context + 1026, *(const void **)(v12 + 1008), 6u);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(context + 4);
  }
  else
  {
    raw_spin_lock_bh(context + 4);
    context[5] |= 1uLL;
  }
  v156[0] = 0;
  v57 = qdf_list_peek_front(context + 6, v156);
  if ( (_DWORD)v57 || (v105 = (_QWORD *)v156[0], v58 = v156[0] - 8LL, v156[0] == 8) )
  {
    v58 = 0;
LABEL_30:
    v59 = 0;
    goto LABEL_31;
  }
  v106 = *(__int64 *)((char *)&off_18 + v156[0]);
  if ( v106 )
  {
    v107 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v107 + 16);
    v108 = *(_QWORD *)(v106 + 1320);
    v109 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v108);
    do
      v110 = __ldxr(v109);
    while ( __stxr(v110 + 1, v109) );
    v111 = *(_QWORD *)(v107 + 16) - 1LL;
    *(_DWORD *)(v107 + 16) = v111;
    if ( !v111 || !*(_QWORD *)(v107 + 16) )
    {
      v150 = v105;
      preempt_schedule_notrace(v57);
      v105 = v150;
    }
  }
  _X8 = (unsigned int *)(v105 + 6577);
  __asm { PRFM            #0x11, [X8] }
  do
    v152 = __ldxr(_X8);
  while ( __stxr(v152 + 1, _X8) );
  v156[0] = 0;
  v113 = qdf_list_peek_next(context + 6, v105, v156);
  if ( (_DWORD)v113 )
    goto LABEL_30;
  v114 = v156[0];
  v59 = v156[0] - 8LL;
  if ( v156[0] != 8 )
  {
    v115 = *(__int64 *)((char *)&off_18 + v156[0]);
    if ( v115 )
    {
      v116 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v116 + 16);
      v117 = *(_QWORD *)(v115 + 1320);
      v118 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v117);
      do
        v119 = __ldxr(v118);
      while ( __stxr(v119 + 1, v118) );
      v120 = *(_QWORD *)(v116 + 16) - 1LL;
      *(_DWORD *)(v116 + 16) = v120;
      if ( !v120 || !*(_QWORD *)(v116 + 16) )
        preempt_schedule_notrace(v113);
    }
    _X8 = (unsigned int *)(v114 + 52616);
    __asm { PRFM            #0x11, [X8] }
    do
      v154 = __ldxr(_X8);
    while ( __stxr(v154 + 1, _X8) );
  }
LABEL_31:
  v60 = context[5];
  if ( (v60 & 1) != 0 )
  {
    context[5] = v60 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(context + 4);
    if ( v58 )
      goto LABEL_33;
  }
  else
  {
    raw_spin_unlock(context + 4);
    if ( v58 )
    {
LABEL_33:
      v69 = _ReadStatusReg(SP_EL0);
      do
      {
        if ( *(_DWORD *)(v58 + 40) == 1 )
        {
          v70 = *(_QWORD *)(v58 + 52824);
          v71 = *(unsigned __int8 *)(v70 + 8);
          if ( v71 == 255 )
          {
            v72 = jiffies;
            if ( _wlan_hdd_validate_vdev_id___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: adapter is not up (via %s)",
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                "__wlan_hdd_validate_vdev_id",
                "hdd_netdev_notifier_bridge_intf");
              _wlan_hdd_validate_vdev_id___last_ticks = v72;
            }
          }
          else if ( v71 < 6 )
          {
            if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(
                                  *(_QWORD *)(v70 + 32),
                                  5u,
                                  v61,
                                  v62,
                                  v63,
                                  v64,
                                  v65,
                                  v66,
                                  v67,
                                  v68) )
            {
              ucfg_pmo_set_vdev_bridge_addr(*(_QWORD *)(*(_QWORD *)(v58 + 52824) + 32LL), context + 1026);
              ucfg_pmo_del_wow_pattern(*(_QWORD *)(*(_QWORD *)(v58 + 52824) + 32LL));
              v73 = ucfg_pmo_register_wow_default_patterns(*(_QWORD *)(*(_QWORD *)(v58 + 52824) + 32LL));
              wlan_objmgr_vdev_release_ref(
                *(_QWORD *)(*(_QWORD *)(v58 + 52824) + 32LL),
                5u,
                *(unsigned int **)(v58 + 52824),
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80);
            }
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: bad vdev Id:%u (via %s)",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "__wlan_hdd_validate_vdev_id");
          }
        }
        hdd_adapter_dev_put_debug(v58, 25);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(context + 4);
          if ( !v59 )
            goto LABEL_58;
        }
        else
        {
          raw_spin_lock_bh(context + 4);
          context[5] |= 1uLL;
          if ( !v59 )
            goto LABEL_58;
        }
        v156[0] = 0;
        v81 = qdf_list_peek_next(context + 6, (_QWORD *)(v59 + 8), v156);
        v90 = v156[0] - 8LL;
        if ( (_DWORD)v81 )
          v91 = 0;
        else
          v91 = v156[0] - 8LL;
        if ( v59 == v91 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            v89,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v59, 25);
LABEL_58:
          v90 = 0;
          v58 = 0;
          v98 = context[5];
          if ( (v98 & 1) != 0 )
            goto LABEL_64;
          goto LABEL_59;
        }
        if ( v91 )
        {
          v92 = *(_QWORD *)(v91 + 32);
          if ( v92 )
          {
            ++*(_DWORD *)(v69 + 16);
            v93 = *(_QWORD *)(v92 + 1320);
            v94 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v93);
            do
              v95 = __ldxr(v94);
            while ( __stxr(v95 + 1, v94) );
            v96 = *(_QWORD *)(v69 + 16) - 1LL;
            *(_DWORD *)(v69 + 16) = v96;
            if ( !v96 || !*(_QWORD *)(v69 + 16) )
              preempt_schedule_notrace(v81);
          }
          _X8 = (unsigned int *)(v91 + 52624);
          __asm { PRFM            #0x11, [X8] }
          do
            v104 = __ldxr(_X8);
          while ( __stxr(v104 + 1, _X8) );
        }
        else
        {
          v90 = 0;
        }
        v58 = v59;
        v98 = context[5];
        if ( (v98 & 1) != 0 )
        {
LABEL_64:
          context[5] = v98 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(context + 4);
          goto LABEL_60;
        }
LABEL_59:
        raw_spin_unlock(context + 4);
LABEL_60:
        v59 = v90;
      }
      while ( v58 );
    }
  }
LABEL_3:
  if ( !(unsigned int)_osif_vdev_sync_op_start(v12, &v155, "hdd_netdev_notifier_call") )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "__hdd_netdev_notifier_call",
      v12 + 296);
    if ( *(_QWORD *)(v12 + 992) )
    {
      v46 = _cds_get_context(51, (__int64)"__hdd_netdev_notifier_call", v38, v39, v40, v41, v42, v43, v44, v45);
      if ( !v46 )
      {
LABEL_14:
        _osif_vdev_sync_op_stop(v155, "hdd_netdev_notifier_call");
        goto LABEL_15;
      }
      if ( *((_DWORD *)v46 + 366) == 2 )
      {
        v47 = "%s: Driver module is closed";
      }
      else
      {
        v54 = v46;
        adapter_by_iface_name = hdd_get_adapter_by_iface_name();
        if ( !adapter_by_iface_name )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: failed to look up adapter for '%s'",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "__hdd_netdev_notifier_call",
            v12 + 296);
          goto LABEL_14;
        }
        if ( adapter_by_iface_name != v12 + 2688 )
        {
          v47 = "%s: HDD adapter mismatch!";
          v52 = 2;
          goto LABEL_13;
        }
        v122 = adapter_by_iface_name;
        if ( (cds_get_driver_state(v38, v39, v40, v41, v42, v43, v44, v45) & 8) != 0 )
        {
          v47 = "%s: Driver is recovering";
        }
        else
        {
          if ( (cds_get_driver_state(v38, v39, v40, v41, v42, v43, v44, v45) & 0x10) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: %s New Net Device State = %lu, flags 0x%x",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "__hdd_netdev_notifier_call",
              v12 + 296,
              a10,
              *(unsigned int *)(v12 + 176));
            if ( a10 > 9 )
            {
              if ( a10 == 10 )
              {
                vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v122 + 52824), 79, "__hdd_netdev_notifier_call");
                if ( vdev_by_user )
                {
                  v141 = vdev_by_user;
                  if ( (unsigned int)ucfg_scan_get_vdev_status(
                                       vdev_by_user,
                                       v133,
                                       v134,
                                       v135,
                                       v136,
                                       v137,
                                       v138,
                                       v139,
                                       v140) )
                    wlan_abort_scan(v54[1], -1, *(unsigned __int8 *)(*(_QWORD *)(v122 + 52824) + 8LL), 0xFFFFFFFF, 1);
                  _hdd_objmgr_put_vdev_by_user(v141, 79, "__hdd_netdev_notifier_call");
                  cds_flush_work(v122 + 41704);
                  wlan_hdd_cfg80211_scan_block(v122);
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: Scan is not Pending from user",
                    v142,
                    v143,
                    v144,
                    v145,
                    v146,
                    v147,
                    v148,
                    v149,
                    "__hdd_netdev_notifier_call");
                  wlan_cfg80211_cleanup_scan_queue(v54[1], v12);
                }
              }
              else if ( a10 == 12 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: vdev %d netdev Feature 0x%llx\n",
                  v124,
                  v125,
                  v126,
                  v127,
                  v128,
                  v129,
                  v130,
                  v131,
                  "__hdd_netdev_notifier_call",
                  *(unsigned __int8 *)(*(_QWORD *)(v122 + 52824) + 8LL),
                  *(_QWORD *)(v12 + 184));
              }
            }
            else if ( a10 == 1 )
            {
              sme_ch_avoid_update_req(v54[2]);
            }
            else if ( a10 == 4 && *(_BYTE *)(v122 + 1808) == 1 )
            {
              complete(v122 + 1776, v123);
            }
            goto LABEL_14;
          }
          v47 = "%s: Driver is in failed recovery state";
        }
      }
    }
    else
    {
      v47 = "%s: ieee80211_ptr is null";
    }
    v52 = 8;
LABEL_13:
    qdf_trace_msg(0x33u, v52, v47, v38, v39, v40, v41, v42, v43, v44, v45, "__hdd_netdev_notifier_call");
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s New Net Device State = %lu, flags 0x%x NOTIFY_DONE",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_netdev_notifier_call",
    v12 + 296,
    a10,
    *(unsigned int *)(v12 + 176));
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return 0;
}
