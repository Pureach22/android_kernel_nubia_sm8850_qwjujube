__int64 gh_sysfs_register()
{
  __int64 result; // x0

  result = sysfs_create_file_ns(hypervisor_kobj, &type_attr, 0);
  if ( !(_DWORD)result )
  {
    result = sysfs_create_file_ns(hypervisor_kobj, &virt_time_offset_attr, 0);
    if ( !(_DWORD)result )
      return sysfs_create_group(hypervisor_kobj, &version_group);
  }
  return result;
}
