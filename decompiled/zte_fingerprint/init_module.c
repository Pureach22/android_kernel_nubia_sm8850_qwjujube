__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _register_chrdev((unsigned int)SPIDEV_MAJOR, 0, 256, "goodix_fp_spi", &gf_fops);
  if ( (v0 & 0x80000000) != 0 )
  {
    printk(&unk_89B0);
  }
  else
  {
    SPIDEV_MAJOR = v0;
    gf_class = class_create("goodix_fp");
    if ( (unsigned __int64)gf_class < 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_platform_driver_register(gf_driver, &_this_module) & 0x80000000) != 0 )
      {
        class_destroy(gf_class);
        _unregister_chrdev((unsigned int)SPIDEV_MAJOR, 0, 256, off_C8);
        printk(&unk_8B69);
      }
      netlink_init();
      printk(&unk_90F0);
      return 0;
    }
    else
    {
      _unregister_chrdev((unsigned int)SPIDEV_MAJOR, 0, 256, off_C8);
      printk(&unk_98C2);
      return (unsigned int)gf_class;
    }
  }
  return v0;
}
