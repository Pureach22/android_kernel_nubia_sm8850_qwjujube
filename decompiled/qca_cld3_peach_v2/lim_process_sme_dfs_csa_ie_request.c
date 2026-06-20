__int64 __fastcall lim_process_sme_dfs_csa_ie_request(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_bssid; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  _BYTE *v22; // x26
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w0
  int v32; // w8
  unsigned int v33; // w21
  unsigned __int16 input_punc_bitmap; // w0
  unsigned int v35; // w22
  int v36; // w27
  unsigned __int16 v37; // w24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w25
  char v56; // w8
  bool v57; // cc
  int v58; // w25
  unsigned int v59; // w1
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
  __int64 result; // x0
  char v85; // w9
  __int16 v86; // w10
  bool is_vdev_ll_lt_sap; // w24
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  char v96; // w8
  int v97; // w8
  char v98; // w10
  int v99; // w1
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  _BYTE v125[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v126; // [xsp+18h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v125[0] = 0;
  if ( !a2 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Buffer is Pointing to NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_sme_dfs_csa_ie_request");
    goto LABEL_49;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, a2 + 9, v125);
  if ( !session_by_bssid )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session not found for given BSSID%02x:%02x:%02x:**:**:%02x",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "lim_process_sme_dfs_csa_ie_request",
               *(unsigned __int8 *)(a2 + 9),
               *(unsigned __int8 *)(a2 + 10),
               *(unsigned __int8 *)(a2 + 11),
               *(unsigned __int8 *)(a2 + 14));
    goto LABEL_49;
  }
  v21 = session_by_bssid;
  if ( *(_BYTE *)(session_by_bssid + 70) && *(_DWORD *)(session_by_bssid + 88) != 1 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Invalid SystemRole %d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "lim_process_sme_dfs_csa_ie_request");
    goto LABEL_49;
  }
  v22 = (_BYTE *)(session_by_bssid + 7170);
  qdf_mem_set((void *)(session_by_bssid + 7200), 0x20u, 0);
  v31 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a2 + 4), v23, v24, v25, v26, v27, v28, v29, v30);
  v32 = *(_DWORD *)(v21 + 88);
  *(_BYTE *)(v21 + 7208) = v31;
  v33 = *(_DWORD *)(a2 + 4);
  *(_BYTE *)(v21 + 7282) = 1;
  *(_DWORD *)(v21 + 7204) = v33;
  if ( v32 == 1 )
    lim_remove_puncture(a1, v21);
  input_punc_bitmap = wlan_reg_get_input_punc_bitmap(a2 + 16);
  v35 = *(_DWORD *)(a2 + 16);
  v36 = *(_DWORD *)(a2 + 28);
  v37 = input_punc_bitmap;
  wlan_reg_set_non_eht_ch_params(a2 + 16, 1);
  v46 = wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 21632),
          *(_DWORD *)(a2 + 4),
          0,
          a2 + 16,
          0,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45);
  v55 = *(_DWORD *)(a2 + 16);
  if ( v55 >= 3 && (unsigned int)wma_get_vht_ch_width(v46) < 2 )
    v55 = 2;
  *(_BYTE *)(v21 + 7225) = *(_BYTE *)(a2 + 20);
  *(_BYTE *)(v21 + 7226) = *(_BYTE *)(a2 + 21);
  v56 = *(_BYTE *)(a2 + 22);
  *(_DWORD *)(v21 + 7228) = v55;
  *(_BYTE *)(v21 + 7227) = v56;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: legacy BW %d CCFS0 %d, CCFS1 %d",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "lim_process_sme_dfs_csa_ie_request",
    v55,
    *(unsigned __int8 *)(a2 + 21),
    *(unsigned __int8 *)(a2 + 22));
  if ( v37 )
    v57 = 1;
  else
    v57 = v35 > 3;
  v58 = v57;
  if ( v58 == 1 )
  {
    qdf_mem_set((void *)(a2 + 16), 0x18u, 0);
    *(_DWORD *)(a2 + 16) = v35;
    v59 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 28) = v36;
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21632),
      v59,
      0,
      a2 + 16,
      0,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67);
    *(_DWORD *)(v21 + 7212) = *(_DWORD *)(a2 + 16);
    *(_BYTE *)(v21 + 7211) = *(_BYTE *)(a2 + 20);
    *(_BYTE *)(v21 + 7209) = *(_BYTE *)(a2 + 21);
    *(_BYTE *)(v21 + 7210) = *(_BYTE *)(a2 + 22);
    qdf_trace_msg(0x35u, 8u, "%s: 0x%x", v68, v69, v70, v71, v72, v73, v74, v75, "lim_set_chan_switch_puncture", v37);
    *(_WORD *)(v21 + 7216) = v37;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: EHT BW %d CCFS0 %d, CCFS1 %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "lim_process_sme_dfs_csa_ie_request",
      *(unsigned int *)(a2 + 16),
      *(unsigned __int8 *)(a2 + 21),
      *(unsigned __int8 *)(a2 + 22));
  }
  else
  {
    v85 = *(_BYTE *)(v21 + 7225);
    v86 = *(_WORD *)(v21 + 7226);
    *(_DWORD *)(v21 + 7212) = *(_DWORD *)(v21 + 7228);
    *(_BYTE *)(v21 + 7211) = v85;
    *(_WORD *)(v21 + 7209) = v86;
  }
  is_vdev_ll_lt_sap = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v21 + 10));
  if ( is_vdev_ll_lt_sap )
  {
    v96 = 0;
    *(_BYTE *)(v21 + 7218) = 0;
LABEL_25:
    *(_BYTE *)(v21 + 7224) = v96;
    goto LABEL_26;
  }
  *(_BYTE *)(v21 + 7218) = *(_BYTE *)(a2 + 40);
  if ( !*(_BYTE *)(a1 + 14883) )
  {
    v96 = *(_BYTE *)(a2 + 41);
    goto LABEL_25;
  }
LABEL_26:
  if ( *v22 || *(_BYTE *)(v21 + 8676) == 1 )
  {
    v97 = *(_DWORD *)(v21 + 7228);
    if ( v97 <= 1 )
    {
      if ( (unsigned int)v97 <= 1 )
      {
        *(_BYTE *)(v21 + 7283) = 0;
        *(_BYTE *)(v21 + 7189) = 0;
        goto LABEL_39;
      }
    }
    else
    {
      switch ( v97 )
      {
        case 2:
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7189) = 1;
          goto LABEL_39;
        case 3:
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7189) = 2;
          goto LABEL_39;
        case 4:
          v98 = *(_BYTE *)(v21 + 7227);
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7189) = 3;
          *(_BYTE *)(v21 + 7191) = v98;
LABEL_39:
          if ( v58 )
            *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7190) = *(_BYTE *)(v21 + 7226);
          goto LABEL_42;
      }
    }
    *(_BYTE *)(v21 + 7283) = 0;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid Channel Width",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "lim_process_sme_dfs_csa_ie_request");
    goto LABEL_39;
  }
LABEL_42:
  qdf_wake_lock_timeout_acquire(v21 + 8400, 5000);
  qdf_runtime_pm_prevent_suspend((__int64 *)(v21 + 8600));
  v99 = *(_DWORD *)(a2 + 44);
  v100 = *(_QWORD *)(v21 + 16);
  *(_DWORD *)(v21 + 10048) = v99;
  wlan_util_vdev_mgr_set_cac_timeout_for_vdev(v100, v99);
  if ( is_vdev_ll_lt_sap )
  {
    wlan_ll_sap_reset_target_tsf_before_csa(*(_QWORD *)(a1 + 21624), *(_QWORD *)(v21 + 16));
    if ( (unsigned __int8)wlan_vdev_get_peer_sta_count(*(_QWORD *)(v21 + 16)) )
    {
      result = wlan_ll_sap_get_tsf_stats_before_csa(*(_QWORD *)(a1 + 21624), *(_QWORD *)(v21 + 16));
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Peer count is 0 for LL_LT_SAP, continue CSA directly",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "lim_handle_ll_lt_sap_csa");
      lim_notify_channel_switch_started(a1, v21);
      result = lim_process_ap_ecsa_timeout(v21);
    }
  }
  else
  {
    lim_send_dfs_chan_sw_ie_update(a1, v21);
    lim_notify_channel_switch_started(a1, v21);
    if ( (unsigned int)qdf_mc_timer_start(v21 + 8232, 0xFA0u) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: cannot start ap_ecsa_timer",
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        "lim_process_sme_dfs_csa_ie_request");
    lim_cp_stats_cstats_log_csa_evt(
      v21,
      0,
      *(unsigned int *)(v21 + 7204),
      *(unsigned int *)(v21 + 7212),
      *(unsigned __int8 *)(v21 + 7224));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: IE count:%d chan:%d freq %d width:%d wrapper:%d ch_offset:%d",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "lim_process_sme_dfs_csa_ie_request",
      (unsigned int)*(char *)(v21 + 7218),
      *(unsigned __int8 *)(v21 + 7208),
      *(unsigned int *)(v21 + 7204),
      *(unsigned int *)(v21 + 7212),
      *(unsigned __int8 *)(v21 + 7283),
      *(unsigned __int8 *)(v21 + 7211));
    result = send_extended_chan_switch_action_frame(a1, v33, v35);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
