__int64 create_sys_file()
{
  __int64 v0; // x0
  __int64 v1; // x19
  __int64 v2; // x1
  __int64 v3; // x1
  __int64 v4; // x1
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 result; // x0
  __int64 v8; // x1

  v0 = kobject_create_and_add("reg_debug", 0);
  if ( !v0 )
    return printk(&unk_27BF57, "create_sys_file");
  v1 = v0;
  if ( (sysfs_create_file_ns(v0, &primary_debug_attrs, 0) & 0x80000000) != 0 )
    printk(&unk_222BE6, v2);
  if ( (sysfs_create_file_ns(v1, &off_FA08, 0) & 0x80000000) != 0 )
    printk(&unk_222BE6, v3);
  if ( (sysfs_create_file_ns(v1, &off_FA28, 0) & 0x80000000) != 0 )
    printk(&unk_222BE6, v4);
  if ( (sysfs_create_file_ns(v1, &off_FA48, 0) & 0x80000000) != 0 )
    printk(&unk_222BE6, v5);
  if ( (sysfs_create_file_ns(v1, &off_FA68, 0) & 0x80000000) != 0 )
    printk(&unk_222BE6, v6);
  result = sysfs_create_file_ns(v1, &off_FA88, 0);
  if ( (result & 0x80000000) != 0 )
    return printk(&unk_222BE6, v8);
  return result;
}
