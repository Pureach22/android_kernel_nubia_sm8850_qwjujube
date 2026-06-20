void __fastcall ipa3_usb_pm_cb(__int64 a1, int a2)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x20
  __int64 ipc_logbuf; // x0
  __int64 v7; // x8
  const char *v8; // x4
  __int64 v9; // x0
  __int64 v10; // x8
  const char *v11; // x4
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_pm_cb", 553);
  }
  if ( a2 == 1 )
  {
    v5 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      v7 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v7 > 7 )
        v8 = "UNSUPPORTED";
      else
        v8 = off_1E52B8[v7];
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d state is %s\n", "ipa3_usb_pm_cb", 563, v8);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      v10 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v10 > 7 )
        v11 = "UNSUPPORTED";
      else
        v11 = off_1E52B8[v10];
      ipc_log_string(v9, "ipa_usb %s:%d state is %s\n", "ipa3_usb_pm_cb", 563, v11);
    }
    if ( *(_DWORD *)(a1 + 64) == 5 )
      queue_work_on(32, *(_QWORD *)(ipa3_usb_ctx + 536), *(_QWORD *)(a1 + 32));
    raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v5);
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipa_usb %s:%d exit\n", "ipa3_usb_pm_cb", 568);
    }
  }
  else
  {
    printk(&unk_3BCB00, "ipa3_usb_pm_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_usb %s:%d Unexpected event %d\n", "ipa3_usb_pm_cb", 556, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_usb %s:%d Unexpected event %d\n", "ipa3_usb_pm_cb", 556, a2);
    }
    __break(0x800u);
  }
}
