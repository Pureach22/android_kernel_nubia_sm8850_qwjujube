__int64 __fastcall cnss_pci_enable_bus(__int64 *a1)
{
  __int64 v2; // x19
  __int64 v3; // x7
  unsigned int v4; // w0
  __int64 v5; // x1
  unsigned int v6; // w0
  __int64 v7; // x7
  unsigned int v8; // w20
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  unsigned __int64 v11; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  unsigned int v15; // w0
  __int64 v16; // x7
  unsigned __int64 v17; // x8
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  __int64 v21; // x6
  unsigned __int64 v22; // x22
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  unsigned int v26; // w0
  __int64 v27; // x7
  __int64 v28; // x0
  const char *v29; // x1
  unsigned int v30; // w0
  const char *v31; // x5
  __int64 v32; // x0
  __int64 v33; // x6
  __int64 v34; // x7
  const char *v36; // x1
  char v37; // [xsp+0h] [xbp-10h]
  char v38; // [xsp+0h] [xbp-10h]
  unsigned __int16 v39; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v39 = 0;
  pci_read_config_word(v2, 2, &v39);
  v3 = *(unsigned int *)(a1[2] + 4);
  if ( (_DWORD)v3 == v39 )
  {
    v4 = pci_assign_resource(v2, 0);
    if ( v4 )
    {
      v8 = v4;
      printk(&unk_54565, v4);
      goto LABEL_51;
    }
    v6 = pci_enable_device(v2, v5);
    if ( v6 )
    {
      v8 = v6;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(StatusReg + 16);
        v20 = (const char *)(StatusReg + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v20;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_pci_enable_bus",
        3u,
        3u,
        "Failed to enable PCI device, err = %d\n",
        v6,
        v7,
        v37);
      goto LABEL_51;
    }
    v15 = pci_request_region(v2, 0, "cnss");
    if ( v15 )
    {
      v8 = v15;
      v17 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
      {
        v18 = "irq";
      }
      else
      {
        v24 = *(_DWORD *)(v17 + 16);
        v25 = (const char *)(v17 + 2320);
        if ( (v24 & 0xFF00) != 0 )
          v18 = "soft_irq";
        else
          v18 = v25;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_pci_enable_bus",
        3u,
        3u,
        "Failed to request PCI region, err = %d\n",
        v15,
        v16,
        v37);
      goto LABEL_50;
    }
    v21 = 0xFFFFFFFFLL;
    if ( (unsigned int)v39 - 4353 <= 0x11 && ((1 << (v39 - 1)) & 0x32245) != 0 )
      v21 = 0xFFFFFFFFFLL;
    a1[4] = v21;
    v22 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
    {
      v23 = "soft_irq";
    }
    else
    {
      v23 = (const char *)(v22 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_pci_enable_bus",
      7u,
      7u,
      "Set PCI DMA MASK (0x%llx)\n",
      v21,
      v16,
      v37);
    v26 = dma_set_mask(v2 + 200, a1[4]);
    if ( v26 )
    {
      v8 = v26;
      v28 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
      {
        v29 = "irq";
      }
      else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
      {
        v29 = "soft_irq";
      }
      else
      {
        v29 = (const char *)(v22 + 2320);
      }
      v31 = "Failed to set PCI DMA mask, err = %d\n";
    }
    else
    {
      v30 = dma_set_coherent_mask(v2 + 200, a1[4]);
      if ( !v30 )
      {
        v32 = pci_iomap(v2, 0, 0);
        a1[40] = v32;
        if ( v32 )
        {
          pci_save_state(v2);
          a1[8] = pci_store_saved_state(v2);
          pci_set_master(v2);
          v8 = 0;
          goto LABEL_51;
        }
        if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
        {
          v36 = "irq";
        }
        else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
        {
          v36 = "soft_irq";
        }
        else
        {
          v36 = (const char *)(v22 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v36,
          "cnss_pci_enable_bus",
          3u,
          3u,
          "Failed to do PCI IO map!\n",
          v33,
          v34,
          v38);
        v8 = -5;
        goto LABEL_49;
      }
      v8 = v30;
      v28 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
      {
        v29 = "irq";
      }
      else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
      {
        v29 = "soft_irq";
      }
      else
      {
        v29 = (const char *)(v22 + 2320);
      }
      v31 = "Failed to set PCI coherent DMA mask, err = %d\n";
    }
    cnss_debug_ipc_log_print(v28, v29, "cnss_pci_enable_bus", 3u, 3u, v31, v8, v27, v38);
LABEL_49:
    pci_release_region(v2, 0);
LABEL_50:
    pci_disable_device(v2);
    goto LABEL_51;
  }
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else
  {
    v13 = *(_DWORD *)(v11 + 16);
    v14 = (const char *)(v11 + 2320);
    if ( (v13 & 0xFF00) != 0 )
      v12 = "soft_irq";
    else
      v12 = v14;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_pci_enable_bus",
    3u,
    3u,
    "PCI device ID mismatch, config ID: 0x%x, probe ID: 0x%x\n",
    v39,
    v3,
    v37);
  v8 = -5;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v8;
}
