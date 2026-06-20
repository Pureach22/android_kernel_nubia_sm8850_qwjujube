__int64 rmnet_perf_tether_state_free()
{
  __int64 v0; // x0
  _QWORD *v1; // x0
  _QWORD *v2; // x8
  _QWORD *v3; // x21
  _QWORD *v4; // x9
  __int64 i; // x19
  __int64 v6; // x8
  __int64 v7; // x0
  _QWORD *v8; // x9
  __int64 v9; // x21
  __int64 result; // x0

  v0 = rmnet_module_hook_unregister_no_sync(&rmnet_perf_tether_module_hooks, 3);
  synchronize_rcu(v0);
  v1 = rmnet_perf_tether_free_list;
  if ( rmnet_perf_tether_free_list != (_UNKNOWN *)&rmnet_perf_tether_free_list )
  {
    do
    {
      v3 = (_QWORD *)*v1;
      v2 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v2 == v1 && (_QWORD *)v3[1] == v1 )
      {
        v3[1] = v2;
        *v2 = v3;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
        v1 = v4;
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      ((void (*)(void))kfree)();
      v1 = v3;
    }
    while ( v3 != &rmnet_perf_tether_free_list );
  }
  for ( i = 0; i != 32; ++i )
  {
    v6 = rmnet_perf_tether_flow_table[i];
    if ( v6 )
    {
      v7 = v6 - 16;
      if ( v6 != 16 )
      {
        do
        {
          v9 = *(_QWORD *)(v7 + 16);
          v8 = *(_QWORD **)(v7 + 24);
          if ( v8 )
          {
            *v8 = v9;
            if ( v9 )
              *(_QWORD *)(v9 + 8) = v8;
            *(_QWORD *)(v7 + 16) = 0;
            *(_QWORD *)(v7 + 24) = 0;
          }
          ((void (*)(void))kfree)();
          if ( !v9 )
            break;
          v7 = v9 - 16;
        }
        while ( v9 != 16 );
      }
    }
  }
  result = kfree(rmnet_perf_tether);
  rmnet_perf_tether = 0;
  return result;
}
