__int64 cleanup_module()
{
  if ( hdr )
    unregister_sysctl_table();
  class_interface_unregister(&sg_interface);
  class_unregister(&sg_sysfs_class);
  sg_sysfs_valid = 0;
  unregister_chrdev_region(22020096, 0x100000);
  return idr_destroy(&sg_index_idr);
}
