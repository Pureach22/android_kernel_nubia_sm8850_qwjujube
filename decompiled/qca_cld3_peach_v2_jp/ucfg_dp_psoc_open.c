__int64 __fastcall ucfg_dp_psoc_open(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  const char *v23; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP context not found", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_dp_psoc_open");
    return 16;
  }
  v11 = comp_private_obj;
  v12 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !v12 )
  {
    v23 = "%s: DP context not found";
LABEL_10:
    qdf_trace_msg(0x45u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "ucfg_dp_store_qdf_dev");
    goto LABEL_11;
  }
  if ( !a1 )
  {
    *(_QWORD *)(v12 + 16) = 0;
LABEL_9:
    v23 = "%s: QDF_DEV is NULL";
    goto LABEL_10;
  }
  v21 = *(_QWORD *)(a1 + 2120);
  *(_QWORD *)(v12 + 16) = v21;
  if ( !v21 )
    goto LABEL_9;
LABEL_11:
  dp_rtpm_tput_policy_init(a1);
  pmo_register_suspend_handler(46, ucfg_dp_suspend_handler, 0);
  pmo_register_resume_handler(46, ucfg_dp_resume_handler, 0);
  dp_trace_init(a1);
  dp_bus_bandwidth_init(a1);
  wlan_dp_load_balancer_init(a1);
  _qdf_wake_lock_create((_QWORD *)(v11 + 1200), (__int64)"qcom_rx_wakelock");
  return 0;
}
