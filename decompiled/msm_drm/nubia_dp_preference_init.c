__int64 nubia_dp_preference_init()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 v3; // x24
  unsigned __int64 StatusReg; // x26
  unsigned int file_ns; // w19
  __int64 v6; // x0
  __int64 ipc_log_context; // x0
  void *v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0

  edid_ctl = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  if ( !edid_ctl )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]: edid_ctl alloc failed !\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_22028A;
LABEL_15:
    printk(v8, "nubia_dp_preference_init");
    return (unsigned int)-12;
  }
  v0 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  *(_QWORD *)(edid_ctl + 32) = v0;
  if ( !v0 )
  {
    v9 = get_ipc_log_context();
    ipc_log_string(v9, "[e][%-4d]: edid_ctl->edid_modes alloc failed !\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_21915B, "nubia_dp_preference_init");
LABEL_13:
    kfree(edid_ctl);
    return (unsigned int)-12;
  }
  v1 = _kmalloc_cache_noprof(_mutex_init, 3520, 8);
  v2 = edid_ctl;
  *(_QWORD *)(edid_ctl + 48) = v1;
  if ( !v1 )
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]: edid_ctl->sel_mode alloc failed !\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245A60, "nubia_dp_preference_init");
    kfree(*(_QWORD *)(edid_ctl + 32));
    goto LABEL_13;
  }
  *(_QWORD *)(v2 + 56) = v2 + 56;
  *(_QWORD *)(v2 + 64) = v2 + 56;
  nubia_global_enhace_kobj = kobject_create_and_add("lcd_enhance", kernel_kobj);
  if ( !nubia_global_enhace_kobj )
  {
    v11 = get_ipc_log_context();
    ipc_log_string(
      v11,
      "[e][%-4d]: lcd_enhance fail nubia_global_enhace_kobj is NULL\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_242373;
    goto LABEL_15;
  }
  v3 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    file_ns = sysfs_create_file_ns(nubia_global_enhace_kobj, &(&disp_attrs)[v3], 0);
    if ( file_ns )
    {
      v6 = get_ipc_log_context();
      ipc_log_string(v6, "[e][%-4d]: create sysfs file failed !\n", *(_DWORD *)(StatusReg + 1800));
      printk(&unk_215580, "nubia_dp_preference_init");
    }
    v3 += 4;
  }
  while ( v3 != 16 );
  return file_ns;
}
