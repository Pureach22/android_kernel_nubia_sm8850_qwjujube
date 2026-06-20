__int64 __fastcall wlan_hdd_cfg80211_register_frames(
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
  __int64 v10; // x8
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  unsigned int v31; // w0
  unsigned int v32; // w19
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w20
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7

  if ( a1 && (v10 = *(_QWORD *)(a1 + 24)) != 0 )
    v11 = *(_QWORD *)(v10 + 16);
  else
    v11 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_register_frames");
  if ( *(_DWORD *)(a1 + 40) == 4 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: No need to register frames in FTM mode",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_cfg80211_register_frames");
    return 0;
  }
  if ( !v11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: mac_handle is NULL, failed to register frames",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_cfg80211_register_frames");
    v31 = 4;
    return qdf_status_to_os_return(v31);
  }
  v21 = sme_register_mgmt_frame_ind_callback(v11, hdd_indicate_mgmt_frame);
  if ( v21 )
  {
    v30 = "%s: Failed to register hdd_indicate_mgmt_frame";
LABEL_13:
    v32 = v21;
    qdf_trace_msg(0x33u, 2u, v30, v22, v23, v24, v25, v26, v27, v28, v29, "wlan_hdd_cfg80211_register_frames");
    v31 = v32;
    return qdf_status_to_os_return(v31);
  }
  v21 = sme_register_mgmt_frame(v11, 50, 208, &unk_A3C94B, 2);
  if ( v21 )
  {
    v30 = "%s: Failed to register GAS_INITIAL_REQ";
    goto LABEL_13;
  }
  v33 = sme_register_mgmt_frame(v11, 50, 208, &unk_95CB17, 2);
  if ( v33 )
  {
    v42 = v33;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to register GAS_INITIAL_RSP",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wlan_hdd_cfg80211_register_frames");
LABEL_29:
    sme_deregister_mgmt_frame(v11, 50, 208, &unk_A3C94B, 2);
    v31 = v42;
    return qdf_status_to_os_return(v31);
  }
  v43 = sme_register_mgmt_frame(v11, 50, 208, &unk_9379B8, 2);
  if ( v43 )
  {
    v42 = v43;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to register GAS_COMEBACK_REQ",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "wlan_hdd_cfg80211_register_frames");
LABEL_28:
    sme_deregister_mgmt_frame(v11, 50, 208, &unk_95CB17, 2);
    goto LABEL_29;
  }
  v52 = sme_register_mgmt_frame(v11, 50, 208, &unk_9CCE51, 2);
  if ( v52 )
  {
    v42 = v52;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to register GAS_COMEBACK_RSP",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wlan_hdd_cfg80211_register_frames");
LABEL_27:
    sme_deregister_mgmt_frame(v11, 50, 208, &unk_9379B8, 2);
    goto LABEL_28;
  }
  v61 = sme_register_mgmt_frame(v11, 50, 208, "\n\a", 2);
  if ( v61 )
  {
    v42 = v61;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to register WNM_BSS_ACTION_FRAME",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wlan_hdd_cfg80211_register_frames");
LABEL_26:
    sme_deregister_mgmt_frame(v11, 50, 208, &unk_9CCE51, 2);
    goto LABEL_27;
  }
  result = sme_register_mgmt_frame(v11, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 208, &unk_A24094, 2);
  if ( (_DWORD)result )
  {
    v42 = result;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to register WNM_NOTIFICATION_FRAME",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "wlan_hdd_cfg80211_register_frames");
    sme_deregister_mgmt_frame(v11, 50, 208, "\n\a", 2);
    goto LABEL_26;
  }
  return result;
}
