__int64 __fastcall cscfg_unload_config_sets(_QWORD *a1)
{
  __int64 v2; // x8
  unsigned int v3; // w20
  _QWORD *v5; // x9
  __int64 v6; // x8
  _QWORD *i; // x20
  _QWORD *j; // x20
  __int64 v9; // x9
  __int64 v10; // x8
  _QWORD *v11; // x8
  __int64 v12; // x9

  mutex_lock(&cscfg_mutex);
  v2 = cscfg_mgr;
  if ( *(_DWORD *)(cscfg_mgr + 1176) )
  {
    v3 = -16;
  }
  else
  {
    *(_DWORD *)(cscfg_mgr + 1176) = 2;
    if ( *(_DWORD *)(v2 + 976) )
    {
      v3 = -16;
    }
    else if ( *(_QWORD *)(v2 + 960) == v2 + 960 )
    {
      v3 = -22;
    }
    else
    {
      v5 = *(_QWORD **)(v2 + 968);
      v3 = -22;
      if ( v5 == a1 && v5 )
      {
        mutex_unlock(&cscfg_mutex);
        v6 = cscfg_mgr;
        for ( i = *(_QWORD **)(cscfg_mgr + 944); i != (_QWORD *)(v6 + 944); i = (_QWORD *)*i )
        {
          if ( (_QWORD *)i[8] == a1 )
          {
            cscfg_configfs_del_config((__int64)(i - 2));
            v6 = cscfg_mgr;
          }
        }
        for ( j = *(_QWORD **)(v6 + 928); j != (_QWORD *)(v6 + 928); j = (_QWORD *)*j )
        {
          if ( (_QWORD *)j[6] == a1 )
          {
            cscfg_configfs_del_feature((__int64)(j - 2));
            v6 = cscfg_mgr;
          }
        }
        mutex_lock(&cscfg_mutex);
        cscfg_unload_owned_cfgs_feats((__int64)a1);
        v9 = *(_QWORD *)(cscfg_mgr + 960);
        if ( v9 == cscfg_mgr + 960 || v9 != *(_QWORD *)(cscfg_mgr + 968) )
        {
          v10 = a1[1];
          if ( *(_DWORD *)(v10 + 16) == 1 )
            module_put(*(_QWORD *)(v10 + 24));
        }
        v11 = (_QWORD *)a1[1];
        if ( (_QWORD *)*v11 == a1 && (v12 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
        {
          *(_QWORD *)(v12 + 8) = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(a1);
        }
        v3 = 0;
        *a1 = 0xDEAD000000000100LL;
        a1[1] = 0xDEAD000000000122LL;
        v2 = cscfg_mgr;
      }
    }
    *(_DWORD *)(v2 + 1176) = 0;
  }
  mutex_unlock(&cscfg_mutex);
  return v3;
}
