__int64 __fastcall cma_best_fit_setup(__int64 a1)
{
  __int64 node_opts_by_path; // x0
  __int64 v3; // x20
  __int64 result; // x0
  const char **v5; // x21

  node_opts_by_path = of_find_node_opts_by_path("/reserved-memory", 0);
  if ( node_opts_by_path )
  {
    v3 = node_opts_by_path;
    result = of_get_next_child(node_opts_by_path, 0);
    if ( result )
    {
      v5 = (const char **)result;
      do
      {
        if ( !strcmp(*v5, (const char *)(a1 + 64)) )
        {
          raw_spin_lock_irq(a1 + 28);
          *(_QWORD *)(a1 + 176) = of_get_property(v5, "cma-best-fit", 0) != 0;
          raw_spin_unlock_irq(a1 + 28);
        }
        result = of_get_next_child(v3, v5);
        v5 = (const char **)result;
      }
      while ( result );
    }
  }
  else
  {
    printk(&unk_7665);
    return 4294967277LL;
  }
  return result;
}
