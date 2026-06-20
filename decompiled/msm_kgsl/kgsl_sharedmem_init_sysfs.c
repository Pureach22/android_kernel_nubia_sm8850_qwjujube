__int64 kgsl_sharedmem_init_sysfs()
{
  return sysfs_create_files(&unk_3A458, drv_attr_list);
}
