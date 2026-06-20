__int64 __fastcall rmnet_perf_quickack_work_process(__int64 a1)
{
  char v2; // w23
  __int64 v3; // x25
  __int64 i; // x22
  __int64 *v5; // x19
  __int64 *v6; // x8
  int v7; // w9
  _QWORD *v8; // x9
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = raw_spin_lock_irqsave(&rmnet_perf_quickack_lock);
  v2 = *(_BYTE *)(a1 + 104);
  v3 = jiffies;
  for ( i = 0; i != 16; ++i )
  {
    v5 = (__int64 *)rmnet_perf_quickack_hash[i];
    while ( v5 )
    {
      v6 = v5;
      v7 = *((unsigned __int8 *)v5 + 101);
      v5 = (__int64 *)*v5;
      if ( !v7 && ((v2 & 1) != 0 || (unsigned __int64)(v3 - v6[9]) >= 0x1F5) )
      {
        v8 = (_QWORD *)v6[1];
        *((_BYTE *)v6 + 101) = 1;
        if ( v8 )
        {
          *v8 = v5;
          if ( v5 )
            v5[1] = (__int64)v8;
          v6[1] = 0;
        }
        call_rcu(v6 + 2, rmnet_perf_quickack_node_free);
        ++qword_EA10;
        --rmnet_perf_quickack_hash_size;
      }
    }
  }
  if ( rmnet_perf_quickack_hash_size )
    queue_delayed_work_on(32, system_wq, a1, 125);
  return raw_spin_unlock_irqrestore(&rmnet_perf_quickack_lock, v10);
}
