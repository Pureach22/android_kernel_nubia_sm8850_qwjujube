__int64 __fastcall cscfg_register_csdev(__int64 a1, int a2, __int64 *a3)
{
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  _QWORD *v9; // x2
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  __int64 *i; // x23
  int feat_csdev; // w0
  _QWORD *v14; // x20
  _QWORD *v15; // x8
  __int64 v16; // x11
  _QWORD *v17; // x9
  _QWORD *v18; // x10
  __int64 v19; // x11
  _QWORD *v20; // x10
  unsigned int v21; // w19
  _QWORD *v22; // x0
  __int64 v23; // x1
  _QWORD *v24; // x10

  mutex_lock(&cscfg_mutex);
  v6 = _kmalloc_cache_noprof(module_put, 3520, 40);
  if ( v6 )
  {
    v7 = *a3;
    *(_QWORD *)v6 = a1;
    v8 = cscfg_mgr;
    *(_DWORD *)(v6 + 8) = a2;
    *(_QWORD *)(v6 + 16) = v7;
    v9 = *(_QWORD **)(v8 + 912);
    v10 = (_QWORD *)(v8 + 912);
    v11 = (_QWORD *)(v6 + 24);
    if ( v9[1] != v8 + 912 || v11 == v10 || v9 == v11 )
    {
      _list_add_valid_or_report(v6 + 24, v10);
      v8 = cscfg_mgr;
    }
    else
    {
      v9[1] = v11;
      *(_QWORD *)(v6 + 24) = v9;
      *(_QWORD *)(v6 + 32) = v10;
      *v10 = v11;
    }
    *(_QWORD *)(a1 + 1008) = a1 + 1008;
    *(_QWORD *)(a1 + 1016) = a1 + 1008;
    *(_QWORD *)(a1 + 1024) = a1 + 1024;
    *(_QWORD *)(a1 + 1032) = a1 + 1024;
    *(_DWORD *)(a1 + 1040) = 0;
    if ( *a3 )
    {
      for ( i = *(__int64 **)(v8 + 928); i != (__int64 *)(v8 + 928); i = (__int64 *)*i )
      {
        if ( ((_DWORD)i[2] & a2) != 0 )
        {
          feat_csdev = cscfg_load_feat_csdev(a1, i - 2, a3);
          v8 = cscfg_mgr;
          if ( feat_csdev )
            goto LABEL_21;
        }
      }
      v14 = (_QWORD *)(v8 + 944);
      do
      {
        v14 = (_QWORD *)*v14;
        if ( v14 == (_QWORD *)(cscfg_mgr + 944) )
        {
          v23 = *(_QWORD *)(a1 + 168);
          if ( !v23 )
            v23 = *(_QWORD *)(a1 + 56);
          printk(&unk_1257A, v23);
          v21 = 0;
          goto LABEL_35;
        }
        feat_csdev = cscfg_add_csdev_cfg(a1, v14 - 2);
      }
      while ( !feat_csdev );
      v15 = *(_QWORD **)(cscfg_mgr + 912);
      while ( v15 != (_QWORD *)(cscfg_mgr + 912) )
      {
        v16 = *(v15 - 3);
        v17 = v15;
        v15 = (_QWORD *)*v15;
        if ( v16 == a1 )
        {
LABEL_24:
          v20 = (_QWORD *)v17[1];
          v21 = feat_csdev;
          v22 = v17 - 3;
          if ( (_QWORD *)*v20 == v17 && (_QWORD *)v15[1] == v17 )
          {
            v15[1] = v20;
            *v20 = v15;
          }
          else
          {
            _list_del_entry_valid_or_report(v17);
            v22 = v24;
          }
          *v17 = 0xDEAD000000000100LL;
          v17[1] = 0xDEAD000000000122LL;
          kfree(v22);
          goto LABEL_35;
        }
      }
    }
    else
    {
      feat_csdev = -22;
LABEL_21:
      v15 = *(_QWORD **)(v8 + 912);
      v18 = (_QWORD *)(v8 + 912);
      while ( v15 != v18 )
      {
        v19 = *(v15 - 3);
        v17 = v15;
        v15 = (_QWORD *)*v15;
        if ( v19 == a1 )
          goto LABEL_24;
      }
    }
    v21 = feat_csdev;
  }
  else
  {
    v21 = -12;
  }
LABEL_35:
  mutex_unlock(&cscfg_mutex);
  return v21;
}
