__int64 __fastcall mem_buf_relinquish_work(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x19
  int v4; // w22
  _DWORD *v5; // x8
  int v6; // w11
  _QWORD *v7; // x9
  _QWORD *v8; // x10
  __int64 v9; // x23
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x21

  v1 = *(_QWORD *)(a1 - 16);
  v3 = (_QWORD *)(a1 - 24);
  v4 = *(_DWORD *)(v1 + 16);
  mutex_lock(&mem_buf_xfer_mem_list_lock);
  v5 = mem_buf_xfer_mem_list;
  do
  {
    if ( v5 == (_DWORD *)&mem_buf_xfer_mem_list )
    {
      mutex_unlock(&mem_buf_xfer_mem_list_lock);
      goto LABEL_13;
    }
    v6 = v5[10];
    v7 = v5;
    v5 = *(_DWORD **)v5;
  }
  while ( v6 != v4 );
  v8 = (_QWORD *)v7[1];
  v9 = (__int64)(v7 - 6);
  if ( (_QWORD *)*v8 == v7 && *((_QWORD **)v5 + 1) == v7 )
  {
    *((_QWORD *)v5 + 1) = v8;
    *v8 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v7);
  }
  *v7 = 0xDEAD000000000100LL;
  v7[1] = 0xDEAD000000000122LL;
  mutex_unlock(&mem_buf_xfer_mem_list_lock);
  if ( v9 )
  {
    mem_buf_cleanup_alloc_req(v9, *(_DWORD *)(v1 + 12));
    goto LABEL_9;
  }
LABEL_13:
  printk(&unk_97CC, "mem_buf_relinquish_work");
LABEL_9:
  v10 = mem_buf_construct_relinquish_resp(v1);
  if ( v10 <= 0xFFFFFFFFFFFFF000LL )
  {
    v11 = v10;
    mem_buf_msgq_send(*v3, v10);
    kfree(v11);
  }
  kfree(*(_QWORD *)(a1 - 16));
  return kfree(v3);
}
