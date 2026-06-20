__int64 init_module()
{
  __int64 v0; // x0
  unsigned int v1; // w19

  probe_finished = 0;
  v0 = _platform_driver_register(bt_power_driver, &_this_module);
  if ( (_DWORD)v0 )
  {
    v1 = v0;
    printk(&unk_114D2, "btpower_init");
    return v1;
  }
  bt_major = _register_chrdev(v0, 0, 256, &unk_11A34, &bt_dev_fops);
  if ( bt_major < 0 )
  {
    printk(&unk_12C78, "btpower_init");
    v1 = -1;
LABEL_12:
    platform_driver_unregister(bt_power_driver);
    return v1;
  }
  bt_class = class_create("bt-dev");
  if ( (unsigned __int64)bt_class >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_12D5C, "btpower_init");
    v1 = -1;
LABEL_11:
    _unregister_chrdev((unsigned int)bt_major, 0, 256, &unk_11A34);
    goto LABEL_12;
  }
  if ( !device_create() )
  {
    printk(&unk_12C78, "btpower_init");
    class_destroy(bt_class);
    v1 = 0;
    goto LABEL_11;
  }
  return 0;
}
