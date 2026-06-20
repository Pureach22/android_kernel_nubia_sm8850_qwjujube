__int64 __fastcall qlpmm_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  int v4; // w0
  __int64 dir; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x2
  __int64 *v12; // x1
  __int64 v13; // x8
  __int64 *v14; // x9
  unsigned __int64 v15; // x10
  __int64 **v16; // x8
  __int64 *v17; // x11
  unsigned int v18; // w20

  v2 = devm_kmalloc(a1 + 16, 416, 3520);
  qlpmm_pd = v2;
  if ( !v2 )
    return 4294967284LL;
  result = qmi_handle_init(v2 + 48, 2509, &server_ops, &handlers);
  if ( (_DWORD)result )
    return result;
  v4 = qmi_add_server(qlpmm_pd + 48, 1104, 1, 0);
  if ( v4 )
  {
    v18 = v4;
    dev_err(a1 + 16, "qlpmm: error adding qmi server %d\n", v4);
    qmi_handle_release(qlpmm_pd + 48);
    return v18;
  }
  dir = debugfs_create_dir("qcom_lpmm", 0);
  *(_QWORD *)(qlpmm_pd + 8) = dir;
  debugfs_create_file("adsp_clks", 256, dir, 0, &qlpmm_get_adsp_clks_stats_fops);
  v6 = qlpmm_pd;
  v7 = qlpmm_pd + 24;
  *(_DWORD *)qlpmm_pd = 0;
  *(_DWORD *)(v6 + 16) = 0;
  _init_swait_queue_head(v7, "&x->wait", &init_completion___key);
  _mutex_init(qlpmm_pd + 352, "&qlpmm_pd->lock", &qlpmm_probe___key);
  v8 = qlpmm_pd;
  *(_QWORD *)(qlpmm_pd + 400) = qlpmm_pd + 400;
  *(_QWORD *)(v8 + 408) = v8 + 400;
  v9 = devm_kmalloc(a1 + 16, 2976, 3520);
  if ( !v9 )
  {
    debugfs_remove(*(_QWORD *)(qlpmm_pd + 8));
    v13 = qlpmm_pd;
    v14 = *(__int64 **)(qlpmm_pd + 400);
    if ( v14 != (__int64 *)(qlpmm_pd + 400) )
    {
      v15 = 0xDEAD000000000100LL;
      do
      {
        v17 = (__int64 *)*v14;
        v16 = (__int64 **)v14[1];
        *((_BYTE *)v14 + 28) = 0;
        if ( *v16 == v14 && (__int64 *)v17[1] == v14 )
        {
          v17[1] = (__int64)v16;
          *v16 = v17;
        }
        else
        {
          _list_del_entry_valid_or_report(v14);
        }
        *v14 = v15;
        v14[1] = v15 + 34;
        v14 = v17;
        v13 = qlpmm_pd;
      }
      while ( v17 != (__int64 *)(qlpmm_pd + 400) );
    }
    qmi_handle_release(v13 + 48);
    return 4294967284LL;
  }
  v10 = qlpmm_pd;
  *(_WORD *)(v9 + 28) = 0;
  *(_DWORD *)(v9 + 36) = 0;
  v11 = v10 + 400;
  v12 = *(__int64 **)(v10 + 408);
  if ( v9 == v10 + 400 || v12 == (__int64 *)v9 || *v12 != v11 )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)(v10 + 408) = v9;
    *(_QWORD *)v9 = v11;
    *(_QWORD *)(v9 + 8) = v12;
    *v12 = v9;
  }
  return 0;
}
