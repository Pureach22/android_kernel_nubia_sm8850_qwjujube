__int64 cleanup_module()
{
  __int64 v0; // x0
  __int64 v1; // x1
  _UNKNOWN ***v2; // x0
  _UNKNOWN **v3; // x20
  __int64 v4; // x1
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  _QWORD *v7; // x21
  __int64 result; // x0
  __int64 v9; // [xsp+Ch] [xbp-14h] BYREF
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  proc_remove(aps_activity_file);
  proc_remove(aps_proc_dir);
  rmnet_module_hook_unregister_no_sync(&aps_data_activity_hooks, 2);
  rmnet_module_hook_unregister_no_sync(&aps_data_report_hooks, 1);
  v0 = rmnet_module_hook_unregister_no_sync(&rmnet_aps_module_hooks, 2);
  synchronize_rcu(v0);
  mutex_lock(&rmnet_aps_mutex);
  v2 = (_UNKNOWN ***)aps_flow_list;
  rmnet_aps_active = 0;
  if ( aps_flow_list != (_UNKNOWN *)&aps_flow_list )
  {
    do
    {
      v3 = *v2;
      rmnet_aps_remove_flow(v2 - 4, v1);
      v2 = (_UNKNOWN ***)v3;
    }
    while ( v3 != &aps_flow_list );
  }
  mutex_unlock(&rmnet_aps_mutex);
  if ( HIDWORD(aps_client_genl_info) )
  {
    v9 = 0x300000005LL;
    v10 = 0;
    if ( (unsigned int)rmnet_aps_send_msg((__int64)&aps_client_genl_info, 1u, 2u, 0xCu, (__int64)&v9, 0x820u) )
      HIDWORD(aps_client_genl_info) = 0;
  }
  cancel_delayed_work_sync(&rmnet_aps_rate_work);
  timer_delete_sync(&rmnet_aps_timer);
  cancel_work_sync(&rmnet_aps_flow_expire_work);
  raw_spin_lock_bh(&data_report_lock);
  v5 = data_report_req_list;
  if ( data_report_req_list != (_UNKNOWN *)&data_report_req_list )
  {
    do
    {
      v7 = (_QWORD *)*v5;
      v6 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v6 == v5 && (_QWORD *)v7[1] == v5 )
      {
        v7[1] = v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v5, v4);
      }
      *v5 = 0xDEAD000000000100LL;
      v5[1] = 0xDEAD000000000122LL;
      kfree(v5);
      v5 = v7;
    }
    while ( v7 != &data_report_req_list );
  }
  data_report_enabled = 1;
  data_report_count = 0;
  raw_spin_unlock_bh(&data_report_lock);
  timer_delete_sync(&data_report_timer);
  unregister_netdevice_notifier(&rmnet_aps_notifier);
  result = rmnet_aps_genl_deinit();
  _ReadStatusReg(SP_EL0);
  return result;
}
