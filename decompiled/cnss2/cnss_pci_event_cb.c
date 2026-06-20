unsigned int *__fastcall cnss_pci_event_cb(
        unsigned int *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 v9; // x19
  __int64 v10; // x6
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x23
  int v13; // w8
  const char *v14; // x1
  const char *v15; // x1
  const char *v16; // x1
  const char *v17; // x1
  const char *v18; // x1
  const char *v19; // x1
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 v29; // x8
  const char *v30; // x1
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  char v38; // [xsp+0h] [xbp+0h]
  char v39; // [xsp+0h] [xbp+0h]

  if ( !result )
    return result;
  v8 = *((_QWORD *)result + 1);
  if ( !v8 )
    return result;
  v9 = *(_QWORD *)(v8 + 352);
  if ( !v9 )
    return result;
  v10 = *result;
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)v9;
  v13 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( (int)v10 <= 15 )
  {
    if ( (_DWORD)v10 == 1 )
    {
      if ( v13 )
      {
        v18 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v18 = "soft_irq";
      }
      else
      {
        v18 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_pci_event_cb",
        7u,
        7u,
        "PCI link down event callback\n",
        v10,
        a8,
        v38);
      return cnss_pci_handle_linkdown((__int64 *)v9);
    }
    if ( (_DWORD)v10 == 4 )
    {
      if ( v13 )
      {
        v15 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v15 = "soft_irq";
      }
      else
      {
        v15 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_pci_event_cb",
        7u,
        7u,
        "PCI Wake up event callback\n",
        v10,
        a8,
        v38);
      if ( *(_BYTE *)(v9 + 260) && *(_DWORD *)(v9 + 224) || *(_DWORD *)(v12 + 700) == 3 )
      {
        *(_BYTE *)(v9 + 260) = 0;
        cnss_pci_pm_request_resume((__int64 *)v9, v31, v32, v33, v34, v35, v36, v37);
      }
      return (unsigned int *)complete(v9 + 368);
    }
LABEL_20:
    if ( v13 )
    {
      v19 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v19 = "soft_irq";
    }
    else
    {
      v19 = (const char *)(StatusReg + 2320);
    }
    return (unsigned int *)cnss_debug_ipc_log_print(
                             cnss_ipc_log_context,
                             v19,
                             "cnss_pci_event_cb",
                             3u,
                             3u,
                             "Received invalid PCI event: %d\n",
                             v10,
                             a8,
                             v38);
  }
  if ( (_DWORD)v10 == 16 )
  {
    if ( v13 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(StatusReg + 2320);
    }
    result = (unsigned int *)cnss_debug_ipc_log_print(
                               cnss_ipc_log_context,
                               v16,
                               "cnss_pci_event_cb",
                               7u,
                               7u,
                               "DRV subsystem is connected\n",
                               v10,
                               a8,
                               v38);
    *(_DWORD *)(v9 + 228) = 1;
    return result;
  }
  if ( (_DWORD)v10 == 32 )
  {
    if ( v13 )
    {
      v17 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v17 = "soft_irq";
    }
    else
    {
      v17 = (const char *)(StatusReg + 2320);
    }
    result = (unsigned int *)cnss_debug_ipc_log_print(
                               cnss_ipc_log_context,
                               v17,
                               "cnss_pci_event_cb",
                               7u,
                               7u,
                               "DRV subsystem is disconnected\n",
                               v10,
                               a8,
                               v38);
    if ( *(_DWORD *)(v9 + 224) )
      result = (unsigned int *)cnss_pci_pm_request_resume((__int64 *)v9, v20, v21, v22, v23, v24, v25, v26);
    *(_DWORD *)(v9 + 228) = 0;
    return result;
  }
  if ( (_DWORD)v10 != 64 )
    goto LABEL_20;
  if ( v13 )
  {
    v14 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v14 = "soft_irq";
  }
  else
  {
    v14 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v14,
    "cnss_pci_event_cb",
    7u,
    7u,
    "PCI link recover callback\n",
    v10,
    a8,
    v38);
  v29 = *(_QWORD *)(v9 + 8);
  if ( v29 )
  {
    if ( !*(_BYTE *)(v29 + 7955) )
      *(_QWORD *)(v29 + 6680) |= 1uLL;
    result = (unsigned int *)msm_pcie_pm_control(32, *(unsigned __int8 *)(*(_QWORD *)(v8 + 16) + 248LL));
    if ( (_DWORD)result )
      return cnss_pci_handle_linkdown((__int64 *)v9);
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v30 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v30 = "soft_irq";
    }
    else
    {
      v30 = (const char *)(StatusReg + 2320);
    }
    return (unsigned int *)cnss_debug_ipc_log_print(
                             cnss_ipc_log_context,
                             v30,
                             "cnss_pci_event_cb",
                             3u,
                             3u,
                             "plat_priv is NULL\n",
                             v27,
                             v28,
                             v39);
  }
  return result;
}
