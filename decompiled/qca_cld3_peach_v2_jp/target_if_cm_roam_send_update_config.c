__int64 __fastcall target_if_cm_roam_send_update_config(
        __int64 a1,
        char *a2,
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
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  const char *v34; // x2
  __int64 result; // x0
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w0
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x4
  const char *v56; // x2
  __int64 v57; // x9
  __int64 v58; // x0
  unsigned int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w22
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // [xsp+0h] [xbp-30h]

  _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(a1 + 152);
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
    qdf_trace_msg(0x49u, 2u, v34, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    result = 16;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id:%d, first_bcnt: %d, final_bcnt: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_cm_roam_scan_bmiss_cnt",
    *(unsigned int *)a2,
    (unsigned __int8)a2[4],
    (unsigned __int8)a2[5]);
  v15 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v15 )
  {
    v24 = v15;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_cm_roam_scan_bmiss_cnt");
    v33 = "%s: vdev set bmiss bcnt param failed";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "target_if_cm_roam_send_update_config");
LABEL_12:
    result = v24;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id %d bmiss_timeout_onwakeup: %dsec, bmiss_timeout_onsleep: %dsec",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "target_if_cm_roam_scan_bmiss_timeout",
    *((unsigned int *)a2 + 2),
    (unsigned __int8)a2[12],
    (unsigned __int8)a2[13]);
  v36 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v36 )
  {
    v24 = v36;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "target_if_cm_roam_scan_bmiss_timeout");
    v33 = "%s: vdev set bmiss timeout param failed";
    goto LABEL_11;
  }
  v45 = target_if_cm_roam_scan_filter(v12, 4, a2 + 16);
  if ( v45 )
  {
    v33 = "%s: Sending update for roam scan filter failed";
LABEL_18:
    v24 = v45;
    goto LABEL_11;
  }
  v45 = target_if_cm_roam_scan_offload_rssi_thresh(v12, a2 + 3944, v25, v26, v27, v28, v29, v30, v31, v32);
  if ( v45 )
  {
    v33 = "%s: Sending roam scan offload rssi thresh failed";
    goto LABEL_18;
  }
  if ( !*((_DWORD *)a2 + 257) || (result = target_if_cm_roam_scan_offload_scan_period(v12, a2 + 1024), !(_DWORD)result) )
  {
    v46 = wmi_unified_roam_scan_offload_rssi_change_cmd(v12, a2 + 1056);
    if ( v46 )
    {
      v55 = *((unsigned int *)a2 + 264);
      v56 = "%s: vdev:%d Sending rssi change threshold failed";
    }
    else
    {
      result = target_if_cm_roam_scan_offload_ap_profile(a1, v12, a2 + 3028);
      if ( (_DWORD)result )
        goto LABEL_13;
      v46 = wmi_unified_roam_scan_offload_chan_list_cmd(v12, a2 + 3532);
      if ( !v46 )
      {
        v57 = *(_QWORD *)(a1 + 152);
        if ( !v57 || (v58 = *(_QWORD *)(v57 + 80)) == 0 )
        {
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: psoc handle is NULL",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "target_if_cm_roam_send_update_config");
          result = 4;
          goto LABEL_13;
        }
        v85 = *(_QWORD *)(v57 + 80);
        if ( (unsigned int)mlme_get_roam_state(v58, *(unsigned __int8 *)(a1 + 104)) == 2 )
        {
          v59 = wmi_unified_roam_scan_offload_mode_cmd(v12, a2 + 1072);
          if ( v59 )
          {
            v68 = v59;
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: vdev:%d Send RSO mode cmd failed",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "target_if_cm_roam_send_update_config",
              *((unsigned int *)a2 + 268),
              v85);
            result = v68;
            goto LABEL_13;
          }
          target_if_cm_roam_disconnect_params(v12, 4, a2 + 4052);
          target_if_cm_roam_idle_params(v12, 4, a2 + 4064);
          target_if_cm_roam_triggers(a1, a2 + 4092);
          if ( a2[4316] )
            target_if_cm_roam_rt_stats_config(a1, v69, v70, v71, v72, v73, v74, v75, v76);
          if ( *((_WORD *)a2 + 2159) )
            target_if_cm_roam_ho_delay_config(a1, v69, v70, v71, v72, v73, v74, v75, v76);
          if ( a2[4320] )
            target_if_cm_exclude_rm_partial_scan_freq(a1, v69, v70, v71, v72, v73, v74, v75, v76);
          if ( a2[4321] )
            target_if_cm_roam_full_scan_6ghz_on_disc(a1, v69, v70, v71, v72, v73, v74, v75, v76);
          wlan_cm_same_band_sta_allowed(v85);
          target_if_cm_roam_mcc_disallow(a1, v77, v78, v79, v80, v81, v82, v83, v84);
          if ( a2[4322] )
            target_if_cm_roam_rssi_diff_6ghz(a1);
          if ( a2[4323] )
            target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz(a1);
        }
        result = 0;
        goto LABEL_13;
      }
      v55 = *((unsigned int *)a2 + 883);
      v56 = "%s: vdev:%d Send channel list command failed";
    }
    v24 = v46;
    qdf_trace_msg(0x49u, 2u, v56, v47, v48, v49, v50, v51, v52, v53, v54, "target_if_cm_roam_send_update_config", v55);
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
