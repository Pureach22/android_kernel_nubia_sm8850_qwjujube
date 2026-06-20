void *__fastcall kgsl_pwrscale_close(__int64 a1)
{
  void *result; // x0
  void **v3; // x20
  unsigned __int64 v4; // x0
  __int64 v5; // x0

  if ( *(_BYTE *)(a1 + 14232) != 1 )
  {
    result = *(void **)(a1 + 11424);
    if ( !result )
      return result;
    v3 = (void **)(a1 + 11424);
    goto LABEL_13;
  }
  result = *(void **)(a1 + 12952);
  v3 = (void **)(a1 + 11416);
  if ( result )
  {
    ((void (*)(void))devfreq_remove_device)();
    *(_QWORD *)(a1 + 12952) = 0;
    dev_pm_opp_remove_all_dynamic(a1 + 12040);
    device_unregister(a1 + 12040);
    result = memset((void *)(a1 + 12040), 0, 0x390u);
  }
  if ( *v3 )
  {
    v4 = *(_QWORD *)(a1 + 11968);
    if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
      kthread_destroy_worker(v4);
    v5 = *(_QWORD *)(a1 + 11896);
    if ( v5 )
    {
      _flush_workqueue(v5);
      destroy_workqueue(*(_QWORD *)(a1 + 11896));
      *(_QWORD *)(a1 + 11896) = 0;
    }
    result = *v3;
LABEL_13:
    result = (void *)devfreq_remove_device(result);
    *v3 = nullptr;
  }
  return result;
}
