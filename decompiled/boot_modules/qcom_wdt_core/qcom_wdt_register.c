__int64 __fastcall qcom_wdt_register(__int64 a1, __int64 a2, __int64 a3)
{
  char v6; // w0
  unsigned __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  unsigned int v10; // w0
  int v11; // w0
  __int64 v13; // x20
  void (__fastcall *v14)(__int64, __int64); // x9
  __int64 v15; // x0
  void (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 (__fastcall *v19)(__int64, __int64); // x9
  __int64 v20; // x0
  unsigned int v21; // w0
  __int64 (__fastcall *v22)(_QWORD); // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  int file; // w20
  __int64 v27; // x10
  __int64 v28; // x8
  _QWORD v29[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_7C55, a2);
    v8 = -22;
    goto LABEL_13;
  }
  *(_DWORD *)(a2 + 32) = platform_get_irq();
  v6 = irq_check_status_bit();
  *(_QWORD *)(a2 + 24) = 0x2AF800002490LL;
  *(_BYTE *)(a2 + 39) = v6 & 1;
  *(_BYTE *)(a2 + 36) = 1;
  *(_BYTE *)(a2 + 38) = 1;
  wdog_data = a2;
  *(_QWORD *)(a2 + 8) = a1 + 16;
  *(_QWORD *)(a1 + 168) = a2;
  *(_QWORD *)(a2 + 48) = 0;
  v7 = kthread_create_on_node(qcom_wdt_kthread, a2, 0xFFFFFFFFLL, a3);
  *(_QWORD *)(a2 + 216) = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = v7;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(a2 + 39) == 1 )
  {
    v9 = pcpu_alloc_noprof(8, 8, 0, 3264);
    *(_QWORD *)(a2 + 104) = v9;
    if ( !v9 )
    {
      dev_err(*(_QWORD *)(a2 + 8), "failed to allocate cpu data\n");
      v8 = -12;
      goto LABEL_12;
    }
    *(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + v9) = a2;
    v10 = _request_percpu_irq(*(unsigned int *)(a2 + 32), qcom_wdt_ppi_bark, 0, "apps_wdog_bark", *(_QWORD *)(a2 + 104));
    if ( v10 )
    {
      v8 = v10;
      dev_err(*(_QWORD *)(a2 + 8), "failed to request bark irq\n");
      free_percpu(*(_QWORD *)(a2 + 104));
LABEL_12:
      kthread_stop(*(_QWORD *)(a2 + 216));
      goto LABEL_13;
    }
  }
  else
  {
    v11 = devm_request_threaded_irq(
            *(_QWORD *)(a2 + 8),
            *(unsigned int *)(a2 + 32),
            qcom_wdt_bark_handler,
            0,
            16385,
            "apps_wdog_bark",
            a2);
    if ( v11 )
    {
      dev_err(*(_QWORD *)(a2 + 8), "failed to request bark irq: %d\n", v11);
      v8 = -22;
      goto LABEL_12;
    }
  }
  *(_BYTE *)(wdog_data + 1000) = 0;
  v8 = register_pm_notifier(&qcom_wdt_notif_block);
  if ( v8 )
    goto LABEL_12;
  v13 = _msecs_to_jiffies(*(unsigned int *)(a2 + 24));
  v14 = **(void (__fastcall ***)(__int64, __int64))(a2 + 16);
  v15 = *(unsigned int *)(a2 + 28);
  if ( *((_DWORD *)v14 - 1) != -872624411 )
    __break(0x8229u);
  v14(v15, a2);
  v16 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 16) + 8LL);
  v17 = (unsigned int)(*(_DWORD *)(a2 + 28) + 3000);
  if ( *((_DWORD *)v16 - 1) != -872624411 )
    __break(0x8228u);
  v16(v17, a2);
  *(_QWORD *)(a2 + 112) = qcom_wdt_panic_handler;
  *(_DWORD *)(a2 + 128) = 2147483646;
  atomic_notifier_chain_register(&panic_notifier_list, a2 + 112);
  *(_QWORD *)(a2 + 136) = qcom_wdt_die_handler;
  *(_DWORD *)(a2 + 152) = 2147483646;
  register_die_notifier(a2 + 136);
  *(_QWORD *)(a2 + 184) = restart_wdog_handler;
  *(_DWORD *)(a2 + 200) = 255;
  register_restart_handler(a2 + 184);
  _mutex_init(a2 + 56, "&wdog_dd->disable_lock", &qcom_wdt_init___key);
  _init_waitqueue_head(a2 + 264, "&wdog_dd->pet_complete", &qcom_wdt_init___key_26);
  v18 = *(_QWORD *)(a2 + 216);
  *(_BYTE *)(a2 + 209) = 0;
  *(_WORD *)(a2 + 288) = 256;
  *(_DWORD *)(a2 + 956) = 0;
  *(_BYTE *)(a2 + 952) = 0;
  wake_up_process(v18);
  init_timer_key(a2 + 224, qcom_wdt_pet_task_wakeup, 0, 0, 0);
  *(_QWORD *)(a2 + 240) = jiffies + v13;
  add_timer(a2 + 224);
  init_timer_key(a2 + 960, qcom_wdt_user_pet_bite, 0, 0, 0);
  v19 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 16) + 24LL);
  if ( *(_BYTE *)(a2 + 38) )
    v20 = 3;
  else
    v20 = 1;
  if ( *((_DWORD *)v19 - 1) != -872624411 )
    __break(0x8229u);
  v21 = v19(v20, a2);
  if ( v21 )
  {
    v8 = v21;
    atomic_notifier_chain_unregister(&panic_notifier_list, a2 + 112);
    unregister_die_notifier(a2 + 136);
    unregister_restart_handler(a2 + 184);
    if ( *(_BYTE *)(a2 + 39) == 1 )
    {
      free_percpu_irq(*(unsigned int *)(a2 + 32), *(_QWORD *)(a2 + 104));
      free_percpu(*(_QWORD *)(a2 + 104));
    }
    timer_delete_sync(a2 + 224);
    dev_err(*(_QWORD *)(a2 + 8), "Failed Initializing QCOM Apps Watchdog\n");
    goto LABEL_12;
  }
  v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 16) + 16LL);
  if ( *((_DWORD *)v22 - 1) != 2060914831 )
    __break(0x8228u);
  v23 = v22(a2);
  v24 = sched_clock(v23);
  v25 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)(a2 + 40) = v24;
  *(_BYTE *)(a2 + 208) = 1;
  file = device_create_file(v25, &dev_attr_disable);
  if ( (unsigned int)device_create_file(*(_QWORD *)(a2 + 8), &dev_attr_wakeup_enable) | file )
    dev_err(*(_QWORD *)(a2 + 8), "cannot create sysfs attribute\n");
  if ( *(_BYTE *)(a2 + 39) == 1 )
    enable_percpu_irq(*(unsigned int *)(a2 + 32), 0);
  *(_QWORD *)(a2 + 160) = qcom_wdt_cpu_pm_notify;
  cpu_pm_register_notifier(a2 + 160);
  dev_info(*(_QWORD *)(a2 + 8), "QCOM Apps Watchdog Initialized\n");
  v27 = a2 << 8 >> 8;
  strcpy((char *)v29, "KWDOGDATA");
  v28 = memstart_addr + v27 + 0x8000000000LL;
  if ( (unsigned __int64)(v27 + 0x8000000000LL) >> 38 )
    v28 = v27 - kimage_voffset;
  v30 = a2;
  v31 = v28;
  v32 = 1008;
  if ( (msm_minidump_add_region(v29) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(a2 + 8), "Failed to add Wdt data in Minidump\n");
  v8 = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v8;
}
