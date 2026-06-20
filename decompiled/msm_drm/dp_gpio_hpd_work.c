__int64 __fastcall dp_gpio_hpd_work(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  __int64 v3; // x4
  int v4; // w21
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  v1 = a1 - 120;
  v2 = *(unsigned __int8 *)(a1 + 116);
  devm_free_irq(*(_QWORD *)(a1 - 120), *(unsigned int *)(a1 + 112), a1 - 120);
  if ( v2 )
    v3 = 8194;
  else
    v3 = 8193;
  v4 = devm_request_threaded_irq(*(_QWORD *)v1, *(unsigned int *)(v1 + 232), 0, dp_gpio_isr, v3, "dp-gpio-intp");
  result = dp_gpio_hpd_connect(v1, v2);
  if ( v4 < 0 )
  {
    ipc_log_context = get_ipc_log_context(result);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]Cannot claim IRQ dp-gpio-intp\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_272B31, "dp_gpio_hpd_work");
  }
  return result;
}
