__int64 __fastcall policy_mgr_con_mode_by_vdev_id(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int opmode_from_vdev_id; // w0

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(context + 8), a2);
    return policy_mgr_qdf_opmode_to_pm_con_mode(a1, opmode_from_vdev_id, a2);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_con_mode_by_vdev_id");
    return 7;
  }
}
