__int64 qdf_mem_init()
{
  __int64 result; // x0

  result = qdf_debugfs_get_root();
  if ( result )
  {
    result = debugfs_create_dir("mem", result);
    qdf_mem_debugfs_root = result;
    if ( result )
    {
      debugfs_create_atomic_t("kmalloc", 256, result, &qdf_mem_stat);
      debugfs_create_atomic_t("dma", 256, qdf_mem_debugfs_root, &dword_716984);
      return debugfs_create_atomic_t("skb", 256, qdf_mem_debugfs_root, &dword_716988);
    }
  }
  return result;
}
