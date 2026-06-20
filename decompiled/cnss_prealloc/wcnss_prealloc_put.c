__int64 __fastcall wcnss_prealloc_put(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  int v4; // w24
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x25

  result = 0;
  if ( !a1 )
    return result;
  if ( !cnss_pools )
    return result;
  result = 0;
  if ( mempool_initialization_done != 1 || !cnss_prealloc_pool_size )
    return result;
  v3 = 0;
  while ( 1 )
  {
    v4 = v3;
    v5 = cnss_pools + 96LL * v3;
    if ( *(_QWORD *)(v5 + 64) )
      break;
LABEL_7:
    v3 = v4 + 1;
    if ( v4 + 1 >= (unsigned int)cnss_prealloc_pool_size )
      return 0;
  }
  if ( *(_QWORD *)(v5 + 80) )
  {
    v6 = raw_spin_lock_irqsave(&pool_table_lock);
    v7 = cnss_pools + 96LL * v4;
    v8 = *(int *)(v7 + 88);
    if ( (_DWORD)v8 )
    {
      v9 = *(_QWORD *)(v7 + 80);
      v10 = 0;
      while ( *(_QWORD *)(v9 + 8 * v10) != a1 )
      {
        if ( v8 == ++v10 )
          goto LABEL_6;
      }
      *(_QWORD *)(v9 + 8 * v10) = 0;
      raw_spin_unlock_irqrestore(&pool_table_lock, v6);
      if ( (v10 & 0x80000000) == 0 )
      {
        mempool_free(a1, *(_QWORD *)(cnss_pools + 96LL * v4 + 64));
        return 1;
      }
    }
    else
    {
LABEL_6:
      raw_spin_unlock_irqrestore(&pool_table_lock, v6);
    }
    goto LABEL_7;
  }
  printk(&unk_6C6F, v5 + 12);
  return 0;
}
