__int64 cam_debugfs_deinit()
{
  __int64 result; // x0

  result = debugfs_remove(cam_debugfs_root);
  cam_debugfs_root = 0;
  return result;
}
