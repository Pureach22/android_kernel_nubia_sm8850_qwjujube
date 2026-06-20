__int64 cleanup_module()
{
  printk(&unk_A50D, "ipclite_test", "ipclite_test_exit");
  sysfs_remove_file_ns(sysfs_dir, ipclite_test_params, 0);
  return kobject_put(sysfs_dir);
}
