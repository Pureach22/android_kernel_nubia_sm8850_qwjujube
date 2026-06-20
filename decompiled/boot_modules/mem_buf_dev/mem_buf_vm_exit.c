__int64 mem_buf_vm_exit()
{
  xa_destroy(&mem_buf_vms);
  xa_destroy(&mem_buf_vm_minors);
  class_for_each_device(mem_buf_vm_class, 0, 0, mem_buf_vm_put_class_device_cb);
  class_destroy(mem_buf_vm_class);
  return unregister_chrdev_region((unsigned int)mem_buf_vm_devt, 128);
}
