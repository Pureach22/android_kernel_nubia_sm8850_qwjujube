__int64 __fastcall hfi_msm_dbg_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x10
  unsigned __int64 v14; // x0
  _QWORD *cmd_buf; // x0
  __int64 v16; // x6
  __int64 v17; // x21
  unsigned int property; // w0
  unsigned int v19; // w21
  _DWORD *v20; // x8
  unsigned int v21; // w0
  __int64 v22; // x8
  void *v24; // x0
  unsigned int v25; // w19
  void *v26; // x0
  char v27; // [xsp+0h] [xbp-10h]

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 56)) == 0 )
  {
    v24 = &unk_26C29E;
LABEL_25:
    printk(v24, "hfi_msm_dbg_init");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(v3 + 8) + 6440LL);
  *(_QWORD *)(v3 + 5688) = a2;
  v7 = _kvmalloc_node_noprof(392, 0, 3520, 0xFFFFFFFFLL);
  hfi_dbg = v7;
  if ( !v7 )
  {
    v24 = &unk_2157FA;
    goto LABEL_25;
  }
  if ( !*(_QWORD *)(v7 + 24) )
  {
    v8 = _kvmalloc_node_noprof(2883584, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(hfi_dbg + 24) = v8;
    if ( !v8 )
      printk(&unk_26545F, "hfi_msm_dbg_init");
  }
  v9 = sde_evtlog_init();
  v10 = hfi_dbg;
  *(_QWORD *)hfi_dbg = a1;
  v11 = hfi_dbg;
  *(_QWORD *)(v10 + 16) = v9;
  *(_QWORD *)(v11 + 8) = a2;
  _mutex_init(v11 + 272, "&hfi_dbg->mutex", &hfi_msm_dbg_init___key);
  v12 = hfi_dbg;
  v13 = *(_QWORD *)(hfi_dbg + 16);
  *(_QWORD *)(hfi_dbg + 320) = 0x200000001LL;
  *(_DWORD *)(v12 + 56) = 0;
  *(_DWORD *)(v12 + 112) = 0;
  *(_DWORD *)(v12 + 168) = 0;
  *(_DWORD *)(v12 + 224) = 0;
  *(_DWORD *)(v13 + 786452) = 11;
  *(_DWORD *)(*(_QWORD *)(v12 + 16) + 786456LL) = 2;
  v14 = hfi_util_u32_prop_helper_alloc(1024);
  *(_QWORD *)(hfi_dbg + 264) = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_242684, "hfi_msm_dbg_init");
    kfree(*(_QWORD *)(hfi_dbg + 264));
    return 4294967274LL;
  }
  cmd_buf = hfi_adapter_get_cmd_buf(v6 + 8);
  if ( !cmd_buf )
  {
    v24 = &unk_237EB0;
    goto LABEL_25;
  }
  v16 = hfi_dbg + 336;
  v17 = (__int64)cmd_buf;
  *(_QWORD *)(hfi_dbg + 336) = hfi_dbg_property_handler;
  property = hfi_adapter_add_get_property((__int64)cmd_buf, -16777207, 0, 0, 0, 0, v16, 2);
  if ( property )
  {
    v25 = property;
    v26 = &unk_219465;
  }
  else
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_msm_dbg_init", 1147, -1, 0, -16777207, 13107, -1059143953, v27);
    v19 = hfi_adapter_set_cmd_buf_blocking(v17);
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_msm_dbg_init", 1149, -1, 0, -16777207, v19, 17476, 239);
    if ( v19 )
    {
      printk(&unk_23B5A2, "hfi_msm_dbg_init");
      return v19;
    }
    v20 = (_DWORD *)hfi_dbg;
    if ( *(_DWORD *)(hfi_dbg + 56) )
    {
      hfi_adapter_buffer_alloc(hfi_dbg + 40);
      v20 = (_DWORD *)hfi_dbg;
    }
    if ( v20[28] )
    {
      hfi_adapter_buffer_alloc((__int64)(v20 + 24));
      v20 = (_DWORD *)hfi_dbg;
    }
    if ( v20[42] )
    {
      hfi_adapter_buffer_alloc((__int64)(v20 + 38));
      v20 = (_DWORD *)hfi_dbg;
    }
    if ( v20[56] )
      hfi_adapter_buffer_alloc((__int64)(v20 + 52));
    v21 = hfi_dbg_device_setup(v6);
    if ( !v21 )
    {
      v22 = hfi_dbg;
      *(_DWORD *)(*(_QWORD *)(hfi_dbg + 16) + 786472LL) = *(_DWORD *)(hfi_dbg + 112);
      *(_QWORD *)(*(_QWORD *)(v22 + 16) + 786464LL) = *(_QWORD *)(v22 + 104);
      debugfs_create_file("recovery_reg", 384, a2, 0, &dump_recovery_reg_fops);
      debugfs_create_file("dump", 384, a2, 0, &dump_dbg_info_fops);
      debugfs_create_file("recovery_dbgbus", 384, a2, 0, &dump_dbg_bus_info_fops);
      debugfs_create_file("recovery_dev_state", 384, a2, 0, &dump_dev_state_fops);
      debugfs_create_file("dbg_ctrl", 384, a2, 0, &dump_dbg_ctrl_fops);
      debugfs_create_u32("enable", 384, a2, *(_QWORD *)(hfi_dbg + 16) + 786452LL);
      debugfs_create_u32("panic", 384, a2, hfi_dbg + 320);
      debugfs_create_u32("dump_mode", 384, a2, hfi_dbg + 324);
      debugfs_create_u32("evtlog_dump", 384, a2, *(_QWORD *)(hfi_dbg + 16) + 786456LL);
      debugfs_create_file("mdss_off", 384, a2, 0, &dump_dbg_off_fops);
      debugfs_create_file("mdss_reg", 384, a2, 0, &dump_dbg_reg_fops);
      return 0;
    }
    v25 = v21;
    v26 = &unk_211F98;
  }
  printk(v26, "hfi_msm_dbg_init");
  return v25;
}
