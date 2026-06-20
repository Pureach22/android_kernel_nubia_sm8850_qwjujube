__int64 __fastcall spcom_create_channel_chardev(char *a1, char a2, __int64 a3)
{
  __int64 v3; // x19
  char *v4; // x25
  __int64 v7; // x21
  __int64 v8; // x22
  size_t v9; // x0
  __int64 v10; // x27
  const char *v11; // x24
  __int64 v12; // x2
  __int64 v13; // x8
  unsigned int inited; // w0
  unsigned int v15; // w0
  __int64 v16; // x23
  unsigned int v17; // w24
  unsigned __int64 v18; // x0
  __int64 v19; // x2
  unsigned __int64 v20; // x20
  unsigned int v21; // w0
  unsigned int v23; // w19
  unsigned int v24; // w21
  __int64 v25; // x0
  const char *v26; // x1
  int v27; // w21
  unsigned int v28; // w0
  unsigned int v29; // w20
  unsigned __int64 StatusReg; // x24
  __int64 v31; // x27
  int (*v32)(char *, size_t, const char *, ...); // x0

  if ( !a1
    || (v7 = *(_QWORD *)(spcom_dev + 1168), v8 = *(_QWORD *)(spcom_dev + 1176), v9 = strnlen(a1, 0x20u), v9 == 32) )
  {
    printk(&unk_1128C, "spcom_create_channel_chardev", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: invalid channel name\n",
      "spcom_create_channel_chardev",
      (const char *)&unk_F80E);
    return 4294967274LL;
  }
  if ( v9 != -1 )
  {
    v4 = "el name\n";
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: creating channel [%s]\n",
      "spcom_create_channel_chardev",
      (const char *)&unk_F80E,
      a1);
    v10 = 32;
    v3 = spcom_dev + 1200;
    v11 = (const char *)(spcom_dev + 1200);
    while ( strcmp(v11, a1) )
    {
      --v10;
      v11 += 1784;
      if ( !v10 )
        goto LABEL_9;
    }
    if ( v11 )
    {
      printk(&unk_FE04, "spcom_create_channel_chardev", a1);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: channel [%s] already exist\n",
        "spcom_create_channel_chardev",
        (const char *)&unk_F80E,
        a1);
      return 4294967280LL;
    }
LABEL_9:
    v13 = 32;
    while ( *(_BYTE *)v3 )
    {
      --v13;
      v3 += 1784;
      if ( !v13 )
        goto LABEL_21;
    }
    if ( !v3 )
    {
LABEL_21:
      printk(&unk_10B97, "spcom_create_channel_chardev", v12);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: no free channel\n",
        "spcom_create_channel_chardev",
        (const char *)&unk_F80E);
      return 4294967277LL;
    }
    inited = spcom_init_channel(v3, a2 & 1, a1);
    if ( (inited & 0x80000000) != 0 )
    {
      v23 = inited;
      printk(&unk_EADB, "spcom_create_channel_chardev", inited);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: can't init channel %d\n",
        "spcom_create_channel_chardev",
        (const char *)&unk_F80E,
        v23);
      return v23;
    }
    v15 = spcom_register_rpmsg_drv(v3);
    if ( (v15 & 0x80000000) != 0 )
    {
      v24 = v15;
      printk(&unk_11C2C, "spcom_create_channel_chardev", v15);
      v25 = spcom_ipc_log_context;
      v26 = "%sspcom:%s: register rpmsg driver failed %d\n";
      goto LABEL_32;
    }
    v16 = _kmalloc_cache_noprof(snprintf, 3520, 136);
    if ( !v16 )
      goto LABEL_28;
    goto LABEL_17;
  }
  _fortify_panic(2, -1, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  v31 = *(_QWORD *)(StatusReg + 80);
  v32 = snprintf;
  *(_QWORD *)(StatusReg + 80) = &spcom_create_channel_chardev__alloc_tag;
  v16 = _kmalloc_cache_noprof(v32, 3520, 136);
  *(_QWORD *)(StatusReg + 80) = v31;
  if ( v16 )
  {
LABEL_17:
    v17 = *(_DWORD *)(spcom_dev + 58288) + *(_DWORD *)(spcom_dev + 1160);
    v18 = device_create(v7, v8, v17, v3, "%s", a1);
    if ( v18 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_12AA8, "spcom_create_channel_chardev", v19);
      ipc_log_string(
        *((_QWORD *)v4 + 504),
        "%sspcom:%s: device_create failed\n",
        "spcom_create_channel_chardev",
        (const char *)&unk_F80E);
    }
    else
    {
      v20 = v18;
      cdev_init(v16, &fops);
      *(_QWORD *)(v16 + 96) = &_this_module;
      v21 = cdev_add(v16, v17, 1);
      if ( (v21 & 0x80000000) == 0 )
      {
        ++*(_DWORD *)(spcom_dev + 58288);
        mutex_lock(v3 + 32);
        *(_QWORD *)(v3 + 96) = v16;
        *(_QWORD *)(v3 + 104) = v20;
        *(_DWORD *)(v3 + 144) = v17;
        mutex_unlock(v3 + 32);
        return 0;
      }
      v27 = v21;
      printk(&unk_1144C, "spcom_create_channel_chardev", v21);
      ipc_log_string(
        *((_QWORD *)v4 + 504),
        "%sspcom:%s: cdev_add failed %d\n",
        "spcom_create_channel_chardev",
        (const char *)&unk_F80E,
        v27);
      device_destroy(*(_QWORD *)(spcom_dev + 1168), v17);
    }
    kfree(v16);
  }
LABEL_28:
  v28 = spcom_unregister_rpmsg_drv(v3);
  if ( v28 )
  {
    v24 = v28;
    printk(&unk_12432, "spcom_create_channel_chardev", v28);
    v25 = *((_QWORD *)v4 + 504);
    v26 = "%sspcom:%s: can't unregister rpmsg drv %d\n";
LABEL_32:
    v29 = v24;
    ipc_log_string(v25, v26, "spcom_create_channel_chardev", &unk_F80E, v24);
  }
  else
  {
    v29 = 0;
  }
  mutex_lock(v3 + 32);
  *(_QWORD *)(v3 + 16) = 0;
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0;
  mutex_unlock(v3 + 32);
  return v29;
}
