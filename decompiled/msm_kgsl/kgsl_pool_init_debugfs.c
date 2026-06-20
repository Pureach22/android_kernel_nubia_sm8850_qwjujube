unsigned __int64 __fastcall kgsl_pool_init_debugfs(__int64 a1, const char *a2, __int64 a3)
{
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x21
  unsigned __int64 file; // x0

  result = debugfs_create_dir(a2, mempools_debugfs);
  v6 = result;
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    file = debugfs_create_file("reserved", 292, result, a3, &reserved_fops);
    if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
    {
      _warn_printk("Unable to create 'reserved' file for %s\n", a2);
      __break(0x800u);
    }
    result = debugfs_create_file("count", 292, v6, a3, &page_count_fops);
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = _warn_printk("Unable to create 'count' file for %s\n", a2);
      __break(0x800u);
    }
  }
  else if ( !result )
  {
    result = _warn_printk("Unable to create debugfs dir for %s\n", a2);
    __break(0x800u);
  }
  return result;
}
