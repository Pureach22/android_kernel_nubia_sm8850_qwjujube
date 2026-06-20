__int64 __fastcall cnss_pci_start_xdump_timer(__int64 a1)
{
  char v1; // w0
  unsigned __int64 StatusReg; // x10
  const char *v3; // x1
  __int16 v4; // w11
  const char *v5; // x10

  v1 = mod_timer(a1 + 400, jiffies + 1250LL);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v3 = "irq";
  }
  else
  {
    v4 = *(_DWORD *)(StatusReg + 16);
    v5 = (const char *)(StatusReg + 2320);
    if ( (v4 & 0xFF00) != 0 )
      v3 = "soft_irq";
    else
      v3 = v5;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v3,
           "__cnss_start_rddm_timer",
           7u,
           7u,
           "Start RDDM timer @%s(%d), ret %d\n",
           (__int64)"cnss_pci_start_xdump_timer",
           987,
           v1);
}
