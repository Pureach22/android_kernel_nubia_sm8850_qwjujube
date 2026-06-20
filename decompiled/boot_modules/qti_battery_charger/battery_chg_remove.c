__int64 __fastcall battery_chg_remove(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x19

  v1 = *(__int64 **)(a1 + 168);
  down_write(v1 + 24);
  *((_DWORD *)v1 + 139) = 0;
  *((_BYTE *)v1 + 1144) = 0;
  up_write(v1 + 24);
  if ( v1[65] )
    panel_event_notifier_unregister();
  v2 = *v1;
  device_wakeup_disable(*v1);
  device_set_wakeup_capable(v2, 0);
  debugfs_remove(v1[64]);
  class_unregister(v1 + 1);
  pmic_glink_unregister_client(v1[17]);
  cancel_work_sync(v1 + 70);
  cancel_work_sync(v1 + 74);
  cancel_work_sync(v1 + 126);
  return unregister_reboot_notifier(v1 + 137);
}
