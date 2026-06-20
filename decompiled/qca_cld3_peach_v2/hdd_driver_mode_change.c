__int64 __fastcall hdd_driver_mode_change(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *context; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  unsigned int started; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w20
  unsigned int v46; // w21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  _QWORD *v63; // x20
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v97; // w23
  __int64 v98; // x20
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x0
  unsigned int v132; // w0
  const char *v133; // x2
  __int64 v134; // x20
  __int64 v135; // x0
  unsigned int v136; // w0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 (__fastcall *v145)(); // x8
  __int64 v146; // x0
  __int64 adapter; // x0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  unsigned int v156; // w0
  __int64 v157; // [xsp+0h] [xbp-20h] BYREF
  __int64 v158; // [xsp+8h] [xbp-18h] BYREF
  int v159; // [xsp+10h] [xbp-10h]
  __int64 v160; // [xsp+18h] [xbp-8h]

  v160 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v157 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_driver_mode_change");
  if ( !curr_con_mode )
  {
    v158 = 0;
    context = _cds_get_context(51, (__int64)"hdd_pre_mode_change", v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !(unsigned int)_wlan_hdd_validate_context(
                          (__int64)context,
                          (__int64)"hdd_pre_mode_change",
                          v19,
                          v20,
                          v21,
                          v22,
                          v23,
                          v24,
                          v25,
                          v26) )
    {
      if ( (unsigned int)_osif_psoc_sync_op_start(context[12], &v158, "hdd_pre_mode_change") )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: psoc op start failed",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "hdd_pre_mode_change");
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: cleanup scan queue",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "hdd_pre_mode_change");
        if ( context )
        {
          v35 = context[1];
          if ( v35 )
            wlan_cfg80211_cleanup_scan_queue(v35, 0);
        }
        _osif_psoc_sync_op_stop(v158, "hdd_pre_mode_change");
      }
    }
  }
  started = _osif_driver_sync_trans_start_wait(&v157, "hdd_driver_mode_change");
  if ( !started )
  {
    v55 = osif_driver_sync_wait_for_ops(v157);
    v63 = _cds_get_context(51, (__int64)"hdd_driver_mode_change", v55, v56, v57, v58, v59, v60, v61, v62);
    v46 = _wlan_hdd_validate_context(
            (__int64)v63,
            (__int64)"hdd_driver_mode_change",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71);
    if ( v46 )
      goto LABEL_13;
    v159 = 0;
    v158 = 0;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Driver mode changing to %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "__hdd_driver_mode_change",
      a1);
    v46 = _wlan_hdd_validate_context(
            (__int64)v63,
            (__int64)"__hdd_driver_mode_change",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87);
    if ( v46 )
      goto LABEL_13;
    if ( a1 > 8 || ((1 << a1) & 0x131) == 0 )
    {
      v134 = jiffies;
      if ( _hdd_driver_mode_change___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Requested driver mode is invalid",
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          "__hdd_driver_mode_change");
        _hdd_driver_mode_change___last_ticks = v134;
      }
      v46 = -22;
      goto LABEL_13;
    }
    v97 = curr_con_mode;
    if ( curr_con_mode == a1 )
    {
      v98 = jiffies;
      if ( _hdd_driver_mode_change___last_ticks_917 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Driver is already in the requested mode",
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          "__hdd_driver_mode_change");
        v46 = 0;
        _hdd_driver_mode_change___last_ticks_917 = v98;
        goto LABEL_13;
      }
LABEL_19:
      v46 = 0;
LABEL_13:
      osif_driver_sync_trans_stop(v157);
      goto LABEL_14;
    }
    _qdf_delayed_work_stop_sync();
    qdf_wake_lock_release((__int64)wlan_wake_lock, 0x15u);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Stopped psoc idle timer",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "hdd_psoc_idle_timer_stop");
    if ( *((_DWORD *)v63 + 366) == 2 )
      goto LABEL_28;
    if ( v97 && v97 != 5 )
    {
      if ( v97 != 4 )
      {
LABEL_26:
        v131 = v63[12];
        is_mode_change_psoc_idle_shutdown = 1;
        v132 = pld_idle_shutdown(v131, hdd_mode_change_psoc_idle_shutdown);
        if ( v132 )
        {
          v46 = v132;
          is_mode_change_psoc_idle_shutdown = 0;
          v133 = "%s: Stop wlan modules failed";
LABEL_49:
          qdf_trace_msg(0x33u, 2u, v133, v107, v108, v109, v110, v111, v112, v113, v114, "__hdd_driver_mode_change");
          goto LABEL_13;
        }
LABEL_28:
        if ( (unsigned int)(v97 - 4) >= 2 )
        {
          if ( v97 == 8 )
          {
            v135 = epping_disable();
            epping_close(v135);
LABEL_37:
            curr_con_mode = a1;
            pld_set_mode(a1);
            qdf_event_reset((__int64)(v63 + 869));
            qdf_mutex_acquire((__int64)(v63 + 874));
            *((_BYTE *)v63 + 6948) = 1;
            qdf_mutex_release((__int64)(v63 + 874));
            v136 = pld_idle_restart(v63[12], hdd_mode_change_psoc_idle_restart);
            if ( v136 )
            {
              v46 = v136;
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Start wlan modules failed: %d",
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                v143,
                v144,
                "__hdd_driver_mode_change",
                v136);
              goto LABEL_13;
            }
            if ( ((0x6CEuLL >> a1) & 1) != 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Driver mode %d not supported",
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                v143,
                v144,
                "hdd_open_adapters_for_mode",
                a1);
              v46 = -524;
            }
            else
            {
              rtnl_lock();
              v145 = hdd_open_mode_handlers[a1];
              if ( *((_DWORD *)v145 - 1) != 237692882 )
                __break(0x8228u);
              v146 = ((__int64 (__fastcall *)(_QWORD *))v145)(v63);
              v46 = v146;
              rtnl_unlock(v146);
              if ( !v46 )
              {
                if ( a1 == 4 )
                {
                  adapter = hdd_get_adapter((__int64)v63, 6);
                  if ( !adapter )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Failed to get monitor adapter",
                      v148,
                      v149,
                      v150,
                      v151,
                      v152,
                      v153,
                      v154,
                      v155,
                      "__hdd_driver_mode_change");
                    v46 = -22;
                    goto LABEL_13;
                  }
                  v156 = hdd_start_adapter(adapter, v148, v149, v150, v151, v152, v153, v154, v155);
                  if ( v156 )
                  {
                    v46 = v156;
                    v133 = "%s: Failed to start monitor adapter";
                    goto LABEL_49;
                  }
                  qdf_trace_msg(
                    0x33u,
                    4u,
                    "%s: Acquire wakelock for monitor mode",
                    v107,
                    v108,
                    v109,
                    v110,
                    v111,
                    v112,
                    v113,
                    v114,
                    "__hdd_driver_mode_change");
                  qdf_wake_lock_acquire((__int64)(v63 + 411), 0x16u);
                }
                con_mode = a1;
                qdf_trace_msg(
                  0x33u,
                  4u,
                  "%s: Driver mode successfully changed to %d",
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  "__hdd_driver_mode_change",
                  a1);
                LODWORD(v158) = 0;
                HIDWORD(v158) = con_mode;
                ucfg_dp_bbm_apply_independent_policy(*v63, (__int64)&v158);
                goto LABEL_19;
              }
            }
            v133 = "%s: Failed to open adapters";
            goto LABEL_49;
          }
          if ( v97 )
            goto LABEL_37;
        }
        hdd_close_all_adapters(v63, 0, v107, v108, v109, v110, v111, v112, v113, v114);
        goto LABEL_37;
      }
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Release wakelock for monitor mode!",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "hdd_stop_present_mode");
      qdf_wake_lock_release((__int64)(v63 + 411), 0x16u);
    }
    hdd_abort_mac_scan_all_adapters(v63, v107, v108, v109, v110, v111, v112, v113, v114);
    wlan_cfg80211_cleanup_scan_queue(v63[1], 0);
    hdd_stop_all_adapters(v63, v115, v116, v117, v118, v119, v120, v121, v122);
    hdd_deinit_all_adapters((__int64)v63, v123, v124, v125, v126, v127, v128, v129, v130);
    if ( *((_DWORD *)v63 + 366) == 2 )
      goto LABEL_28;
    goto LABEL_26;
  }
  v45 = started;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to start 'mode change'; status:%u",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "hdd_driver_mode_change",
    started);
  v46 = qdf_status_to_os_return(v45);
LABEL_14:
  qdf_trace_msg(0x33u, 8u, "%s: exit", v47, v48, v49, v50, v51, v52, v53, v54, "hdd_driver_mode_change");
  _ReadStatusReg(SP_EL0);
  return v46;
}
