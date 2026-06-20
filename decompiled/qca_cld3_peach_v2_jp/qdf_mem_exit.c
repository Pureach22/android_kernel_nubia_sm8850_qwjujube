__int64 qdf_mem_exit()
{
  __int64 result; // x0

  result = debugfs_remove(qdf_mem_debugfs_root);
  qdf_mem_debugfs_root = 0;
  return result;
}
