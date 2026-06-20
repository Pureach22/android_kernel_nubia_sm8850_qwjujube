__int64 __fastcall cnss_init_direct_cx_host_sol_gpio(_DWORD *a1)
{
  unsigned int named_gpio; // w0
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x21
  const char *v5; // x1
  unsigned int v6; // w20
  __int64 v7; // x7
  const char *v8; // x1
  __int64 v9; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  named_gpio = of_get_named_gpio(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cnss-direct-cx-host-sol-init-gpio", 0);
  a1[1999] = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    return 0;
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v5 = "soft_irq";
    }
    else
    {
      v5 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v5,
      "cnss_init_direct_cx_host_sol_gpio",
      7u,
      7u,
      "Get Direct CX Host SOL GPIO (%d) from device node\n",
      named_gpio,
      v3,
      vars0);
    v6 = gpio_request((unsigned int)a1[1999], "cnss_direct_cx_host_sol_init_gpio");
    if ( v6 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v8 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v8 = "soft_irq";
      }
      else
      {
        v8 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v8,
        "cnss_init_direct_cx_host_sol_gpio",
        3u,
        3u,
        "Failed to request Direct CX Host SOL GPIO: %d\n",
        v6,
        v7,
        vars0a);
    }
    else
    {
      v9 = gpio_to_desc((unsigned int)a1[1999]);
      gpiod_direction_output_raw(v9, 0);
    }
  }
  return v6;
}
