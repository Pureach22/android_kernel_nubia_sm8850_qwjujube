__int64 cleanup_module()
{
  __int64 v0; // x0
  __int64 i; // x0
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = rmnet_module_hook_unregister_no_sync("\b", 10);
  synchronize_rcu(v0);
  genl_unregister_family(&rmnet_perf_nl_family);
  rmnet_perf_udp_exit();
  rmnet_perf_tcp_exit();
  raw_spin_lock(&rmnet_perf_ecn_map);
  v3[0] = 0;
  for ( i = xa_find(&rmnet_perf_ecn_map, v3, -1, 8); i; i = xa_find_after(&rmnet_perf_ecn_map, v3, -1, 8) )
    call_rcu(i, rmnet_perf_ecn_node_free);
  raw_spin_unlock(&rmnet_perf_ecn_map);
  xa_destroy(&rmnet_perf_ecn_map);
  result = printk(&unk_EFD0, "rmnet_perf_exit");
  _ReadStatusReg(SP_EL0);
  return result;
}
