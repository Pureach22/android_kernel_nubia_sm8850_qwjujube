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
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w0
  unsigned __int8 is_conc_sap_doing_scc_dfs; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x22
  __int64 v44; // x22
  __int64 v45; // x22
  __int64 v46; // x22
  __int64 v47; // x22
  __int64 v48; // x21
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

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
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3369LL) == 1 )
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
  *(_BYTE *)(a2 + 1644) = 1;
  if ( *sap_ch_sw_info )
  {
    v25 = sap_phymode_is_eht(*(unsigned int *)(a2 + 1484));
    if ( (v33 & 1) != 0 )
      wlan_reg_set_create_punc_bitmap(a2 + 1500, 1);
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21632),
      *v24,
      0,
      a2 + 1500,
      0,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32);
  }
  is_conc_sap_doing_scc_dfs = sap_is_conc_sap_doing_scc_dfs(a1, a2);
  if ( (unsigned __int8)sap_get_total_number_sap_intf(a1) < 2u
    || (policy_mgr_is_current_hwmode_dbs(*(_QWORD *)(a1 + 21624)) & 1) != 0
    || ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(*(_QWORD *)(a1 + 21624)) & 1) != 0
    || ((*(_DWORD *)(a2 + 732) != 10) & is_conc_sap_doing_scc_dfs) == 0 )
  {
    result = wlansap_channel_change_request(a2, *v24);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_21;
  }
  *(_BYTE *)(a2 + 1563) = 1;
  result = is_concurrent_sap_ready_for_channel_change(a1, a2);
  if ( (result & 1) == 0 )
  {
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: sapdfs: sapctx[%pK] ready but not concurrent sap",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "wlansap_roam_process_dfs_chansw_update",
               a2);
    *a3 = 0;
    return result;
  }
  if ( (*(_DWORD *)(a1 + 14896) | 2) == 3 )
  {
    v43 = *(_QWORD *)(a1 + 14888);
    if ( v43 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14888));
      result = wlansap_channel_change_request(v43, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v43 + 1563) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14912) | 2) == 3 )
  {
    v44 = *(_QWORD *)(a1 + 14904);
    if ( v44 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14904));
      result = wlansap_channel_change_request(v44, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v44 + 1563) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14928) | 2) == 3 )
  {
    v45 = *(_QWORD *)(a1 + 14920);
    if ( v45 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14920));
      result = wlansap_channel_change_request(v45, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v45 + 1563) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14944) | 2) == 3 )
  {
    v46 = *(_QWORD *)(a1 + 14936);
    if ( v46 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14936));
      result = wlansap_channel_change_request(v46, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v46 + 1563) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14960) | 2) == 3 )
  {
    v47 = *(_QWORD *)(a1 + 14952);
    if ( v47 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        *(_QWORD *)(a1 + 14952));
      result = wlansap_channel_change_request(v47, *v24);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x39u,
                   2u,
                   "%s: post chnl chng req failed, sap[%pK]",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "wlansap_roam_process_dfs_chansw_update",
                   a2);
        *a3 = 16;
      }
      else
      {
        *(_BYTE *)(v47 + 1563) = 0;
      }
    }
  }
  if ( (*(_DWORD *)(a1 + 14976) | 2) == 3 )
  {
    v48 = *(_QWORD *)(a1 + 14968);
    if ( v48 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs:issue chnl change for sapctx[%pK]",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlansap_roam_process_dfs_chansw_update",
        v48);
      result = wlansap_channel_change_request(v48, *v24);
      if ( !(_DWORD)result )
      {
        *(_BYTE *)(v48 + 1563) = 0;
        return result;
      }
      result = qdf_trace_msg(
                 0x39u,
                 2u,
                 "%s: post chnl chng req failed, sap[%pK]",
                 v49,
                 v50,
                 v51,
                 v52,
                 v53,
                 v54,
                 v55,
                 v56,
                 "wlansap_roam_process_dfs_chansw_update",
                 a2);
LABEL_21:
      *a3 = 16;
    }
  }
  return result;
}
