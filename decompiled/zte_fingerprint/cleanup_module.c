__int64 cleanup_module()
{
  netlink_exit();
  platform_driver_unregister(gf_driver);
  class_destroy(gf_class);
  return _unregister_chrdev((unsigned int)SPIDEV_MAJOR, 0, 256, off_C8);
}
