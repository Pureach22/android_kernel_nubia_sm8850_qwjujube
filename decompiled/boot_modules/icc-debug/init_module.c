__int64 init_module()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x3

  v0 = debugfs_lookup("interconnect", 0);
  qcom_icc_debug_init_dir = v0;
  if ( v0 && v0 < 0xFFFFFFFFFFFFF001LL )
    dentry_suspend = debugfs_create_file_unsafe("debug_suspend", 420, v0, 0, &icc_debug_suspend_fops);
  else
    printk(&unk_676D, "qcom_icc_debug_init", v0, v1);
  return 0;
}
