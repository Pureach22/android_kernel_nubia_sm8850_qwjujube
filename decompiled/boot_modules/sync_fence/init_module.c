__int64 init_module()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x20

  sync_dev = class_create("sync");
  if ( sync_dev )
  {
    if ( (unsigned int)alloc_chrdev_region(&dword_7B48, 0, 1, "spec_sync") )
    {
      printk(&unk_7ADE, "spec_sync_register_device");
    }
    else
    {
      qword_7B50 = device_create(sync_dev, 0, (unsigned int)dword_7B48, &sync_dev, "spec_sync");
      if ( (unsigned __int64)qword_7B50 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_77FC, "spec_sync_register_device");
      }
      else
      {
        v0 = cdev_alloc();
        qword_7B58 = v0;
        if ( v0 )
        {
          cdev_init(v0, &spec_sync_fops);
          *(_QWORD *)(qword_7B58 + 96) = &_this_module;
          if ( (unsigned int)cdev_add() )
          {
            printk(&unk_76C2, "spec_sync_register_device");
          }
          else
          {
            dword_7BBC = 1;
            _mutex_init(&unk_7B60, "&sync_dev.lock", &spec_sync_register_device___key);
            _mutex_init(&unk_7BC0, "&sync_dev.l_lock", &spec_sync_register_device___key_29);
            qword_7BF0 = (__int64)&qword_7BF0;
            qword_7BF8 = (__int64)&qword_7BF0;
            _init_waitqueue_head(&unk_7C00, "&sync_dev.wait_queue", &spec_sync_register_device___key_31);
            v1 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
            v2 = v1;
            if ( v1 )
            {
              *(_DWORD *)(v1 + 64) = 0;
              dma_fence_init(v1, &dummy_spec_fence_ops, v1 + 64, 0xFAFADADAFAFADADALL, 0xEFA9CE00EFA9CE00LL);
              qword_7B90 = v2;
              return 0;
            }
          }
          cdev_del(qword_7B58);
        }
        else
        {
          printk(&unk_7B03, "spec_sync_register_device");
        }
        device_destroy(sync_dev, (unsigned int)dword_7B48);
      }
      unregister_chrdev_region((unsigned int)dword_7B48, 1);
    }
    class_destroy(sync_dev);
  }
  else
  {
    printk(&unk_781B, "spec_sync_register_device");
  }
  printk(&unk_79EF, "spec_sync_init");
  return 4294967277LL;
}
