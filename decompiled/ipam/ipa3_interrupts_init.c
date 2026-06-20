__int64 __fastcall ipa3_interrupts_init(unsigned int a1, int a2, __int64 a3)
{
  __int64 v5; // x8
  char *v6; // x11
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w20
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0

  v5 = 0;
  ipa_ee = a2;
  do
  {
    v6 = (char *)&ipa_interrupt_to_cb + v5;
    v5 += 32;
    v6[24] = 0;
    *(_QWORD *)v6 = 0;
    *((_QWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 2) = -1;
  }
  while ( v5 != 1024 );
  ipa_interrupt_wq = alloc_workqueue("%s", (const char *)0x6000A);
  if ( ipa_interrupt_wq )
  {
    if ( *(_DWORD *)(ipa3_ctx + 32248) == 3 )
    {
LABEL_17:
      result = 0;
      suspend_wa_lock = 0;
      return result;
    }
    if ( !(unsigned int)request_threaded_irq(a1, ipa3_isr, 0, 2097153, "ipa", a3) )
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d IPA IRQ handler irq=%d registered\n", "ipa3_interrupts_init", 640, a1);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d IPA IRQ handler irq=%d registered\n", "ipa3_interrupts_init", 640, a1);
      }
      v10 = irq_set_irq_wake(a1, 1);
      if ( v10 )
      {
        v21 = v10;
        printk(&unk_3E6723, "ipa3_interrupts_init");
        v22 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v23 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v23 )
          {
            ipc_log_string(
              v23,
              "ipa %s:%d fail to enable IPA IRQ wakeup irq=%d res=%d\n",
              "ipa3_interrupts_init",
              645,
              a1,
              v21);
            v22 = ipa3_ctx;
          }
          v24 = *(_QWORD *)(v22 + 34160);
          if ( v24 )
            ipc_log_string(
              v24,
              "ipa %s:%d fail to enable IPA IRQ wakeup irq=%d res=%d\n",
              "ipa3_interrupts_init",
              645,
              a1,
              v21);
        }
      }
      else
      {
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d IPA IRQ wakeup enabled irq=%d\n", "ipa3_interrupts_init", 647, a1);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d IPA IRQ wakeup enabled irq=%d\n", "ipa3_interrupts_init", 647, a1);
        }
      }
      goto LABEL_17;
    }
    printk(&unk_3BB36A, "ipa3_interrupts_init");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d fail to register IPA IRQ handler irq=%d\n", "ipa3_interrupts_init", 635, a1);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d fail to register IPA IRQ handler irq=%d\n", "ipa3_interrupts_init", 635, a1);
    }
    destroy_workqueue(ipa_interrupt_wq);
    ipa_interrupt_wq = 0;
    return 4294967277LL;
  }
  else
  {
    printk(&unk_3EF2E0, "ipa3_interrupts_init");
    v15 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967284LL;
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d workqueue creation failed\n", "ipa3_interrupts_init", 614);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d workqueue creation failed\n", "ipa3_interrupts_init", 614);
      return 4294967284LL;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
