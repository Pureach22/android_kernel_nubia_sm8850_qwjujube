__int64 ipa_odl_init()
{
  __int64 v0; // x0
  _QWORD *v1; // x19
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  __int64 v4; // x1
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  unsigned int v7; // w0
  unsigned __int64 v8; // x0
  __int64 v9; // x1
  unsigned int v10; // w0
  __int16 v11; // w9
  __int64 v12; // x1
  __int64 result; // x0
  int v14; // w19
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 ipc_logbuf; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w23
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  int v32; // w20
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  int v45; // w20
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  _QWORD v49[3]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v50; // [xsp+20h] [xbp-10h]
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 744);
  v1 = (_QWORD *)v0;
  ipa3_odl_ctx = v0;
  if ( !v0 )
  {
    result = 4294967284LL;
    goto LABEL_71;
  }
  *(_QWORD *)(v0 + 320) = v0 + 320;
  *(_QWORD *)(v0 + 328) = v0 + 320;
  _init_waitqueue_head(v0 + 720, "&ipa3_odl_ctx->adpl_msg_waitq", &ipa_odl_init___key);
  _mutex_init(ipa3_odl_ctx + 336, "&ipa3_odl_ctx->adpl_msg_lock", &ipa_odl_init___key_27);
  _mutex_init(ipa3_odl_ctx + 384, "&ipa3_odl_ctx->pipe_lock", &ipa_odl_init___key_29);
  v2 = class_create("ipa_adpl");
  *v1 = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3EC7FA, "ipa_odl_init");
    v22 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_72;
    v23 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d Error: odl_cdev->class NULL\n", "ipa_odl_init", 711);
      v22 = ipa3_ctx;
    }
    v24 = *(_QWORD *)(v22 + 34160);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d Error: odl_cdev->class NULL\n", "ipa_odl_init", 711);
      v25 = -19;
    }
    else
    {
LABEL_72:
      v25 = -19;
    }
    goto LABEL_70;
  }
  if ( (unsigned int)alloc_chrdev_region(v1 + 1, 0, 1, "ipa_adpl") )
  {
    printk(&unk_3D2FCE, "ipa_odl_init");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d alloc_chrdev_region error for ipa adpl pipe\n", "ipa_odl_init", 718);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d alloc_chrdev_region error for ipa adpl pipe\n", "ipa_odl_init", 718);
    }
    v25 = -19;
    goto LABEL_69;
  }
  v3 = device_create(*v1, 0, *((unsigned int *)v1 + 2), ipa3_ctx, "ipa_adpl");
  v1[2] = v3;
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C4361, "ipa_odl_init");
    v29 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d device_create err:%ld\n", "ipa_odl_init", 726, v1[2]);
        v29 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v29 + 34160);
      if ( v31 )
        ipc_log_string(v31, "ipa %s:%d device_create err:%ld\n", "ipa_odl_init", 726, v1[2]);
    }
    v25 = *((_DWORD *)v1 + 4);
    goto LABEL_68;
  }
  cdev_init(v1 + 3, &ipa_adpl_fops);
  v4 = *((unsigned int *)v1 + 2);
  v1[15] = &_this_module;
  v1[16] = &ipa_adpl_fops;
  v5 = cdev_add(v1 + 3, v4, 1);
  if ( v5 )
  {
    v32 = -v5;
    v25 = v5;
    printk(&unk_3D2EEE, "ipa_odl_init");
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d cdev_add err=%d\n", "ipa_odl_init", 738, v32);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d cdev_add err=%d\n", "ipa_odl_init", 738, v32);
    }
    goto LABEL_67;
  }
  v6 = class_create("ipa_odl_ctl");
  v1[20] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3EC7FA, "ipa_odl_init");
    v36 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_73;
    v37 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v37 )
    {
      ipc_log_string(v37, "ipa %s:%d Error: odl_cdev->class NULL\n", "ipa_odl_init", 747);
      v36 = ipa3_ctx;
    }
    v38 = *(_QWORD *)(v36 + 34160);
    if ( v38 )
    {
      ipc_log_string(v38, "ipa %s:%d Error: odl_cdev->class NULL\n", "ipa_odl_init", 747);
      v25 = -19;
    }
    else
    {
LABEL_73:
      v25 = -19;
    }
    goto LABEL_67;
  }
  v7 = alloc_chrdev_region(v1 + 21, 0, 1, "ipa_odl_ctl");
  if ( v7 )
  {
    v25 = v7;
    printk(&unk_3C444D, "ipa_odl_init");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d alloc_chrdev_region error for ipa odl ctl pipe\n", "ipa_odl_init", 755);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(v41, "ipa %s:%d alloc_chrdev_region error for ipa odl ctl pipe\n", "ipa_odl_init", 755);
    }
    goto LABEL_66;
  }
  v8 = device_create(v1[20], 0, *((unsigned int *)v1 + 42), ipa3_ctx, "ipa_odl_ctl");
  v1[22] = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C4361, "ipa_odl_init");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d device_create err:%ld\n", "ipa_odl_init", 762, v1[22]);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
        ipc_log_string(v44, "ipa %s:%d device_create err:%ld\n", "ipa_odl_init", 762, v1[22]);
    }
    v25 = *((_DWORD *)v1 + 44);
    goto LABEL_65;
  }
  cdev_init(v1 + 23, &ipa_odl_ctl_fops);
  v9 = *((unsigned int *)v1 + 42);
  v1[35] = &_this_module;
  v1[36] = &ipa_odl_ctl_fops;
  v10 = cdev_add(v1 + 23, v9, 1);
  if ( v10 )
  {
    v45 = -v10;
    v25 = v10;
    printk(&unk_3A2D21, "ipa_odl_init");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d :cdev_add err=%d\n", "ipa_odl_init", 774, v45);
        v46 = ipa3_ctx;
      }
      v48 = *(_QWORD *)(v46 + 34160);
      if ( v48 )
        ipc_log_string(v48, "ipa %s:%d :cdev_add err=%d\n", "ipa_odl_init", 774, v45);
    }
    device_destroy(v1[20], *((unsigned int *)v1 + 42));
LABEL_65:
    unregister_chrdev_region(*((unsigned int *)v1 + 42), 1);
LABEL_66:
    class_destroy(v1[20]);
LABEL_67:
    device_destroy(*v1, *((unsigned int *)v1 + 2));
LABEL_68:
    unregister_chrdev_region(*((unsigned int *)v1 + 2), 1);
LABEL_69:
    class_destroy(*v1);
LABEL_70:
    kfree(ipa3_odl_ctx);
    ipa3_odl_ctx = 0;
    result = v25;
    goto LABEL_71;
  }
  v49[2] = 0;
  v50 = 0;
  v11 = *(_WORD *)(ipa3_odl_ctx + 692);
  v12 = ipa3_odl_ctx + 716;
  v49[0] = "ODL";
  v49[1] = 0;
  BYTE4(v50) = 1;
  *(_WORD *)(ipa3_odl_ctx + 692) = v11 | 1;
  result = ipa_pm_register(v49, v12);
  if ( (_DWORD)result )
  {
    v14 = result;
    printk(&unk_3C6B8B, "ipa3_odl_register_pm");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_odl_register_pm", 354, v14);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_odl_register_pm", 354, v14);
    }
    v18 = printk(&unk_3A6FFB, "ipa_odl_init");
    ipc_logbuf = ipa3_get_ipc_logbuf(v18);
    if ( ipc_logbuf )
    {
      v20 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v20, "ipa-wan %s:%d ipa3_odl_register_pm failed, ret: %d\n", "ipa_odl_init", 784, v14);
    }
    result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
      ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d ipa3_odl_register_pm failed, ret: %d\n", "ipa_odl_init", 784, v14);
      result = 0;
    }
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
