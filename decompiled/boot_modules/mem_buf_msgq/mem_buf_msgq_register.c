__int64 __fastcall mem_buf_msgq_register(const char *a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x24
  __int64 v6; // x20
  char **v8; // x8
  unsigned int v9; // w23
  _UNKNOWN **v10; // x22
  __int64 v11; // x9
  unsigned __int64 v12; // x0
  __int64 v13; // x2
  _QWORD *v14; // x1
  unsigned __int64 v15; // x0
  __int64 v16; // x2
  unsigned __int64 v17; // x19
  unsigned __int64 v18; // x19

  v4 = _kmalloc_cache_noprof(kfree, 3520, 120);
  if ( !v4 )
    return -12;
  if ( !a2 )
    return -22;
  v5 = *(_QWORD **)a2;
  if ( !*(_QWORD *)a2 || !*v5 || !v5[1] || !v5[2] )
    return -22;
  v6 = v4;
  if ( !strcmp(a1, "trusted_vm") )
  {
    v8 = &mem_buf_msgqs;
  }
  else if ( !strcmp(a1, "oem_vm") )
  {
    v8 = &off_72C8;
  }
  else
  {
    if ( strcmp(a1, nullptr) )
      return -22;
    v8 = (char **)&unk_72D8;
  }
  v9 = *((_DWORD *)v8 + 2);
  if ( (v9 & 0x80000000) != 0 )
    return (int)v9;
  v10 = (_UNKNOWN **)(v6 + 104);
  *(_QWORD *)(v6 + 104) = v6 + 104;
  *(_QWORD *)(v6 + 112) = v6 + 104;
  v11 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)v6 = v5;
  *(_QWORD *)(v6 + 8) = v11;
  _mutex_init(v6 + 16, "&desc->idr_mutex", &mem_buf_msgq_register___key);
  *(_QWORD *)(v6 + 64) = 0x1000000400000000LL;
  *(_QWORD *)(v6 + 72) = 0;
  *(_QWORD *)(v6 + 80) = 0;
  v12 = gh_msgq_register(v9);
  *(_QWORD *)(v6 + 88) = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v18 = v12;
    printk(&unk_6F8E, v12, v13);
  }
  else
  {
    mutex_lock(&mem_buf_msgq_list_lock);
    v14 = off_188;
    if ( off_188 == v10 || *off_188 != (_UNKNOWN *)&mem_buf_msgq_list )
    {
      _list_add_valid_or_report(v6 + 104);
    }
    else
    {
      off_188 = (_UNKNOWN **)(v6 + 104);
      *(_QWORD *)(v6 + 104) = &mem_buf_msgq_list;
      *(_QWORD *)(v6 + 112) = v14;
      *v14 = v10;
    }
    mutex_unlock(&mem_buf_msgq_list_lock);
    v15 = kthread_create_on_node(mem_buf_msgq_recv_fn, v6, 0xFFFFFFFFLL, "mem_buf_%s_rcvr", a1);
    if ( v15 <= 0xFFFFFFFFFFFFF000LL )
    {
      v17 = v15;
      wake_up_process();
      *(_QWORD *)(v6 + 96) = v17;
      return v6;
    }
    *(_QWORD *)(v6 + 96) = v15;
    v18 = v15;
    printk(&unk_71BB, v15, v16);
    gh_msgq_unregister(*(_QWORD *)(v6 + 88));
  }
  idr_destroy(v6 + 64);
  kfree(v6);
  return v18;
}
