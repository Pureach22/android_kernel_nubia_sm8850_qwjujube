__int64 __fastcall dp_gpio_hpd_register(__int64 a1)
{
  __int64 v2; // x0
  bool v3; // zf
  __int64 v4; // x0
  __int64 v5; // x1
  char v6; // w8
  __int64 v7; // x4
  __int64 v8; // x0
  unsigned int v10; // w19
  __int64 ipc_log_context; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = gpio_to_desc(*(unsigned int *)(a1 + 72));
  v3 = (unsigned int)gpiod_get_raw_value_cansleep(v2) == 0;
  v4 = *(_QWORD *)(a1 - 8);
  v5 = *(unsigned int *)(a1 + 224);
  v6 = !v3;
  if ( v3 )
    v7 = 8193;
  else
    v7 = 8194;
  *(_BYTE *)(a1 + 228) = v6;
  v8 = devm_request_threaded_irq(v4, v5, 0, dp_gpio_isr, v7, "dp-gpio-intp");
  if ( (_DWORD)v8 )
  {
    v10 = v8;
    ipc_log_context = get_ipc_log_context(v8);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]Failed to request INTP threaded IRQ: %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v10);
    printk(&unk_241E84, "dp_gpio_hpd_register");
    return v10;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 228) == 1 )
      queue_delayed_work_on(32, system_wq, a1 + 112, 0);
    return 0;
  }
}
