__int64 __fastcall mem_buf_txn_wait(__int64 a1, int *a2)
{
  int v4; // w21
  __int64 v5; // x2
  unsigned int v6; // w21
  int v7; // w22

  v4 = wait_for_completion_timeout(a2 + 2, 875);
  mutex_lock(a1 + 16);
  if ( v4 || (try_wait_for_completion(a2 + 2) & 1) != 0 )
  {
    v6 = 0;
    v7 = 1;
  }
  else
  {
    printk(&unk_6FF9, "mem_buf_txn_wait", v5);
    v7 = 0;
    v6 = -110;
  }
  idr_remove(a1 + 64, *a2);
  mutex_unlock(a1 + 16);
  if ( v7 )
    return (unsigned int)a2[1];
  return v6;
}
