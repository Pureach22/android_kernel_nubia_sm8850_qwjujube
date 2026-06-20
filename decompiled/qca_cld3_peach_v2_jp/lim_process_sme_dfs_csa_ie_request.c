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
  unsigned int v31; // w21
  __int16 input_punc_bitmap; // w0
  unsigned int v33; // w22
  int v34; // w27
  __int16 v35; // w24
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w25
  char v54; // w8
  bool v55; // cc
  int v56; // w25
  unsigned int v57; // w1
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 result; // x0
  char v75; // w9
  __int16 v76; // w10
  bool is_vdev_ll_lt_sap; // w24
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  char v86; // w8
  int v87; // w8
  char v88; // w10
  int v89; // w1
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
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
  _BYTE v115[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v116; // [xsp+18h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v115[0] = 0;
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
    goto LABEL_47;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, a2 + 9, v115);
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
    goto LABEL_47;
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
    goto LABEL_47;
  }
  v22 = (_BYTE *)(session_by_bssid + 7170);
  qdf_mem_set((void *)(session_by_bssid + 7200), 0x20u, 0);
  *(_BYTE *)(v21 + 7208) = wlan_reg_freq_to_chan(
                             *(_QWORD *)(a1 + 21560),
                             *(_DWORD *)(a2 + 4),
                             v23,
                             v24,
                             v25,
                             v26,
                             v27,
                             v28,
                             v29,
                             v30);
  v31 = *(_DWORD *)(a2 + 4);
  *(_BYTE *)(v21 + 7282) = 1;
  *(_DWORD *)(v21 + 7204) = v31;
  input_punc_bitmap = wlan_reg_get_input_punc_bitmap();
  v33 = *(_DWORD *)(a2 + 16);
  v34 = *(_DWORD *)(a2 + 28);
  v35 = input_punc_bitmap;
  wlan_reg_set_non_eht_ch_params();
  v44 = wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 21560),
          *(_DWORD *)(a2 + 4),
          0,
          a2 + 16,
          0,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43);
  v53 = *(_DWORD *)(a2 + 16);
  if ( v53 >= 3 && (unsigned int)wma_get_vht_ch_width(v44) < 2 )
    v53 = 2;
  *(_BYTE *)(v21 + 7225) = *(_BYTE *)(a2 + 20);
  *(_BYTE *)(v21 + 7226) = *(_BYTE *)(a2 + 21);
  v54 = *(_BYTE *)(a2 + 22);
  *(_DWORD *)(v21 + 7228) = v53;
  *(_BYTE *)(v21 + 7227) = v54;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: legacy BW %d CCFS0 %d, CCFS1 %d",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "lim_process_sme_dfs_csa_ie_request",
    v53,
    *(unsigned __int8 *)(a2 + 21),
    *(unsigned __int8 *)(a2 + 22));
  if ( v35 )
    v55 = 1;
  else
    v55 = v33 > 3;
  v56 = v55;
  if ( v56 == 1 )
  {
    qdf_mem_set((void *)(a2 + 16), 0x10u, 0);
    *(_DWORD *)(a2 + 16) = v33;
    v57 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 28) = v34;
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21560),
      v57,
      0,
      a2 + 16,
      0,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65);
    *(_DWORD *)(v21 + 7212) = *(_DWORD *)(a2 + 16);
    *(_BYTE *)(v21 + 7211) = *(_BYTE *)(a2 + 20);
    *(_BYTE *)(v21 + 7209) = *(_BYTE *)(a2 + 21);
    *(_BYTE *)(v21 + 7210) = *(_BYTE *)(a2 + 22);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: EHT BW %d CCFS0 %d, CCFS1 %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "lim_process_sme_dfs_csa_ie_request",
      *(unsigned int *)(a2 + 16),
      *(unsigned __int8 *)(a2 + 21));
  }
  else
  {
    v75 = *(_BYTE *)(v21 + 7225);
    v76 = *(_WORD *)(v21 + 7226);
    *(_DWORD *)(v21 + 7212) = *(_DWORD *)(v21 + 7228);
    *(_BYTE *)(v21 + 7211) = v75;
    *(_WORD *)(v21 + 7209) = v76;
  }
  is_vdev_ll_lt_sap = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v21 + 10));
  if ( is_vdev_ll_lt_sap )
  {
    v86 = 0;
    *(_BYTE *)(v21 + 7216) = 0;
LABEL_23:
    *(_BYTE *)(v21 + 7224) = v86;
    goto LABEL_24;
  }
  *(_BYTE *)(v21 + 7216) = *(_BYTE *)(a2 + 32);
  if ( !*(_BYTE *)(a1 + 14811) )
  {
    v86 = *(_BYTE *)(a2 + 33);
    goto LABEL_23;
  }
LABEL_24:
  if ( *v22 || *(_BYTE *)(v21 + 8676) == 1 )
  {
    v87 = *(_DWORD *)(v21 + 7228);
    if ( v87 <= 1 )
    {
      if ( (unsigned int)v87 <= 1 )
      {
        *(_BYTE *)(v21 + 7283) = 0;
        *(_BYTE *)(v21 + 7187) = 0;
        goto LABEL_37;
      }
    }
    else
    {
      switch ( v87 )
      {
        case 2:
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7187) = 1;
          goto LABEL_37;
        case 3:
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7187) = 2;
          goto LABEL_37;
        case 4:
          v88 = *(_BYTE *)(v21 + 7227);
          *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7187) = 3;
          *(_BYTE *)(v21 + 7189) = v88;
LABEL_37:
          if ( v56 )
            *(_BYTE *)(v21 + 7283) = 1;
          *(_BYTE *)(v21 + 7188) = *(_BYTE *)(v21 + 7226);
          goto LABEL_40;
      }
    }
    *(_BYTE *)(v21 + 7283) = 0;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid Channel Width",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "lim_process_sme_dfs_csa_ie_request");
    goto LABEL_37;
  }
LABEL_40:
  qdf_wake_lock_timeout_acquire(v21 + 8400, 5000);
  qdf_runtime_pm_prevent_suspend((__int64 *)(v21 + 8600));
  v89 = *(_DWORD *)(a2 + 36);
  v90 = *(_QWORD *)(v21 + 16);
  *(_DWORD *)(v21 + 10048) = v89;
  wlan_util_vdev_mgr_set_cac_timeout_for_vdev(v90, v89);
  if ( is_vdev_ll_lt_sap )
  {
    wlan_ll_sap_reset_target_tsf_before_csa(*(_QWORD *)(a1 + 21552), *(_QWORD *)(v21 + 16));
    if ( (unsigned __int8)wlan_vdev_get_peer_sta_count(*(_QWORD *)(v21 + 16)) )
    {
      result = wlan_ll_sap_get_tsf_stats_before_csa(*(_QWORD *)(a1 + 21552), *(_QWORD *)(v21 + 16));
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Peer count is 0 for LL_LT_SAP, continue CSA directly",
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
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
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
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
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "lim_process_sme_dfs_csa_ie_request",
      (unsigned int)*(char *)(v21 + 7216),
      *(unsigned __int8 *)(v21 + 7208),
      *(unsigned int *)(v21 + 7204),
      *(unsigned int *)(v21 + 7212),
      *(unsigned __int8 *)(v21 + 7283),
      *(unsigned __int8 *)(v21 + 7211));
    result = send_extended_chan_switch_action_frame(a1, v31, v33);
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
