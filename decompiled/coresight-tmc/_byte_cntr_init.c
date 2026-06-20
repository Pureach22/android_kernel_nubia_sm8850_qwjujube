__int64 __fastcall byte_cntr_init(__int64 *a1, __int64 a2)
{
  unsigned int byname; // w0
  unsigned int v5; // w22
  __int64 v6; // x20
  __int64 v7; // x5
  __int64 v8; // x3
  unsigned int v9; // w0
  __int64 v10; // x1
  unsigned __int64 v11; // x0
  __int64 v12; // x8
  const char *v13; // x1
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  byname = of_irq_get_byname(a1[93], "byte-cntr-irq");
  if ( (byname & 0x80000000) != 0 )
    goto LABEL_24;
  v5 = byname;
  v6 = devm_kmalloc(a1, 432, 3520);
  if ( v6 )
  {
    v7 = a1[14];
    if ( !v7 )
      v7 = *a1;
    if ( (unsigned int)devm_request_threaded_irq(a1, v5, etr_handler, 0, 129, v7, v6) )
    {
      v13 = "Byte_cntr interrupt registration failed\n";
    }
    else
    {
      if ( (of_property_read_variable_u32_array(a1[93], "csr-irqctrl-offset", v6 + 392, 1, 0) & 0x80000000) != 0 )
        *(_DWORD *)(v6 + 392) = 108;
      if ( (unsigned int)device_property_read_string(a1, "byte-cntr-name", v6 + 376) )
        *(_QWORD *)(v6 + 376) = "byte-cntr";
      if ( (unsigned int)device_property_read_string(a1, "byte-cntr-class-name", v6 + 384) )
        *(_QWORD *)(v6 + 384) = "coresight-tmc-etr-stream";
      v8 = *(_QWORD *)(v6 + 376);
      v15 = 0;
      v9 = alloc_chrdev_region(&v15, 0, 1, v8);
      if ( (v9 & 0x80000000) != 0 )
      {
        printk(&unk_100B6, v9);
      }
      else
      {
        cdev_init(v6, &byte_cntr_fops);
        v10 = v15;
        *(_QWORD *)(v6 + 96) = &_this_module;
        *(_QWORD *)(v6 + 104) = &byte_cntr_fops;
        if ( !(unsigned int)cdev_add(v6, v10, 1) )
        {
          v11 = class_create(*(_QWORD *)(v6 + 384));
          *(_QWORD *)(v6 + 136) = v11;
          if ( v11 >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_FBCF, 4294967284LL);
          }
          else
          {
            if ( (unsigned __int64)device_create() < 0xFFFFFFFFFFFFF001LL )
            {
              v12 = *(_QWORD *)(a2 + 312);
              *(_DWORD *)(v6 + 156) = v5;
              *(_QWORD *)(v6 + 360) = v12;
              *(_QWORD *)(v6 + 368) = a2;
              *(_DWORD *)(v6 + 160) = 0;
              _init_waitqueue_head(v6 + 168, "&byte_cntr_data->wq", &byte_cntr_init___key);
              _mutex_init(v6 + 312, "&byte_cntr_data->byte_cntr_lock", &byte_cntr_init___key_9);
              goto LABEL_25;
            }
            printk(&unk_FF03, 0);
            class_destroy(*(_QWORD *)(v6 + 136));
          }
        }
        unregister_chrdev_region(*(unsigned int *)(v6 + 128), 1);
      }
      v13 = "Byte_cntr char dev registration failed\n";
    }
    dev_err(a1, v13);
LABEL_24:
    v6 = 0;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v6;
}
