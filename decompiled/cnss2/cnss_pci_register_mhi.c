__int64 __fastcall cnss_pci_register_mhi(_QWORD *a1)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 result; // x0
  _QWORD *v5; // x0
  __int64 v6; // x6
  __int64 v7; // x7
  _QWORD *v8; // x25
  __int64 v9; // x9
  __int64 v10; // x7
  unsigned __int64 v11; // x8
  const char *v12; // x1
  unsigned __int64 StatusReg; // x28
  const char *v14; // x1
  __int64 v15; // x0
  __int64 v16; // x7
  unsigned int v17; // w8
  unsigned int v18; // w20
  const char *v19; // x1
  const char *v20; // x1
  __int16 v21; // w9
  const char *v22; // x8
  __int64 v23; // x27
  unsigned __int64 v24; // x22
  __int64 v25; // x23
  __int64 v26; // x27
  unsigned int v27; // w19
  unsigned int v28; // w26
  const char *v29; // x1
  unsigned __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x9
  unsigned int soc_info; // w0
  __int64 v36; // x7
  unsigned int v37; // w8
  __int64 v38; // x0
  const char *v39; // x1
  __int64 v40; // x6
  __int64 v41; // x0
  __int64 v42; // x7
  int v43; // w8
  const char *v44; // x1
  const char *v45; // x2
  const char *v46; // x5
  unsigned __int64 v47; // x8
  int v48; // w10
  void *v49; // x9
  bool v50; // cc
  unsigned int v51; // w8
  void *v52; // x1
  bool v53; // cf
  unsigned int v54; // w8
  char v55; // w9
  unsigned int v56; // w0
  unsigned int v57; // w8
  char v58; // [xsp+0h] [xbp-40h]
  char v59; // [xsp+0h] [xbp-40h]
  __int64 v60; // [xsp+20h] [xbp-20h] BYREF
  unsigned int v61; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v62[2]; // [xsp+30h] [xbp-10h] BYREF

  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = a1[1];
  v60 = 0;
  if ( (unsigned int)cnss_qmi_init(v3) )
  {
    result = 4294967274LL;
    goto LABEL_93;
  }
  if ( *((_DWORD *)a1 + 6) == 62 )
  {
    result = 0;
    goto LABEL_93;
  }
  v5 = (_QWORD *)mhi_alloc_controller();
  if ( v5 )
  {
    a1[43] = v5;
    v5[1] = v2 + 200;
    v8 = v5;
    v5[11] = v3 + 6515;
    v5[4] = a1[40];
    v9 = *(_QWORD *)(*a1 + 1128LL);
    if ( v9 )
      v10 = v9 - *(_QWORD *)(*a1 + 1120LL) + 1;
    else
      v10 = 0;
    v5[18] = v10;
    StatusReg = _ReadStatusReg(SP_EL0);
    v60 = *(_QWORD *)(*a1 + 1120LL);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
      "cnss_pci_register_mhi",
      7u,
      7u,
      "BAR starts at %pa, length is %x\n",
      (__int64)&v60,
      v10,
      v58);
    v15 = *a1 + 200LL;
    v62[0] = 0;
    v61 = 0;
    v17 = ((__int64 (__fastcall *)(__int64, const char *, char *, _QWORD *, unsigned int *))cnss_get_user_msi_assignment)(
            v15,
            "MHI",
            (char *)v62 + 4,
            v62,
            &v61);
    if ( v17 )
      goto LABEL_17;
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
    v23 = HIDWORD(v62[0]);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v20,
      "cnss_pci_get_mhi_msi",
      7u,
      7u,
      "Number of assigned MSI for MHI is %d, base vector is %d\n",
      HIDWORD(v62[0]),
      v61,
      v59);
    if ( (v23 & 0x80000000) != 0 || (v24 = 4 * v23, (v25 = _kmalloc_noprof(4 * v23, 3520)) == 0) )
    {
      v17 = -12;
LABEL_17:
      v18 = v17;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v19,
        "cnss_pci_register_mhi",
        3u,
        3u,
        "Failed to get MSI for MHI, err = %d\n",
        v17,
        v16,
        v59);
      goto LABEL_92;
    }
    if ( (int)v23 >= 1 )
    {
      v26 = 0;
      do
      {
        v27 = v61;
        v28 = pci_irq_vector(*a1);
        v29 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v29 = "soft_irq";
          else
            v29 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v29,
          "cnss_get_msi_irq",
          7u,
          7u,
          "Get IRQ number %d for vector index %d\n",
          v28,
          v27 + (unsigned int)v26,
          v59);
        v30 = 4 * v26;
        if ( v24 < 4 * v26 || v24 - 4 * v26 < 4 || (v30 & 0x8000000000000000LL) != 0 || v24 < v30 )
          __break(1u);
        *(_DWORD *)(v25 + 4 * v26++) = v28;
      }
      while ( v26 < SHIDWORD(v62[0]) );
      LODWORD(v23) = HIDWORD(v62[0]);
    }
    *(_QWORD *)(a1[43] + 200LL) = v25;
    *(_DWORD *)(a1[43] + 224LL) = v23;
    if ( *((_BYTE *)a1 + 272) )
    {
      v31 = a1[35];
      v8[9] = v31;
      v32 = a1[36] + v31;
    }
    else
    {
      v8[9] = 0;
      v32 = a1[4];
    }
    v8[10] = v32;
    v8[60] = cnss_mhi_notify_status;
    v8[64] = cnss_mhi_pm_runtime_get;
    v8[65] = cnss_mhi_pm_runtime_get_sync;
    v8[67] = cnss_mhi_pm_runtime_put_autosuspend;
    v8[66] = cnss_mhi_pm_runtime_put_noidle;
    v8[71] = cnss_mhi_read_reg;
    v8[72] = cnss_mhi_write_reg;
    v33 = *(_QWORD *)(a1[1] + 264LL);
    if ( !v33 )
      v33 = 4325376;
    v8[15] = v33;
    v34 = 0x40000;
    if ( *(_QWORD *)(v3 + 528) != 4354 )
      v34 = 0x80000;
    v8[16] = v34;
    v8[17] = 0x80000;
    *((_BYTE *)v8 + 614) = 1;
    soc_info = mhi_get_soc_info(v8);
    if ( soc_info )
    {
      v37 = soc_info;
      v38 = cnss_ipc_log_context;
      v18 = v37;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v39 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v39 = "soft_irq";
      }
      else
      {
        v39 = (const char *)(StatusReg + 2320);
      }
      v45 = "cnss_get_mhi_soc_info";
      v46 = "failed to get mhi soc info, ret %d\n";
LABEL_90:
      cnss_debug_ipc_log_print(v38, v39, v45, 3u, 3u, v46, v18, v36, v59);
      goto LABEL_91;
    }
    v40 = *((unsigned int *)v8 + 57);
    v41 = cnss_ipc_log_context;
    *(_DWORD *)(v3 + 504) = v40;
    v42 = *((unsigned int *)v8 + 58);
    *(_DWORD *)(v3 + 508) = v42;
    v43 = *((_DWORD *)v8 + 59);
    *(_DWORD *)(v3 + 512) = v43;
    *(_DWORD *)(v3 + 516) = *((_DWORD *)v8 + 60);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v44 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v44 = "soft_irq";
    }
    else
    {
      v44 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      v41,
      v44,
      "cnss_get_mhi_soc_info",
      7u,
      7u,
      "Get device version info, family number: 0x%x, device number: 0x%x, major version: 0x%x, minor version: 0x%x\n",
      v40,
      v42,
      v43);
    v47 = *(_QWORD *)(v3 + 528);
    v48 = *(_DWORD *)(v3 + 512) & 0xF;
    *(_DWORD *)(v3 + 512) = v48;
    if ( v47 >> 2 < 0x441 || (v49 = &cnss_mhi_config_default, v47 == 4359) && v48 == 1 )
    {
      v49 = &cnss_mhi_config_genoa;
      if ( v47 != 4354 )
        v49 = &cnss_mhi_config_no_satellite;
    }
    v50 = v47 >> 1 > 0x886;
    v51 = *((_DWORD *)a1 + 6) - 4366;
    if ( v50 )
      v52 = &cnss_mhi_config_no_diag;
    else
      v52 = v49;
    v53 = v51 >= 5;
    v54 = 0x19u >> v51;
    v55 = !v53;
    *((_BYTE *)v8 + 168) = v55 & v54;
    v56 = mhi_register_controller(v8, v52);
    if ( v56 )
    {
      v57 = v56;
      v38 = cnss_ipc_log_context;
      v18 = v57;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v39 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v39 = "soft_irq";
      }
      else
      {
        v39 = (const char *)(StatusReg + 2320);
      }
      v45 = "cnss_pci_register_mhi";
      v46 = "Failed to register to MHI bus, err = %d\n";
      goto LABEL_90;
    }
    if ( *((_BYTE *)a1 + 697) == 1 )
      mhi_controller_set_base(a1[43]);
    if ( (*(_BYTE *)(v3 + 7840) & 1) == 0 )
      mhi_controller_set_bw_scale_cb(a1[43], cnss_mhi_bw_scale);
    result = cnss_pci_update_fw_name(a1);
    if ( (_DWORD)result )
    {
      v18 = result;
      mhi_unregister_controller(v8);
LABEL_91:
      kfree(v8[25]);
LABEL_92:
      mhi_free_controller(v8);
      result = v18;
    }
  }
  else
  {
    v11 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v21 = *(_DWORD *)(v11 + 16);
      v22 = (const char *)(v11 + 2320);
      if ( (v21 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v22;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_pci_register_mhi",
      3u,
      3u,
      "Invalid MHI controller context\n",
      v6,
      v7,
      v58);
    result = 4294967274LL;
  }
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return result;
}
