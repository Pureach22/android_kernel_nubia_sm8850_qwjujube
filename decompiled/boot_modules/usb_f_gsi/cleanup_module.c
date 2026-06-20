__int64 cleanup_module()
{
  if ( ipa_usb_wq )
    destroy_workqueue();
  usb_function_unregister(&gsiusb_func);
  if ( major )
  {
    unregister_chrdev_region((unsigned int)(major << 20), 3);
    major = 0;
  }
  class_destroy(gsi_class);
  return debugfs_remove(debugfs);
}
