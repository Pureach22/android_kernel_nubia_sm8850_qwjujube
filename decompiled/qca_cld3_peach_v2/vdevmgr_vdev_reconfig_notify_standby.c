__int64 __fastcall vdevmgr_vdev_reconfig_notify_standby(
        __int64 a1,
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
  __int64 v10; // x0

  v10 = *(_QWORD *)(a1 + 520);
  if ( v10 )
    return policy_mgr_handle_link_removal_on_standby(v10, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x68u, 2u, "%s: invalid vdev", a3, a4, a5, a6, a7, a8, a9, a10, "vdevmgr_vdev_reconfig_notify_standby");
  return 4;
}
