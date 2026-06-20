__int64 __fastcall dp_mon_cdp_ops_register(
        _QWORD **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19
  unsigned int target_type; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x0

  v9 = *a1;
  if ( !*a1 )
    return qdf_trace_msg(0x92u, 2u, "%s: cdp_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_cdp_ops_register");
  target_type = hal_get_target_type(a1[141]);
  if ( target_type > 0x2B )
    goto LABEL_11;
  if ( ((1LL << target_type) & 0xD76FFB00000LL) != 0 )
  {
    dp_mon_cdp_ops_register_1_0((__int64)v9);
    result = dp_cfr_filter_register_1_0((__int64)v9);
    if ( target_type == 36 || target_type == 26 )
      *(_QWORD *)(v9[3] + 96LL) = dp_update_mon_mac_filter;
    goto LABEL_10;
  }
  if ( ((1LL << target_type) & 0x28900000000LL) != 0 )
  {
    dp_mon_cdp_ops_register_2_0(v9);
    result = dp_cfr_filter_register_2_0(v9);
  }
  else
  {
LABEL_11:
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %s: Unknown tgt type %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_mon_cdp_ops_register",
      "dp_mon_cdp_ops_register",
      target_type);
    v20 = printk(
            &unk_9BB309,
            "0",
            "dp_mon_cdp_ops_register",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c");
    result = dump_stack(v20);
  }
LABEL_10:
  *(_QWORD *)(*v9 + 168LL) = dp_vdev_set_monitor_mode;
  *(_QWORD *)(*v9 + 376LL) = dp_get_mon_vdev_from_pdev_wifi3;
  *(_QWORD *)(v9[8] + 152LL) = dp_pkt_log_init;
  *(_QWORD *)(v9[8] + 160LL) = dp_pkt_log_con_service;
  *(_QWORD *)(v9[8] + 168LL) = dp_pkt_log_exit;
  *(_QWORD *)(v9[1] + 160LL) = dp_enable_peer_based_pktlog;
  *(_QWORD *)(v9[1] + 128LL) = dp_get_pldev;
  return result;
}
