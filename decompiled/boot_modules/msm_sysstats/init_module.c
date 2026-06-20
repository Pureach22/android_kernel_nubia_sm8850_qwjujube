__int64 init_module()
{
  unsigned int v0; // w19

  v0 = genl_register_family(&family);
  if ( !v0 )
  {
    sysstats_kgsl_get_stats = sysstats_kgsl_stats;
    printk(&unk_791E, 2);
  }
  return v0;
}
