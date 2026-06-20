__int64 qdf_debugfs_init()
{
  __int64 dir; // x8

  dir = debugfs_create_dir("qca_cld3_peach_v2", 0);
  qdf_debugfs_root = dir;
  return 16 * (unsigned int)(dir == 0);
}
