__int64 __fastcall ccid_set_inst_name(__int64 a1, char *s)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v12; // w21
  unsigned int v13; // w22
  unsigned int v14; // w22
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (int)(strlen(s) + 1) <= 40 )
  {
    v4 = _kmalloc_cache_noprof(device_destroy, 3520, 704);
    v3 = v4;
    if ( !v4 )
    {
      v3 = -12;
LABEL_25:
      printk(&unk_83B9, v5, v6);
      if ( v3 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_12;
      goto LABEL_11;
    }
    *(_DWORD *)(v4 + 228) = 0;
    *(_QWORD *)(v4 + 280) = v4 + 280;
    *(_QWORD *)(v4 + 288) = v4 + 280;
    _init_waitqueue_head(v4 + 296, "&ccid_dev->ctrl_dev.tx_wait_q", &ccid_setup___key);
    _init_waitqueue_head(v3 + 480, "&ccid_dev->bulk_dev.read_wq", &ccid_setup___key_7);
    _init_waitqueue_head(v3 + 504, "&ccid_dev->bulk_dev.write_wq", &ccid_setup___key_9);
    *(_QWORD *)(v3 + 544) = v3 + 544;
    *(_QWORD *)(v3 + 552) = v3 + 544;
    mutex_lock(&ccid_ida_lock);
    if ( !qword_140 )
    {
      v15 = 0;
      v7 = class_create("ccid_usb");
      ccid_class = v7;
      if ( v7 > 0xFFFFFFFFFFFFF000LL )
      {
        ccid_class = 0;
        v14 = v7;
        printk(&unk_8133, "ccid_alloc_chrdev_region", (unsigned int)v7);
        v12 = v14;
LABEL_23:
        mutex_unlock(&ccid_ida_lock);
        kfree(v3);
        v3 = (int)v12;
        goto LABEL_25;
      }
      v8 = alloc_chrdev_region(&v15, 0, 4, "ccid_usb");
      if ( v8 )
      {
        v12 = v8;
        printk(&unk_7FB8, "ccid_alloc_chrdev_region", v8);
LABEL_22:
        class_destroy();
        ccid_class = 0;
        goto LABEL_23;
      }
      major = v15 >> 20;
    }
    mutex_unlock(&ccid_ida_lock);
    v9 = ccid_cdev_init(v3 + 328, &ccid_ctrl_fops, "ccid_ctrl");
    if ( v9 )
    {
      v12 = v9;
      printk(&unk_8107, "ccid_setup", v9);
    }
    else
    {
      v10 = ccid_cdev_init(v3 + 560, &ccid_bulk_fops, "ccid_bulk");
      if ( !v10 )
      {
        if ( v3 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_12;
LABEL_11:
        *(_QWORD *)(a1 + 176) = v3;
        LODWORD(v3) = 0;
        goto LABEL_12;
      }
      v12 = v10;
      printk(&unk_8095, "ccid_setup", v10);
      v13 = *(_DWORD *)(v3 + 456);
      device_destroy(ccid_class, v13);
      cdev_del(v3 + 328);
      ida_free(&ccid_ida, v13 & 0xFFFFF);
    }
    mutex_lock(&ccid_ida_lock);
    if ( qword_140 )
      goto LABEL_23;
    if ( major )
    {
      unregister_chrdev_region((unsigned int)(major << 20), 4);
      major = 0;
    }
    if ( !ccid_class )
      goto LABEL_23;
    goto LABEL_22;
  }
  LODWORD(v3) = -36;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3;
}
