__int64 __fastcall dp_link_psm_config(__int64 a1, unsigned __int8 *a2, char a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned int v7; // w20
  __int64 v8; // x0
  int v9; // w2
  const char *v10; // x19

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24B695, "dp_link_psm_config");
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL);
  if ( (a3 & 1) != 0 )
  {
    result = dp_link_power_down(v4, a2);
    if ( !(_DWORD)result )
      return result;
  }
  else
  {
    result = dp_link_power_up(v4, a2);
    if ( !(_DWORD)result )
      return result;
  }
  v7 = result;
  v8 = get_ipc_log_context(result);
  v9 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
  if ( (a3 & 1) != 0 )
    v10 = "enter";
  else
    v10 = "exit";
  ipc_log_string(v8, "[e][%-4d]Failed to %s low power mode\n", v9, v10);
  printk(&unk_25D5EC, "dp_link_psm_config");
  return v7;
}
