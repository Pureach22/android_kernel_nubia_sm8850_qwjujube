__int64 __fastcall target_if_cm_roam_send_start(
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
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  unsigned int v33; // w19
  const char *v34; // x2
  __int64 result; // x0
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  int v39; // w8
  int v40; // w9
  int v41; // w8
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x6
  int v54; // w8
  int v55; // w9
  int v56; // w8
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int v66; // w6
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  _QWORD *v76; // x8
  const char *v77; // x2
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x4
  const char *v88; // x2
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int v97; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w22
  const char *v107; // x2
  unsigned int v108; // w0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w23
  unsigned int v118; // w0
  unsigned int v119; // w0
  unsigned int v120; // w0
  __int64 v121; // x8
  __int64 v122; // x22
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  __int64 v139; // [xsp+0h] [xbp-30h] BYREF
  __int64 v140; // [xsp+8h] [xbp-28h]
  int *v141; // [xsp+10h] [xbp-20h]
  int v142; // [xsp+18h] [xbp-18h] BYREF
  int v143; // [xsp+1Ch] [xbp-14h]
  int v144; // [xsp+20h] [xbp-10h]
  int v145; // [xsp+24h] [xbp-Ch]
  __int64 v146; // [xsp+28h] [xbp-8h]

  v146 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  BYTE4(v139) = 0;
  LOBYTE(v139) = 0;
  if ( !v10 )
  {
    v34 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v34 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v34, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev", v139);
    result = 16;
    goto LABEL_15;
  }
  wmi_send_time_stamp_sync_cmd_tlv(*v11);
  v23 = target_if_cm_roam_scan_offload_rssi_thresh(v12, (char *)a2, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( v23 )
  {
    v32 = "%s: Sending roam scan offload rssi thresh failed";
    v33 = v23;
LABEL_13:
    qdf_trace_msg(
      0x49u,
      2u,
      v32,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "target_if_cm_roam_send_start",
      v139,
      v140,
      v141);
LABEL_14:
    result = v33;
    goto LABEL_15;
  }
  v36 = *(unsigned int *)(a2 + 108);
  v37 = *(unsigned __int8 *)(a2 + 112);
  v38 = *(unsigned __int8 *)(a2 + 113);
  v140 = 0;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id:%d, first_bcnt: %d, final_bcnt: %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "target_if_cm_roam_scan_bmiss_cnt",
    v36,
    v37,
    v38);
  v39 = *(unsigned __int8 *)(a2 + 112);
  v142 = 18;
  v143 = v39;
  v40 = *(unsigned __int8 *)(a2 + 113);
  v41 = *(_DWORD *)(a2 + 108);
  LODWORD(v140) = 1;
  v144 = 19;
  v145 = v40;
  BYTE5(v140) = v41;
  BYTE6(v140) = 2;
  v141 = &v142;
  v42 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v42 )
  {
    v33 = v42;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "target_if_cm_roam_scan_bmiss_cnt");
    v32 = "%s: vdev set bmiss bcnt param failed";
    goto LABEL_13;
  }
  v51 = *(unsigned int *)(a2 + 116);
  v52 = *(unsigned __int8 *)(a2 + 120);
  v53 = *(unsigned __int8 *)(a2 + 121);
  v140 = 0;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id %d bmiss_timeout_onwakeup: %dsec, bmiss_timeout_onsleep: %dsec",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "target_if_cm_roam_scan_bmiss_timeout",
    v51,
    v52,
    v53);
  v54 = *(unsigned __int8 *)(a2 + 120);
  LODWORD(v140) = 1;
  v142 = 183;
  v143 = v54;
  v55 = *(unsigned __int8 *)(a2 + 121);
  v56 = *(_DWORD *)(a2 + 116);
  BYTE6(v140) = 2;
  v144 = 184;
  v145 = v55;
  BYTE5(v140) = v56;
  v141 = &v142;
  v57 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v57 )
  {
    v33 = v57;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "target_if_cm_roam_scan_bmiss_timeout");
    v32 = "%s: vdev set bmiss timeout param failed";
    goto LABEL_13;
  }
  v66 = *(unsigned __int8 *)(a2 + 128);
  if ( (unsigned __int8)*(_DWORD *)(a2 + 124) >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev_id: %d is invalid, reject the req: param id %d val %d",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "target_if_vdev_set_param");
    goto LABEL_20;
  }
  v142 = *(_DWORD *)(a2 + 124);
  v143 = 157;
  v144 = v66;
  if ( (unsigned int)wmi_unified_vdev_set_param_send(v12) )
LABEL_20:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set vdev param %d",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "target_if_cm_roam_reason_vsie",
      157,
      v139,
      v140,
      v141);
  v75 = *(_QWORD *)(a1 + 216);
  if ( v75 )
  {
    v76 = *(_QWORD **)(v75 + 1240);
    if ( v76 && *v76 )
    {
      if ( *(unsigned __int8 *)(a2 + 132) <= 5u )
        wmi_unified_set_roam_triggers();
      goto LABEL_29;
    }
    v77 = "%s: wmi_handle is null";
  }
  else
  {
    v77 = "%s: PDEV is NULL";
  }
  qdf_trace_msg(
    0x49u,
    2u,
    v77,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    "target_if_cm_roam_get_wmi_handle_from_vdev",
    v139);
LABEL_29:
  if ( !*(_DWORD *)(a2 + 360) )
    goto LABEL_32;
  if ( (unsigned __int8)*(_DWORD *)(a2 + 356) >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid vdev id:%d",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "target_if_cm_roam_scan_offload_scan_period");
    result = 16;
    goto LABEL_15;
  }
  result = wmi_unified_roam_scan_offload_scan_period(v12, a2 + 356);
  if ( !(_DWORD)result )
  {
LABEL_32:
    v78 = wmi_unified_roam_scan_offload_rssi_change_cmd(v12, a2 + 2344);
    if ( v78 )
    {
      v87 = *(unsigned int *)(a2 + 2344);
      v88 = "%s: vdev:%d Sending rssi change threshold failed";
LABEL_34:
      v33 = v78;
LABEL_35:
      qdf_trace_msg(0x49u, 2u, v88, v79, v80, v81, v82, v83, v84, v85, v86, "target_if_cm_roam_send_start", v87, v139);
      goto LABEL_14;
    }
    result = target_if_cm_roam_scan_offload_ap_profile(a1, v12, a2 + 2360);
    if ( (_DWORD)result )
      goto LABEL_15;
    v78 = wmi_unified_roam_scan_offload_chan_list_cmd(v12, a2 + 2872);
    if ( v78 )
    {
      v87 = *(unsigned int *)(a2 + 2872);
      v88 = "%s: vdev:%d Send channel list command failed";
      goto LABEL_34;
    }
    if ( (wmi_service_enabled(v12, 0x91u, v79, v80, v81, v82, v83, v84, v85, v86) & 1) != 0 )
    {
      v97 = target_if_cm_roam_scan_mawc_params(v12, a2 + 3284);
      if ( v97 )
      {
        v106 = v97;
        v107 = "%s: Sending roaming MAWC params failed";
LABEL_50:
        qdf_trace_msg(
          0x49u,
          2u,
          v107,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "target_if_cm_roam_send_start",
          v139);
        result = v106;
        goto LABEL_15;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: MAWC roaming not supported by firmware",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "target_if_cm_roam_send_start");
    }
    v108 = wmi_unified_roam_scan_offload_mode_cmd(v12, a2 + 388);
    if ( v108 )
    {
      v117 = v108;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: vdev:%d Send RSO mode cmd failed",
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        "target_if_cm_roam_send_start",
        *(unsigned int *)(a2 + 388));
      result = v117;
      goto LABEL_15;
    }
    v118 = target_if_cm_roam_scan_filter(v12, 1, a2 + 3304);
    if ( v118 )
    {
      v106 = v118;
      v107 = "%s: Sending start for roam scan filter failed";
      goto LABEL_50;
    }
    v119 = wmi_unified_send_btm_config(v12, a2 + 4792);
    if ( v119 )
    {
      v106 = v119;
      v107 = "%s: Sending BTM config to fw failed";
      goto LABEL_50;
    }
    v120 = target_if_cm_roam_offload_11k_params(v12, a2 + 4824);
    if ( v120 )
    {
      v88 = "%s: 11k offload enable not sent, status %d";
      v33 = v120;
      v87 = v120;
      goto LABEL_35;
    }
    v121 = *(_QWORD *)(a1 + 216);
    if ( v121 && (v122 = *(_QWORD *)(v121 + 80)) != 0 )
    {
      wlan_mlme_get_bss_load_enabled(*(_QWORD *)(v121 + 80), (_BYTE *)&v139 + 4);
      if ( BYTE4(v139) == 1 )
        target_if_cm_roam_bss_load_config(v12, a2 + 4892);
      target_if_cm_roam_disconnect_params(v12, 1, a2 + 4920);
      target_if_cm_roam_idle_params(v12, 1, a2 + 4932);
      wlan_psoc_mlme_get_11be_capab(v122, (bool *)&v139);
      if ( (unsigned __int8)v139 == 1 )
        target_if_cm_roam_send_mlo_config(a1, a2 + 4964);
      if ( *(_BYTE *)(a2 + 4960) )
        target_if_cm_roam_rt_stats_config(a1, v123, v124, v125, v126, v127, v128, v129, v130);
      if ( *(_WORD *)(a2 + 4984) )
        target_if_cm_roam_ho_delay_config(a1, v123, v124, v125, v126, v127, v128, v129, v130);
      if ( *(_BYTE *)(a2 + 4986) )
        target_if_cm_exclude_rm_partial_scan_freq(a1, v123, v124, v125, v126, v127, v128, v129, v130);
      if ( *(_BYTE *)(a2 + 4987) )
        target_if_cm_roam_full_scan_6ghz_on_disc(a1, v123, v124, v125, v126, v127, v128, v129, v130);
      wlan_cm_same_band_sta_allowed(v122);
      target_if_cm_roam_mcc_disallow(a1, v131, v132, v133, v134, v135, v136, v137, v138);
      if ( *(_BYTE *)(a2 + 4988) )
        target_if_cm_roam_rssi_diff_6ghz(a1);
      if ( *(_BYTE *)(a2 + 4989) )
        target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz(a1);
      result = target_if_cm_roam_oem_eht_mlo_bitmap(a1);
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc handle is NULL",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "target_if_cm_roam_send_start",
        v139);
      result = 4;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
