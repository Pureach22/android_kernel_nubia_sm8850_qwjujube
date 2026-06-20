__int64 __fastcall dp_lphw_hpd_register(__int64 a1)
{
  __int64 v2; // x0
  bool v3; // zf
  __int64 v4; // x0
  __int64 v5; // x1
  char v6; // w8
  __int64 v7; // x0
  unsigned int v9; // w19
  __int64 ipc_log_context; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = gpio_to_desc(*(unsigned int *)(a1 + 88));
  v3 = (unsigned int)gpiod_get_raw_value_cansleep(v2) == 0;
  v4 = *(_QWORD *)(a1 - 8);
  v5 = *(unsigned int *)(a1 + 344);
  v6 = !v3;
  *(_BYTE *)(a1 + 348) = v6;
  v7 = devm_request_threaded_irq(v4, v5, 0, dp_tlmm_isr, 8193, "dp-gpio-intp");
  if ( (_DWORD)v7 )
  {
    v9 = v7;
    ipc_log_context = get_ipc_log_context(v7);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]Failed to request INTP threaded IRQ: %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v9);
    printk(&unk_241E84, "dp_lphw_hpd_register");
    return v9;
  }
  else
  {
    irq_set_irq_wake(*(unsigned int *)(a1 + 344), 1);
    if ( *(_BYTE *)(a1 + 348) == 1 )
      queue_work_on(32, *(_QWORD *)(a1 + 128), a1 + 240);
    return 0;
  }
}
