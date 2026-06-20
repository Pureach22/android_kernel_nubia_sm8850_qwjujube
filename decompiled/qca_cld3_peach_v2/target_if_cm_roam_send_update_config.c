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
  int v15; // w8
  int v16; // w9
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  const char *v36; // x2
  __int64 result; // x0
  int v38; // w8
  int v39; // w9
  unsigned int v40; // w8
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  unsigned int v51; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x4
  const char *v61; // x2
  __int64 v62; // x9
  __int64 v63; // x0
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w24
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // [xsp+0h] [xbp-30h]
  __int64 v91; // [xsp+8h] [xbp-28h]
  int v92; // [xsp+18h] [xbp-18h] BYREF
  int v93; // [xsp+1Ch] [xbp-14h]
  int v94; // [xsp+20h] [xbp-10h]
  int v95; // [xsp+24h] [xbp-Ch]
  __int64 v96; // [xsp+28h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v36 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v36 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v36, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
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
  v15 = (unsigned __int8)a2[4];
  v92 = 18;
  v93 = v15;
  v16 = (unsigned __int8)a2[5];
  v94 = 19;
  v95 = v16;
  v17 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v17 )
  {
    v26 = v17;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_cm_roam_scan_bmiss_cnt");
    v35 = "%s: vdev set bmiss bcnt param failed";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "target_if_cm_roam_send_update_config");
LABEL_12:
    result = v26;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id %d bmiss_timeout_onwakeup: %dsec, bmiss_timeout_onsleep: %dsec",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "target_if_cm_roam_scan_bmiss_timeout",
    *((unsigned int *)a2 + 2),
    (unsigned __int8)a2[12],
    (unsigned __int8)a2[13]);
  v38 = (unsigned __int8)a2[12];
  v91 = 0x2000000000001LL;
  v92 = 183;
  v93 = v38;
  v39 = (unsigned __int8)a2[13];
  v40 = *((_DWORD *)a2 + 2);
  v94 = 184;
  v95 = v39;
  BYTE5(v91) = v40;
  v41 = wmi_unified_multiple_vdev_param_send(v12);
  if ( v41 )
  {
    v26 = v41;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to set bmiss first,final bcntset params",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "target_if_cm_roam_scan_bmiss_timeout");
    v35 = "%s: vdev set bmiss timeout param failed";
    goto LABEL_11;
  }
  v50 = target_if_cm_roam_scan_filter(v12, 4, a2 + 16);
  if ( v50 )
  {
    v35 = "%s: Sending update for roam scan filter failed";
LABEL_18:
    v26 = v50;
    goto LABEL_11;
  }
  v50 = target_if_cm_roam_scan_offload_rssi_thresh(v12, a2 + 4432, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( v50 )
  {
    v35 = "%s: Sending roam scan offload rssi thresh failed";
    goto LABEL_18;
  }
  if ( !*((_DWORD *)a2 + 377) || (result = target_if_cm_roam_scan_offload_scan_period(v12, a2 + 1504), !(_DWORD)result) )
  {
    v51 = wmi_unified_roam_scan_offload_rssi_change_cmd(v12, a2 + 1536);
    if ( v51 )
    {
      v60 = *((unsigned int *)a2 + 384);
      v61 = "%s: vdev:%d Sending rssi change threshold failed";
LABEL_23:
      v26 = v51;
      qdf_trace_msg(0x49u, 2u, v61, v52, v53, v54, v55, v56, v57, v58, v59, "target_if_cm_roam_send_update_config", v60);
      goto LABEL_12;
    }
    result = target_if_cm_roam_scan_offload_ap_profile(a1, v12, a2 + 3508);
    if ( (_DWORD)result )
      goto LABEL_13;
    v51 = wmi_unified_roam_scan_offload_chan_list_cmd(v12, a2 + 4020);
    if ( v51 )
    {
      v60 = *((unsigned int *)a2 + 1005);
      v61 = "%s: vdev:%d Send channel list command failed";
      goto LABEL_23;
    }
    v62 = *(_QWORD *)(a1 + 216);
    if ( v62 && (v63 = *(_QWORD *)(v62 + 80)) != 0 )
    {
      v90 = *(_QWORD *)(v62 + 80);
      if ( (unsigned int)mlme_get_roam_state(v63, *(unsigned __int8 *)(a1 + 168)) == 2 )
      {
        v64 = wmi_unified_roam_scan_offload_mode_cmd(v12, a2 + 1552);
        if ( v64 )
        {
          v73 = v64;
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: vdev:%d Send RSO mode cmd failed",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "target_if_cm_roam_send_update_config",
            *((unsigned int *)a2 + 388),
            v90,
            v91,
            &v92);
          result = v73;
        }
        else
        {
          target_if_cm_roam_disconnect_params(v12, 4, a2 + 4540);
          target_if_cm_roam_idle_params(v12, 4, a2 + 4552);
          target_if_cm_roam_triggers(a1, a2 + 4580);
          if ( a2[4804] )
            target_if_cm_roam_rt_stats_config(a1, v74, v75, v76, v77, v78, v79, v80, v81);
          if ( *((_WORD *)a2 + 2403) )
            target_if_cm_roam_ho_delay_config(a1, v74, v75, v76, v77, v78, v79, v80, v81);
          if ( a2[4808] )
            target_if_cm_exclude_rm_partial_scan_freq(a1, v74, v75, v76, v77, v78, v79, v80, v81);
          if ( a2[4809] )
            target_if_cm_roam_full_scan_6ghz_on_disc(a1, v74, v75, v76, v77, v78, v79, v80, v81);
          wlan_cm_same_band_sta_allowed(v90);
          target_if_cm_roam_mcc_disallow(a1, v82, v83, v84, v85, v86, v87, v88, v89);
          if ( a2[4810] )
            target_if_cm_roam_rssi_diff_6ghz(a1);
          if ( a2[4811] )
            target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz(a1);
          result = target_if_cm_roam_oem_eht_mlo_bitmap(a1);
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc handle is NULL",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "target_if_cm_roam_send_update_config");
      result = 4;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
