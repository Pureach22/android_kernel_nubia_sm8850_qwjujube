__int64 __fastcall cnss_pci_enable_msi(__int64 *a1)
{
  unsigned int v1; // w20
  __int64 v2; // x21
  unsigned int msi_assignment; // w0
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  unsigned int *v9; // x20
  __int64 v10; // x3
  unsigned int v11; // w0
  __int64 v12; // x7
  __int64 v13; // x6
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x8
  int variable_u32_array; // w0
  __int64 v18; // x7
  unsigned __int64 v19; // x9
  int v20; // w21
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v24; // x8
  const char *v25; // x1
  int v26; // w20
  unsigned __int64 v27; // x8
  const char *v28; // x1
  __int16 v29; // w9
  const char *v30; // x8
  __int16 v31; // w9
  const char *v32; // x8
  unsigned __int64 v33; // x8
  __int64 v34; // x0
  const char *v35; // x1
  __int16 v36; // w10
  const char *v37; // x9
  __int64 irq_data; // x0
  __int64 v39; // x8
  __int64 v40; // x6
  unsigned __int64 v41; // x8
  __int64 v42; // x0
  const char *v43; // x1
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  __int16 v46; // w9
  const char *v47; // x8
  const char *v48; // x5
  __int16 v49; // w9
  const char *v50; // x8
  const char *v51; // x2
  const char *v52; // x5
  __int16 v53; // w9
  const char *v54; // x8
  __int16 v56; // w9
  const char *v57; // x8
  char v58; // [xsp+0h] [xbp+0h]

  if ( *((_DWORD *)a1 + 6) == 62 )
    return 0;
  v2 = *a1;
  msi_assignment = cnss_pci_get_msi_assignment();
  if ( msi_assignment )
  {
    v1 = msi_assignment;
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
      "cnss_pci_enable_msi",
      3u,
      3u,
      "Failed to get MSI assignment, err = %d\n",
      msi_assignment,
      v6,
      v58);
    return v1;
  }
  v9 = (unsigned int *)a1[41];
  if ( v9 )
  {
    if ( *((_DWORD *)a1 + 6) == 4370 )
      v10 = 6;
    else
      v10 = 2;
    v11 = pci_alloc_irq_vectors(v2, *v9, *v9, v10);
    v13 = *v9;
    if ( v11 != (_DWORD)v13 )
    {
      v26 = v11;
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
        "cnss_pci_enable_msi",
        3u,
        3u,
        "Failed to get enough MSI vectors (%d), available vectors = %d",
        v13,
        v11,
        v58);
      if ( v26 >= 0 )
        v1 = -22;
      else
        v1 = 0;
      goto LABEL_64;
    }
    v14 = *a1;
    if ( !*a1 )
    {
LABEL_63:
      pci_free_irq_vectors(*a1);
      v1 = -22;
LABEL_64:
      a1[41] = 0;
      return v1;
    }
    v15 = *(_DWORD *)(v14 + 2849);
    if ( (v15 & 0x2000) != 0 )
    {
      v16 = a1[1];
      if ( !v16 )
      {
        v33 = _ReadStatusReg(SP_EL0);
        v34 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v33 + 16) & 0xF0000) != 0 )
        {
          v35 = "irq";
        }
        else
        {
          v53 = *(_DWORD *)(v33 + 16);
          v54 = (const char *)(v33 + 2320);
          if ( (v53 & 0xFF00) != 0 )
            v35 = "soft_irq";
          else
            v35 = v54;
        }
        v51 = "cnss_pci_config_msi_addr";
        v52 = "plat_priv is NULL\n";
LABEL_62:
        cnss_debug_ipc_log_print(v34, v35, v51, 3u, 3u, v52, v13, v12, v58);
        goto LABEL_63;
      }
      variable_u32_array = of_property_read_variable_u32_array(
                             *(_QWORD *)(*(_QWORD *)v16 + 760LL),
                             "msix-match-addr",
                             (char *)a1 + 340,
                             1,
                             0);
      v19 = _ReadStatusReg(SP_EL0);
      v20 = variable_u32_array;
      if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
      {
        v21 = "irq";
      }
      else
      {
        v36 = *(_DWORD *)(v19 + 16);
        v37 = (const char *)(v19 + 2320);
        if ( (v36 & 0xFF00) != 0 )
          v21 = "soft_irq";
        else
          v21 = v37;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v21,
        "cnss_pci_config_msi_addr",
        7u,
        7u,
        "MSI-X Match address is 0x%X\n",
        *((unsigned int *)a1 + 85),
        v18,
        v58);
      if ( v20 < 0 )
        goto LABEL_63;
      v14 = *a1;
      v15 = *(_DWORD *)(*a1 + 2849);
    }
    if ( (v15 & 0x2000) != 0 )
    {
      v42 = cnss_ipc_log_context;
      v40 = *(unsigned int *)(*(_QWORD *)(a1[41] + 8) + 12LL);
      v44 = _ReadStatusReg(SP_EL0);
      *((_DWORD *)a1 + 84) = v40;
      if ( (*(_DWORD *)(v44 + 16) & 0xF0000) != 0 )
      {
        v43 = "irq";
      }
      else
      {
        v46 = *(_DWORD *)(v44 + 16);
        v47 = (const char *)(v44 + 2320);
        if ( (v46 & 0xFF00) != 0 )
          v43 = "soft_irq";
        else
          v43 = v47;
      }
      v48 = "MSI-X base data is %d\n";
      goto LABEL_70;
    }
    irq_data = irq_get_irq_data(*(unsigned int *)(v14 + 1116));
    if ( irq_data )
    {
      v39 = *(_QWORD *)(*(_QWORD *)(irq_data + 16) + 16LL);
      if ( v39 )
      {
        v40 = *(unsigned int *)(v39 + 24);
        v41 = _ReadStatusReg(SP_EL0);
        v42 = cnss_ipc_log_context;
        *((_DWORD *)a1 + 84) = v40;
        if ( (*(_DWORD *)(v41 + 16) & 0xF0000) != 0 )
        {
          v43 = "irq";
        }
        else
        {
          v56 = *(_DWORD *)(v41 + 16);
          v57 = (const char *)(v41 + 2320);
          if ( (v56 & 0xFF00) != 0 )
            v43 = "soft_irq";
          else
            v43 = v57;
        }
        v48 = "MSI base data is %d\n";
LABEL_70:
        cnss_debug_ipc_log_print(v42, v43, "cnss_pci_config_msi_data", 7u, 7u, v48, v40, v12, v58);
        return 0;
      }
    }
    v45 = _ReadStatusReg(SP_EL0);
    v34 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v45 + 16) & 0xF0000) != 0 )
    {
      v35 = "irq";
    }
    else
    {
      v49 = *(_DWORD *)(v45 + 16);
      v50 = (const char *)(v45 + 2320);
      if ( (v49 & 0xFF00) != 0 )
        v35 = "soft_irq";
      else
        v35 = v50;
    }
    v51 = "cnss_pci_config_msi_data";
    v52 = "msi_desc is NULL!\n";
    goto LABEL_62;
  }
  v24 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
  {
    v25 = "irq";
  }
  else
  {
    v29 = *(_DWORD *)(v24 + 16);
    v30 = (const char *)(v24 + 2320);
    if ( (v29 & 0xFF00) != 0 )
      v25 = "soft_irq";
    else
      v25 = v30;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v25,
    "cnss_pci_enable_msi",
    3u,
    3u,
    "msi_config is NULL!\n",
    v5,
    v6,
    v58);
  return (unsigned int)-22;
}
