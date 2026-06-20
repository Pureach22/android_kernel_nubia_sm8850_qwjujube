__int64 __fastcall qbt_probe(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w22
  __int64 v5; // x8
  __int64 v6; // x22
  unsigned __int64 *v7; // x19
  void *v8; // x0
  int named_gpio; // w0
  unsigned __int64 v10; // x0
  _DWORD *v11; // x0
  unsigned int v12; // w0
  unsigned int v13; // w23
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned __int64 v16; // x0
  void *v17; // x0
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x0
  void *v20; // x0
  unsigned int input_device; // w0
  unsigned int v22; // w0
  void *v23; // x0
  unsigned int v24; // w0
  __int64 v25; // x0
  unsigned int v26; // w0
  __int64 v27; // x0
  unsigned int v28; // w0
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_9DD2, "qbt_probe");
  v2 = devm_kmalloc(a1 + 16, 11968, 3520);
  if ( v2 )
  {
    v5 = *(_QWORD *)(a1 + 760);
    *(_QWORD *)(v2 + 288) = a1 + 16;
    *(_QWORD *)(a1 + 168) = v2;
    v6 = v2;
    *(_DWORD *)(v2 + 1048) = of_get_named_gpio(v5, "qcom,intr2-gpio", 0);
    printk(&unk_9DF6, "qbt_read_device_tree");
    v7 = (unsigned __int64 *)v6;
    if ( (*(_DWORD *)(v6 + 1048) & 0x80000000) != 0 )
      printk(&unk_92B8, "qbt_read_device_tree");
    *(_DWORD *)(v6 + 456) = of_get_named_gpio(*(_QWORD *)(a1 + 760), "qcom,ipc-gpio", 0);
    printk(&unk_9426, "qbt_read_device_tree");
    v3 = *(_DWORD *)(v6 + 456);
    if ( (v3 & 0x80000000) != 0 )
    {
      printk(&unk_9AD3, "qbt_read_device_tree");
      printk(&unk_9809, "qbt_read_device_tree");
      v8 = &unk_9233;
LABEL_31:
      printk(v8, "qbt_probe");
LABEL_32:
      v20 = &unk_9809;
LABEL_33:
      printk(v20, "qbt_probe");
      goto LABEL_3;
    }
    named_gpio = of_get_named_gpio(*(_QWORD *)(a1 + 760), "qcom,finger-detect-gpio", 0);
    if ( named_gpio < 0 )
    {
      printk(&unk_99B4, "qbt_read_device_tree");
      *((_BYTE *)v7 + 1144) = 0;
    }
    else
    {
      *((_DWORD *)v7 + 126) = named_gpio;
      *((_BYTE *)v7 + 1144) = 1;
      *((_DWORD *)v7 + 127) = 0;
      printk(&unk_950A, "qbt_read_device_tree");
    }
    printk(&unk_9809, "qbt_read_device_tree");
    *((_DWORD *)v7 + 76) = 1;
    *((_DWORD *)v7 + 77) = 1;
    *((_DWORD *)v7 + 1570) = 0;
    _mutex_init(v7 + 39, "&drvdata->mutex", &qbt_probe___key);
    _mutex_init(v7 + 45, "&drvdata->fd_events_mutex", &qbt_probe___key_6);
    _mutex_init(v7 + 51, "&drvdata->ipc_events_mutex", &qbt_probe___key_8);
    v10 = v7[36];
    v29 = 0;
    v11 = (_DWORD *)devm_kmalloc(v10, 4, 3520);
    v7[37] = (unsigned __int64)v11;
    if ( !v11 )
    {
      v3 = -12;
      printk(&unk_9ABB, "qbt_dev_register");
LABEL_30:
      v8 = &unk_97C2;
      goto LABEL_31;
    }
    *v11 = 7627377;
    v12 = alloc_chrdev_region(&v29, 0, 2, v11);
    if ( v12 )
    {
      v3 = v12;
      printk(&unk_9C38, "qbt_dev_register");
      goto LABEL_29;
    }
    printk(&unk_9E9E, "qbt_dev_register");
    v13 = v29 & 0xFFF00000;
    cdev_init(v7 + 1, &qbt_fops);
    v7[13] = (unsigned __int64)&_this_module;
    v14 = cdev_add(v7 + 1, v13, 1);
    if ( v14 )
    {
      v3 = v14;
      v17 = &unk_A336;
    }
    else
    {
      printk(&unk_A064, "qbt_dev_register");
      cdev_init(v7 + 18, &qbt_fops);
      v7[30] = (unsigned __int64)&_this_module;
      v15 = cdev_add(v7 + 18, v13 | 1, 1);
      if ( !v15 )
      {
        printk(&unk_98BB, "qbt_dev_register");
        v16 = class_create(v7[37]);
        *v7 = v16;
        if ( v16 < 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_95AE, "qbt_dev_register");
          v18 = device_create(*v7, 0, *((unsigned int *)v7 + 34), v7, "%s_fd", (const char *)v7[37]);
          if ( v18 < 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_96CE, "qbt_dev_register");
            v19 = device_create(*v7, 0, *((unsigned int *)v7 + 68), v7, "%s_ipc", (const char *)v7[37]);
            if ( v19 < 0xFFFFFFFFFFFFF001LL )
            {
              printk(&unk_A189, "qbt_dev_register");
              goto LABEL_35;
            }
            v3 = v19;
            printk(&unk_A3CC, "qbt_dev_register");
          }
          else
          {
            v3 = v18;
            printk(&unk_96A4, "qbt_dev_register");
          }
          class_destroy(*v7);
        }
        else
        {
          v3 = v16;
          printk(&unk_A163, "qbt_dev_register");
        }
        cdev_del(v7 + 1);
        cdev_del(v7 + 18);
        goto LABEL_28;
      }
      v3 = v15;
      v17 = &unk_A35F;
    }
    printk(v17, "qbt_dev_register");
LABEL_28:
    unregister_chrdev_region(*((unsigned int *)v7 + 34), 1);
    unregister_chrdev_region(*((unsigned int *)v7 + 68), 1);
LABEL_29:
    printk(&unk_9ABB, "qbt_dev_register");
    if ( (v3 & 0x80000000) != 0 )
      goto LABEL_30;
LABEL_35:
    input_device = qbt_create_input_device(v7);
    if ( (input_device & 0x80000000) != 0 )
    {
      v3 = input_device;
      printk(&unk_9BB2, "qbt_probe");
LABEL_46:
      qbt_dev_unregister(v7);
      goto LABEL_32;
    }
    v7[787] = 0x280000007FLL;
    v7[788] = (unsigned __int64)(v7 + 789);
    v7[786] = 0;
    v7[1430] = 0x40000007FLL;
    v7[1429] = 0;
    v7[1431] = (unsigned __int64)(v7 + 1432);
    _init_waitqueue_head(v7 + 137, "&drvdata->read_wait_queue_fd", &qbt_probe___key_12);
    _init_waitqueue_head(v7 + 140, "&drvdata->read_wait_queue_ipc", &qbt_probe___key_14);
    if ( (v7[131] & 0x80000000) != 0 || (v22 = setup_intr2_irq(a1, v7), (v22 & 0x80000000) == 0) )
    {
      v24 = setup_fd_gpio_irq(a1, v7);
      if ( (v24 & 0x80000000) != 0 )
      {
        v3 = v24;
        v23 = &unk_97E5;
      }
      else
      {
        v25 = *((unsigned int *)v7 + 128);
        *((_BYTE *)v7 + 560) = 0;
        disable_irq(v25);
        v26 = setup_ipc_irq(a1, v7);
        if ( (v26 & 0x80000000) == 0 )
        {
          v27 = *((unsigned int *)v7 + 115);
          *((_BYTE *)v7 + 464) = 0;
          disable_irq(v27);
          device_set_wakeup_capable(a1 + 16, 1);
          v28 = device_wakeup_enable(a1 + 16);
          if ( (v28 & 0x80000000) != 0 )
          {
            v3 = v28;
            printk(&unk_9CF7, "qbt_probe");
          }
          else
          {
            v7[76] = 0xFFFFFFFE00000LL;
            qbt_touch_handler = (__int64)v7;
            v7[77] = (unsigned __int64)(v7 + 77);
            v7[78] = (unsigned __int64)(v7 + 77);
            v7[79] = (unsigned __int64)qbt_touch_work_func;
            *((_DWORD *)v7 + 162) = -1;
            *((_DWORD *)v7 + 202) = -1;
            *((_DWORD *)v7 + 166) = -1;
            *((_DWORD *)v7 + 206) = -1;
            *((_DWORD *)v7 + 170) = -1;
            *((_DWORD *)v7 + 210) = -1;
            *((_DWORD *)v7 + 174) = -1;
            *((_DWORD *)v7 + 214) = -1;
            *((_DWORD *)v7 + 178) = -1;
            *((_DWORD *)v7 + 218) = -1;
            *((_DWORD *)v7 + 182) = -1;
            *((_DWORD *)v7 + 222) = -1;
            *((_DWORD *)v7 + 186) = -1;
            *((_DWORD *)v7 + 226) = -1;
            *((_DWORD *)v7 + 190) = -1;
            *((_DWORD *)v7 + 230) = -1;
            *((_DWORD *)v7 + 194) = -1;
            *((_DWORD *)v7 + 234) = -1;
            *((_DWORD *)v7 + 198) = -1;
            *((_DWORD *)v7 + 238) = -1;
            v3 = input_register_handler();
            if ( (v3 & 0x80000000) == 0 )
            {
              v20 = &unk_A01D;
              goto LABEL_33;
            }
            printk(&unk_9344, "qbt_probe");
            device_wakeup_disable(a1 + 16);
            device_set_wakeup_capable(a1 + 16, 0);
          }
          goto LABEL_45;
        }
        v3 = v26;
        v23 = &unk_9FFD;
      }
    }
    else
    {
      v3 = v22;
      v23 = &unk_9956;
    }
    printk(v23, "qbt_probe");
LABEL_45:
    qbt_unregister_input_device(v7);
    goto LABEL_46;
  }
  v3 = -12;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
