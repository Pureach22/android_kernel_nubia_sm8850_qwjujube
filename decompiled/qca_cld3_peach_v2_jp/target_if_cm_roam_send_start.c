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
  int v36; // w8
  int v37; // w9
  int v38; // w8
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  int v51; // w8
  int v52; // w9
  int v53; // w8
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w6
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x8
  _QWORD *v73; // x8
  const char *v74; // x2
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x4
  const char *v85; // x2
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // w0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int v103; // w22
  const char *v104; // x2
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int v114; // w23
  unsigned int v115; // w0
  unsigned int v116; // w0
  unsigned int v117; // w0
  __int64 v118; // x8
  __int64 v119; // x22
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // [xsp+0h] [xbp-30h] BYREF
  __int64 v137; // [xsp+8h] [xbp-28h]
  int *v138; // [xsp+10h] [xbp-20h]
  int v139; // [xsp+18h] [xbp-18h] BYREF
  int v140; // [xsp+1Ch] [xbp-14h]
  int v141; // [xsp+20h] [xbp-10h]
  int v142; // [xsp+24h] [xbp-Ch]
  __int64 v143; // [xsp+28h] [xbp-8h]

  v143 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 152);
  BYTE4(v136) = 0;
  LOBYTE(v136) = 0;
  if ( !v10 )
  {
    v34 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v34 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v34, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev", v136);
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
      v136,
      v137,
      v138);
LABEL_14:
    result = v33;
    goto LABEL_15;
  }
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
    *(unsigned int *)(a2 + 108),
    *(unsigned __int8 *)(a2 + 112),
    *(unsigned __int8 *)(a2 + 113),
    v136,
    0);
  v36 = *(unsigned __int8 *)(a2 + 112);
  v139 = 18;
  v140 = v36;
  v37 = *(unsigned __int8 *)(a2 + 113);
  v38 = *(_DWORD *)(a2 + 108);
  LODWORD(v137) = 1;
  v141 = 19;
  v142 = v37;
  BYTE5(v137) = v38;
  BYTE6(v137) = 2;
  v138 = &v139;
  v39 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v39 )
  {
    v33 = v39;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "target_if_cm_roam_scan_bmiss_cnt");
    v32 = "%s: vdev set bmiss bcnt param failed";
    goto LABEL_13;
  }
  v48 = *(unsigned int *)(a2 + 116);
  v49 = *(unsigned __int8 *)(a2 + 120);
  v50 = *(unsigned __int8 *)(a2 + 121);
  v137 = 0;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id %d bmiss_timeout_onwakeup: %dsec, bmiss_timeout_onsleep: %dsec",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "target_if_cm_roam_scan_bmiss_timeout",
    v48,
    v49,
    v50);
  v51 = *(unsigned __int8 *)(a2 + 120);
  LODWORD(v137) = 1;
  v139 = 183;
  v140 = v51;
  v52 = *(unsigned __int8 *)(a2 + 121);
  v53 = *(_DWORD *)(a2 + 116);
  BYTE6(v137) = 2;
  v141 = 184;
  v142 = v52;
  BYTE5(v137) = v53;
  v138 = &v139;
  v54 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v54 )
  {
    v33 = v54;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "target_if_cm_roam_scan_bmiss_timeout");
    v32 = "%s: vdev set bmiss timeout param failed";
    goto LABEL_13;
  }
  v63 = *(unsigned __int8 *)(a2 + 128);
  if ( (unsigned __int8)*(_DWORD *)(a2 + 124) >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev_id: %d is invalid, reject the req: param id %d val %d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "target_if_vdev_set_param");
    goto LABEL_20;
  }
  v139 = *(_DWORD *)(a2 + 124);
  v140 = 157;
  v141 = v63;
  if ( (unsigned int)wmi_unified_vdev_set_param_send(v12) )
LABEL_20:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set vdev param %d",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "target_if_cm_roam_reason_vsie",
      157);
  v72 = *(_QWORD *)(a1 + 152);
  if ( v72 )
  {
    v73 = *(_QWORD **)(v72 + 1232);
    if ( v73 && *v73 )
    {
      if ( *(unsigned __int8 *)(a2 + 132) <= 5u )
        wmi_unified_set_roam_triggers();
      goto LABEL_29;
    }
    v74 = "%s: wmi_handle is null";
  }
  else
  {
    v74 = "%s: PDEV is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v74, v64, v65, v66, v67, v68, v69, v70, v71, "target_if_cm_roam_get_wmi_handle_from_vdev");
LABEL_29:
  if ( !*(_DWORD *)(a2 + 360) )
    goto LABEL_32;
  if ( (unsigned __int8)*(_DWORD *)(a2 + 356) >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid vdev id:%d",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "target_if_cm_roam_scan_offload_scan_period");
    result = 16;
    goto LABEL_15;
  }
  result = wmi_unified_roam_scan_offload_scan_period(v12, a2 + 356);
  if ( !(_DWORD)result )
  {
LABEL_32:
    v75 = wmi_unified_roam_scan_offload_rssi_change_cmd(v12, a2 + 2344);
    if ( v75 )
    {
      v84 = *(unsigned int *)(a2 + 2344);
      v85 = "%s: vdev:%d Sending rssi change threshold failed";
LABEL_34:
      v33 = v75;
LABEL_35:
      qdf_trace_msg(0x49u, 2u, v85, v76, v77, v78, v79, v80, v81, v82, v83, "target_if_cm_roam_send_start", v84);
      goto LABEL_14;
    }
    result = target_if_cm_roam_scan_offload_ap_profile(a1, v12, a2 + 2360);
    if ( (_DWORD)result )
      goto LABEL_15;
    v75 = wmi_unified_roam_scan_offload_chan_list_cmd(v12, a2 + 2864);
    if ( v75 )
    {
      v84 = *(unsigned int *)(a2 + 2864);
      v85 = "%s: vdev:%d Send channel list command failed";
      goto LABEL_34;
    }
    if ( (wmi_service_enabled(v12, 0x91u, v76, v77, v78, v79, v80, v81, v82, v83) & 1) != 0 )
    {
      v94 = target_if_cm_roam_scan_mawc_params(v12, a2 + 3276);
      if ( v94 )
      {
        v103 = v94;
        v104 = "%s: Sending roaming MAWC params failed";
LABEL_50:
        qdf_trace_msg(0x49u, 2u, v104, v95, v96, v97, v98, v99, v100, v101, v102, "target_if_cm_roam_send_start");
        result = v103;
        goto LABEL_15;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: MAWC roaming not supported by firmware",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "target_if_cm_roam_send_start");
    }
    v105 = wmi_unified_roam_scan_offload_mode_cmd(v12, a2 + 388);
    if ( v105 )
    {
      v114 = v105;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: vdev:%d Send RSO mode cmd failed",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "target_if_cm_roam_send_start",
        *(unsigned int *)(a2 + 388));
      result = v114;
      goto LABEL_15;
    }
    v115 = target_if_cm_roam_scan_filter(v12, 1, a2 + 3296);
    if ( v115 )
    {
      v103 = v115;
      v104 = "%s: Sending start for roam scan filter failed";
      goto LABEL_50;
    }
    v116 = wmi_unified_send_btm_config(v12, a2 + 4304);
    if ( v116 )
    {
      v103 = v116;
      v104 = "%s: Sending BTM config to fw failed";
      goto LABEL_50;
    }
    v117 = target_if_cm_roam_offload_11k_params(v12, a2 + 4336);
    if ( v117 )
    {
      v85 = "%s: 11k offload enable not sent, status %d";
      v33 = v117;
      v84 = v117;
      goto LABEL_35;
    }
    v118 = *(_QWORD *)(a1 + 152);
    if ( v118 && (v119 = *(_QWORD *)(v118 + 80)) != 0 )
    {
      wlan_mlme_get_bss_load_enabled(*(_QWORD *)(v118 + 80), (_BYTE *)&v136 + 4);
      if ( BYTE4(v136) == 1 )
        target_if_cm_roam_bss_load_config(v12, a2 + 4404);
      target_if_cm_roam_disconnect_params(v12, 1, a2 + 4432);
      target_if_cm_roam_idle_params(v12, 1, a2 + 4444);
      wlan_psoc_mlme_get_11be_capab(v119, (bool *)&v136);
      if ( *(_BYTE *)(a2 + 4472) )
        target_if_cm_roam_rt_stats_config(a1, v120, v121, v122, v123, v124, v125, v126, v127);
      if ( *(_WORD *)(a2 + 4496) )
        target_if_cm_roam_ho_delay_config(a1, v120, v121, v122, v123, v124, v125, v126, v127);
      if ( *(_BYTE *)(a2 + 4498) )
        target_if_cm_exclude_rm_partial_scan_freq(a1, v120, v121, v122, v123, v124, v125, v126, v127);
      if ( *(_BYTE *)(a2 + 4499) )
        target_if_cm_roam_full_scan_6ghz_on_disc(a1, v120, v121, v122, v123, v124, v125, v126, v127);
      wlan_cm_same_band_sta_allowed(v119);
      target_if_cm_roam_mcc_disallow(a1, v128, v129, v130, v131, v132, v133, v134, v135);
      if ( *(_BYTE *)(a2 + 4500) )
        target_if_cm_roam_rssi_diff_6ghz(a1);
      if ( *(_BYTE *)(a2 + 4501) )
        target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz(a1);
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc handle is NULL",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "target_if_cm_roam_send_start");
      result = 4;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
