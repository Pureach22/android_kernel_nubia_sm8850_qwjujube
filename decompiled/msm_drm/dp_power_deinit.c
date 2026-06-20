__int64 __fastcall dp_power_deinit(_BYTE *a1)
{
  _BYTE *v2; // x19
  __int64 v3; // x20
  unsigned int v4; // w8
  __int64 v5; // x22
  unsigned int i; // w21
  unsigned int *v7; // x24
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = a1 - 72;
    if ( a1[121] == 1 )
      ((void (__fastcall *)(_BYTE *, __int64, _QWORD))dp_power_clk_enable)(a1, 5, 0);
    ((void (__fastcall *)(_BYTE *, _QWORD, _QWORD))dp_power_clk_enable)(a1, 0, 0);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a1 + 8LL), 4);
    v3 = *((_QWORD *)a1 - 9);
    v4 = *(_DWORD *)(v3 + 32);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v3 + 40);
      for ( i = 0; i < v4; ++i )
      {
        v7 = (unsigned int *)(v5 + 40LL * (int)i);
        v8 = *v7;
        if ( (v8 & 0x80000000) == 0 )
        {
          v9 = gpio_to_desc(v8);
          gpiod_set_raw_value(v9, 0);
          gpio_free(*v7);
          v4 = *(_DWORD *)(v3 + 32);
        }
      }
    }
    dp_power_pinctrl_set(v2, 0);
    dp_power_regulator_ctrl(v2, 0);
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_deinit");
    return 4294967274LL;
  }
}
