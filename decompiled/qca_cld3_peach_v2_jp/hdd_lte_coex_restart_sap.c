__int64 __fastcall hdd_lte_coex_restart_sap(__int64 a1, __int64 a2)
{
  unsigned int safe_channel_from_pcl_and_acs_range; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  safe_channel_from_pcl_and_acs_range = wlansap_get_safe_channel_from_pcl_and_acs_range(
                                          *(_QWORD *)(*(_QWORD *)(a1 + 52824) + 272LL),
                                          0);
  v13 = wlan_reg_freq_to_chan(
          *(_QWORD *)(a2 + 8),
          safe_channel_from_pcl_and_acs_range,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12);
  if ( !(_BYTE)v13 )
    return qdf_trace_msg(
             0x33u,
             1u,
             "%s: fail to restart SAP",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "hdd_lte_coex_restart_sap");
  v22 = v13;
  *(_DWORD *)(a2 + 1620) = 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sending coex indication",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hdd_lte_coex_restart_sap");
  wlan_hdd_send_svc_nlink_msg(*(_DWORD *)(a2 + 1456), 0x101u, nullptr, 0);
  wlan_hdd_set_sap_csa_reason(*(_QWORD *)a2, *(_BYTE *)(*(_QWORD *)(a1 + 52824) + 8LL), 7u);
  return hdd_switch_sap_channel(*(_QWORD *)(a1 + 52824), v22, 1, v23, v24, v25, v26, v27, v28, v29, v30);
}
