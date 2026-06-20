__int64 __fastcall msm_show_resume_probe(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x2
  unsigned int v13; // w19
  void *v14; // x0

  printk(&unk_7237, a2, a3);
  v4 = class_register(&unfreeze_event_class);
  if ( (v4 & 0x80000000) != 0 )
  {
    v13 = v4;
    printk(&unk_7251, v5, v6);
    return v13;
  }
  dev = device_create(&unfreeze_event_class, 0, 0, 0, "unfreezer");
  if ( (unsigned __int64)dev >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_720C, v7, v8);
  }
  else
  {
    if ( (sysfs_create_group() & 0x80000000) != 0 )
    {
      v14 = &unk_719B;
    }
    else
    {
      unfreeze_eventqueue = alloc_workqueue(&unk_71C6, 262152, 1, "send_unfreeze_event");
      if ( unfreeze_eventqueue )
      {
        tracepoint_probe_register(&_tracepoint_android_vh_do_send_sig_info, signal_catch_for_freeze, 0);
        tracepoint_probe_register(
          &_tracepoint_android_vh_binder_proc_transaction_finish,
          binder_catch_for_freeze_notify,
          0);
        tracepoint_probe_register(&_tracepoint_android_vh_binder_trans, binder_trans_for_freeze_notify, 0);
        tracepoint_probe_register(&_tracepoint_android_vh_thermal_pm_notify_suspend, zte_thermal_pm_notify_suspend, 0);
        goto LABEL_6;
      }
      v14 = &unk_7298;
    }
    printk(v14, v9, v10);
    device_destroy(&unfreeze_event_class, 0);
  }
  class_unregister(&unfreeze_event_class);
LABEL_6:
  base = of_iomap(*(_QWORD *)(a1 + 760), 0);
  if ( base )
  {
    tracepoint_probe_register_prio(&_tracepoint_android_vh_cpuidle_psci_enter, gic_s2idle_enter, 0, 0x7FFFFFFF);
    tracepoint_probe_register_prio(&_tracepoint_android_vh_cpuidle_psci_exit, gic_s2idle_exit, 0, 0x7FFFFFFF);
    register_syscore_ops(&gic_syscore_ops);
    return 0;
  }
  else
  {
    printk(&unk_7096, *(_QWORD *)(a1 + 760), v11);
    return 4294967290LL;
  }
}
