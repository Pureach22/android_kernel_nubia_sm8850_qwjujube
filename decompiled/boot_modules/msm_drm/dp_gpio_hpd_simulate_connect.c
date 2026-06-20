__int64 __fastcall dp_gpio_hpd_simulate_connect(__int64 a1, char a2)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    dp_gpio_hpd_connect(a1 - 8, a2 & 1);
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_gpio_hpd_simulate_connect");
    return 4294967274LL;
  }
}
