__int64 __fastcall gh_panic_notifier_probe(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x24
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  _DWORD *v6; // x25
  unsigned int variable_u32_array; // w0
  unsigned int v8; // w21
  __int64 property; // x0
  _QWORD *v10; // x22
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned __int64 v14; // x0
  unsigned int v15; // w23
  __int64 v16; // x0
  unsigned int file_ns; // w0
  __int64 v18; // x1
  unsigned int v19; // w0
  __int64 compatible_node; // x0
  __int64 v21; // x23
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x0
  const char *v30; // x1
  const char *v31; // x2
  _QWORD *v32; // x0
  int *v33; // x8
  int v34; // [xsp+4h] [xbp-5Ch] BYREF
  _QWORD v35[11]; // [xsp+8h] [xbp-58h] BYREF

  v1 = a1 + 2;
  v35[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[95];
  v4 = (_QWORD *)devm_kmalloc(a1 + 2, 232, 3520);
  if ( !v4 )
    goto LABEL_34;
  v5 = v4;
  a1[21] = v4;
  *v4 = v1;
  v6 = v4 + 15;
  variable_u32_array = of_property_read_variable_u32_array(v3, "gunyah-label", v4 + 15, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v15 = variable_u32_array;
    dev_err(v1, "Failed to read label %d\n", variable_u32_array);
    goto LABEL_35;
  }
  v8 = *((_DWORD *)v5 + 30);
  property = of_find_property(v3, "qcom,primary-vm", 0);
  *((_BYTE *)v5 + 132) = property != 0;
  if ( !property )
  {
    v34 = 0;
    compatible_node = of_find_compatible_node(0, 0, "qcom,gunyah-panic-gen");
    if ( !compatible_node )
    {
LABEL_37:
      dev_err(*v5, "can't find the label=%d memory!\n", *((_DWORD *)v5 + 30));
      v15 = -19;
      goto LABEL_35;
    }
    v21 = compatible_node;
    while ( (of_property_read_variable_u32_array(v21, "qcom,label", &v34, 1, 0) & 0x80000000) != 0 || v34 != *v6 )
    {
      v21 = of_find_compatible_node(v21, 0, "qcom,gunyah-panic-gen");
      if ( !v21 )
        goto LABEL_37;
    }
    memset(v35, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v21, "memory-region", 0, 0, 0, v35) )
      v22 = 0;
    else
      v22 = v35[0];
    if ( (unsigned int)of_address_to_resource(v22, 0, v5 + 1) )
    {
      dev_err(*v5, "of_address_to_resource failed!\n");
      v15 = -22;
      goto LABEL_35;
    }
    v5[14] = v5[2] - v5[1] + 1LL;
    v23 = _devm_request_region();
    v24 = *v5;
    if ( !v23 )
    {
      dev_err(v24, "request mem region fail\n");
      v15 = -6;
      goto LABEL_35;
    }
    v25 = devm_ioremap_wc(v24, v5[1], v5[14]);
    v5[13] = v25;
    if ( v25 )
    {
      v26 = gh_dbl_rx_register(v8, gh_panic_notify_receiver, v5);
      v15 = v26;
      v5[18] = v26;
      if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v1, "%s:Failed to get gunyah rx dbl %d\n", "gh_panic_notifier_probe", v26);
        goto LABEL_35;
      }
      v27 = a1[16];
      if ( !v27 )
        v27 = *v1;
      v28 = wakeup_source_register(v1, v27);
      v5[19] = v28;
      if ( v28 )
      {
        v15 = 0;
        goto LABEL_35;
      }
      dev_err(v1, "%s:Failed to register wakeup source\n", "gh_panic_notifier_probe");
      gh_dbl_rx_unregister(v5[18]);
    }
    else
    {
      dev_err(*v5, "ioremap fail\n");
    }
LABEL_34:
    v15 = -12;
    goto LABEL_35;
  }
  v10 = (_QWORD *)*v5;
  LODWORD(v35[0]) = 0;
  v11 = dma_set_mask(v10, -1);
  if ( v11 )
  {
    v15 = v11;
    dev_err(v10, "%s: dma_set_mask_and_coherent failed\n", "gh_panic_notifier_pvm_mem_probe");
    goto LABEL_35;
  }
  dma_set_coherent_mask(v10, -1);
  v12 = of_reserved_mem_device_init_by_idx(v10, v10[93], 0);
  if ( v12 )
  {
    v15 = v12;
    v30 = "%s: Failed to initialize CMA mem, ret %d\n";
LABEL_41:
    v31 = "gh_panic_notifier_pvm_mem_probe";
    v32 = v10;
LABEL_43:
    dev_err(v32, v30, v31, v15);
    goto LABEL_35;
  }
  v13 = of_property_read_variable_u32_array(*(_QWORD *)(*v5 + 744LL), "shared-buffer-size", v35, 1, 0);
  if ( (v13 & 0x80000000) != 0 )
  {
    v15 = v13;
    v30 = "%s: Failed to get shared memory size, ret %d\n";
    goto LABEL_41;
  }
  v5[14] = LODWORD(v35[0]);
  if ( (of_property_read_variable_u32_array(v3, "peer-name", (char *)v5 + 124, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)v5 + 31) = 0;
  v14 = gh_dbl_tx_register(v8);
  v15 = v14;
  v5[17] = v14;
  if ( !v14 || v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    v30 = "%s:Failed to get gunyah tx dbl %d\n";
    v31 = "gh_panic_notifier_probe";
    v32 = v1;
    goto LABEL_43;
  }
  v16 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  recovery_vms = v16;
  if ( !v16 )
  {
    gh_dbl_tx_unregister(v5[17]);
    goto LABEL_34;
  }
  *(_BYTE *)v16 = 0;
  *(_QWORD *)(v16 + 24) = recovery_show;
  *(_QWORD *)(v16 + 32) = recovery_store;
  *(_WORD *)(v16 + 16) = 384;
  *(_QWORD *)(v16 + 8) = "trustedvm_recovery";
  file_ns = sysfs_create_file_ns(v1, v16 + 8, 0);
  if ( file_ns )
  {
    v15 = file_ns;
    v33 = &recovery_name_to_vm_name;
LABEL_48:
    printk(&unk_7775, (unsigned int)*v33, v15);
    gh_dbl_tx_unregister(v5[17]);
    kfree(recovery_vms);
    goto LABEL_35;
  }
  v18 = recovery_vms;
  *(_QWORD *)(recovery_vms + 48) = "oemvm_recovery";
  v18 += 48;
  *(_BYTE *)(v18 - 8) = 0;
  *(_QWORD *)(v18 + 16) = recovery_show;
  *(_QWORD *)(v18 + 24) = recovery_store;
  *(_WORD *)(v18 + 8) = 384;
  v19 = sysfs_create_file_ns(v1, v18, 0);
  if ( v19 )
  {
    v15 = v19;
    v33 = &dword_7B28;
    goto LABEL_48;
  }
  v5[20] = gh_panic_notifier_vm_cb;
  *((_DWORD *)v5 + 44) = 0x7FFFFFFF;
  gunyah_qtvm_register_notifier(v5 + 20);
  v5[23] = gh_panic_notifier_rm_cb;
  v15 = gh_rm_register_notifier(v5 + 23);
  if ( v15 )
  {
    gh_dbl_tx_unregister(v5[17]);
    gunyah_qtvm_unregister_notifier(v5 + 20);
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v15;
}
