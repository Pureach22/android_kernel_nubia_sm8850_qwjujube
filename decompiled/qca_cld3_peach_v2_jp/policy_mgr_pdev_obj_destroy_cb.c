__int64 __fastcall policy_mgr_pdev_obj_destroy_cb(__int64 a1)
{
  __int64 v1; // x19
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v1 = *(_QWORD *)(a1 + 80);
  context = policy_mgr_get_context(v1);
  if ( context )
  {
    *(_QWORD *)(context + 8) = 0;
    wlan_reg_unregister_chan_change_callback(v1, (__int64)&policy_mgr_reg_chan_change_callback);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: invalid context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_pdev_obj_destroy_cb");
    return 16;
  }
}
