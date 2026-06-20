__int64 init_module()
{
  void *v0; // x0
  __int64 v1; // x0
  unsigned int v2; // w21
  __int64 v3; // x24
  void *v4; // x0
  __int64 v5; // x19
  void *v6; // x0
  unsigned int v7; // w0
  void *v8; // x0
  unsigned __int64 v9; // x0
  int v10; // w0
  __int64 v11; // x20
  int v12; // w9
  __int64 v13; // x10
  int v14; // w8
  __int64 v15; // x9
  __int64 v16; // x2
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int file; // w0
  void *v20; // x0
  __int64 v21; // x9
  __int64 v22; // x26
  __int64 v23; // x0

  if ( (unsigned __int8)log_lvl <= 7u )
    v0 = &unk_C2CA;
  else
    v0 = &unk_D931;
  printk(v0, "btfmcodec_init");
  v1 = _kmalloc_cache_noprof(device_create_file, 3520, 1088);
  btfmcodec = v1;
  if ( v1 )
  {
    _mutex_init(v1 + 1040, "&btfmcodec->hwep_drv_lock", &btfmcodec_init___key);
    v3 = btfmcodec;
    if ( (unsigned __int8)log_lvl <= 7u )
      v4 = &unk_DC16;
    else
      v4 = &unk_DBFA;
    *(_QWORD *)(btfmcodec + 964) = 0;
    printk(v4, "btfmcodec_init");
    v5 = _kmalloc_cache_noprof(device_add, 3520, 760);
    if ( v5 )
    {
      if ( (unsigned __int8)log_lvl <= 7u )
        v6 = &unk_C14F;
      else
        v6 = &unk_C482;
      printk(v6, "btfmcodec_init");
      v7 = alloc_chrdev_region(&dev_major, 0, 0, "btfmcodec");
      if ( (v7 & 0x80000000) != 0 )
      {
        v2 = v7;
        printk(&unk_BF67, "btfmcodec_init");
      }
      else
      {
        if ( (unsigned __int8)log_lvl <= 7u )
          v8 = &unk_CC80;
        else
          v8 = &unk_DC32;
        printk(v8, "btfmcodec_init");
        v9 = class_create("btfmcodec");
        dev_class = v9;
        if ( v9 < 0xFFFFFFFFFFFFF001LL )
        {
          v10 = idr_alloc(&dev_minor, btfmcodec, 1, 0, 3264);
          v11 = btfmcodec;
          *(_DWORD *)(v5 + 240) = v10;
          *(_QWORD *)(v11 + 136) = &driver;
          *(_QWORD *)(v11 + 976) = v5;
          *(_DWORD *)(v5 + 136) = 1;
          _mutex_init(v5 + 144, "&btfmcodec_dev->lock", &btfmcodec_init___key_29);
          _mutex_init(v5 + 192, "&btfmcodec_dev->trans_lock", &btfmcodec_init___key_31);
          strcpy((char *)(v5 + 244), "btfmcodec_dev");
          device_initialize(v11);
          v12 = dev_major;
          v13 = btfmcodec;
          *(_QWORD *)(v11 + 792) = dev_class;
          v14 = *(_DWORD *)(v5 + 240);
          *(_QWORD *)(v11 + 152) = v13;
          *(_DWORD *)(v11 + 760) = v12 & 0xFFF00000 | v14;
          cdev_init(v5, &btfmcodec_fops);
          v15 = btfmcodec;
          v16 = *(unsigned int *)(v5 + 240);
          *(_QWORD *)(v5 + 96) = &_this_module;
          *(_QWORD *)(v5 + 752) = v15;
          dev_set_name(v11, v5 + 244, v16);
          v17 = cdev_add(v5, *(unsigned int *)(v11 + 760), 1);
          if ( v17 )
          {
            v2 = v17;
            printk(&unk_DAE7, "btfmcodec_init");
          }
          else
          {
            *(_QWORD *)(v11 + 808) = 0;
            v18 = device_add(v11);
            if ( v18 )
            {
              v2 = v18;
              printk(&unk_CDA6, "btfmcodec_init");
            }
            else
            {
              printk(&unk_C4A5, "btfmcodec_init");
              file = device_create_file(v11, &dev_attr_btfmcodec_attributes);
              if ( file )
              {
                v2 = file;
                printk(&unk_D771, "btfmcodec_init");
              }
              else
              {
                if ( (unsigned __int8)log_lvl <= 7u )
                  v20 = &unk_D51A;
                else
                  v20 = &unk_CDCE;
                printk(v20, "btfmcodec_init");
                *(_QWORD *)(v5 + 320) = v5 + 320;
                *(_QWORD *)(v5 + 328) = v5 + 320;
                *(_QWORD *)(v5 + 336) = 0;
                *(_QWORD *)(v5 + 344) = v5 + 344;
                *(_QWORD *)(v5 + 352) = v5 + 344;
                *(_QWORD *)(v5 + 360) = 0;
                _mutex_init(v5 + 144, "&btfmcodec_dev->lock", &btfmcodec_init___key_40);
                *(_QWORD *)(v5 + 368) = 0xFFFFFFFE00000LL;
                *(_QWORD *)(v5 + 376) = v5 + 376;
                *(_QWORD *)(v5 + 384) = v5 + 376;
                *(_QWORD *)(v5 + 392) = btfmcodec_dev_rxwork;
                _init_waitqueue_head(v5 + 496, "&btfmcodec_dev->readq", &btfmcodec_init___key_42);
                v21 = btfmcodec;
                v22 = 0;
                *(_QWORD *)(v5 + 528) = v5 + 528;
                *(_QWORD *)(v5 + 536) = v5 + 528;
                *(_DWORD *)(v5 + 520) = 0;
                *(_QWORD *)(v5 + 544) = 0;
                *(_QWORD *)(v21 + 992) = v21 + 992;
                *(_QWORD *)(v21 + 1000) = v21 + 992;
                do
                {
                  _init_waitqueue_head(v5 + 552 + v22, "&btfmcodec_dev->rsp_wait_q[i]", &btfmcodec_init___key_44);
                  v22 += 24;
                }
                while ( v22 != 192 );
                _mutex_init(v3 + 912, "&states->state_machine_lock", &btfmcodec_init___key_46);
                v23 = alloc_workqueue("btfmcodec_wq", 131074, 1);
                *(_QWORD *)(v5 + 312) = v23;
                if ( v23 )
                  return 0;
                printk(&unk_CA96, "btfmcodec_init");
                v2 = -12;
              }
            }
            put_device(v11);
          }
          idr_remove(&dev_minor, *(int *)(v5 + 240));
          class_destroy(dev_class);
        }
        else
        {
          v2 = v9;
          printk(&unk_D74E, "btfmcodec_init");
        }
        unregister_chrdev_region((unsigned int)dev_major >> 20, 0);
      }
      kfree(v5);
    }
    else
    {
      printk(&unk_CD85, "btfmcodec_init");
      v2 = -12;
    }
    kfree(btfmcodec);
    return v2;
  }
  printk(&unk_CD85, "btfmcodec_init");
  return (unsigned int)-12;
}
