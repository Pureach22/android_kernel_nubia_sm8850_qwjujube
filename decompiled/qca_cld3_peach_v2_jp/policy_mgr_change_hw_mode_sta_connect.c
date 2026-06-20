__int64 __fastcall policy_mgr_change_hw_mode_sta_connect(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  char is_hwmode_offload_enabled; // w25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 context; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x25
  int v39; // w8
  unsigned int *v40; // x8
  const char *v41; // x2
  __int64 result; // x0
  _QWORD *v43; // x1
  __int64 v44; // x26
  unsigned int v45; // w25
  char is_hw_dbs_required_for_band; // w27
  bool is_24ghz_ch_freq; // w0
  __int64 ch_width_from_phymode; // x0
  unsigned int v49; // w28
  unsigned int bw; // w27
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // [xsp+8h] [xbp-28h] BYREF
  bool v69; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD *v70; // [xsp+10h] [xbp-20h] BYREF
  _QWORD *v71; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v72[2]; // [xsp+20h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = nullptr;
  v71 = nullptr;
  v69 = 0;
  v68 = 8;
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 24);
  if ( !v8 )
    goto LABEL_24;
  v9 = v8;
  is_hwmode_offload_enabled = policy_mgr_is_hwmode_offload_enabled(a1);
  if ( (is_hwmode_offload_enabled & 1) != 0 )
  {
    context = policy_mgr_get_context(a1);
    if ( context )
    {
      if ( *(_DWORD *)(context + 268) == 21 )
        qdf_mc_timer_stop(context + 120);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid context",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "policy_mgr_stop_opportunistic_timer");
    }
    wlan_psoc_mlme_get_11be_capab(a1, &v69);
    v40 = (unsigned int *)v69;
    if ( !v69 )
      goto LABEL_23;
    if ( (unsigned int)policy_mgr_get_sap_bw(a1, &v68) )
      goto LABEL_23;
    v40 = (unsigned int *)v68;
    if ( v68 != 7 )
      goto LABEL_23;
    v28 = 7;
    if ( !a2 )
      goto LABEL_20;
  }
  else
  {
    v28 = 8;
    if ( !a2 )
    {
LABEL_20:
      v41 = "%s: Scan list is NULL or No BSSIDs present";
LABEL_22:
      qdf_trace_msg(0x4Fu, 8u, v41, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_check_for_hw_mode_change");
LABEL_23:
      wlan_objmgr_vdev_release_ref(v9, 0x18u, v40, v11, v12, v13, v14, v15, v16, v17, v18);
LABEL_24:
      result = 6;
      goto LABEL_25;
    }
  }
  if ( !*(_DWORD *)(a2 + 16) )
    goto LABEL_20;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v41 = "%s: Driver isn't DBS capable";
    goto LABEL_22;
  }
  if ( (is_hwmode_offload_enabled & 1) == 0 )
  {
    v29 = policy_mgr_get_context(a1);
    if ( v29 )
    {
      v38 = v29;
      if ( (unsigned int)policy_mgr_get_connection_count(a1) == 1 )
      {
        v39 = *(_DWORD *)(v38 + 2228);
        if ( (unsigned int)(pm_conc_connection_list - 2) >= 2 )
        {
          if ( !(_DWORD)pm_conc_connection_list && (v39 & 1) == 0 )
            goto LABEL_52;
        }
        else if ( (v39 & 2) == 0 )
        {
LABEL_52:
          v41 = "%s: DBS not allowed for concurrency combo";
          goto LABEL_22;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid context",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "policy_mgr_is_dbs_allowed_for_concurrency");
    }
    if ( (policy_mgr_is_hw_dbs_2x2_capable(a1) & 1) == 0
      && (policy_mgr_is_hw_dbs_required_for_band(a1, 1) & 1) == 0
      && !(unsigned int)policy_mgr_get_connection_count(a1) )
    {
      v41 = "%s: 1x1 DBS with no existing connection, HW mode change not required";
      goto LABEL_22;
    }
  }
  qdf_list_peek_front((_QWORD *)a2, &v71);
  v43 = v71;
  if ( !v71 )
    goto LABEL_23;
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)a2, v43, &v70);
    v44 = v71[3];
    v45 = *(_DWORD *)(v44 + 1064);
    is_hw_dbs_required_for_band = policy_mgr_is_hw_dbs_required_for_band(a1, 1);
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v45);
    if ( (is_hw_dbs_required_for_band & 1) == 0 )
      break;
    if ( is_24ghz_ch_freq )
      goto LABEL_44;
LABEL_38:
    ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(*(unsigned int *)(v44 + 52));
    v49 = *(_DWORD *)(v44 + 1064);
    v72[0] = 0;
    bw = policy_mgr_get_bw(ch_width_from_phymode);
    if ( (policy_mgr_is_conn_lead_to_dbs_sbs(a1, a3, v49) & 1) != 0 )
    {
      policy_mgr_get_hw_dbs_max_bw(a1, v72);
      if ( bw > HIDWORD(v72[0]) && bw > LODWORD(v72[0]) )
        goto LABEL_44;
    }
    if ( (unsigned int)wlan_cm_bss_mlo_type() )
      goto LABEL_44;
    v43 = v70;
    v70 = nullptr;
    v71 = v43;
    if ( !v43 )
      goto LABEL_23;
  }
  if ( (!is_24ghz_ch_freq || (policy_mgr_is_any_mode_active_on_band_along_with_session(a1, a3, 1) & 1) == 0)
    && (!wlan_reg_is_5ghz_ch_freq(v45) || (policy_mgr_is_any_mode_active_on_band_along_with_session(a1, a3, 0) & 1) == 0) )
  {
    goto LABEL_38;
  }
LABEL_44:
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Scan list has BSS of freq %d hw mode/SAP ch_width:%d update required",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "policy_mgr_check_for_hw_mode_change",
    v45,
    v28);
  wlan_objmgr_vdev_release_ref(v9, 0x18u, v51, v52, v53, v54, v55, v56, v57, v58, v59);
  if ( !v45 )
    goto LABEL_24;
  LODWORD(result) = policy_mgr_current_connections_update(a1, (unsigned __int8)a3, v45, 0xEu, a4);
  if ( (_DWORD)result == 16 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Hw mode change failed",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "policy_mgr_change_hw_mode_sta_connect");
    result = 16;
  }
  else if ( (_DWORD)result == 11 )
  {
    result = 6;
  }
  else
  {
    result = (unsigned int)result;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
