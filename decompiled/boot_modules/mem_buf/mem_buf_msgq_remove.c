__int64 __fastcall mem_buf_msgq_remove(__int64 a1)
{
  debugfs_lookup_and_remove("xmem_total_size", mem_buf_debugfs_root);
  gunyah_qtvm_unregister_notifier(&vm_nb);
  device_destroy(mem_buf_class, (unsigned int)mem_buf_dev_no);
  cdev_del(&mem_buf_char_dev);
  return mem_buf_msgq_free(a1 + 16);
}
