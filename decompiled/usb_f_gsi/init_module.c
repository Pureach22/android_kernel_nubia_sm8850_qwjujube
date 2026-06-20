__int64 init_module()
{
  unsigned __int64 v0; // x0
  unsigned int v1; // w0
  __int64 dir; // x0
  unsigned int v3; // w19
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  ipa_usb_wq = alloc_workqueue("k_ipa_usb", 14, 1);
  if ( ipa_usb_wq )
  {
    _mutex_init(&inst_status, "&inst_status[i].gsi_lock", &fgsi_init___key);
    _mutex_init(&unk_FBF8, "&inst_status[i].gsi_lock", &fgsi_init___key);
    _mutex_init(&unk_FC38, "&inst_status[i].gsi_lock", &fgsi_init___key);
    _mutex_init(&unk_FC78, "&inst_status[i].gsi_lock", &fgsi_init___key);
    _mutex_init(&unk_FCB8, "&inst_status[i].gsi_lock", &fgsi_init___key);
    _mutex_init(&unk_FCF8, "&inst_status[i].gsi_lock", &fgsi_init___key);
    v0 = class_create("gsi_usb");
    gsi_class = v0;
    if ( v0 > 0xFFFFFFFFFFFFF000LL )
    {
      v3 = v0;
      gsi_class = 0;
      printk(&unk_107F9, "fgsi_init");
    }
    else
    {
      v1 = alloc_chrdev_region(&v5, 0, 3, "gsi_usb");
      if ( v1 )
      {
        v3 = v1;
        printk(&unk_FFB2, "fgsi_init");
        class_destroy(gsi_class);
        gsi_class = 0;
      }
      else
      {
        major = v5 >> 20;
        dir = debugfs_create_dir("usb_gsi", 0);
        debugfs = dir;
        if ( dir )
        {
          debugfs_create_file("remote_wakeup_enable", 384, dir, &inst_status, &fops_usb_gsi_rw);
          debugfs_create_file("remote_wakeup_interval", 384, debugfs, &inst_status, &fops_usb_gsi_rw_timer);
          debugfs_create_bool("log_ctrl_packets", 420, debugfs, &byte_FD50);
        }
        v3 = usb_function_register(&gsiusb_func);
      }
    }
  }
  else
  {
    printk(&unk_120FC, "fgsi_init");
    v3 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
