__int64 __fastcall if_mgr_ap_start_bss(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 16;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 16;
  wlan_tdls_notify_start_bss(*(_QWORD *)(v1 + 80), a1);
  if ( (*(_DWORD *)(a1 + 16) | 2) == 3 )
    wlan_mlme_is_aux_emlsr_support(v2);
  if ( (unsigned int)policy_mgr_is_hw_mode_change_in_progress(v2)
    && (unsigned int)policy_mgr_wait_for_connection_update(v2) )
  {
    v12 = "%s: qdf wait for event failed!!";
LABEL_11:
    qdf_trace_msg(0x78u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "if_mgr_ap_start_bss");
    return 16;
  }
  if ( (policy_mgr_is_chan_switch_in_progress(v2) & 1) != 0
    && (unsigned int)policy_mgr_wait_chan_switch_complete_evt(v2) )
  {
    v12 = "%s: qdf wait for csa event failed!!";
    goto LABEL_11;
  }
  if ( (policy_mgr_is_sta_active_connection_exists(v2) & 1) != 0 )
    if_mgr_disable_roaming(v1, a1, 1);
  ucfg_p2p_cleanup_roc_by_psoc(v2);
  return 0;
}
