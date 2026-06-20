__int64 __fastcall hdd_context_create(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 v19; // x19
  unsigned int v20; // w0
  int v21; // w20
  __int64 v22; // x0
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x20
  __int64 v42; // x21
  __int64 values; // x0
  __int64 v44; // x0
  const char *v45; // x2
  __int64 v46; // x0
  unsigned int multiplier; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  __int64 v57; // x1
  __int64 v58; // x2
  __int64 v59; // x3
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x0
  __int64 v85; // x1
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  int v94; // w0
  bool v96; // zf
  int inited; // w0
  double v98; // d0
  __int64 v99; // x2
  __int64 v100; // x3
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_context_create");
  v18 = hdd_cfg80211_wiphy_alloc(v10, v11, v12, v13, v14, v15, v16, v17);
  if ( v18 )
  {
    v19 = v18;
    v20 = _qdf_delayed_work_create((_QWORD *)(v18 + 1472), (__int64)hdd_psoc_idle_timeout_callback, v18);
    if ( v20 )
    {
      v21 = qdf_status_to_os_return(v20);
LABEL_36:
      wiphy_free(*(_QWORD *)(v19 + 24));
      return v21;
    }
    *(_QWORD *)(v19 + 96) = a1;
    *(_BYTE *)(v19 + 1803) = -1;
    v22 = _qdf_mem_malloc(0xD8u, "hdd_context_create", 15950);
    *(_QWORD *)(v19 + 104) = v22;
    if ( !v22 )
    {
      v21 = -12;
LABEL_35:
      _qdf_delayed_work_destroy();
      goto LABEL_36;
    }
    v23 = cfg_parse("wlan/qca_cld/peach_v2/WCNSS_qcom_cfg.ini");
    if ( v23 )
    {
      v32 = v23;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to parse cfg %s; status:%d\n",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_context_create",
        "wlan/qca_cld/peach_v2/WCNSS_qcom_cfg.ini",
        v23);
      v21 = qdf_status_to_os_return(v32);
LABEL_34:
      _qdf_mem_free(*(_QWORD *)(v19 + 104));
      goto LABEL_35;
    }
    v21 = hdd_objmgr_create_and_store_psoc(v19, 1);
    if ( v21 )
    {
LABEL_33:
      cfg_release();
      goto LABEL_34;
    }
    v41 = *(_QWORD *)v19;
    if ( *(_QWORD *)v19 )
    {
      v42 = *(_QWORD *)(v19 + 104);
      if ( v42 )
      {
        *(_DWORD *)v42 = *(_DWORD *)(cfg_psoc_get_values(*(_QWORD *)v19) + 2936);
        *(_BYTE *)(v42 + 19) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2817);
        *(_BYTE *)(v42 + 20) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2895);
        *(_DWORD *)(v42 + 24) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2900);
        *(_BYTE *)(v42 + 28) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2904);
        *(_BYTE *)(v42 + 29) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2908);
        *(_DWORD *)(v42 + 32) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2920);
        *(_BYTE *)(v42 + 36) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2892);
        *(_BYTE *)(v42 + 37) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2888);
        *(_DWORD *)(v42 + 60) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2916);
        *(_BYTE *)(v42 + 64) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2912);
        values = cfg_psoc_get_values(v41);
        sized_strscpy(v42 + 65, values + 2868, 16);
        v44 = cfg_psoc_get_values(v41);
        sized_strscpy(v42 + 81, v44 + 2818, 42);
        *(_BYTE *)(v42 + 125) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2905);
        *(_BYTE *)(v42 + 126) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2893);
        *(_DWORD *)(v42 + 128) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2924);
        *(_DWORD *)(v42 + 132) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2864);
        *(_BYTE *)(v42 + 9) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2816);
        *(_BYTE *)(v42 + 16) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2896);
        *(_BYTE *)(v42 + 17) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2940);
        *(_DWORD *)(v42 + 140) = *(unsigned __int8 *)(cfg_psoc_get_values(v41) + 2942);
        *(_BYTE *)(v42 + 174) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2932);
        *(_BYTE *)(v42 + 18) = *(_BYTE *)(cfg_psoc_get_values(v41) + 3999);
        *(_DWORD *)(v42 + 4) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2792);
        *(_BYTE *)(v42 + 123) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2784);
        *(_BYTE *)(v42 + 38) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2804);
        *(_DWORD *)(v42 + 40) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2808);
        *(_BYTE *)(v42 + 44) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2812);
        *(_BYTE *)(v42 + 8) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2894);
        hdd_dp_cfg_update(v41, v19);
        *(_DWORD *)(v42 + 148) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3948);
        *(_DWORD *)(v42 + 152) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3952);
        *(_DWORD *)(v42 + 156) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3956);
        *(_DWORD *)(v42 + 160) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3960);
        *(_DWORD *)(v42 + 164) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3964);
        *(_DWORD *)(v42 + 168) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3968);
        *(_BYTE *)(v42 + 172) = *(_DWORD *)(cfg_psoc_get_values(v41) + 3972);
        *(_BYTE *)(v42 + 173) = *(_BYTE *)(cfg_psoc_get_values(v41) + 3976);
        *(_BYTE *)(v42 + 124) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2788) != 0;
        *(_DWORD *)(v42 + 176) = *(_DWORD *)(cfg_psoc_get_values(v41) + 2800);
        *(_BYTE *)(v42 + 180) = *(_BYTE *)(cfg_psoc_get_values(v41) + 2941);
        *(_BYTE *)(v42 + 181) = *(_BYTE *)(cfg_psoc_get_values(v41) + 3977);
        *(_QWORD *)(v42 + 184) = *(unsigned int *)(cfg_psoc_get_values(v41) + 3980);
        *(_BYTE *)(v42 + 192) = *(_BYTE *)(cfg_psoc_get_values(v41) + 3984);
        *(_QWORD *)(v42 + 200) = *(unsigned int *)(cfg_psoc_get_values(v41) + 3988);
        *(_DWORD *)(v42 + 208) = *(_DWORD *)(cfg_psoc_get_values(v41) + 7480);
        goto LABEL_16;
      }
      v45 = "%s: Invalid hdd config";
    }
    else
    {
      v45 = "%s: Invalid psoc";
    }
    qdf_trace_msg(0x33u, 2u, v45, v33, v34, v35, v36, v37, v38, v39, v40, "hdd_cfg_params_init");
LABEL_16:
    if ( (unsigned int)qdf_timer_get_multiplier() == 1 )
    {
      v46 = cfg_psoc_get_values(*(_QWORD *)v19);
      qdf_timer_set_multiplier(*(unsigned int *)(v46 + 2928));
    }
    multiplier = qdf_timer_get_multiplier();
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: set timer multiplier: %u",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "hdd_context_create",
      multiplier);
    v56 = cfg_psoc_get_values(*(_QWORD *)v19);
    cds_set_fatal_event(*(unsigned __int8 *)(v56 + 7477), v57, v58, v59);
    if ( (unsigned int)enable_dfs_chan_scan <= 1 )
    {
      wlan_scan_cfg_set_dfs_chan_scan_allowed(*(_QWORD *)v19, enable_dfs_chan_scan != 0);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Module enable_dfs_chan_scan set to %d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "hdd_override_ini_config",
        (unsigned int)enable_dfs_chan_scan);
    }
    if ( (unsigned int)enable_11d <= 1 && (unsigned int)wlan_mlme_set_11d_enabled(*(_QWORD *)v19, enable_11d != 0) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set 11d_enable flag",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "hdd_override_ini_config");
    *(_DWORD *)(v19 + 856) = 1;
    *(_BYTE *)(v19 + 852) = 6;
    *(_DWORD *)(v19 + 152) = 0;
    _init_swait_queue_head(v19 + 160, "&x->wait", &init_completion___key_1);
    *(_DWORD *)(v19 + 496) = 0;
    _init_swait_queue_head(v19 + 504, "&x->wait", &init_completion___key_1);
    *(_DWORD *)(v19 + 1432) = 0;
    *(_QWORD *)(v19 + 1440) = 0;
    *(_DWORD *)(v19 + 32) = 0;
    *(_QWORD *)(v19 + 40) = 0;
    *(_QWORD *)(v19 + 48) = v19 + 48;
    *(_QWORD *)(v19 + 56) = v19 + 48;
    *(_QWORD *)(v19 + 64) = 0;
    v21 = hdd_scan_context_init(v19);
    if ( !v21 )
    {
      v21 = hdd_sap_context_init(v19);
      if ( !v21 )
      {
        v21 = ucfg_dp_bbm_context_init(*(_QWORD *)v19);
        if ( !v21 )
        {
          _mutex_init(v19 + 1304, "&hdd_ctx->op_ctx.op_lock", &hdd_init_offloaded_packets_ctx___key);
          v84 = *(_QWORD *)(v19 + 96);
          *(_BYTE *)(v19 + 1268) = 1;
          v85 = *(_QWORD *)(v19 + 24);
          *(_BYTE *)(v19 + 1276) = 2;
          *(_BYTE *)(v19 + 1284) = 3;
          *(_BYTE *)(v19 + 1292) = 4;
          *(_DWORD *)(v19 + 1256) = -1;
          *(_DWORD *)(v19 + 1264) = -1;
          *(_DWORD *)(v19 + 1272) = -1;
          *(_DWORD *)(v19 + 1280) = -1;
          *(_DWORD *)(v19 + 1288) = -1;
          *(_DWORD *)(v19 + 1296) = -1;
          *(_BYTE *)(v19 + 1300) = 5;
          *(_BYTE *)(v19 + 1260) = 0;
          v94 = wlan_hdd_cfg80211_init(v84, v85, v86, v87, v88, v89, v90, v91, v92, v93);
          if ( !v94 )
          {
            _qdf_wake_lock_create((_QWORD *)(v19 + 3288), (__int64)"monitor_mode_wakelock");
            *(_BYTE *)(v19 + 8296) = 0;
            *(_QWORD *)(v19 + 8280) = hdd_lpc_work_handler;
            *(_QWORD *)(v19 + 8248) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v19 + 8288) = v19;
            *(_QWORD *)(v19 + 8256) = v19 + 8256;
            *(_QWORD *)(v19 + 8264) = v19 + 8256;
            *(_BYTE *)(v19 + 8312) = 0;
            v96 = curr_con_mode == 8;
            *(_QWORD *)(v19 + 8272) = _qdf_defer_func;
            if ( !v96 )
            {
              cds_set_multicast_logging(*(unsigned __int8 *)(*(_QWORD *)(v19 + 104) + 29LL));
              inited = hdd_init_netlink_services(v19);
              if ( inited )
              {
                v21 = inited;
                hdd_context_deinit(v19);
LABEL_32:
                hdd_objmgr_release_and_destroy_psoc(v19);
                goto LABEL_33;
              }
              hdd_set_wlan_logging(v19);
              *(_DWORD *)(v19 + 6872) = 0;
            }
            v98 = hdd_set_trace_level_for_each(v19);
            cds_set_context(0x33u, v19, v99, v100, v98, v101, v102, v103, v104, v105, v106, v107);
            wlan_hdd_sar_timers_init(v19);
            qdf_trace_msg(0x33u, 8u, "%s: exit", v108, v109, v110, v111, v112, v113, v114, v115, "hdd_context_create");
            return v19;
          }
          v21 = v94;
          ucfg_dp_bbm_context_deinit(*(_QWORD *)v19);
        }
        hdd_sap_context_destroy(v19);
      }
      hdd_scan_context_destroy(v19);
    }
    if ( *(_DWORD *)(v19 + 64) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "qdf_list_destroy");
    goto LABEL_32;
  }
  return -12;
}
