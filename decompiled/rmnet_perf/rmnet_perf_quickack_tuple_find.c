unsigned __int64 __fastcall rmnet_perf_quickack_tuple_find(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x21
  unsigned __int64 i; // x22
  unsigned __int64 v8; // x0
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 *v13; // x10
  unsigned __int64 v14; // x8
  int v15; // w8
  __int64 v16; // x8
  unsigned int v17; // w8
  int v19; // w8
  unsigned int v21; // w8
  int v22; // w8

  v6 = raw_spin_lock_irqsave(&rmnet_perf_quickack_lock);
  for ( i = rmnet_perf_quickack_hash[(unsigned int)(1640531527 * *(_DWORD *)(a1 + 32)) >> 28]; i; i = *(_QWORD *)i )
  {
    if ( !*(_BYTE *)(i + 101) )
    {
      v19 = *(unsigned __int8 *)(i + 68);
      if ( v19 == *(unsigned __int8 *)(a1 + 36)
        && *(unsigned __int16 *)(i + 64) == *(unsigned __int16 *)(a1 + 32)
        && *(unsigned __int16 *)(i + 66) == *(unsigned __int16 *)(a1 + 34) )
      {
        if ( v19 == 4 )
        {
          if ( *(_DWORD *)(i + 32) == *(_DWORD *)a1 && *(_DWORD *)(i + 48) == *(_DWORD *)(a1 + 16) )
            goto LABEL_28;
        }
        else if ( *(_QWORD *)(i + 32) == *(_QWORD *)a1
               && *(_QWORD *)(i + 40) == *(_QWORD *)(a1 + 8)
               && *(_QWORD *)(i + 48) == *(_QWORD *)(a1 + 16)
               && *(_QWORD *)(i + 56) == *(_QWORD *)(a1 + 24) )
        {
LABEL_28:
          raw_spin_unlock_irqrestore(&rmnet_perf_quickack_lock, v6);
          return i;
        }
      }
    }
  }
  if ( rmnet_perf_quickack_hash_size >= (unsigned int)rmnet_perf_quickack_hash_size_param )
  {
LABEL_31:
    raw_spin_unlock_irqrestore(&rmnet_perf_quickack_lock, v6);
    return 0;
  }
  v8 = _kmalloc_cache_noprof(_fortify_panic, 2336, 104);
  i = v8;
  if ( !v8 )
  {
    ++qword_EA08;
    goto LABEL_31;
  }
  v9 = *(_QWORD *)(a1 + 24);
  v10 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(v8 + 48) = *(_QWORD *)(a1 + 16);
  *(_QWORD *)(v8 + 56) = v9;
  v11 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(v8 + 32) = *(_QWORD *)a1;
  *(_QWORD *)(v8 + 40) = v11;
  *(_DWORD *)(v8 + 92) = 192000;
  v12 = jiffies;
  LODWORD(v11) = 1640531527 * *(_DWORD *)(a1 + 32);
  *(_QWORD *)(v8 + 64) = v10;
  *(_QWORD *)(v8 + 72) = v12;
  v13 = &rmnet_perf_quickack_hash[(unsigned int)v11 >> 28];
  v14 = *v13;
  *(_QWORD *)v8 = *v13;
  *(_QWORD *)(v8 + 8) = 0;
  *(_QWORD *)(v8 + 8) = v13;
  atomic_store(v8, v13);
  if ( v14 )
    *(_QWORD *)(v14 + 8) = v8;
  v15 = rmnet_perf_quickack_hash_size;
  ++rmnet_perf_quickack_stats;
  if ( !rmnet_perf_quickack_hash_size )
  {
    queue_delayed_work_on(32, system_wq, &rmnet_perf_quickack_work, 125);
    v15 = rmnet_perf_quickack_hash_size;
  }
  rmnet_perf_quickack_hash_size = v15 + 1;
  raw_spin_unlock_irqrestore(&rmnet_perf_quickack_lock, v6);
  v16 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182);
  *(_DWORD *)(i + 88) = *(_DWORD *)(a2 + 152);
  if ( (a3 & 1) != 0 )
  {
    v17 = bswap32(*(_DWORD *)(v16 + 8));
    *(_DWORD *)(i + 84) = v17;
    *(_DWORD *)(i + 80) = v17;
  }
  else
  {
    v21 = bswap32(*(_DWORD *)(v16 + 4));
    *(_DWORD *)(i + 80) = v21;
    *(_DWORD *)(i + 84) = v21 - 1;
    v22 = *(_DWORD *)(i + 92);
    *(_DWORD *)(a2 + 52) = 0;
    *(_DWORD *)(a2 + 56) = v22;
  }
  return i;
}
