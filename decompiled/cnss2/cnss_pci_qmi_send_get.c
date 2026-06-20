__int64 __fastcall cnss_pci_qmi_send_get(__int64 a1)
{
  __int64 v2; // x7
  unsigned int v3; // w20
  __int64 v4; // x0
  __int64 v5; // x6
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    mutex_lock(a1 + 600);
    if ( *(_DWORD *)(a1 + 224) && !*(_DWORD *)(a1 + 236) )
      v3 = cnss_pci_resume_bus(a1);
    else
      v3 = 0;
    v4 = cnss_ipc_log_long_context;
    v5 = (unsigned int)(*(_DWORD *)(a1 + 236) + 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(a1 + 236) = v5;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v8 = *(_DWORD *)(StatusReg + 16);
      v9 = (const char *)(StatusReg + 2320);
      if ( (v8 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v9;
    }
    cnss_debug_ipc_log_print(
      v4,
      v7,
      "cnss_pci_qmi_send_get",
      8u,
      7u,
      "Increased QMI send usage count to %d\n",
      v5,
      v2,
      vars0);
    mutex_unlock(a1 + 600);
  }
  else
  {
    return (unsigned int)-19;
  }
  return v3;
}
