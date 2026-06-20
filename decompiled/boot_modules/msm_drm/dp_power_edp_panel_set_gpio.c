__int64 __fastcall dp_power_edp_panel_set_gpio(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // x0
  __int64 ipc_log_context; // x0
  __int64 v12; // x0
  __int64 v14; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_edp_panel_set_gpio");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(a1 - 72) + 40LL);
  if ( !v3 )
    return 4294967274LL;
  if ( a2 - 3 > 3 )
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(
      v12,
      "[e][%-4d]Invalid GPIO call with pin state: %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a2);
    printk(&unk_24B4C9, "dp_power_edp_panel_set_gpio");
    return 4294967274LL;
  }
  v4 = *(unsigned int *)(v3 + 40LL * a2);
  if ( (v4 & 0x80000000) != 0 )
  {
    v14 = get_ipc_log_context(v4);
    ipc_log_string(v14, "[e][%-4d]gpio invalid for %d pin\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    printk(&unk_210DEA, "dp_power_edp_panel_set_gpio");
    return 0;
  }
  else
  {
    v6 = gpio_to_desc(v4);
    result = gpiod_direction_output_raw(v6, a3 & 1);
    if ( (_DWORD)result )
    {
      v8 = result;
      v9 = get_ipc_log_context(result);
      ipc_log_string(v9, "[e][%-4d]unable to set gpio rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v8);
      printk(&unk_2595F2, "dp_power_edp_panel_set_gpio");
      return v8;
    }
  }
  return result;
}
