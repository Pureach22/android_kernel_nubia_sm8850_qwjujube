void rmnet_shs_wq_exit()
{
  __int64 v0; // x0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  _QWORD v15[16]; // [xsp+10h] [xbp-80h] BYREF

  v15[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rmnet_shs_wq && rmnet_shs_delayed_wq )
  {
    memset(v15, 0, 120);
    rmnet_shs_create_cleanup_msg_resp(v15);
    rmnet_shs_genl_msg_direct_send_to_userspace(v15);
    v0 = rmnet_shs_genl_send_int_to_userspace_no_info(42);
    rmnet_shs_wq_pause(v0, v1, v2, v3, v4, v5, v6, v7);
    cancel_delayed_work_sync(rmnet_shs_delayed_wq, v8, v9, v10, v11, v12, v13, v14);
    drain_workqueue(rmnet_shs_wq);
    destroy_workqueue(rmnet_shs_wq);
    kfree(rmnet_shs_delayed_wq);
    rmnet_shs_delayed_wq = 0;
    rmnet_shs_wq = 0;
    rmnet_shs_wq_cleanup_hash_tbl(1, 0);
  }
  _ReadStatusReg(SP_EL0);
}
