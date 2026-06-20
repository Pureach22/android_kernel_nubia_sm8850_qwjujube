__int64 __fastcall rmnet_wlan_connection_work_process(__int64 a1)
{
  __int64 v2; // x0
  char v3; // w22
  __int64 v4; // x19
  __int64 v5; // x23
  __int64 i; // x21
  __int64 *v7; // x27
  __int64 *v8; // x1
  char v9; // w8
  _QWORD *v10; // x8

  v2 = raw_spin_lock_irqsave(&rmnet_wlan_connection_lock);
  v3 = *(_BYTE *)(a1 + 104);
  v4 = v2;
  v5 = jiffies;
  for ( i = 0; i != 16; ++i )
  {
    v7 = (__int64 *)rmnet_wlan_connection_hash[i];
    while ( v7 )
    {
      v8 = v7;
      v9 = *((_BYTE *)v7 + 88);
      v7 = (__int64 *)*v7;
      if ( (v9 & 1) == 0 && ((v3 & 1) != 0 || (unsigned __int64)(v5 - v8[10]) >= 0x1F5) )
      {
        v10 = (_QWORD *)v8[1];
        *((_BYTE *)v8 + 88) = 1;
        if ( v10 )
        {
          *v10 = v7;
          if ( v7 )
            v7[1] = (__int64)v10;
          v8[1] = 0;
        }
        kvfree_call_rcu(v8 + 2);
        --rmnet_wlan_connection_hash_size;
      }
    }
  }
  if ( rmnet_wlan_connection_hash_size )
    queue_delayed_work_on(32, system_wq, a1, 125);
  return raw_spin_unlock_irqrestore(&rmnet_wlan_connection_lock, v4);
}
