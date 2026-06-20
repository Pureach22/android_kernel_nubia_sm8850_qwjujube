__int64 __fastcall qcom_ddump_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  _DWORD *v6; // x25
  unsigned int variable_u32_array; // w0
  __int64 property; // x0
  __int64 v9; // x24
  __int64 v10; // x23
  unsigned int v11; // w23
  __int64 compatible_node; // x0
  int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  __int64 v17; // x3
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x0
  unsigned __int64 v21; // x3
  __int64 *v22; // x20
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x21
  __int64 v26; // x8
  __int64 v27; // x1
  __int64 v28; // x0
  unsigned int v29; // w21
  unsigned __int64 v30; // x0
  unsigned __int64 v31; // x0
  unsigned int v33; // [xsp+4h] [xbp-5Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-58h] BYREF
  __int64 v35; // [xsp+10h] [xbp-50h]
  __int64 v36; // [xsp+18h] [xbp-48h]
  __int64 v37; // [xsp+20h] [xbp-40h]
  __int64 v38; // [xsp+28h] [xbp-38h]
  __int64 v39; // [xsp+30h] [xbp-30h]
  __int64 v40; // [xsp+38h] [xbp-28h]
  __int64 v41; // [xsp+40h] [xbp-20h]
  __int64 v42; // [xsp+48h] [xbp-18h]
  __int64 v43; // [xsp+50h] [xbp-10h]
  __int64 v44; // [xsp+58h] [xbp-8h]

  v1 = a1 + 16;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v4 = (_QWORD *)devm_kmalloc(a1 + 16, 352, 3520);
  if ( !v4 )
  {
    v11 = -12;
    goto LABEL_66;
  }
  v5 = v4;
  *(_QWORD *)(a1 + 168) = v4;
  *v4 = v1;
  v6 = v4 + 21;
  variable_u32_array = of_property_read_variable_u32_array(v3, "gunyah-label", v4 + 21, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v11 = variable_u32_array;
    dev_err(v1, "Failed to read label %d\n", variable_u32_array);
    goto LABEL_66;
  }
  property = of_find_property(v3, "qcom,primary-vm", 0);
  v9 = *v5;
  v33 = 0;
  *((_BYTE *)v5 + 180) = property != 0;
  if ( property )
  {
    v10 = *(_QWORD *)(v9 + 744);
  }
  else
  {
    LODWORD(v34) = 0;
    compatible_node = of_find_compatible_node(0, 0, "qcom,ddump-gunyah-gen");
    if ( !compatible_node )
    {
LABEL_48:
      dev_err(v9, "Unable to parse shared mem node\n");
      v11 = -22;
      goto LABEL_66;
    }
    v10 = compatible_node;
    while ( (of_property_read_variable_u32_array(v10, "qcom,label", &v34, 1, 0) & 0x80000000) != 0 || (_DWORD)v34 != *v6 )
    {
      v10 = of_find_compatible_node(v10, 0, "qcom,ddump-gunyah-gen");
      if ( !v10 )
        goto LABEL_48;
    }
  }
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v13 = _of_parse_phandle_with_args(v10, "memory-region", 0, 0, 0, &v34);
  v11 = -22;
  if ( v13 || !v34 )
    goto LABEL_66;
  if ( (unsigned int)of_address_to_resource(v34, 0, v5 + 7) )
  {
    v14 = dma_set_mask(v9, -1);
    if ( v14 )
    {
      v11 = v14;
      dev_err(v9, "%s: dma_set_mask_and_coherent failed\n", "qcom_ddump_map_memory");
      goto LABEL_66;
    }
    dma_set_coherent_mask(v9, -1);
    v15 = of_reserved_mem_device_init_by_idx(v9, *(_QWORD *)(v9 + 744), 0);
    if ( v15 )
    {
      v11 = v15;
      dev_err(v9, "%s: Failed to initialize CMA mem, ret %d\n", "qcom_ddump_map_memory", v15);
      goto LABEL_66;
    }
    v16 = of_property_read_variable_u32_array(*(_QWORD *)(*v5 + 744LL), "shared-buffer-size", &v33, 1, 0);
    if ( (v16 & 0x80000000) != 0 )
    {
      v11 = v16;
      dev_err(v9, "%s: Failed to get shared memory size, ret %d\n", "qcom_ddump_map_memory", v16);
      goto LABEL_66;
    }
    v17 = v33;
    *((_BYTE *)v5 + 336) = 0;
  }
  else
  {
    v19 = v5[7];
    v18 = v5[8];
    *((_BYTE *)v5 + 336) = 1;
    v17 = v18 - v19 + 1;
  }
  v5[20] = v17;
  if ( *((_BYTE *)v5 + 180) == 1 )
  {
    if ( (of_property_read_variable_u32_array(v3, "peer-name", (char *)v5 + 172, 1, 0) & 0x80000000) != 0 )
      *((_DWORD *)v5 + 43) = 0;
    v5[23] = qcom_ddump_vm_cb;
    *((_DWORD *)v5 + 50) = 0x7FFFFFFF;
    gunyah_qtvm_register_notifier();
  }
  else
  {
    if ( !_devm_request_region(v1, &iomem_resource, v5[7]) )
    {
      dev_err(v1, "request mem region fail\n");
      v11 = -6;
      goto LABEL_66;
    }
    v20 = devm_ioremap_wc(v1, v5[7], v5[20]);
    v5[19] = v20;
    if ( !v20 )
    {
      dev_err(v1, "ioremap fail\n");
      v11 = -12;
      goto LABEL_66;
    }
    kmsg_dump_rewind(v5 + 5);
    v5[3] = qcom_ddump_to_shm;
    v11 = kmsg_dump_register(v5 + 1);
    if ( v11 )
      goto LABEL_66;
  }
  v21 = v5[20];
  v22 = (__int64 *)*v5;
  v34 = 0;
  v35 = 0;
  if ( v21 <= 0x497 )
  {
    dev_err(v22, "Shared memory size should greater than %zu\n", 0x498u);
    v11 = -22;
    goto LABEL_63;
  }
  if ( *((_BYTE *)v5 + 180) == 1 )
  {
    if ( *((_BYTE *)v5 + 336) == 1 )
    {
      if ( !_devm_request_region(v22, &iomem_resource, v5[7]) )
      {
        dev_err(v22, "request mem region fail\n");
        v11 = -6;
        goto LABEL_63;
      }
      v23 = devm_ioremap_wc(v22, v5[7], v5[20]);
      v5[19] = v23;
      if ( !v23 )
      {
        dev_err(v22, "ioremap fail\n");
        goto LABEL_62;
      }
    }
    v24 = devm_kmalloc(v22, 128, 3520);
    v5[43] = v24;
    if ( !v24 )
    {
LABEL_62:
      v11 = -12;
LABEL_63:
      if ( *((_BYTE *)v5 + 180) == 1 )
        gunyah_qtvm_unregister_notifier(v5 + 23);
      else
        kmsg_dump_unregister(v5 + 1);
      goto LABEL_66;
    }
    *((_DWORD *)v5 + 56) = 0;
    _init_swait_queue_head(v5 + 29, "&x->wait", &init_completion___key);
    if ( !proc_create_data("vmkmsg", 256, 0, &ddump_proc_ops, v5) )
    {
      dev_err(v22, "proc_create_data fail\n");
      goto LABEL_62;
    }
  }
  else
  {
    v25 = v5[19];
    *(_WORD *)(v25 + 144) = 0;
    gh_get_virt_time_offset(&v34);
    v26 = v34;
    *(_QWORD *)(v25 + 128) = 0;
    *(_QWORD *)(v25 + 136) = 0;
    *(_QWORD *)(v25 + 112) = 0;
    *(_QWORD *)(v25 + 120) = 0;
    *(_QWORD *)(v25 + 96) = 0;
    *(_QWORD *)(v25 + 104) = 0;
    *(_QWORD *)(v25 + 80) = 0;
    *(_QWORD *)(v25 + 88) = 0;
    *(_QWORD *)(v25 + 64) = 0;
    *(_QWORD *)(v25 + 72) = 0;
    *(_QWORD *)(v25 + 48) = 0;
    *(_QWORD *)(v25 + 56) = 0;
    *(_QWORD *)(v25 + 32) = 0;
    *(_QWORD *)(v25 + 40) = 0;
    *(_QWORD *)(v25 + 16) = 0;
    *(_QWORD *)(v25 + 24) = 0;
    *(_QWORD *)(v25 + 128) = v26;
    v27 = v22[14];
    if ( !v27 )
      v27 = *v22;
    v28 = wakeup_source_register(v22, v27);
    v5[32] = v28;
    if ( !v28 )
      goto LABEL_62;
    v5[33] = qcom_ddump_gh_panic_handler;
    *((_DWORD *)v5 + 50) = 2147483646;
    v11 = gh_panic_notifier_register(v5 + 33);
    if ( v11 )
      goto LABEL_38;
  }
  v29 = *((_DWORD *)v5 + 42);
  v30 = gh_dbl_tx_register(v29);
  v11 = v30;
  v5[26] = v30;
  if ( v30 && v30 < 0xFFFFFFFFFFFFF001LL )
  {
    v31 = gh_dbl_rx_register(v29, qcom_ddump_gh_cb, v5);
    v11 = v31;
    v5[27] = v31;
    if ( v31 && v31 <= 0xFFFFFFFFFFFFF000LL )
    {
      v11 = 0;
      goto LABEL_66;
    }
    dev_err(v22, "%s:Failed to get gunyah rx dbl %d\n", "qcom_ddump_alive_log_probe", v31);
    gh_dbl_tx_unregister(v5[26]);
  }
  else
  {
    dev_err(v22, "%s:Failed to get gunyah tx dbl %d\n", "qcom_ddump_alive_log_probe", v30);
  }
  if ( *((_BYTE *)v5 + 180) == 1 )
    remove_proc_entry("vmkmsg", 0);
  else
    gh_panic_notifier_unregister(v5 + 33);
LABEL_38:
  if ( (*((_BYTE *)v5 + 180) & 1) == 0 )
    wakeup_source_unregister(v5[32]);
  if ( v11 )
    goto LABEL_63;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v11;
}
