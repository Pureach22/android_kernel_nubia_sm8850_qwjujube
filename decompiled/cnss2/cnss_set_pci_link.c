__int64 __fastcall cnss_set_pci_link(
        _QWORD *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x25
  const char *v12; // x1
  const char *v13; // x6
  __int64 v14; // x7
  unsigned int v15; // w21
  unsigned int v16; // w26
  unsigned int v17; // w28
  const char *v18; // x1
  const char *v19; // x1
  __int64 v20; // x21
  const char *v21; // x20
  unsigned int input_gpio_value; // w0
  __int64 v23; // x7
  __int64 v24; // x6
  __int64 v25; // x7
  char *v26; // x1
  __int64 v27; // x20
  __int64 v28; // x0
  const char *v29; // x1
  const char *v30; // x1
  int v31; // w20
  const char *v32; // x1
  __int64 v33; // x6
  __int64 v34; // x7
  __int16 v35; // w22
  const char *v36; // x1
  char v38; // [xsp+0h] [xbp-10h]
  int v39; // [xsp+0h] [xbp-10h]
  char v40; // [xsp+0h] [xbp-10h]
  char v41; // [xsp+0h] [xbp-10h]
  unsigned int v42; // [xsp+4h] [xbp-Ch]
  __int64 v43; // [xsp+8h] [xbp-8h]

  v8 = a1[1];
  StatusReg = _ReadStatusReg(SP_EL0);
  v43 = v8;
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
  if ( (a2 & 1) != 0 )
    v13 = "Resuming";
  else
    v13 = "Suspending";
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v12,
    "cnss_set_pci_link",
    7u,
    7u,
    "%s PCI link\n",
    (__int64)v13,
    a8,
    v38);
  v39 = a2;
  if ( (a2 & 1) != 0 )
  {
    v15 = msm_pcie_pm_control(4, *(unsigned __int8 *)(*(_QWORD *)(*a1 + 16LL) + 248LL));
    if ( v15 )
    {
      v16 = 1;
      v17 = 500;
      do
      {
        v18 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v18 = "soft_irq";
          else
            v18 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v18,
          "cnss_pci_set_link_up",
          3u,
          3u,
          "Failed to resume PCI link with default option, err = %d\n",
          v15,
          v14,
          v39);
        if ( v16 == 4 )
          break;
        v19 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v19 = "soft_irq";
          else
            v19 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v19,
          "cnss_set_pci_link",
          7u,
          7u,
          "Retry PCI link training #%d\n",
          v16,
          v14,
          v39);
        v20 = cnss_ipc_log_context;
        v21 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = (const char *)(StatusReg + 2320);
        }
        input_gpio_value = cnss_get_input_gpio_value(v43, v42);
        cnss_debug_ipc_log_print(
          v20,
          v21,
          "cnss_set_pci_link",
          7u,
          7u,
          "Value of SW_CTRL GPIO: %d\n",
          input_gpio_value,
          v23,
          v40);
        if ( *((_BYTE *)a1 + 49) )
          msleep(v17);
        v15 = msm_pcie_pm_control(4, *(unsigned __int8 *)(*(_QWORD *)(*a1 + 16LL) + 248LL));
        ++v16;
        v17 += 500;
      }
      while ( v15 );
    }
  }
  else
  {
    cnss_pci_get_link_status(a1);
    if ( *((_BYTE *)a1 + 232) )
    {
      if ( *((unsigned __int16 *)a1 + 122) >= 3u )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          v26 = "irq";
        else
          v26 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
        cnss_debug_ipc_log_print(
          cnss_ipc_log_long_context,
          v26,
          "cnss_set_pci_link_status",
          7u,
          7u,
          "Set PCI link status to: %u\n",
          1,
          v25,
          a2);
        if ( !(unsigned int)msm_pcie_set_link_bandwidth(*a1) )
          *((_WORD *)a1 + 122) = 2;
      }
      v27 = *a1;
      if ( *((_BYTE *)a1 + 232) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v29 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v29 = "soft_irq";
        }
        else
        {
          v29 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_long_context,
          v29,
          "cnss_pci_set_link_down",
          7u,
          7u,
          "Use PCIe DRV suspend\n",
          v24,
          v25,
          v39);
        v28 = 1;
      }
      else
      {
        v28 = 2;
      }
    }
    else
    {
      v27 = *a1;
      v28 = 2;
    }
    v15 = msm_pcie_pm_control(v28, *(unsigned __int8 *)(*(_QWORD *)(v27 + 16) + 248LL));
    if ( v15 )
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
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v30,
        "cnss_pci_set_link_down",
        3u,
        3u,
        "Failed to suspend PCI link with default option, err = %d\n",
        v15,
        v14,
        v39);
    }
  }
  if ( *((_BYTE *)a1 + 232) && (((v15 != 0) ^ v39) & 1) != 0 )
  {
    v31 = *((unsigned __int16 *)a1 + 121);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v32 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v32 = "soft_irq";
    }
    else
    {
      v32 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v32,
      "cnss_set_pci_link_status",
      7u,
      7u,
      "Set PCI link status to: %u\n",
      2,
      v14,
      v39);
    v35 = *((_WORD *)a1 + 120);
    if ( v35 && v31 )
    {
      if ( !(unsigned int)msm_pcie_set_link_bandwidth(*a1) )
        *((_WORD *)a1 + 122) = v35;
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v36 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v36 = "soft_irq";
      }
      else
      {
        v36 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v36,
        "cnss_set_pci_link_status",
        3u,
        3u,
        "PCI link speed or width is not valid\n",
        v33,
        v34,
        v41);
    }
  }
  return v15;
}
