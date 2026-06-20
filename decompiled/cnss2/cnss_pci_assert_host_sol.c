__int64 __fastcall cnss_pci_assert_host_sol(__int64 a1)
{
  unsigned int host_sol_value; // w0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x21
  int v6; // w9
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  const char *v10; // x1
  unsigned int v11; // w19
  const char *v12; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  char v20; // w8
  const char *v21; // x1
  char v22; // [xsp+0h] [xbp-10h]

  host_sol_value = cnss_get_host_sol_value(*(_QWORD *)(a1 + 8));
  if ( !host_sol_value )
  {
    if ( !(unsigned int)cnss_get_dev_sol_value(*(_QWORD *)(a1 + 8)) )
      return 4294967285LL;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v10 = "soft_irq";
    }
    else
    {
      v10 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_pci_assert_host_sol",
      7u,
      7u,
      "Assert host SOL GPIO to retry RDDM, expecting link down\n",
      v8,
      v9,
      v22);
    cnss_set_host_sol_value(*(_QWORD *)(a1 + 8), 1u, v14, v15, v16, v17, v18, v19);
    goto LABEL_19;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( (host_sol_value & 0x80000000) == 0 )
  {
    if ( v6 )
    {
      v7 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v7 = "soft_irq";
    }
    else
    {
      v7 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "cnss_pci_assert_host_sol",
      7u,
      7u,
      "Host SOL is already high\n",
      v3,
      v4,
      v22);
LABEL_19:
    v20 = mod_timer(a1 + 400, jiffies + 1250LL);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "__cnss_start_rddm_timer",
      7u,
      7u,
      "Start RDDM timer @%s(%d), ret %d\n",
      (__int64)"cnss_pci_assert_host_sol",
      6906,
      v20);
    return 0;
  }
  v11 = host_sol_value;
  if ( v6 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_pci_assert_host_sol",
    7u,
    7u,
    "Host SOL functionality is not enabled\n",
    v3,
    v4,
    v22);
  return v11;
}
