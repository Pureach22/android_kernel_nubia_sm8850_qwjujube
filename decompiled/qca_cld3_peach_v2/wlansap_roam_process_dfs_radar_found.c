__int64 __fastcall wlansap_roam_process_dfs_radar_found(__int64 a1, __int64 a2, _DWORD *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  __int64 v25; // [xsp+8h] [xbp-18h]
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  v24 = 0;
  if ( (sap_is_dfs_cac_wait_state(a2) & 1) != 0 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3369LL) == 1 )
    {
      v14 = "%s: sapdfs: DFS channel switch disabled";
LABEL_16:
      result = qdf_trace_msg(
                 0x39u,
                 2u,
                 v14,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "wlansap_roam_process_dfs_radar_found",
                 v24,
                 v25,
                 v26,
                 v27);
      goto LABEL_17;
    }
    if ( !*(_BYTE *)(a2 + 13) )
    {
      v14 = "%s: sapdfs: sap_radar_found_status is false";
      goto LABEL_16;
    }
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sapdfs:Posting event eSAP_DFS_CHANNEL_CAC_RADAR_FOUND",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlansap_roam_process_dfs_radar_found",
      v24,
      v25,
      v26,
      v27);
    if ( (*(_BYTE *)(a2 + 1643) & 1) == 0 )
    {
      qdf_mc_timer_stop(a1 + 14712);
      qdf_mc_timer_destroy(a1 + 14712);
    }
    *(_BYTE *)(a1 + 14881) = 0;
    if ( (unsigned int)sap_signal_hdd_event(a2, 0, 15, 0) )
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Failed to send CAC end",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlansap_roam_process_dfs_radar_found");
    v24 = 0;
    v25 = 14;
    LODWORD(v26) = 0;
    result = sap_fsm(a2, &v24);
    if ( (_DWORD)result )
      *a3 = 16;
  }
  else if ( *(_DWORD *)(a2 + 728) == 2 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sapdfs:Posting event eSAP_DFS_CHNL_SWITCH_ANNOUNCEMENT_START",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlansap_roam_process_dfs_radar_found",
      v24,
      v25,
      v26,
      v27);
    v24 = 0;
    v25 = 16;
    LODWORD(v26) = 0;
    result = sap_fsm(a2, &v24);
    if ( (_DWORD)result )
      *a3 = 16;
  }
  else
  {
    result = qdf_trace_msg(
               0x39u,
               2u,
               "%s: eCSR_ROAM_RESULT_DFS_RADAR_FOUND_IND received in (%d) state",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlansap_roam_process_dfs_radar_found",
               v24,
               v25,
               v26,
               v27);
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
