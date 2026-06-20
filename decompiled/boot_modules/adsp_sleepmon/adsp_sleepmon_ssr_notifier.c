__int64 __fastcall adsp_sleepmon_ssr_notifier(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = a1 - 48;
  mutex_lock(a1 - 48);
  if ( a2 == 1 )
  {
    if ( *(_BYTE *)(a1 + 32) == 1 && adsp_sleepmon_ssr_notifier_is_subsystem_crashed == 1 && *(_QWORD *)(a1 - 56) )
    {
      printk(&unk_921D);
      qcom_rproc_update_recovery_status(*(_QWORD *)(a1 - 56), 0, 0);
      adsp_sleepmon_ssr_notifier_is_subsystem_crashed = 0;
      *(_BYTE *)(a1 + 32) = 0;
    }
  }
  else if ( a2 == 2 && a3 && (*(_BYTE *)(a1 + 32) & 1) != 0 && *(_BYTE *)(a3 + 8) == 1 )
  {
    adsp_sleepmon_ssr_notifier_is_subsystem_crashed = 1;
  }
  mutex_unlock(v3);
  return 1;
}
