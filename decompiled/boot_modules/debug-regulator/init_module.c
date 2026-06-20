__int64 init_module()
{
  unsigned __int64 v0; // x2
  void *v1; // x0

  v0 = debugfs_lookup("regulator", 0);
  regulator_debug_init_dir = v0;
  v1 = &unk_7ED2;
  if ( !v0 || v0 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_6;
  regulator_suspend_debugfs = debugfs_create_file_unsafe("debug_suspend", 420, v0, 0, &reg_debug_suspend_enable_fops);
  dput(regulator_debug_init_dir);
  if ( (unsigned __int64)regulator_suspend_debugfs >= 0xFFFFFFFFFFFFF001LL )
  {
    v1 = &unk_808E;
LABEL_6:
    printk(v1, "regulator_debug_init");
  }
  return 0;
}
