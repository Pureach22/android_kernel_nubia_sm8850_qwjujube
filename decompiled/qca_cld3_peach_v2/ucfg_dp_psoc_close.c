__int64 __fastcall ucfg_dp_psoc_close(__int64 a1)
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

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    dp_rtpm_tput_policy_deinit(a1);
    pmo_unregister_suspend_handler(46, ucfg_dp_suspend_handler);
    pmo_unregister_resume_handler(46, ucfg_dp_resume_handler);
    qdf_dp_trace_deinit();
    wlan_dp_load_balancer_deinit(a1);
    dp_bus_bandwidth_deinit(a1);
    _qdf_wake_lock_destroy(v11 + 1200);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP context not found", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_dp_psoc_close");
    return 16;
  }
}
