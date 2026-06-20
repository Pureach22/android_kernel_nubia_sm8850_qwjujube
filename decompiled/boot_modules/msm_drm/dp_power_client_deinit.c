__int64 __fastcall dp_power_client_deinit(__int64 a1)
{
  __int64 v1; // x19
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = a1 - 72;
    dp_power_clk_init(a1 - 72, 0);
    return dp_power_regulator_deinit(v1);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_22992C, "dp_power_client_deinit");
  }
}
