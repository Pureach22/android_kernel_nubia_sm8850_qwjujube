__int64 __fastcall mem_buf_init_txn(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  unsigned int v5; // w22

  v4 = _kmalloc_cache_noprof(printk, 3520, 48);
  if ( !v4 )
    return -12;
  mutex_lock(a1 + 16);
  v5 = idr_alloc_cyclic(a1 + 64, v4, 0, 0x7FFFFFFF, 3264);
  if ( (v5 & 0x80000000) != 0 )
  {
    printk(&unk_7254, "mem_buf_init_txn", v5);
    mutex_unlock(a1 + 16);
    kfree(v4);
    return (int)v5;
  }
  else
  {
    *(_DWORD *)v4 = v5;
    *(_DWORD *)(v4 + 8) = 0;
    _init_swait_queue_head(v4 + 16, "&x->wait", &init_completion___key);
    *(_QWORD *)(v4 + 40) = a2;
    mutex_unlock(a1 + 16);
  }
  return v4;
}
