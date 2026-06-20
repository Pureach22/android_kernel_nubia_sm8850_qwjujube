__int64 __fastcall hdd_debugfs_ini_config_init(__int64 a1)
{
  __int64 root; // x0

  root = qdf_debugfs_get_root();
  if ( debugfs_create_file("ini_config", 292, root, a1, &fops_config_debugfs) )
    return 0;
  else
    return 4294967274LL;
}
