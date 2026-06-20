__int64 init_module()
{
  unsigned int inited; // w19
  __int64 v1; // x0

  inited = init_si_core_wq();
  if ( !inited )
  {
    v1 = kobject_create_and_add("si_core", kernel_kobj);
    si_core_kobj = v1;
    if ( v1 )
    {
      inited = sysfs_create_group(v1, &attr_group);
      if ( inited )
      {
        kobject_put(si_core_kobj);
        destroy_si_core_wq();
      }
      adci_start();
    }
    else
    {
      destroy_si_core_wq();
      return (unsigned int)-12;
    }
  }
  return inited;
}
