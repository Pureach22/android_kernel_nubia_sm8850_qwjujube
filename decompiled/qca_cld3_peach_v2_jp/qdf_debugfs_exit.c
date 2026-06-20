__int64 qdf_debugfs_exit()
{
  __int64 result; // x0

  result = qdf_debugfs_root;
  if ( qdf_debugfs_root )
  {
    result = debugfs_remove(qdf_debugfs_root);
    qdf_debugfs_root = 0;
  }
  return result;
}
