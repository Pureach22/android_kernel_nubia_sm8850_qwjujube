__int64 __fastcall sde_rm_debugfs_init(__int64 a1, __int64 a2)
{
  return debugfs_create_file("rm_status", 256, a2, a1, &sde_rm_debugfs_init_debugfs_rm_status_fops);
}
