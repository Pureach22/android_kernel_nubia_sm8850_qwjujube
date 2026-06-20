__int64 __fastcall hdd_hostapd_check_channel_post_csa(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v12; // w0
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int v23; // w1
  __int64 result; // x0

  if ( !*(_QWORD *)(a2 + 272) )
  {
    v22 = "%s: sap ctx is null";
    v23 = 2;
    return qdf_trace_msg(0x33u, v23, v22, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_hostapd_check_channel_post_csa");
  }
  v12 = wlansap_validate_channel_post_csa(a1[2]);
  v13 = *(_DWORD *)(*(_QWORD *)(a2 + 272) + 732LL);
  if ( v13 == 6 || (v12 & 1) == 0 )
  {
    if ( (unsigned int)hdd_unsafe_channel_restart_sap(a1) != 24 )
      goto LABEL_6;
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: csa is pending with reason %d",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "hdd_hostapd_check_channel_post_csa",
             *(unsigned int *)(*(_QWORD *)(a2 + 272) + 732LL));
  }
  if ( v13 == 10
    && (unsigned int)hdd_dcs_hostapd_set_chan(a1, *(unsigned __int8 *)(a2 + 8), *(unsigned int *)(a2 + 2152)) == 24 )
  {
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: csa is pending with reason %d",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "hdd_hostapd_check_channel_post_csa",
             *(unsigned int *)(*(_QWORD *)(a2 + 272) + 732LL));
  }
LABEL_6:
  if ( (unsigned int)policy_mgr_nan_sap_post_enable_conc_check(*a1) == 24 )
  {
    v22 = "%s: csa is pending by nan sap conc";
LABEL_13:
    v23 = 8;
    return qdf_trace_msg(0x33u, v23, v22, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_hostapd_check_channel_post_csa");
  }
  if ( (unsigned int)policy_mgr_check_sap_go_force_scc(
                       *a1,
                       *(_QWORD *)(a2 + 32),
                       *(_DWORD *)(*(_QWORD *)(a2 + 272) + 732LL)) == 24 )
  {
    v22 = "%s: csa is pending by sap go force scc";
    goto LABEL_13;
  }
  result = policy_mgr_get_beaconing_mode_count(*a1, nullptr);
  if ( (result & 0xFE) != 0 )
  {
    policy_mgr_check_concurrent_intf_and_restart_sap(*a1, *(_BYTE *)(a2 + 1416) != 0);
    return policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(*a1);
  }
  return result;
}
