__int64 ipa_opt_log_init()
{
  __int64 v0; // x0
  _QWORD *v1; // x19
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w22
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0

  v0 = _kmalloc_cache_noprof(scnprintf, 3520, 320);
  v1 = (_QWORD *)v0;
  ipa3_opt_log_ctx = v0;
  if ( !v0 )
    return 4294967284LL;
  *(_QWORD *)(v0 + 160) = v0 + 160;
  *(_QWORD *)(v0 + 168) = v0 + 160;
  _init_waitqueue_head(v0 + 296, "&ipa3_opt_log_ctx->opt_log_msg_waitq", &ipa_opt_log_init___key);
  _mutex_init(ipa3_opt_log_ctx + 176, "&ipa3_opt_log_ctx->opt_log_msg_lock", &ipa_opt_log_init___key_9);
  _mutex_init(ipa3_opt_log_ctx + 224, "&ipa3_opt_log_ctx->ctx_lock", &ipa_opt_log_init___key_11);
  v2 = class_create("ipa_events");
  *v1 = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3DBA50, "ipa_opt_log_init");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_31;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Error: opt_log_cdev->class NULL\n", "ipa_opt_log_init", 238);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d Error: opt_log_cdev->class NULL\n", "ipa_opt_log_init", 238);
      v9 = -19;
    }
    else
    {
LABEL_31:
      v9 = -19;
    }
  }
  else
  {
    if ( (unsigned int)alloc_chrdev_region(v1 + 1, 0, 1, "ipa_events") )
    {
      printk(&unk_3A9FE5, "ipa_opt_log_init");
      v10 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_32;
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d alloc_chrdev_region error for ipa opt log\n", "ipa_opt_log_init", 245);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d alloc_chrdev_region error for ipa opt log\n", "ipa_opt_log_init", 245);
        v9 = -19;
      }
      else
      {
LABEL_32:
        v9 = -19;
      }
    }
    else
    {
      v3 = device_create(*v1, 0, *((unsigned int *)v1 + 2), ipa3_ctx, "ipa_events");
      v1[2] = v3;
      if ( v3 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_3C4361, "ipa_opt_log_init");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v14 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v14 )
          {
            ipc_log_string(v14, "ipa %s:%d device_create err:%ld\n", "ipa_opt_log_init", 253, v1[2]);
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(v15, "ipa %s:%d device_create err:%ld\n", "ipa_opt_log_init", 253, v1[2]);
        }
        v9 = *((_DWORD *)v1 + 4);
      }
      else
      {
        cdev_init(v1 + 3, &ipa_opt_log_fops);
        v4 = *((unsigned int *)v1 + 2);
        v1[15] = &_this_module;
        v1[16] = &ipa_opt_log_fops;
        result = cdev_add(v1 + 3, v4, 1);
        if ( !(_DWORD)result )
        {
          *(_BYTE *)(ipa3_opt_log_ctx + 272) |= 1u;
          return result;
        }
        v16 = -(int)result;
        v9 = result;
        printk(&unk_3D2EEE, "ipa_opt_log_init");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d cdev_add err=%d\n", "ipa_opt_log_init", 265, v16);
            v17 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v17 + 34160);
          if ( v19 )
            ipc_log_string(v19, "ipa %s:%d cdev_add err=%d\n", "ipa_opt_log_init", 265, v16);
        }
        device_destroy(*v1, *((unsigned int *)v1 + 2));
      }
      unregister_chrdev_region(*((unsigned int *)v1 + 2), 1);
    }
    class_destroy(*v1);
  }
  kfree(ipa3_opt_log_ctx);
  ipa3_opt_log_ctx = 0;
  return v9;
}
