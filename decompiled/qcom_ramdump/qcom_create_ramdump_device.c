__int64 __fastcall qcom_create_ramdump_device(const char *a1, __int64 a2)
{
  int v4; // w0
  __int64 v5; // x20
  unsigned int v6; // w22
  unsigned __int64 v7; // x0
  int v8; // w0
  __int64 v10; // x19
  int v11; // w21
  int v12; // w20

  if ( !a1 )
  {
    printk(&unk_6FD7, "qcom_create_ramdump_device");
    return 0;
  }
  mutex_lock(&rd_minor_mutex);
  if ( (ramdump_devnode_inited & 1) == 0 )
  {
    ramdump_class = class_create("ramdump");
    v4 = alloc_chrdev_region(&ramdump_dev, 0, 256, "ramdump");
    if ( v4 )
    {
      v12 = v4;
      printk(&unk_6F9D, "ramdump_devnode_init");
      mutex_unlock(&rd_minor_mutex);
      return v12;
    }
    ramdump_devnode_inited = 1;
  }
  mutex_unlock(&rd_minor_mutex);
  v5 = _kmalloc_cache_noprof(device_create, 3520, 400);
  if ( !v5 )
    return 0;
  v6 = ida_alloc_range(&rd_minor_id, 0, 255, 3264);
  if ( (v6 & 0x80000000) != 0 )
  {
    printk(&unk_7063, "qcom_create_ramdump_device");
    v10 = -19;
  }
  else
  {
    snprintf((char *)v5, 0x100u, "%s", a1);
    v7 = device_create(ramdump_class, a2, ramdump_dev & 0xFFF00000 | v6, v5, v5);
    *(_QWORD *)(v5 + 392) = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v11 = v7;
      printk(&unk_708C, "qcom_create_ramdump_device");
    }
    else
    {
      cdev_init(v5 + 256, 0);
      v8 = cdev_add(v5 + 256, ramdump_dev & 0xFFF00000 | v6, 1);
      if ( !v8 )
        return *(_QWORD *)(v5 + 392);
      v11 = v8;
      printk(&unk_6F28, "qcom_create_ramdump_device");
      device_unregister(*(_QWORD *)(v5 + 392));
    }
    ida_free(&rd_minor_id, v6);
    v10 = v11;
  }
  kfree(v5);
  return v10;
}
