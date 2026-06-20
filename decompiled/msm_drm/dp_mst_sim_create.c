__int64 __fastcall dp_mst_sim_create(_QWORD *a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD *v5; // x0
  _QWORD *v6; // x20
  __int64 v7; // x11
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x12
  unsigned __int64 v11; // x0
  __int64 ipc_log_context; // x0

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = (_QWORD *)_kmalloc_cache_noprof(kthread_should_park, 3520, 1840);
    v6 = v5;
    if ( v5 )
    {
      v7 = a1[1];
      v8 = a1[3];
      v9 = a1[4];
      v10 = a1[2];
      *v5 = *a1;
      v5[1] = v8;
      v5[2] = v9;
      *(_QWORD *)((char *)v5 + 796) = v7;
      *(_QWORD *)((char *)v5 + 804) = v10;
      _mutex_init(v5 + 86, "&ctx->session_lock", &dp_mst_sim_create___key);
      *((_DWORD *)v6 + 184) = 0;
      _init_swait_queue_head(v6 + 93, "&x->wait", &init_completion___key_4);
      v11 = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
      v6[96] = v11;
      if ( v11 && v11 < 0xFFFFFFFFFFFFF001LL )
      {
        *a2 = v6;
        return 0;
      }
      else
      {
        ipc_log_context = get_ipc_log_context(v11);
        ipc_log_string(ipc_log_context, "[e][%-4d]Error creating wq\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_259CE9, "dp_mst_sim_create");
        kfree(v6);
        return 0xFFFFFFFFLL;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
