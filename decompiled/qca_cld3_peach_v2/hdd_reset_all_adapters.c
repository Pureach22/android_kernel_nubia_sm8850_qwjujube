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
  __int64 v13; // x28
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
  __int64 v31; // x20
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
  _DWORD *v51; // x28
  __int64 v52; // x25
  __int64 v53; // x1
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  __int64 v63; // x9
  __int64 v64; // x10
  unsigned __int64 v71; // x9
  __int64 *v72; // x25
  __int64 v73; // x28
  __int64 v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x22
  __int64 v84; // x8
  __int64 v85; // x8
  unsigned int *v86; // x8
  unsigned int v87; // w10
  __int64 v88; // x8
  unsigned int v91; // w9
  _QWORD *v92; // x1
  __int64 v93; // x9
  unsigned __int64 v94; // x8
  __int64 v95; // x9
  unsigned int *v96; // x9
  unsigned int v97; // w12
  __int64 v98; // x9
  __int64 v100; // x0
  __int64 v101; // x20
  __int64 v102; // x9
  unsigned __int64 v103; // x8
  __int64 v104; // x9
  unsigned int *v105; // x9
  unsigned int v106; // w12
  __int64 v107; // x9
  _QWORD *v110; // x20
  unsigned int v112; // w9
  unsigned int v114; // w9
  unsigned __int64 v115; // [xsp+0h] [xbp-30h]
  __int64 *v116; // [xsp+8h] [xbp-28h]
  __int64 v117; // [xsp+10h] [xbp-20h]
  _BYTE v118[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v119[2]; // [xsp+20h] [xbp-10h] BYREF

  v119[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v118[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_reset_all_adapters");
  wlan_mlme_get_sap_internal_restart(*a1, v118);
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
  v119[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v119);
  if ( (_DWORD)v11 || (v92 = (_QWORD *)v119[0], v12 = v119[0] - 8LL, v119[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v93 = *(__int64 *)((char *)&off_18 + v119[0]);
  if ( v93 )
  {
    v94 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v94 + 16);
    v95 = *(_QWORD *)(v93 + 1320);
    v96 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v95);
    do
      v97 = __ldxr(v96);
    while ( __stxr(v97 + 1, v96) );
    v98 = *(_QWORD *)(v94 + 16) - 1LL;
    *(_DWORD *)(v94 + 16) = v98;
    if ( !v98 || !*(_QWORD *)(v94 + 16) )
    {
      v110 = v92;
      preempt_schedule_notrace(v11);
      v92 = v110;
    }
  }
  _X8 = (unsigned int *)(v92 + 6573);
  __asm { PRFM            #0x11, [X8] }
  do
    v112 = __ldxr(_X8);
  while ( __stxr(v112 + 1, _X8) );
  v119[0] = 0;
  v100 = qdf_list_peek_next(a1 + 6, v92, v119);
  if ( (_DWORD)v100 )
    goto LABEL_7;
  v101 = v119[0];
  v13 = v119[0] - 8LL;
  if ( v119[0] != 8 )
  {
    v102 = *(__int64 *)((char *)&off_18 + v119[0]);
    if ( v102 )
    {
      v103 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v103 + 16);
      v104 = *(_QWORD *)(v102 + 1320);
      v105 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v104);
      do
        v106 = __ldxr(v105);
      while ( __stxr(v106 + 1, v105) );
      v107 = *(_QWORD *)(v103 + 16) - 1LL;
      *(_DWORD *)(v103 + 16) = v107;
      if ( !v107 || !*(_QWORD *)(v103 + 16) )
        preempt_schedule_notrace(v100);
    }
    _X8 = (unsigned int *)(v101 + 52584);
    __asm { PRFM            #0x11, [X8] }
    do
      v114 = __ldxr(_X8);
    while ( __stxr(v114 + 1, _X8) );
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
      v115 = _ReadStatusReg(SP_EL0);
      v116 = a1 + 4;
      while ( 1 )
      {
        v117 = v13;
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
        if ( (*(_QWORD *)(v12 + 1640) & 1) != 0 && (v51 = (_DWORD *)(v12 + 52840), v12 != -52840)
          || (*(_QWORD *)(v12 + 1640) & 2) != 0 && (v51 = (_DWORD *)(v12 + 58928), v12 != -58928)
          || (*(_QWORD *)(v12 + 1640) & 4) != 0 && (v51 = (_DWORD *)(v12 + 65016), v12 != -65016) )
        {
          do
          {
            if ( (*(_DWORD *)(v12 + 40) | 2) == 2 )
            {
              hdd_send_twt_del_all_sessions_to_userspace(v51);
              vdev_by_user = _hdd_objmgr_get_vdev_by_user(v51, 87, "hdd_reset_all_adapters");
              if ( vdev_by_user )
              {
                v52 = vdev_by_user;
                hdd_notify_tdls_reset_adapter();
                vdev_by_user = _hdd_objmgr_put_vdev_by_user(v52, 87, "hdd_reset_all_adapters");
              }
            }
            if ( v118[0] == 1 && *(_DWORD *)(v12 + 40) == 1 )
            {
              hdd_medium_assess_ssr_enable_flag(vdev_by_user);
              v53 = 1;
            }
            else
            {
              v53 = 4;
            }
            wlan_hdd_netif_queue_control(v12, v53, 1);
            if ( (*(_BYTE *)(v12 + 42092) & 4) != 0 )
              wlan_hdd_netif_queue_control(v12, 2, 2);
            hdd_reset_scan_operation(v51);
            if ( (*(_QWORD *)(v12 + 1624) & 2) != 0 )
            {
              hdd_wmm_adapter_close(v12);
              _X8 = (unsigned __int64 *)(v12 + 1624);
              __asm { PRFM            #0x11, [X8] }
              do
                v71 = __ldxr(_X8);
              while ( __stxr(v71 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Flush any mgmt references held by peer",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "hdd_reset_all_adapters",
              v115);
            vdev_by_user = hdd_stop_adapter(a1, v12);
            if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v51 - *v51 - 52840) >> 3) + 1) > 2u )
              break;
            v62 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v51 - *v51 - 52840) >> 3) + 1);
            v51 = nullptr;
            v63 = v12 + 52840 + 6088LL * (unsigned int)v62;
            do
            {
              if ( v51 )
                break;
              v64 = *(_QWORD *)(v12 + 1640) >> v62++;
              v51 = (_DWORD *)((v64 << 63 >> 63) & v63);
              v63 += 6088;
            }
            while ( v62 != 3 );
          }
          while ( v51 );
        }
        hdd_adapter_dev_put_debug(v12, 0x11u, v43, v44, v45, v46, v47, v48, v49, v50);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v115 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v115 + 16) & 0xFF00) != 0 )
        {
          v72 = a1 + 4;
          raw_spin_lock(v116);
          v73 = v117;
          if ( v117 )
            goto LABEL_44;
LABEL_12:
          v31 = 0;
          v12 = 0;
          v32 = a1[5];
          if ( (v32 & 1) == 0 )
            goto LABEL_13;
LABEL_57:
          a1[5] = v32 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v72);
          v13 = v31;
          if ( !v12 )
            break;
        }
        else
        {
          v72 = a1 + 4;
          raw_spin_lock_bh(v116);
          a1[5] |= 1uLL;
          v73 = v117;
          if ( !v117 )
            goto LABEL_12;
LABEL_44:
          v119[0] = 0;
          v74 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v73 + 8), v119);
          v31 = v119[0] - 8LL;
          if ( (_DWORD)v74 )
            v83 = 0;
          else
            v83 = v119[0] - 8LL;
          if ( v73 == v83 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v73, 0x11u, v23, v24, v25, v26, v27, v28, v29, v30);
            goto LABEL_12;
          }
          if ( v83 )
          {
            v84 = *(_QWORD *)(v83 + 32);
            if ( v84 )
            {
              ++*(_DWORD *)(v115 + 16);
              v85 = *(_QWORD *)(v84 + 1320);
              v86 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v85);
              do
                v87 = __ldxr(v86);
              while ( __stxr(v87 + 1, v86) );
              v88 = *(_QWORD *)(v115 + 16) - 1LL;
              *(_DWORD *)(v115 + 16) = v88;
              if ( !v88 || !*(_QWORD *)(v115 + 16) )
                preempt_schedule_notrace(v74);
            }
            _X8 = (unsigned int *)(v83 + 52592);
            __asm { PRFM            #0x11, [X8] }
            do
              v91 = __ldxr(_X8);
            while ( __stxr(v91 + 1, _X8) );
          }
          else
          {
            v31 = 0;
          }
          v12 = v73;
          v32 = a1[5];
          if ( (v32 & 1) != 0 )
            goto LABEL_57;
LABEL_13:
          raw_spin_unlock(v72);
          v13 = v31;
          if ( !v12 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_reset_all_adapters", v115);
  _ReadStatusReg(SP_EL0);
  return 0;
}
