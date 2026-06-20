__int64 __fastcall if_mgr_ap_csa_complete(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  unsigned int v4; // w21
  unsigned int v5; // w19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  char acs_mode_for_vdev; // w0

  v1 = *(_QWORD *)(a1 + 216);
  if ( v1 && (v2 = *(_QWORD *)(v1 + 80)) != 0 )
  {
    v4 = *(unsigned __int8 *)(a1 + 168);
    v5 = wlan_p2p_check_and_force_scc_go_plus_go(*(_QWORD *)(v1 + 80), a1);
    if ( v5 )
      qdf_trace_msg(
        0x78u,
        2u,
        "%s: force scc failure with status: %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "if_mgr_ap_csa_complete",
        v5);
    if ( *(_DWORD *)(a1 + 16) == 3 )
    {
      policy_mgr_check_sap_go_force_scc(v2, a1, 13);
    }
    else if ( (policy_mgr_is_vdev_ll_lt_sap(v2, *(unsigned __int8 *)(a1 + 168)) & 1) != 0 )
    {
      policy_mgr_ll_lt_sap_restart_concurrent_sap(v2, 2);
    }
    else
    {
      acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(a1);
      policy_mgr_check_concurrent_intf_and_restart_sap(v2, acs_mode_for_vdev & 1);
    }
    wlan_tdls_notify_channel_switch_complete(v2, v4);
    if ( (wlan_ll_sap_is_bearer_switch_req_on_csa(v2, v4) & 1) != 0 )
      wlan_ll_sap_switch_bearer_on_ll_sap_csa_complete(v2, v4);
  }
  else
  {
    return 16;
  }
  return v5;
}
