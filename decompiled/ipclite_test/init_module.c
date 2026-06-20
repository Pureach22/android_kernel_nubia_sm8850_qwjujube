__int64 init_module()
{
  unsigned int global_partition_info; // w0
  unsigned int v1; // w0
  __int64 v2; // x0
  unsigned int v3; // w19
  void *v4; // x0

  global_partition_info = get_global_partition_info(&global_memory);
  if ( global_partition_info )
  {
    v3 = global_partition_info;
    v4 = &unk_B13D;
LABEL_11:
    printk(v4, "ipclite_test", "ipclite_test_init");
    return v3;
  }
  v1 = ipclite_register_test_client(ipclite_test_callback_fn, 0);
  if ( v1 )
  {
    v3 = v1;
    v4 = &unk_AE71;
    goto LABEL_11;
  }
  v2 = kobject_create_and_add("ipclite_test", kernel_kobj);
  sysfs_dir = v2;
  if ( !v2 )
  {
    printk(&unk_ADEA, "ipclite_test", "ipclite_test_sysfs_node_setup");
LABEL_10:
    v3 = -2;
    v4 = &unk_B058;
    goto LABEL_11;
  }
  if ( (unsigned int)sysfs_create_file_ns(v2, ipclite_test_params, 0) )
  {
    printk(&unk_A938, "ipclite_test", "ipclite_test_sysfs_node_setup");
    goto LABEL_10;
  }
  return 0;
}
