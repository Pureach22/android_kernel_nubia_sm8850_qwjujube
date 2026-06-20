__int64 cleanup_module()
{
  platform_driver_unregister(mem_buf_msgq_driver);
  class_destroy(mem_buf_class);
  return unregister_chrdev_region((unsigned int)mem_buf_dev_no, 1);
}
