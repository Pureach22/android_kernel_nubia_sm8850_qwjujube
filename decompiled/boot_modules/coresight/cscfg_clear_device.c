__int64 cscfg_clear_device()
{
  __int64 v0; // x1
  __int64 i; // x8
  __int64 v2; // x22
  int v3; // w8
  __int64 v4; // x8
  _QWORD *j; // x25
  _QWORD *k; // x25
  _QWORD *v7; // x8
  __int64 v8; // x9

  mutex_lock(&cscfg_mutex);
  for ( i = cscfg_mgr; *(_QWORD *)(cscfg_mgr + 960) != cscfg_mgr + 960; i = cscfg_mgr )
  {
    v2 = *(_QWORD *)(i + 968);
    v3 = *(_DWORD *)(v2 + 16);
    if ( v3 == 1 )
    {
      printk(&unk_1280E, v0);
    }
    else
    {
      if ( !v3 )
        printk(&unk_128E9, v0);
      mutex_unlock(&cscfg_mutex);
      v4 = cscfg_mgr;
      for ( j = *(_QWORD **)(cscfg_mgr + 944); j != (_QWORD *)(v4 + 944); j = (_QWORD *)*j )
      {
        if ( j[8] == v2 )
        {
          cscfg_configfs_del_config((__int64)(j - 2));
          v4 = cscfg_mgr;
        }
      }
      for ( k = *(_QWORD **)(v4 + 928); k != (_QWORD *)(v4 + 928); k = (_QWORD *)*k )
      {
        if ( k[6] == v2 )
        {
          cscfg_configfs_del_feature((__int64)(k - 2));
          v4 = cscfg_mgr;
        }
      }
      mutex_lock(&cscfg_mutex);
      cscfg_unload_owned_cfgs_feats(v2);
    }
    v7 = *(_QWORD **)(v2 + 8);
    if ( *v7 == v2 && (v8 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
    {
      *(_QWORD *)(v8 + 8) = v7;
      *v7 = v8;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *(_QWORD *)v2 = 0xDEAD000000000100LL;
    *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
  }
  mutex_unlock(&cscfg_mutex);
  cscfg_configfs_release(cscfg_mgr);
  return device_unregister(cscfg_mgr);
}
