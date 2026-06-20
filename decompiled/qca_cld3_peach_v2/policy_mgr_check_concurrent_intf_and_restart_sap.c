__int64 __fastcall policy_mgr_check_concurrent_intf_and_restart_sap(__int64 a1, char a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int mode_specific_conn_info; // w22
  unsigned int v24; // w23
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  char is_sta_sap_scc_allowed_on_dfs_chan; // w26
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x2
  char is_hw_dbs_capable; // w23
  char sta_sap_scc_allowed_on_indoor_chnl; // w25
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w24
  unsigned int mcc_to_scc_switch_mode; // w25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 result; // x0
  __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w20
  unsigned int v84; // w1
  unsigned int v85; // [xsp+14h] [xbp-2Ch] BYREF
  int v86; // [xsp+18h] [xbp-28h] BYREF
  char v87; // [xsp+1Ch] [xbp-24h]
  _QWORD v88[2]; // [xsp+20h] [xbp-20h] BYREF
  int v89; // [xsp+30h] [xbp-10h]
  __int64 v90; // [xsp+38h] [xbp-8h]

  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = 0;
  v88[0] = 0;
  v88[1] = 0;
  v87 = 0;
  v85 = 0;
  v86 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v22 = "%s: Invalid context";
LABEL_45:
    v84 = 2;
    goto LABEL_46;
  }
  v13 = context;
  if ( !*(_QWORD *)(context + 2096) )
  {
    v22 = "%s: Invalid sta_ap_intf_check_work_info";
    goto LABEL_45;
  }
  if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, 0)
    && !(unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, 0) )
  {
    v22 = "%s: No action taken at check_concurrent_intf_and_restart_sap";
LABEL_43:
    v84 = 8;
LABEL_46:
    result = qdf_trace_msg(
               0x4Fu,
               v84,
               v22,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "policy_mgr_check_concurrent_intf_and_restart_sap");
    goto LABEL_47;
  }
  if ( (_policy_mgr_is_ll_lt_sap_restart_required(a1, "policy_mgr_check_concurrent_intf_and_restart_sap") & 1) != 0 )
    goto LABEL_37;
  if ( (policy_mgr_is_sap_restart_required_after_sta_disconnect(a1, 255, &v85, a2 & 1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: move the SAP to configured channel %u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "policy_mgr_check_concurrent_intf_and_restart_sap",
      v85);
    goto LABEL_37;
  }
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, v88, &v86, 0);
  if ( !mode_specific_conn_info )
    goto LABEL_26;
  v24 = v88[0];
  v25 = policy_mgr_get_context(a1);
  if ( v25 )
  {
    v34 = v25;
    is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v34 + 8), v24, v36, v37, v38, v39, v40, v41, v42, v43) & 1) != 0
      && (is_sta_sap_scc_allowed_on_dfs_chan & 1) != 0 )
    {
      v52 = "%s: STA, SAP SCC is allowed on DFS chan %u";
LABEL_20:
      qdf_trace_msg(0x4Fu, 8u, v52, v44, v45, v46, v47, v48, v49, v50, v51, "policy_mgr_valid_sta_channel_check", v24);
      is_hw_dbs_capable = 1;
      goto LABEL_27;
    }
    sta_sap_scc_allowed_on_indoor_chnl = policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1);
    if ( (wlan_reg_is_freq_indoor() & 1) != 0 && (sta_sap_scc_allowed_on_indoor_chnl & 1) != 0 )
    {
      v52 = "%s: STA, SAP SCC is allowed on indoor chan %u";
      goto LABEL_20;
    }
    if ( !(is_sta_sap_scc_allowed_on_dfs_chan & 1
         | ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(v34 + 8), v24, v44, v45, v46, v47, v48, v49, v50, v51) & 1) == 0))
      || wlan_reg_is_passive_or_disable_for_pwrmode(
           *(_QWORD *)(v34 + 8),
           v24,
           0,
           v55,
           v56,
           v57,
           v58,
           v59,
           v60,
           v61,
           v62)
      || !(sta_sap_scc_allowed_on_indoor_chnl & 1 | ((wlan_reg_is_freq_indoor() & 1) == 0))
      || (policy_mgr_sta_sap_scc_on_lte_coex_chan(a1) & 1) == 0
      && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, v24) & 1) == 0 )
    {
      is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
      goto LABEL_27;
    }
LABEL_26:
    is_hw_dbs_capable = 1;
    goto LABEL_27;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid context",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "policy_mgr_valid_sta_channel_check");
  is_hw_dbs_capable = 0;
LABEL_27:
  v63 = policy_mgr_get_mode_specific_conn_info(a1, v88, &v86, 2);
  mcc_to_scc_switch_mode = policy_mgr_get_mcc_to_scc_switch_mode(a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: MCC to SCC switch: %d chan: %d sta_count: %d  sta_check: %d, gc_check: %d",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "policy_mgr_check_concurrent_intf_and_restart_sap",
    mcc_to_scc_switch_mode,
    LODWORD(v88[0]),
    mode_specific_conn_info,
    is_hw_dbs_capable & 1,
    v63 != 0);
  result = policy_mgr_get_mode_specific_conn_info(a1, v88, &v86, 1);
  if ( a1 )
  {
    if ( (_DWORD)result == 1 && (a2 & 1) == 0 )
    {
      v74 = *(_QWORD *)(a1 + 2800);
      if ( v74 )
      {
        if ( (*(_BYTE *)(v74 + 994) & 2) != 0 )
        {
          result = ((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, LODWORD(v88[0]));
          if ( (result & 1) == 0 )
          {
            result = qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "%s: Avoid channel switch as it's allowed to operate on unsafe channel: %d",
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       "policy_mgr_check_concurrent_intf_and_restart_sap",
                       LODWORD(v88[0]));
            goto LABEL_47;
          }
        }
      }
    }
  }
  if ( !mcc_to_scc_switch_mode )
    goto LABEL_47;
  if ( !(is_hw_dbs_capable & 1 | (v63 != 0)) )
  {
    if ( !mode_specific_conn_info )
      goto LABEL_47;
    result = policy_mgr_is_hw_dbs_capable(a1);
    if ( (result & 1) != 0 )
      goto LABEL_47;
  }
LABEL_37:
  if ( !*(_QWORD *)(v13 + 2096) )
  {
    v22 = "%s: invalid sta_ap_intf_check_work_info";
    goto LABEL_45;
  }
  if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, 0) )
    v83 = 3000;
  else
    v83 = 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Queue check interface work with timeout %d",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    "policy_mgr_check_concurrent_intf_and_restart_sap",
    v83);
  result = _qdf_delayed_work_start(v13 + 1008, v83);
  if ( (result & 1) == 0 )
  {
    v22 = "%s: change interface request already queued";
    goto LABEL_43;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
