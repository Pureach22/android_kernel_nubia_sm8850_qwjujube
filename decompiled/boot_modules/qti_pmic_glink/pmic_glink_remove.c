__int64 __fastcall pmic_glink_remove(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  _UNKNOWN **v4; // x10
  _QWORD *v5; // x12
  __int64 *v6; // x9
  unsigned __int64 v7; // x11
  _QWORD *v8; // x8
  __int64 **v9; // x8
  __int64 *v10; // x13

  v1 = *(_QWORD *)(a1 + 168);
  ipc_log_context_destroy(*(_QWORD *)(v1 + 32));
  pdr_handle_release(*(_QWORD *)(v1 + 368));
  qcom_unregister_ssr_notifier(*(_QWORD *)(v1 + 360), v1 + 328);
  v3 = *(_QWORD *)(v1 + 8);
  device_wakeup_disable(v3);
  device_set_wakeup_capable(v3, 0);
  debugfs_remove(*(_QWORD *)(v1 + 16));
  _flush_workqueue(*(_QWORD *)(v1 + 248));
  destroy_workqueue(*(_QWORD *)(v1 + 248));
  idr_destroy(v1 + 40);
  of_platform_depopulate(a1 + 16);
  *(_BYTE *)(v1 + 296) = 0;
  mutex_lock(&pmic_glink_dev_lock);
  v4 = &pmic_glink_dev_list;
  v5 = pmic_glink_dev_list;
  if ( pmic_glink_dev_list != (_UNKNOWN *)&pmic_glink_dev_list )
  {
    v6 = (__int64 *)(v1 + 272);
    v7 = 0xDEAD000000000100LL;
    do
    {
      v8 = v5 - 34;
      v5 = (_QWORD *)*v5;
      if ( v8 == (_QWORD *)v1 )
      {
        v9 = *(__int64 ***)(v1 + 280);
        if ( *v9 == v6 && (v10 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
        {
          v10[1] = (__int64)v9;
          *v9 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *(_QWORD *)(v1 + 272) = v7;
        *(_QWORD *)(v1 + 280) = v7 + 34;
      }
    }
    while ( v5 != v4 );
  }
  return mutex_unlock(&pmic_glink_dev_lock);
}
