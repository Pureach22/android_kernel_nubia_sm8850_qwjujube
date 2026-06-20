__int64 ipa3_wan_ioctl_init()
{
  unsigned int v0; // w22
  unsigned __int64 v1; // x0
  unsigned int v2; // w19
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0

  device_0 = 0;
  if ( (unsigned int)alloc_chrdev_region(&device_0, 0, 1, "wwan_ioctl") )
  {
    printk(&unk_3FF491, "ipa3_wan_ioctl_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d :device_alloc err.\n", "ipa3_wan_ioctl_init", 615);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d :device_alloc err.\n", "ipa3_wan_ioctl_init", 615);
    }
    return 4294967277LL;
  }
  v0 = device_0;
  v1 = class_create("wwan_ioctl");
  class_0 = v1;
  if ( v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3B6505, "ipa3_wan_ioctl_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa-wan %s:%d :class_create err.\n", "ipa3_wan_ioctl_init", 623);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa-wan %s:%d :class_create err.\n", "ipa3_wan_ioctl_init", 623);
    }
    goto LABEL_27;
  }
  if ( (unsigned __int64)device_create(v1, 0, (unsigned int)device_0, 0, "wwan_ioctl") >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C84CB, "ipa3_wan_ioctl_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa-wan %s:%d :device_create err.\n", "ipa3_wan_ioctl_init", 630);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa-wan %s:%d :device_create err.\n", "ipa3_wan_ioctl_init", 630);
    }
    goto LABEL_26;
  }
  cdev_init(&ipa3_wan_ioctl_cdev, &rmnet_ipa3_fops);
  if ( (unsigned int)cdev_add(&ipa3_wan_ioctl_cdev, (unsigned int)device_0, 1) )
  {
    printk(&unk_3B34B0, "ipa3_wan_ioctl_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa-wan %s:%d :cdev_add err.\n", "ipa3_wan_ioctl_init", 637);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa-wan %s:%d :cdev_add err.\n", "ipa3_wan_ioctl_init", 637);
    }
    device_destroy(class_0, (unsigned int)device_0);
LABEL_26:
    class_destroy(class_0);
LABEL_27:
    unregister_chrdev_region((unsigned int)device_0, 1);
    return 4294967277LL;
  }
  v2 = v0 >> 20;
  ipa3_process_ioctl = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    v3 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v3,
      "ipa-wan %s:%d IPA %s major(%d) initial ok :>>>>\n",
      "ipa3_wan_ioctl_init",
      644,
      "wwan_ioctl",
      v2);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v5,
      "ipa-wan %s:%d IPA %s major(%d) initial ok :>>>>\n",
      "ipa3_wan_ioctl_init",
      644,
      "wwan_ioctl",
      v2);
    return 0;
  }
  return result;
}
