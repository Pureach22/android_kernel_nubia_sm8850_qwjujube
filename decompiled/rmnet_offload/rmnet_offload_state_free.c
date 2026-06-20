void rmnet_offload_state_free()
{
  __int64 v0; // x19
  __int64 v1; // x0
  _QWORD v2[3]; // [xsp+8h] [xbp-18h] BYREF

  v2[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = v2;
  v2[1] = v2;
  if ( rmnet_offload )
  {
    v0 = *(_QWORD *)rmnet_offload;
    qmi_rmnet_ps_ind_deregister(*(_QWORD *)rmnet_offload, rmnet_offload + 64);
    if ( *(_BYTE *)(rmnet_offload + 56) == 1 )
      rmnet_map_dl_ind_deregister(v0, rmnet_offload + 8);
    rmnet_offload_unset_hooks();
    v1 = rmnet_offload_engine_disable_chain_flush();
    synchronize_rcu(v1);
    rmnet_offload_engine_flush_all_flows((__int64)v2);
    rmnet_offload_engine_exit();
    kfree(rmnet_offload);
    rmnet_offload = 0;
  }
  _ReadStatusReg(SP_EL0);
}
