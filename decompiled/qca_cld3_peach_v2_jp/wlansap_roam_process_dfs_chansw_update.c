__int64 __fastcall wlansap_roam_process_dfs_chansw_update(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *sap_ch_sw_info; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int *v24; // x23
  unsigned __int8 is_conc_sap_doing_scc_dfs; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  __int64 v35; // x22
  __int64 v36; // x22
  __int64 v37; // x22
  __int64 v38; // x22
  __int64 v39; // x21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  sap_ch_sw_info = (unsigned int *)wlan_get_sap_ch_sw_info(*(_QWORD *)(a2 + 16), a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !sap_ch_sw_info )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: Invalid channel info",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wlansap_roam_process_dfs_chansw_update");
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3169LL) == 1 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: sapdfs: DFS channel switch disabled",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlansap_roam_process_dfs_chansw_update");
    wlan_pre_cac_complete_set(*(_QWORD *)(a2 + 16), 0);
    result = sme_roam_start_beacon_req(
               a1,
               *(unsigned int *)(a2 + 816) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 820) << 32),
               1);
    *a3 = result;
    return result;
  }
  if ( *(_DWORD *)(a2 + 728) != 2 )
    return qdf_trace_msg(
             0x39u,
             3u,
             "%s: eCSR_ROAM_RESULT_DFS_RADAR_FOUND_IND received in (%d) state",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wlansap_roam_process_dfs_chansw_update");
  v24 = sap_ch_sw_info;
  *(_BYTE *)(a2 + 1628) = 1;
  if ( *sap_ch_sw_info )
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21560),
      *sap_ch_sw_info,
      0,
      a2 + 1500,
      0,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22);
  is_conc_sap_doing_scc_dfs = sap_is_conc_sap_doing_scc_dfs(a1, a2);
  if ( (unsigned __int8)sap_get_total_number_sap_intf(a1) < 2u
    || (policy_mgr_is_current_hwmode_dbs(*(_QWORD *)(a1 + 21552)) & 1) != 0
    || ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(*(_QWORD *)(a1 + 21552)) & 1) != 0
    || ((*(_DWORD *)(a2 + 732) != 10) & is_conc_sap_doing_scc_dfs) == 0 )
  {
    result = wlansap_channel_change_request(a2, *v24);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_19;
  }
  *(_BYTE *)(a2 + 1555) = 1;
  result = is_concurrent_sap_ready_for_channel_change(a1, a2);
  if ( (result & 1) == 0 )
  {
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: sapdfs: sapctx[%pK] ready but not concurrent sap",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               "wlansap_roam_process_dfs_chansw_update",
               a2);
    *a3 = 0;
    return result;
  }
  if ( (*(_DWORD *)(a1 + 14824) | 2) == 3 )
  {
    v34 = *(_QWORD *)(a1 + 14816);
    if ( v34 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14816));
      result = wlansap_channel_change_request(v34, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v34 + 1555) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14840) | 2) == 3 )
  {
    v35 = *(_QWORD *)(a1 + 14832);
    if ( v35 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14832));
      result = wlansap_channel_change_request(v35, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v35 + 1555) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14856) | 2) == 3 )
  {
    v36 = *(_QWORD *)(a1 + 14848);
    if ( v36 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14848));
      result = wlansap_channel_change_request(v36, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v36 + 1555) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14872) | 2) == 3 )
  {
    v37 = *(_QWORD *)(a1 + 14864);
    if ( v37 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14864));
      result = wlansap_channel_change_request(v37, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v37 + 1555) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14888) | 2) == 3 )
  {
    v38 = *(_QWORD *)(a1 + 14880);
    if ( v38 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14880));
      result = wlansap_channel_change_request(v38, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v38 + 1555) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14904) | 2) == 3 )
  {
    v39 = *(_QWORD *)(a1 + 14896);
    if ( v39 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_roam_process_dfs_chansw_update",
        v39);
      result = wlansap_channel_change_request(v39, *v24);
      if ( !(_DWORD)result )
      {
        *(_BYTE *)(v39 + 1555) = 0;
        return result;
      }
      result = qdf_trace_msg(
                 0x39u,
                 2u,
                 "%s: post chnl chng req failed, sap[%pK]",
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 "wlansap_roam_process_dfs_chansw_update",
                 a2);
LABEL_19:
      *a3 = 16;
    }
  }
  return result;
}
