__int64 rmnet_perf_nl_cmd_ecn_flush()
{
  __int64 v0; // x0
  __int64 v1; // x21
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock(&rmnet_perf_ecn_map);
  v3[0] = 0;
  v0 = xa_find(&rmnet_perf_ecn_map, v3, -1, 8);
  if ( v0 )
  {
    v1 = v0;
    do
    {
      _xa_erase(&rmnet_perf_ecn_map, v3[0]);
      call_rcu(v1, rmnet_perf_ecn_node_free);
      v1 = xa_find_after(&rmnet_perf_ecn_map, v3, -1, 8);
    }
    while ( v1 );
  }
  raw_spin_unlock(&rmnet_perf_ecn_map);
  _ReadStatusReg(SP_EL0);
  return 0;
}
