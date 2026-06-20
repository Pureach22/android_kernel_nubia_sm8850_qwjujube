__int64 rmnet_wlan_cleanup()
{
  __int64 i; // x19
  _QWORD *v1; // x1
  _QWORD *v2; // x8
  _QWORD *v3; // x21
  __int64 j; // x20
  _QWORD *v5; // x19
  _QWORD *v6; // x22
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  __int64 v9; // x19
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  _QWORD *v12; // x21
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 v15; // x0

  if ( rmnet_wlan_device && !(unsigned int)unregister_netdevice_notifier(&rmnet_wlan_notifier) )
    rmnet_wlan_device = 0;
  rmnet_wwan_device = 0;
  mutex_lock(&rmnet_wlan_encap_mutex);
  for ( i = 0; i != 16; ++i )
  {
    v1 = (_QWORD *)rmnet_wlan_encap_hash[i];
    if ( v1 )
    {
      do
      {
        v3 = (_QWORD *)*v1;
        v2 = (_QWORD *)v1[1];
        if ( v2 )
        {
          *v2 = v3;
          if ( v3 )
            v3[1] = v2;
          v1[1] = 0;
        }
        kvfree_call_rcu(v1 + 2);
        v1 = v3;
      }
      while ( v3 );
    }
  }
  mutex_unlock(&rmnet_wlan_encap_mutex);
  rmnet_wlan_fragments_remove();
  mutex_lock(&rmnet_wlan_fwd_mutex);
  for ( j = 0; j != 16; ++j )
  {
    v5 = (_QWORD *)rmnet_wlan_fwd_hash[j];
    if ( v5 )
    {
      do
      {
        v6 = (_QWORD *)*v5;
        if ( !(unsigned int)unregister_netdevice_notifier(v5 + 4) )
        {
          v7 = (_QWORD *)v5[1];
          if ( v7 )
          {
            v8 = (_QWORD *)*v5;
            *v7 = *v5;
            if ( v8 )
              v8[1] = v7;
            v5[1] = 0;
          }
          rmnet_wlan_fragment_del_fwd_info((__int64)(v5 + 9));
          kvfree_call_rcu(v5 + 2);
        }
        v5 = v6;
      }
      while ( v6 );
    }
  }
  mutex_unlock(&rmnet_wlan_fwd_mutex);
  mutex_lock(&rmnet_wlan_tuple_mutex);
  v9 = 0;
  rmnet_wlan_tuple_count = 0;
  do
  {
    v10 = (_QWORD *)rmnet_wlan_tuple_hash[v9];
    if ( v10 )
    {
      do
      {
        v12 = (_QWORD *)*v10;
        v11 = (_QWORD *)v10[1];
        if ( v11 )
        {
          *v11 = v12;
          if ( v12 )
            v12[1] = v11;
          v10[1] = 0;
        }
        kvfree_call_rcu(v10 + 2);
        v10 = v12;
      }
      while ( v12 );
    }
    ++v9;
  }
  while ( v9 != 16 );
  mutex_unlock(&rmnet_wlan_tuple_mutex);
  mutex_lock(&rmnet_wlan_ll_tuple_mutex);
  v13 = raw_spin_lock_irqsave(&rmnet_wlan_tuple_lock);
  v14 = rmnet_wlan_ll_tuple_cache;
  rmnet_wlan_ll_tuple_cache = 0;
  v15 = raw_spin_unlock_irqrestore(&rmnet_wlan_tuple_lock, v13);
  synchronize_rcu(v15);
  if ( v14 )
    kfree(v14);
  return mutex_unlock(&rmnet_wlan_ll_tuple_mutex);
}
