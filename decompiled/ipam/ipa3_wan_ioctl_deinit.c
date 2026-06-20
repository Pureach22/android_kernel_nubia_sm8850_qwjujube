__int64 ipa3_wan_ioctl_deinit()
{
  cdev_del(&ipa3_wan_ioctl_cdev);
  device_destroy(class_0, (unsigned int)device_0);
  class_destroy(class_0);
  return unregister_chrdev_region((unsigned int)device_0, 1);
}
