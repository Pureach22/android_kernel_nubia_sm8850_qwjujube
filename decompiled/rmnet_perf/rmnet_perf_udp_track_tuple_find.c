unsigned __int64 *__fastcall rmnet_perf_udp_track_tuple_find(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 *i; // x20
  unsigned __int64 *v4; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x8
  unsigned __int64 *v8; // x10
  unsigned __int64 v9; // x8
  int v10; // w8
  int v12; // w8

  v2 = raw_spin_lock_irqsave(&rmnet_perf_udp_track_lock);
  for ( i = (unsigned __int64 *)rmnet_perf_udp_track_hash[(unsigned int)(1640531527 * *(_DWORD *)(a1 + 32)) >> 28];
        i;
        i = (unsigned __int64 *)*i )
  {
    if ( !*((_BYTE *)i + 88) )
    {
      v12 = *((unsigned __int8 *)i + 68);
      if ( v12 == *(unsigned __int8 *)(a1 + 36)
        && *((unsigned __int16 *)i + 32) == *(unsigned __int16 *)(a1 + 32)
        && *((unsigned __int16 *)i + 33) == *(unsigned __int16 *)(a1 + 34) )
      {
        if ( v12 == 4 )
        {
          if ( *((_DWORD *)i + 8) == *(_DWORD *)a1 && *((_DWORD *)i + 12) == *(_DWORD *)(a1 + 16) )
            goto LABEL_28;
        }
        else if ( i[4] == *(_QWORD *)a1
               && i[5] == *(_QWORD *)(a1 + 8)
               && i[6] == *(_QWORD *)(a1 + 16)
               && i[7] == *(_QWORD *)(a1 + 24) )
        {
          goto LABEL_28;
        }
      }
    }
  }
  v4 = (unsigned __int64 *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 96);
  i = v4;
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 16);
    v6 = *(_QWORD *)(a1 + 24);
    v4[8] = *(_QWORD *)(a1 + 32);
    v4[6] = v5;
    v4[7] = v6;
    v7 = *(_QWORD *)(a1 + 8);
    v4[4] = *(_QWORD *)a1;
    v4[5] = v7;
    LODWORD(v7) = 1640531527 * *(_DWORD *)(a1 + 32);
    v4[10] = jiffies;
    v8 = &rmnet_perf_udp_track_hash[(unsigned int)v7 >> 28];
    v9 = *v8;
    *v4 = *v8;
    v4[1] = 0;
    v4[1] = (unsigned __int64)v8;
    atomic_store((unsigned __int64)v4, v8);
    if ( v9 )
      *(_QWORD *)(v9 + 8) = v4;
    v10 = rmnet_perf_udp_track_hash_size;
    ++rmnet_perf_udp_track_stats;
    if ( !rmnet_perf_udp_track_hash_size )
    {
      queue_delayed_work_on(32, system_wq, &rmnet_perf_udp_work, 125);
      v10 = rmnet_perf_udp_track_hash_size;
    }
    rmnet_perf_udp_track_hash_size = v10 + 1;
  }
  else
  {
    ++qword_EAB0;
  }
LABEL_28:
  raw_spin_unlock_irqrestore(&rmnet_perf_udp_track_lock, v2);
  return i;
}
