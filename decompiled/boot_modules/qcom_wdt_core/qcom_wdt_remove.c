__int64 __fastcall qcom_wdt_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 168);
  cpu_pm_unregister_notifier(v1 + 160);
  mutex_lock(v1 + 56);
  if ( *(_BYTE *)(v1 + 208) == 1 )
    qcom_wdt_disable(v1);
  mutex_unlock(v1 + 56);
  device_remove_file(*(_QWORD *)(v1 + 8), &dev_attr_disable);
  if ( *(_BYTE *)(v1 + 39) == 1 )
    free_percpu(*(_QWORD *)(v1 + 104));
  irq_dispose_mapping(*(unsigned int *)(v1 + 32));
  dev_info(*(_QWORD *)(v1 + 8), "QCOM Apps Watchdog Exit - Deactivated\n");
  timer_delete_sync(v1 + 224);
  if ( *(_BYTE *)(v1 + 209) == 1 )
    timer_delete_sync(v1 + 960);
  v2 = *(_QWORD *)(v1 + 216);
  *(_WORD *)(v1 + 288) = 257;
  return kthread_stop(v2);
}
