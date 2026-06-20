__int64 __fastcall cnss_pci_runtime_resume(__int64 a1)
{
  __int64 v1; // x23
  _QWORD *v2; // x20
  __int64 v4; // x6
  __int64 v5; // x7
  int v6; // w8
  unsigned __int64 StatusReg; // x21
  const char *v8; // x1
  const char *v10; // x1
  __int64 v11; // x6
  __int64 v12; // x7
  const char *v13; // x1
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x7
  unsigned int v18; // w8
  unsigned int v19; // w19
  const char *v20; // x1
  char v21; // [xsp+0h] [xbp+0h]
  char v22; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967285LL;
  v2 = *(_QWORD **)(v1 + 8);
  if ( !v2 || (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) == 0 )
    return 4294967285LL;
  v6 = *(unsigned __int8 *)(v1 + 49);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( v6 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v8 = "soft_irq";
    }
    else
    {
      v8 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_pci_runtime_resume",
      7u,
      7u,
      "PCI link down recovery is in progress!\n",
      v4,
      v5,
      v21);
    return 4294967285LL;
  }
  else
  {
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
      cnss_ipc_log_long_context,
      v10,
      "cnss_pci_runtime_resume",
      7u,
      7u,
      "Runtime resume start\n",
      v4,
      v5,
      v21);
    if ( (v2[66] == 4369 || of_find_property(*(_QWORD *)(*v2 + 760LL), "fig-direct-cx", 0))
      && (cnss_set_cxpc(a1, 0) & 0x80000000) != 0 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v13 = "soft_irq";
      }
      else
      {
        v13 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "cnss_pci_runtime_resume",
        3u,
        3u,
        "failed to set cx to CX_RET\n",
        v11,
        v12,
        v22);
    }
    v14 = *(_QWORD *)(v1 + 40);
    if ( v14 && (v15 = *(_QWORD *)(v14 + 120)) != 0 && (v16 = *(__int64 (__fastcall **)(_QWORD))(v15 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v16 - 1) != -55329153 )
        __break(0x8228u);
      v18 = v16(a1 - 200);
      if ( !v18 )
      {
        v18 = *(_DWORD *)(v1 + 224);
        if ( v18 )
        {
          cnss_auto_resume(a1);
          v18 = 0;
        }
      }
    }
    else
    {
      v18 = cnss_auto_resume(a1);
    }
    v19 = v18;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v20,
      "cnss_pci_runtime_resume",
      7u,
      7u,
      "Runtime resume status: %d\n",
      v18,
      v17,
      v22);
    return v19;
  }
}
