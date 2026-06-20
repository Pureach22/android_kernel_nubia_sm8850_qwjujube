__int64 __fastcall chg_ulog_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x0
  const char *v8; // x2
  __int64 result; // x0
  unsigned __int64 dir; // x20
  unsigned __int64 file_unsafe; // x0
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w21
  void *v16; // x8
  const char *v17; // [xsp+0h] [xbp-30h] BYREF
  __int64 v18; // [xsp+8h] [xbp-28h]
  __int64 v19; // [xsp+10h] [xbp-20h]
  __int64 (__fastcall *v20)(); // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v1 = a1 + 16;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = nullptr;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = nullptr;
  v3 = devm_kmalloc(a1 + 16, 8440, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_26;
  }
  v4 = v3;
  _mutex_init(v3 + 40, "&cd->lock", &chg_ulog_probe___key);
  *(_DWORD *)(v4 + 88) = 0;
  _init_swait_queue_head(v4 + 96, "&x->wait", &init_completion___key);
  *(_QWORD *)(v4 + 120) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 128) = v4 + 128;
  *(_QWORD *)(v4 + 136) = v4 + 128;
  *(_QWORD *)(v4 + 144) = chg_ulog_work;
  init_timer_key(v4 + 152, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_DWORD *)(v4 + 8428) = 1000;
  LODWORD(v18) = 32778;
  v17 = "chg_ulog";
  *(_QWORD *)(a1 + 168) = v4;
  *(_QWORD *)v4 = v1;
  v19 = v4;
  v20 = chg_ulog_callback;
  v5 = pmic_glink_register_client(v1, &v17);
  *(_QWORD *)(v4 + 8) = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v6 = v5;
    v7 = *(_QWORD *)v4;
    v8 = "Error in registering with pmic_glink\n";
LABEL_25:
    result = dev_err_probe(v7, v6, v8);
    goto LABEL_26;
  }
  dir = debugfs_create_dir("charger_ulog", 0);
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_6F16, "chg_ulog_add_debugfs", (unsigned int)dir);
    v15 = dir;
    goto LABEL_23;
  }
  file_unsafe = debugfs_create_file_unsafe("category", 384, dir, v4, &ulog_cat_fops);
  if ( file_unsafe >= 0xFFFFFFFFFFFFF001LL )
  {
    v15 = file_unsafe;
    printk(&unk_6EA5, "chg_ulog_add_debugfs", file_unsafe);
LABEL_22:
    debugfs_remove(dir);
LABEL_23:
    if ( v15 )
    {
      pmic_glink_unregister_client(*(_QWORD *)(v4 + 8));
      v7 = *(_QWORD *)v4;
      v8 = "Error in creating debugfs\n";
      v6 = 4294967274LL;
      goto LABEL_25;
    }
    goto LABEL_11;
  }
  v12 = debugfs_create_file_unsafe("level", 384, dir, v4, &ulog_level_fops);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = &unk_6D57;
LABEL_21:
    v15 = v12;
    printk(v16, "chg_ulog_add_debugfs", (unsigned int)v12);
    goto LABEL_22;
  }
  v12 = debugfs_create_file_unsafe("enable", 384, dir, v4, &ulog_en_fops);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = &unk_6E2D;
    goto LABEL_21;
  }
  v12 = debugfs_create_file_unsafe("time_ms", 384, dir, v4, &ulog_time_fops);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = &unk_6F9F;
    goto LABEL_21;
  }
  *(_QWORD *)(v4 + 16) = dir;
LABEL_11:
  v13 = ipc_log_context_create(10, "charger_ulog", 0);
  *(_QWORD *)(v4 + 24) = v13;
  if ( !v13 )
  {
    pmic_glink_unregister_client(*(_QWORD *)(v4 + 8));
    debugfs_remove(*(_QWORD *)(v4 + 16));
    v7 = *(_QWORD *)v4;
    v8 = "Error in creating charger_ulog\n";
    goto LABEL_15;
  }
  v14 = ipc_log_context_create(8, "charger_ulog_init", 0);
  result = 0;
  *(_QWORD *)(v4 + 32) = v14;
  if ( !v14 )
  {
    pmic_glink_unregister_client(*(_QWORD *)(v4 + 8));
    ipc_log_context_destroy(*(_QWORD *)(v4 + 24));
    debugfs_remove(*(_QWORD *)(v4 + 16));
    v7 = *(_QWORD *)v4;
    v8 = "Error in creating charger_ulog_init\n";
LABEL_15:
    v6 = 4294967277LL;
    goto LABEL_25;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
