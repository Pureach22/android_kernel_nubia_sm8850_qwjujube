__int64 __fastcall cnss_pci_qmi_send_put(__int64 a1)
{
  __int64 v2; // x7
  int v3; // w8
  __int64 v4; // x6
  unsigned int v5; // w20
  unsigned __int64 StatusReg; // x20
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v11; // x8
  const char *v12; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    mutex_lock(a1 + 600);
    v3 = *(_DWORD *)(a1 + 236);
    if ( v3 )
    {
      v4 = (unsigned int)(v3 - 1);
      *(_DWORD *)(a1 + 236) = v4;
    }
    else
    {
      v4 = 0;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
      cnss_ipc_log_long_context,
      v7,
      "cnss_pci_qmi_send_put",
      8u,
      7u,
      "Decreased QMI send usage count to %d\n",
      v4,
      v2,
      vars0);
    if ( *(_DWORD *)(a1 + 224) && !*(_DWORD *)(a1 + 236) )
    {
      v11 = *(_QWORD *)(a1 + 8);
      if ( v11 )
      {
        if ( !(((unsigned int)*(_QWORD *)(v11 + 552) >> 11) & 1 | *(unsigned __int8 *)(a1 + 49)) )
        {
          v5 = cnss_pci_suspend_bus((_QWORD *)a1);
          goto LABEL_14;
        }
      }
      else
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
          "cnss_pcie_is_device_down",
          3u,
          3u,
          "plat_priv is NULL\n",
          v8,
          v9,
          vars0a);
      }
    }
    v5 = 0;
LABEL_14:
    mutex_unlock(a1 + 600);
    return v5;
  }
  return (unsigned int)-19;
}
