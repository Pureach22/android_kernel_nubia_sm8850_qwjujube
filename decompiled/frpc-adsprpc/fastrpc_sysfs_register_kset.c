__int64 fastrpc_sysfs_register_kset()
{
  __int64 v0; // x2
  __int64 v1; // x3
  __int64 v2; // x4
  __int64 v3; // x5

  fastrpc_kset = kset_create_and_add("fastrpc", 0, kernel_kobj);
  if ( fastrpc_kset )
    return 0;
  printk(&unk_24D56, "fastrpc_sysfs_register_kset", v0, v1, v2, v3);
  return 4294967284LL;
}
