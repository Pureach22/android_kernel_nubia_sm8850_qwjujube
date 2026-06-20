__int64 wlan_hdd_state_ctrl_param_create()
{
  __int64 v0; // x1
  __int64 v1; // x2
  __int64 v2; // x3
  unsigned int v3; // w19
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3

  wlan_start_comp = 0;
  _init_swait_queue_head(&unk_14C40, "&x->wait", &init_completion___key_1);
  wlan_hdd_state_fops_ref = 0;
  dev_num = 1;
  if ( (unsigned int)alloc_chrdev_region(&device, 0, 2, "qcwlanstate") )
  {
    printk(&unk_879D18, v0, v1, v2);
  }
  else
  {
    v3 = device;
    class = class_create("wlan");
    if ( (unsigned __int64)class < 0xFFFFFFFFFFFFF001LL )
    {
      if ( (unsigned __int64)device_create() < 0xFFFFFFFFFFFFF001LL )
      {
        cdev_init(&wlan_hdd_state_cdev, &wlan_hdd_state_fops);
        qword_81E288 = (__int64)&_this_module;
        if ( !(unsigned int)cdev_add(&wlan_hdd_state_cdev, v3, 1) )
        {
          printk(&unk_89BC51, "wlan", v3 >> 20, v3 & 0xFFFFF);
          return 0;
        }
        printk(&unk_8A71F5, v10, v11, v12);
        device_destroy(class, (unsigned int)device);
      }
      else
      {
        printk(&unk_92D90A, v7, v8, v9);
      }
      class_destroy(class);
    }
    else
    {
      printk(&unk_884EE8, v4, v5, v6);
    }
    unregister_chrdev_region((unsigned int)device, 2);
  }
  return 4294967277LL;
}
