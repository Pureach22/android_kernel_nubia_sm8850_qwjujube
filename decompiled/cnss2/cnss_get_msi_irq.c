__int64 __fastcall cnss_get_msi_irq(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w0
  unsigned __int64 StatusReg; // x9
  unsigned int v5; // w20
  const char *v6; // x1
  __int16 v7; // w10
  const char *v8; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v3 = pci_irq_vector(a1 - 200);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = v3;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else
  {
    v7 = *(_DWORD *)(StatusReg + 16);
    v8 = (const char *)(StatusReg + 2320);
    if ( (v7 & 0xFF00) != 0 )
      v6 = "soft_irq";
    else
      v6 = v8;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "cnss_get_msi_irq",
    7u,
    7u,
    "Get IRQ number %d for vector index %d\n",
    v3,
    a2,
    vars0);
  return v5;
}
