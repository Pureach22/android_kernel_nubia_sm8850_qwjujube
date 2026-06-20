__int64 init_module()
{
  _UNKNOWN **i; // x19

  mutex_lock(&gdsc_genpd_debug_lock);
  genpd_rootdir = debugfs_lookup("pm_genpd", 0);
  if ( genpd_rootdir )
  {
    for ( i = (_UNKNOWN **)gdsc_genpd_debug_list; i != &gdsc_genpd_debug_list; i = (_UNKNOWN **)*i )
      gdsc_genpd_debug_create_one((__int64)i, genpd_rootdir);
  }
  else
  {
    printk(&unk_28235);
  }
  mutex_unlock(&gdsc_genpd_debug_lock);
  return 0;
}
