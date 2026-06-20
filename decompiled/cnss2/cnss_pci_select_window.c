__int64 __fastcall cnss_pci_select_window(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  int v5; // w23
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned int v8; // w20
  __int64 v9; // x9
  __int64 v10; // x7
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x9
  unsigned int v17; // w0
  unsigned __int64 v18; // x23
  char *v19; // x1
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x7
  const char *v28; // x1
  char v30; // [xsp+0h] [xbp+0h]
  char v31; // [xsp+0h] [xbp+0h]

  v3 = *(_QWORD *)(a1 + 8);
  v4 = (a2 >> 19) & 0x3F | 0x40000000;
  v5 = (a2 >> 19) & 0x3F;
  v6 = *(_QWORD *)(v3 + 528);
  v7 = v6 - 4366;
  if ( v6 == 4354 )
    v8 = (a2 >> 19) & 0x3F | 0x80000000;
  else
    v8 = (a2 >> 19) & 0x3F | 0x40000000;
  if ( v7 <= 4 && ((1LL << v7) & 0x19) != 0 )
  {
    v9 = 12920;
  }
  else
  {
    v9 = 12556;
    v4 = v8;
  }
  writel_relaxed(v4, *(_QWORD *)(a1 + 320) + v9);
  if ( v5 != *(_DWORD *)(a1 + 360) )
  {
    *(_DWORD *)(a1 + 360) = v5;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v14;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_pci_select_window",
      7u,
      7u,
      "Config PCIe remap window register to 0x%x\n",
      v8,
      v10,
      v30);
  }
  v15 = *(_QWORD *)(v3 + 528) - 4366LL;
  if ( v15 > 4 )
    v16 = 12556;
  else
    v16 = (__int64)*(&off_5BB60 + v15);
  v17 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 320) + v16));
  if ( v17 == v8 )
    return 0;
  v18 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
    v19 = "irq";
  else
    v19 = (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v18 + 2320);
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_pci_select_window",
    3u,
    3u,
    "Failed to config window register to 0x%x, current value: 0x%x\n",
    v8,
    v17,
    v30);
  if ( (unsigned int)cnss_pci_check_link_status(a1, v20, v21, v22, v23, v24, v25, v26)
    || (*(_QWORD *)(v3 + 552) & 0x40000) != 0 )
  {
    return 0;
  }
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v28 = "irq";
  }
  else if ( (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
  {
    v28 = "soft_irq";
  }
  else
  {
    v28 = (const char *)(v18 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v28,
    "cnss_pci_select_window",
    3u,
    3u,
    "ASSERT at line %d\n",
    1310,
    v27,
    v31);
  __break(0x800u);
  return 4294967291LL;
}
