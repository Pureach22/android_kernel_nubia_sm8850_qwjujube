__int64 init_module()
{
  unsigned int v0; // w19

  if ( (unsigned int)scatter_elem_sz <= 0xFFF )
  {
    scatter_elem_sz = 4096;
    scatter_elem_sz_prev = 4096;
  }
  if ( def_reserved_size < 0 )
    def_reserved_size = sg_big_buff;
  else
    sg_big_buff = def_reserved_size;
  v0 = register_chrdev_region(22020096, 0x100000, "sg");
  if ( !v0 )
  {
    v0 = class_register(&sg_sysfs_class);
    if ( !v0 )
    {
      sg_sysfs_valid = 1;
      v0 = scsi_register_interface(&sg_interface);
      if ( !v0 )
        return v0;
      class_unregister(&sg_sysfs_class);
      if ( !hdr )
        hdr = register_sysctl_sz("kernel", &sg_sysctls, 1);
    }
    unregister_chrdev_region(22020096, 0x100000);
  }
  return v0;
}
