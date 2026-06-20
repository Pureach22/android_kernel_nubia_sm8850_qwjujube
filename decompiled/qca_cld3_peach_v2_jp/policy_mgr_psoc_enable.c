__int64 __fastcall policy_mgr_psoc_enable(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  unsigned int inited; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  __int64 result; // x0
  unsigned int v23; // w19
  __int64 (__fastcall *v24)(__int64); // x8
  bool is_2x2_1x1_dbs_capable; // w0
  void *v26; // x20
  void *v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  void *v36; // x9
  const char *v37; // x2
  void *v38; // x9
  bool is_hw_dbs_2x2_capable; // w0
  void *v40; // x8
  char is_hw_dbs_capable; // w20
  char is_hw_sbs_capable; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  bool v51; // w20
  bool is_hw_dbs_required_for_band; // w22
  bool v53; // w23
  bool is_2x2_5G_1x1_2G_dbs_capable; // w24
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  _BOOL4 is_2x2_2G_1x1_5G_dbs_capable; // [xsp+0h] [xbp-20h]
  char v64[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+18h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_psoc_enable");
    result = 16;
    goto LABEL_14;
  }
  v11 = context;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Initializing the policy manager",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "policy_mgr_psoc_enable");
  qdf_mem_set(&pm_conc_connection_list, 0xB4u, 0);
  policy_mgr_clear_concurrent_session_count(a1);
  *(_BYTE *)(v11 + 2661) = 0;
  inited = qdf_mc_timer_init(v11 + 120, 0, (__int64)pm_dbs_opportunistic_timer_handler, a1);
  if ( inited )
  {
    v21 = "%s: Failed to init DBS opportunistic timer";
LABEL_13:
    v23 = inited;
    qdf_trace_msg(0x4Fu, 2u, v21, v13, v14, v15, v16, v17, v18, v19, v20, "policy_mgr_psoc_enable");
    result = v23;
    goto LABEL_14;
  }
  inited = policy_mgr_init_connection_update(v11);
  if ( inited )
  {
    v21 = "%s: connection_update_done_evt init failed";
    goto LABEL_13;
  }
  inited = qdf_event_create((_DWORD *)(v11 + 2112));
  if ( inited )
  {
    v21 = "%s: opportunistic_update_done_evt init failed";
    goto LABEL_13;
  }
  inited = qdf_event_create((_DWORD *)(v11 + 2152));
  if ( inited )
  {
    v21 = "%s: channel_switch_complete_evt init failed";
    goto LABEL_13;
  }
  policy_mgr_get_mcc_adaptive_sch(a1, v64);
  policy_mgr_set_dynamic_mcc_adaptive_sch(a1, v64[0]);
  *(_DWORD *)(v11 + 1668) = 0;
  inited = policy_mgr_reset_sap_mandatory_channels(a1);
  if ( inited )
  {
    v21 = "%s: failed to reset mandatory channels";
    goto LABEL_13;
  }
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1) || policy_mgr_is_hw_dbs_required_for_band(a1, 1) )
  {
    v24 = policy_mgr_get_current_pref_hw_mode_dbs_2x2;
  }
  else
  {
    is_2x2_1x1_dbs_capable = policy_mgr_is_2x2_1x1_dbs_capable(a1);
    v24 = policy_mgr_get_current_pref_hw_mode_dbs_1x1;
    if ( is_2x2_1x1_dbs_capable )
      v24 = policy_mgr_get_current_pref_hw_mode_dual_dbs;
  }
  policy_mgr_get_current_pref_hw_mode_ptr = v24;
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1) && (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
  {
    v26 = &pm_second_connection_pcl_dbs_sbs_2x2_table;
  }
  else if ( policy_mgr_is_hw_dbs_2x2_capable(a1) )
  {
    v26 = &pm_second_connection_pcl_dbs_2x2_table;
  }
  else
  {
    v26 = &pm_second_connection_pcl_dbs_2x2_table;
    if ( !policy_mgr_is_hw_dbs_required_for_band(a1, 1) && !policy_mgr_is_2x2_1x1_dbs_capable(a1) )
      v26 = &pm_second_connection_pcl_dbs_1x1_table;
  }
  second_connection_pcl_dbs_table = (__int64)v26;
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1) && (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
  {
    v27 = &pm_third_connection_pcl_dbs_sbs_2x2_table;
  }
  else if ( policy_mgr_is_hw_dbs_2x2_capable(a1) )
  {
    v27 = &pm_third_connection_pcl_dbs_2x2_table;
  }
  else
  {
    v27 = &pm_third_connection_pcl_dbs_2x2_table;
    if ( !policy_mgr_is_hw_dbs_required_for_band(a1, 1) && !policy_mgr_is_2x2_1x1_dbs_capable(a1) )
      v27 = &pm_third_connection_pcl_dbs_1x1_table;
  }
  third_connection_pcl_dbs_table = (__int64)v27;
  policy_mgr_init_non_dbs_pcl(a1);
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1) )
  {
    if ( policy_mgr_is_hw_dbs_required_for_band(a1, 1) )
    {
      v36 = &pm_next_action_two_connection_dbs_2x2_table;
      v37 = "%s: using hst/hsp policy manager table";
    }
    else
    {
      v36 = &pm_next_action_two_connection_dbs_2x2_table_v2;
      v37 = "%s: using hmt policy manager table";
    }
    next_action_two_connection_table = (__int64)v36;
    qdf_trace_msg(0x4Fu, 8u, v37, v28, v29, v30, v31, v32, v33, v34, v35, "policy_mgr_psoc_enable");
  }
  else if ( policy_mgr_is_2x2_1x1_dbs_capable(a1) )
  {
    next_action_two_connection_table = (__int64)&pm_next_action_two_connection_dbs_2x2_5g_1x1_2g_table;
    next_action_two_connection_2x2_2g_1x1_5g_table = (__int64)&pm_next_action_two_connection_dbs_2x2_2g_1x1_5g_table;
  }
  else
  {
    next_action_two_connection_table = (__int64)&pm_next_action_two_connection_dbs_1x1_table;
  }
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1) || policy_mgr_is_hw_dbs_required_for_band(a1, 1) )
  {
    v38 = &pm_next_action_three_connection_dbs_2x2_table;
  }
  else
  {
    if ( policy_mgr_is_2x2_1x1_dbs_capable(a1) )
    {
      next_action_three_connection_table = (__int64)&pm_next_action_three_connection_dbs_2x2_5g_1x1_2g_table;
      next_action_three_connection_2x2_2g_1x1_5g_table = (__int64)&pm_next_action_three_connection_dbs_2x2_2g_1x1_5g_table;
      goto LABEL_48;
    }
    v38 = &pm_next_action_three_connection_dbs_1x1_table;
  }
  next_action_three_connection_table = (__int64)v38;
LABEL_48:
  is_hw_dbs_2x2_capable = policy_mgr_is_hw_dbs_2x2_capable(a1);
  v40 = &pm_next_action_four_connection_dbs_2x2_table;
  if ( !is_hw_dbs_2x2_capable )
    v40 = nullptr;
  next_action_four_connection_table = (__int64)v40;
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: is DBS Capable %d, is SBS Capable %d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "policy_mgr_psoc_enable",
    is_hw_dbs_capable & 1,
    is_hw_sbs_capable & 1);
  v51 = policy_mgr_is_hw_dbs_2x2_capable(a1);
  is_hw_dbs_required_for_band = policy_mgr_is_hw_dbs_required_for_band(a1, 1);
  v53 = policy_mgr_is_2x2_1x1_dbs_capable(a1);
  is_2x2_5G_1x1_2G_dbs_capable = policy_mgr_is_2x2_5G_1x1_2G_dbs_capable(a1);
  is_2x2_2G_1x1_5G_dbs_capable = policy_mgr_is_2x2_2G_1x1_5G_dbs_capable(a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: is2x2 %d, 2g-on-dbs %d is2x2+1x1 %d, is2x2_5g+1x1_2g %d, is2x2_2g+1x1_5g %d",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "policy_mgr_psoc_enable",
    v51,
    is_hw_dbs_required_for_band,
    v53,
    is_2x2_5G_1x1_2G_dbs_capable,
    is_2x2_2G_1x1_5G_dbs_capable);
  policy_mgr_init_5g_low_high_cut_freq(a1);
  policy_mgr_init_rd_type(a1);
  policy_mgr_update_dfs_master_dynamic_enabled(a1, 1, nullptr);
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
