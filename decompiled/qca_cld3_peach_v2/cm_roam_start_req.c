__int64 __fastcall cm_roam_start_req(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 rso_config_fl; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x25
  __int64 v29; // x24
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x26
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  char is_any_sta_dfs_ap_scc_by_vdev_id; // w0
  char v50; // w8
  char v51; // w9
  unsigned int started; // w20
  char v53; // w8
  int v54; // w5
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 psoc_ext_obj_fl; // x0
  unsigned int v64; // w24
  _DWORD *v65; // x23
  __int64 v66; // x0
  int v67; // w8
  unsigned int v68; // w25
  char assoc_btm_cap; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  char v87; // w8
  __int64 cmpt_obj; // x0
  size_t v89; // x2
  int v91; // w25
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  char btm_abridge_flag; // w25
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x5
  __int64 v110; // [xsp+0h] [xbp-50h] BYREF
  __int64 v111; // [xsp+8h] [xbp-48h]
  __int64 v112; // [xsp+10h] [xbp-40h]
  __int64 v113; // [xsp+18h] [xbp-38h]
  __int64 v114; // [xsp+20h] [xbp-30h] BYREF
  __int64 v115; // [xsp+28h] [xbp-28h]
  __int64 v116; // [xsp+30h] [xbp-20h]
  __int64 v117; // [xsp+38h] [xbp-18h]
  char v118[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v119; // [xsp+48h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v112 = 0;
  v113 = 0;
  v110 = 0;
  v111 = 0;
  v6 = _qdf_mem_malloc(0x1380u, "cm_roam_start_req", 3631);
  if ( v6 )
  {
    v7 = v6;
    v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
    if ( !v8 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_roam_start_req",
        (unsigned __int8)a2);
      started = 4;
LABEL_49:
      _qdf_mem_free(v7);
      goto LABEL_50;
    }
    v17 = v8;
    rso_config_fl = wlan_cm_get_rso_config_fl(v8, "cm_roam_start_req", 3641);
    if ( !rso_config_fl || (v28 = *(_QWORD *)(v17 + 216)) == 0 )
    {
      started = 4;
LABEL_48:
      wlan_objmgr_vdev_release_ref(v17, 0x4Du, v19, v20, v21, v22, v23, v24, v25, v26, v27);
      goto LABEL_49;
    }
    v29 = rso_config_fl;
    v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
    if ( v30 )
    {
      v39 = v30;
      mlme_set_roam_reason_better_ap(v30, 0, v31, v32, v33, v34, v35, v36, v37, v38);
      wlan_objmgr_vdev_release_ref(v39, 2u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
    }
    LOBYTE(v114) = 0;
    v118[0] = 0;
    *(_DWORD *)(v7 + 108) = (unsigned __int8)a2;
    wlan_mlme_get_roam_bmiss_first_bcnt(a1, (char *)&v114);
    wlan_mlme_get_roam_bmiss_final_bcnt(a1, v118);
    is_any_sta_dfs_ap_scc_by_vdev_id = policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(a1, a2);
    v50 = v114;
    if ( (is_any_sta_dfs_ap_scc_by_vdev_id & 1) != 0 )
    {
      v51 = v118[0];
      if ( (unsigned __int8)v114 >= 2u )
        v50 = 2;
      if ( (unsigned __int8)v118[0] >= 5u )
        v51 = 5;
    }
    else
    {
      v51 = v118[0];
    }
    *(_BYTE *)(v7 + 112) = v50;
    *(_BYTE *)(v7 + 113) = v51;
    LOBYTE(v114) = 0;
    *(_DWORD *)(v7 + 116) = (unsigned __int8)a2;
    wlan_mlme_get_bmiss_timeout_on_wakeup(a1, (char *)&v114);
    *(_BYTE *)(v7 + 120) = v114;
    wlan_mlme_get_bmiss_timeout_on_sleep(a1, (char *)&v114);
    v53 = v114;
    LOBYTE(v114) = 0;
    *(_BYTE *)(v7 + 121) = v53;
    *(_DWORD *)(v7 + 124) = (unsigned __int8)a2;
    wlan_mlme_get_roam_reason_vsie_status(a1, &v114);
    *(_BYTE *)(v7 + 128) = v114;
    cm_roam_triggers(a1, a2, (_DWORD *)(v7 + 132));
    cm_roam_fill_rssi_change_params(a1, a2, (_DWORD *)(v7 + 2344));
    LOBYTE(v114) = 0;
    v118[0] = 0;
    *(_BYTE *)(v7 + 3284) = a2;
    wlan_mlme_get_mawc_enabled(a1, &v114);
    wlan_mlme_get_mawc_roam_enabled(a1, v118);
    *(_BYTE *)(v7 + 3285) = v114 & v118[0];
    wlan_mlme_get_mawc_roam_traffic_threshold(a1, (int *)(v7 + 3288));
    wlan_mlme_get_mawc_roam_ap_rssi_threshold(a1, (int *)(v7 + 3292));
    wlan_mlme_get_mawc_roam_rssi_high_adjust(a1, (char *)(v7 + 3296));
    wlan_mlme_get_mawc_roam_rssi_low_adjust(a1, (char *)(v7 + 3297));
    *(_DWORD *)(v7 + 4892) = (unsigned __int8)a2;
    wlan_mlme_get_bss_load_threshold(a1, (int *)(v7 + 4896));
    wlan_mlme_get_bss_load_sample_time(a1, (int *)(v7 + 4900));
    wlan_mlme_get_bss_load_alpha(a1, (int *)(v7 + 4904));
    wlan_mlme_get_bss_load_rssi_threshold_6ghz(a1, (int *)(v7 + 4908));
    wlan_mlme_get_bss_load_rssi_threshold_5ghz(a1, (int *)(v7 + 4912));
    wlan_mlme_get_bss_load_rssi_threshold_24ghz(a1, (int *)(v7 + 4916));
    cm_roam_disconnect_params(a1, a2, v7 + 4920);
    *(_DWORD *)(v7 + 4932) = (unsigned __int8)a2;
    wlan_mlme_get_enable_idle_roam(a1, (_BYTE *)(v7 + 4936));
    wlan_mlme_get_idle_roam_rssi_delta(a1, (int *)(v7 + 4944));
    wlan_mlme_get_idle_roam_inactive_time(a1, (int *)(v7 + 4952));
    wlan_mlme_get_idle_data_packet_count(a1, (int *)(v7 + 4956));
    wlan_mlme_get_idle_roam_min_rssi(a1, (int *)(v7 + 4948));
    wlan_mlme_get_idle_roam_band(a1, (_DWORD *)(v7 + 4940));
    if ( (*(_BYTE *)(v7 + 137) & 0x40) == 0 )
      *(_BYTE *)(v7 + 4936) = 0;
    cm_roam_scan_offload_rssi_thresh(a1, a2, v7, v29);
    *(_DWORD *)(v7 + 356) = (unsigned __int8)a2;
    v54 = *(unsigned __int16 *)(v29 + 146);
    *(_DWORD *)(v7 + 360) = v54;
    *(_DWORD *)(v7 + 364) = v54;
    *(_DWORD *)(v7 + 368) = 3 * v54;
    *(_DWORD *)(v7 + 372) = *(_DWORD *)(v29 + 196);
    *(_DWORD *)(v7 + 376) = *(_DWORD *)(v29 + 200);
    *(_DWORD *)(v7 + 380) = *(_DWORD *)(v29 + 184);
    *(_DWORD *)(v7 + 384) = *(_DWORD *)(v29 + 216);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: full_scan_period:%d, empty_scan_refresh_period:%d, roam_periodic_scan_interval %d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "cm_roam_scan_offload_scan_period");
    cm_roam_scan_offload_ap_profile(a1, v17, v29, v7 + 2360);
    cm_fill_rso_channel_list(a1, v17, v29, v7 + 2872, a3);
    cm_roam_scan_filter(a1, v28, a2, 1, a3, v7 + 3304);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))cm_roam_scan_offload_fill_rso_configs)(
      a1,
      v17,
      v29,
      v7 + 388,
      v7 + 2872,
      1,
      a3);
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( !psoc_ext_obj_fl )
    {
LABEL_26:
      v78 = mlme_get_psoc_ext_obj_fl(a1);
      if ( v78 )
      {
        *(_DWORD *)(v7 + 4824) = *(unsigned __int8 *)(v17 + 168);
        *(_DWORD *)(v7 + 4828) = *(_DWORD *)(v78 + 2724);
        if ( (*(_BYTE *)(v78 + 2728) & 0x3F) != 0 )
        {
          *(_QWORD *)(v7 + 4848) = -1;
          *(_QWORD *)(v7 + 4840) = -1;
          *(_QWORD *)(v7 + 4832) = -1;
          v87 = *(_BYTE *)(v78 + 2728);
          if ( (v87 & 1) != 0 )
          {
            *(_DWORD *)(v7 + 4832) = *(_DWORD *)(v78 + 2732);
            v87 = *(_BYTE *)(v78 + 2728);
            if ( (v87 & 2) == 0 )
            {
LABEL_30:
              if ( (v87 & 4) == 0 )
                goto LABEL_31;
              goto LABEL_41;
            }
          }
          else if ( (*(_BYTE *)(v78 + 2728) & 2) == 0 )
          {
            goto LABEL_30;
          }
          *(_DWORD *)(v7 + 4836) = *(_DWORD *)(v78 + 2736);
          v87 = *(_BYTE *)(v78 + 2728);
          if ( (v87 & 4) == 0 )
          {
LABEL_31:
            if ( (v87 & 8) == 0 )
              goto LABEL_32;
            goto LABEL_42;
          }
LABEL_41:
          *(_DWORD *)(v7 + 4840) = *(_DWORD *)(v78 + 2740);
          v87 = *(_BYTE *)(v78 + 2728);
          if ( (v87 & 8) == 0 )
          {
LABEL_32:
            if ( (v87 & 0x10) == 0 )
              goto LABEL_33;
            goto LABEL_43;
          }
LABEL_42:
          *(_DWORD *)(v7 + 4844) = *(_DWORD *)(v78 + 2744);
          v87 = *(_BYTE *)(v78 + 2728);
          if ( (v87 & 0x10) == 0 )
          {
LABEL_33:
            if ( (v87 & 0x20) == 0 )
              goto LABEL_35;
            goto LABEL_34;
          }
LABEL_43:
          *(_DWORD *)(v7 + 4848) = *(_DWORD *)(v78 + 2748);
          if ( (*(_BYTE *)(v78 + 2728) & 0x20) == 0 )
          {
LABEL_35:
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v17, v79, v80, v81, v82, v83, v84, v85, v86);
            if ( cmpt_obj )
            {
              v89 = *(unsigned __int8 *)(cmpt_obj + 178);
              if ( *(_BYTE *)(cmpt_obj + 178) )
              {
                *(_BYTE *)(v7 + 4856) = v89;
                qdf_mem_copy((void *)(v7 + 4857), (const void *)(cmpt_obj + 145), v89);
              }
              else
              {
                *(_BYTE *)(v7 + 4856) = 0;
              }
            }
            goto LABEL_46;
          }
LABEL_34:
          *(_DWORD *)(v7 + 4852) = *(_DWORD *)(v78 + 2752);
          goto LABEL_35;
        }
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: No valid neighbor report offload params %x",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "cm_roam_offload_11k_params");
        *(_DWORD *)(v7 + 4828) = 0;
      }
LABEL_46:
      *(_BYTE *)(v7 + 4960) = wlan_cm_get_roam_rt_stats(a1, 0);
      cm_roam_mlo_config(a1, v17, v7);
      *(_WORD *)(v7 + 4984) = wlan_cm_roam_get_ho_delay_config(a1);
      *(_BYTE *)(v7 + 4986) = wlan_cm_get_exclude_rm_partial_scan_freq(a1);
      *(_BYTE *)(v7 + 4987) = wlan_cm_roam_get_full_scan_6ghz_on_disc(a1);
      wlan_cm_roam_cfg_get_value(a1, a2, 29, (int)&v110);
      *(_BYTE *)(v7 + 4988) = v110;
      wlan_cm_roam_cfg_get_value(a1, a2, 30, (int)&v110);
      *(_BYTE *)(v7 + 4989) = v110;
      started = wlan_cm_tgt_send_roam_start_req(a1, a2, v7);
      if ( started )
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: fail to send roam start",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cm_roam_start_req");
      goto LABEL_48;
    }
    v64 = *(unsigned __int8 *)(v17 + 168);
    v65 = (_DWORD *)psoc_ext_obj_fl;
    *(_BYTE *)(v7 + 4792) = v64;
    v118[0] = 0;
    v116 = 0;
    v117 = 0;
    v114 = 0;
    v115 = 0;
    v66 = mlme_get_psoc_ext_obj_fl(a1);
    if ( v66 )
    {
      v67 = *(_DWORD *)(v66 + 5868);
      *(_DWORD *)(v7 + 4796) = v67;
      if ( v67 )
      {
        wlan_cm_roam_cfg_get_value(a1, v64, 31, (int)&v114);
        v68 = (unsigned __int8)v115;
        assoc_btm_cap = wlan_cm_get_assoc_btm_cap(a1, v64);
        if ( (assoc_btm_cap & 1) != 0 && !v68 )
        {
          wlan_cm_roam_cfg_get_value(a1, v64, 23, (int)&v114);
          v91 = (unsigned __int8)v115;
          wlan_mlme_is_hs_20_btm_offload_disabled(a1, v118);
          if ( v91 != 1 || v118[0] != 1 )
          {
            btm_abridge_flag = wlan_mlme_get_btm_abridge_flag(a1);
            if ( (btm_abridge_flag & 1) == 0 )
              *(_DWORD *)(v7 + 4796) &= ~0x80u;
            if ( cm_is_mbo_ap_without_pmf(a1, v64) )
            {
              v109 = 0;
              *(_DWORD *)(v7 + 4796) = 0;
            }
            else
            {
              v109 = *(unsigned int *)(v7 + 4796);
            }
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: Abridge flag: %d, btm offload: %u",
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              "cm_update_btm_offload_config",
              btm_abridge_flag & 1,
              v109,
              v110,
              v111,
              v112,
              v113);
            goto LABEL_25;
          }
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: RSO cmd: %d is_hs_20_ap:%d",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "cm_update_btm_offload_config",
            1,
            1);
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: disable btm offload vdev:%d btm_cap: %d is_btm: %d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "cm_update_btm_offload_config",
            v64,
            assoc_btm_cap & 1,
            v68,
            v110,
            v111,
            v112,
            v113);
        }
        *(_DWORD *)(v7 + 4796) = 0;
      }
    }
LABEL_25:
    *(_DWORD *)(v7 + 4800) = v65[1468];
    *(_DWORD *)(v7 + 4804) = v65[1469];
    *(_DWORD *)(v7 + 4808) = v65[1470];
    *(_DWORD *)(v7 + 4812) = v65[1472];
    *(_DWORD *)(v7 + 4816) = v65[1473];
    *(_DWORD *)(v7 + 4820) = v65[1474];
    goto LABEL_26;
  }
  started = 2;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return started;
}
