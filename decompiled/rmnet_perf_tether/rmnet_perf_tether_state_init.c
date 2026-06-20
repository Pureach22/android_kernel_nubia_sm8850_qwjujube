__int64 rmnet_perf_tether_state_init()
{
  _BYTE *v0; // x0
  __int64 v1; // x2
  int v2; // w20
  char v3; // w8
  __int64 v5; // x0
  __int64 *v6; // x1

  v0 = (_BYTE *)_kmalloc_cache_noprof(param_ops_charp, 3520, 1);
  rmnet_perf_tether = (__int64)v0;
  if ( v0 )
  {
    v2 = 50;
    v3 = *v0 + 1;
    _ReadStatusReg(SP_EL0);
    *v0 = v3;
    do
    {
      v5 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
      if ( v5 )
      {
        *(_QWORD *)v5 = v5;
        *(_QWORD *)(v5 + 8) = v5;
        v6 = (__int64 *)off_40;
        *(_QWORD *)(v5 + 16) = 0;
        *(_QWORD *)(v5 + 24) = 0;
        if ( (_UNKNOWN **)v5 == &rmnet_perf_tether_free_list
          || v6 == (__int64 *)v5
          || (_UNKNOWN **)*v6 != &rmnet_perf_tether_free_list )
        {
          _list_add_valid_or_report();
        }
        else
        {
          off_40 = (_UNKNOWN *)v5;
          *(_QWORD *)v5 = &rmnet_perf_tether_free_list;
          *(_QWORD *)(v5 + 8) = v6;
          *v6 = v5;
        }
      }
      --v2;
    }
    while ( v2 );
    rmnet_module_hook_register(&rmnet_perf_tether_module_hooks, 3);
    return 0;
  }
  else
  {
    printk(&unk_736B, "rmnet_perf_tether_state_init", v1);
    return 0xFFFFFFFFLL;
  }
}
