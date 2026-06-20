__int64 __fastcall rmnet_wlan_fragment_work_process(__int64 a1)
{
  char v1; // w26
  __int64 v2; // x25
  __int64 *v3; // x20
  __int64 *v4; // x28
  char v5; // w8
  _QWORD *v6; // x8
  unsigned __int64 v7; // x22
  __int64 v8; // x23
  __int64 **v9; // x24
  bool v10; // cc
  int v11; // w27
  __int64 **v12; // x8
  __int64 *v13; // x19
  __int64 v14; // x0
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v17 = raw_spin_lock_irqsave(&rmnet_wlan_fragment_lock);
  v1 = *(_BYTE *)(a1 + 104);
  v2 = 0;
  v18 = jiffies;
  do
  {
    v3 = (__int64 *)rmnet_wlan_fragment_hash[v2];
    while ( v3 )
    {
      v4 = v3;
      v5 = *((_BYTE *)v3 + 120);
      v3 = (__int64 *)*v3;
      if ( (v5 & 1) == 0 && ((v1 & 1) != 0 || (unsigned __int64)(v18 - v4[14]) >= 0x1A) )
      {
        v6 = (_QWORD *)v4[1];
        *((_BYTE *)v4 + 120) = 1;
        if ( v6 )
        {
          *v6 = v3;
          if ( v3 )
            v3[1] = (__int64)v6;
          v4[1] = 0;
        }
        v7 = v4[13];
        v8 = raw_spin_lock_irqsave(v4 + 2);
        v9 = (__int64 **)v4[3];
        if ( v9 != (__int64 **)(v4 + 3) )
        {
          if ( v7 )
            v10 = v7 > 0xFFFFFFFFFFFFF000LL;
          else
            v10 = 1;
          v11 = v10;
          do
          {
            v13 = *v9;
            v12 = (__int64 **)v9[1];
            if ( *v12 == (__int64 *)v9 && (__int64 **)v13[1] == v9 )
            {
              v13[1] = (__int64)v12;
              *v12 = v13;
              *v9 = nullptr;
              v9[1] = nullptr;
              if ( !v11 )
                goto LABEL_26;
            }
            else
            {
              _list_del_entry_valid_or_report(v9);
              *v9 = nullptr;
              v9[1] = nullptr;
              if ( !v11 )
              {
LABEL_26:
                if ( (unsigned int)rmnet_wlan_deliver_skb(v9, v7) )
                {
                  _netif_rx(v9);
                  v14 = 7;
                }
                else
                {
                  v14 = 6;
                }
                rmnet_wlan_stats_update(v14);
                goto LABEL_22;
              }
            }
            _netif_rx(v9);
LABEL_22:
            v9 = (__int64 **)v13;
          }
          while ( v13 != v4 + 3 );
        }
        raw_spin_unlock_irqrestore(v4 + 2, v8);
        kvfree_call_rcu(v4 + 5);
        rmnet_wlan_stats_update(9);
        --rmnet_wlan_fragment_hash_size;
      }
    }
    ++v2;
  }
  while ( v2 != 16 );
  if ( rmnet_wlan_fragment_hash_size )
    queue_delayed_work_on(32, system_wq, a1, 13);
  return raw_spin_unlock_irqrestore(&rmnet_wlan_fragment_lock, v17);
}
