__int64 __fastcall cnss_pci_runtime_suspend(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v4; // x6
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  const char *v8; // x1
  bool v10; // zf
  unsigned __int64 v11; // x22
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  const char *v15; // x5
  __int64 v16; // x7
  __int64 v17; // x8
  __int64 (__fastcall **v18)(_QWORD); // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w19
  __int64 v21; // x19
  _DWORD *v22; // x20
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  const char *v28; // x1
  unsigned int v29; // w0
  unsigned int v30; // w20
  unsigned __int64 v31; // x8
  __int16 v32; // w9
  const char *v33; // x8
  char v34; // [xsp+0h] [xbp+0h]
  char v35; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967285LL;
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 || (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) == 0 )
    return 4294967285LL;
  if ( *(_BYTE *)(v1 + 49) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v14;
    }
    v15 = "PCI link down recovery is in progress!\n";
LABEL_17:
    cnss_debug_ipc_log_print(v7, v8, "cnss_pci_runtime_suspend", 7u, 7u, v15, v4, v5, v34);
    return 4294967285LL;
  }
  if ( (*(_QWORD *)(v2 + 6680) & 0x200) == 0 && *(_BYTE *)(v1 + 697) == 1 )
  {
    v10 = (unsigned __int8)*(_DWORD *)(v1 + 228) == 0;
    *(_BYTE *)(v1 + 232) = *(_DWORD *)(v1 + 228);
    if ( v10 )
    {
      v31 = _ReadStatusReg(SP_EL0);
      v7 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v31 + 16) & 0xF0000) != 0 )
      {
        v8 = "irq";
      }
      else
      {
        v32 = *(_DWORD *)(v31 + 16);
        v33 = (const char *)(v31 + 2320);
        if ( (v32 & 0xFF00) != 0 )
          v8 = "soft_irq";
        else
          v8 = v33;
      }
      v15 = "Firmware does not support non-DRV suspend, reject\n";
      goto LABEL_17;
    }
  }
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(v11 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v12,
    "cnss_pci_runtime_suspend",
    7u,
    7u,
    "Runtime suspend start\n",
    v4,
    v5,
    v34);
  v17 = *(_QWORD *)(v1 + 40);
  if ( v17 )
  {
    v18 = *(__int64 (__fastcall ***)(_QWORD))(v17 + 120);
    if ( v18 )
    {
      v19 = *v18;
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -55329153 )
          __break(0x8228u);
        v20 = v19(a1 - 200);
        if ( !v20 )
          goto LABEL_34;
        goto LABEL_33;
      }
    }
  }
  v21 = *(_QWORD *)(a1 + 152);
  if ( !v21 || (v22 = *(_DWORD **)(v21 + 8)) == nullptr )
  {
    v20 = -19;
LABEL_33:
    *(_BYTE *)(v1 + 232) = 0;
    goto LABEL_34;
  }
  mutex_lock(v21 + 600);
  if ( !*(_DWORD *)(v21 + 236) )
  {
    v29 = cnss_pci_suspend_bus((_QWORD *)v21);
    if ( v29 )
    {
      v30 = v29;
      mutex_unlock(v21 + 600);
      v20 = v30;
      goto LABEL_33;
    }
  }
  *(_DWORD *)(v21 + 224) = 1;
  mutex_unlock(v21 + 600);
  *(_BYTE *)(v21 + 260) = 1;
  cnss_setup_bus_bandwidth(v22, 0, 0, v23, v24, v25, v26, v27);
  v20 = 0;
LABEL_34:
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v28 = "irq";
  }
  else if ( (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
  {
    v28 = "soft_irq";
  }
  else
  {
    v28 = (const char *)(v11 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v28,
    "cnss_pci_runtime_suspend",
    7u,
    7u,
    "Runtime suspend status: %d\n",
    v20,
    v16,
    v35);
  return v20;
}
