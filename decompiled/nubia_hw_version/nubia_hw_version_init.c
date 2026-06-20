// Alternative name is 'init_module'
__int64 nubia_hw_version_init()
{
  __int64 v0; // x0
  unsigned int group; // w19

  if ( debug_value == 1 )
    printk(byte_748D);
  _platform_driver_register(hardware_ver_driver, &_this_module);
  v0 = kobject_create_and_add("nubia_hw_version", 0);
  hw_version_kobj = v0;
  if ( v0 )
  {
    group = sysfs_create_group(v0, &nubia_hw_version_attr_group);
    if ( group )
      printk(byte_750A, "nubia_hw_version_init");
    if ( debug_value == 1 )
      printk(byte_735D);
  }
  else
  {
    printk(byte_7126, "nubia_hw_version_init");
    return (unsigned int)-12;
  }
  return group;
}
