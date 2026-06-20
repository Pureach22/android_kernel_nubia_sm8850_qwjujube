__int64 __fastcall cnss_pci_init(__int64 *a1)
{
  __int64 v2; // x8
  __int64 property; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  bool v6; // zf
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int64 v9; // x10
  unsigned __int64 v10; // x22
  unsigned int v11; // w25
  unsigned int v12; // w0
  const char *v13; // x1
  const char *v14; // x1
  unsigned int i; // w27
  unsigned int v16; // w0
  __int64 v17; // x6
  __int64 v18; // x7
  unsigned int v19; // w26
  const char *v20; // x1
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  const char *v24; // x1
  unsigned int v25; // w0
  __int64 v26; // x7
  unsigned __int64 v27; // x8
  const char *v28; // x1
  __int64 v29; // x6
  __int64 v30; // x7
  __int16 v31; // w9
  const char *v32; // x8
  unsigned __int64 v34; // x8
  const char *v35; // x1
  __int16 v36; // w9
  const char *v37; // x8
  char v38; // [xsp+0h] [xbp-30h]
  __int64 v39; // [xsp+8h] [xbp-28h]
  __int64 v40; // [xsp+10h] [xbp-20h]
  __int64 v41; // [xsp+18h] [xbp-18h]
  int v42; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v42 = 0;
  property = of_get_property(*(_QWORD *)(v2 + 760), "qcom,wlan-rc-num", &v42);
  if ( property )
    v6 = v42 == 0;
  else
    v6 = 1;
  if ( v6 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_pci_init",
      3u,
      3u,
      "Failed to get PCIe RC number from DT\n",
      v4,
      v5,
      v38);
    v19 = 0;
  }
  else if ( v42 >> 2 < 1 )
  {
LABEL_45:
    if ( (cnss_driver_registered & 1) != 0 )
    {
      v19 = 0;
    }
    else
    {
      v25 = _pci_register_driver(&cnss_pci_driver, &_this_module, "cnss2");
      if ( v25 )
      {
        v19 = v25;
        v27 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
        {
          v28 = "irq";
        }
        else
        {
          v31 = *(_DWORD *)(v27 + 16);
          v32 = (const char *)(v27 + 2320);
          if ( (v31 & 0xFF00) != 0 )
            v28 = "soft_irq";
          else
            v28 = v32;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v28,
          "cnss_pci_init",
          3u,
          3u,
          "Failed to register to PCI framework, err = %d\n",
          v25,
          v26,
          v38);
      }
      else if ( (cnss_pci_is_sync_probe() & 1) != 0 && !a1[1] )
      {
        v34 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v34 + 16) & 0xF0000) != 0 )
        {
          v35 = "irq";
        }
        else
        {
          v36 = *(_DWORD *)(v34 + 16);
          v37 = (const char *)(v34 + 2320);
          if ( (v36 & 0xFF00) != 0 )
            v35 = "soft_irq";
          else
            v35 = v37;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v35,
          "cnss_pci_init",
          3u,
          3u,
          "Failed to probe PCI driver\n",
          v29,
          v30,
          v38);
        pci_unregister_driver(&cnss_pci_driver);
        v19 = -19;
      }
      else
      {
        v19 = 0;
        cnss_driver_registered = 1;
      }
    }
  }
  else
  {
    v9 = 0;
    v10 = _ReadStatusReg(SP_EL0);
    v39 = (unsigned int)((v42 >> 2) - 1);
    v40 = property;
    while ( 2 )
    {
      v41 = v9;
      v11 = bswap32(*(_DWORD *)(property + 4 * v9));
      if ( a1[66] == 4355 )
      {
        v12 = cnss_pci_set_max_link_speed(a1[1], v11, 2);
        if ( v12 != -517 )
        {
          v5 = v12;
          if ( v12 )
          {
            v13 = "irq";
            if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
                v13 = "soft_irq";
              else
                v13 = (const char *)(v10 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v13,
              "cnss_pci_enumerate",
              3u,
              3u,
              "Failed to set max PCIe RC%x link speed to Gen2, err = %d\n",
              v11,
              v12,
              v38);
          }
        }
      }
      v14 = "irq";
      if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = (const char *)(v10 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_pci_enumerate",
        7u,
        7u,
        "Trying to enumerate with PCIe RC%x\n",
        v11,
        v5,
        v38);
      for ( i = 1; ; ++i )
      {
        v16 = cnss_pci_enumerate(a1, v11);
        if ( !v16 )
        {
          *((_DWORD *)a1 + 130) = v11;
          goto LABEL_45;
        }
        v19 = v16;
        if ( v16 == -517 )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
          {
            v24 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v24 = "soft_irq";
          }
          else
          {
            v24 = (const char *)(v10 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v24,
            "cnss_pci_enumerate",
            7u,
            7u,
            "PCIe RC driver is not ready, defer probe\n",
            v17,
            v18,
            v38);
          v19 = -517;
          goto LABEL_61;
        }
        v20 = "irq";
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
            v20 = "soft_irq";
          else
            v20 = (const char *)(v10 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v20,
          "cnss_pci_enumerate",
          3u,
          3u,
          "Failed to enable PCIe RC%x, err = %d\n",
          v11,
          v16,
          v38);
        if ( i == 4 )
          break;
        v21 = "irq";
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = (const char *)(v10 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_pci_enumerate",
          7u,
          7u,
          "Retry PCI link training #%d\n",
          i,
          v5,
          v38);
      }
      property = v40;
      v9 = v41 + 1;
      if ( v41 != v39 )
        continue;
      break;
    }
  }
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return v19;
}
