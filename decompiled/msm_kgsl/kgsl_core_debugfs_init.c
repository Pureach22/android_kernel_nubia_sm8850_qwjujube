unsigned __int64 kgsl_core_debugfs_init()
{
  unsigned __int64 result; // x0
  __int64 dir; // x19

  result = debugfs_create_dir("kgsl", 0);
  kgsl_debugfs_dir = result;
  if ( result )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      dir = debugfs_create_dir("debug", result);
      proc_d_debugfs = debugfs_create_dir("proc", kgsl_debugfs_dir);
      debugfs_create_bool("strict_memory", 420, dir, &kgsl_sharedmem_noretry_flag);
      result = debugfs_create_dir("mempools", kgsl_debugfs_dir);
      mempools_debugfs = result;
      if ( result )
      {
        if ( result <= 0xFFFFFFFFFFFFF000LL )
        {
          result = debugfs_create_file("pool_size", 292, result, 0, &pool_size_fops);
          if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
          {
            result = _warn_printk("Unable to create 'pool_size' file for mempools\n");
            __break(0x800u);
          }
        }
      }
    }
  }
  return result;
}
