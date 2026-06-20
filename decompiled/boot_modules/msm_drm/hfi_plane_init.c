__int64 __fastcall hfi_plane_init(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x1
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  void *v10; // x0

  if ( a2 )
  {
    v3 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    v4 = (_QWORD *)v3;
    if ( v3 )
    {
      a2[539] = hfi_plane_destroy;
      a2[557] = hfi_plane_atomic_update;
      a2[536] = hfi_plane_post_init;
      _mutex_init(v3 + 16, "&plane->hfi_lock", &hfi_plane_custom_kv_props_map);
      v6 = hfi_util_kv_helper_alloc(128, v5);
      v4[10] = v6;
      if ( v6 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_279D4F, "hfi_plane_init");
      }
      else
      {
        v7 = hfi_util_u32_prop_helper_alloc(1024);
        v4[8] = v7;
        if ( v7 >= 0xFFFFFFFFFFFFF001LL )
        {
          v10 = &unk_242684;
        }
        else
        {
          v8 = hfi_util_u32_prop_helper_alloc(1024);
          v4[9] = v8;
          if ( v8 < 0xFFFFFFFFFFFFF001LL )
          {
            *v4 = a2;
            a2[534] = v4;
            return 0;
          }
          v10 = &unk_27693C;
        }
        printk(v10, "hfi_plane_init");
        kfree(v4[8]);
      }
      kfree(v4);
    }
    else
    {
      printk(&unk_279D0D, "hfi_plane_init");
    }
    return 4294967284LL;
  }
  else
  {
    printk(&unk_25A70B, "hfi_plane_init");
    return 4294967274LL;
  }
}
