__int64 rmnet_ll_ipa_tx_pending()
{
  _QWORD *stats; // x19
  __int64 *v1; // x20
  __int64 v2; // x8
  __int64 *v3; // x9
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x9

  stats = rmnet_ll_get_stats();
  raw_spin_lock_bh(&rmnet_ll_tx_lock);
  v1 = (__int64 *)tx_pending_list;
  if ( (__int64 *)tx_pending_list != &tx_pending_list && tx_pending_list )
  {
    while ( 1 )
    {
      --dword_2FE20;
      v2 = *v1;
      v3 = (__int64 *)v1[1];
      *v1 = 0;
      v1[1] = 0;
      *(_QWORD *)(v2 + 8) = v3;
      *v3 = v2;
      v4 = ipa_rmnet_ll_xmit(v1);
      if ( v4 == -11 )
        break;
      if ( v4 >= 0 )
        v5 = 14;
      else
        v5 = 15;
      ++stats[v5];
      v1 = (__int64 *)tx_pending_list;
      if ( (__int64 *)tx_pending_list == &tx_pending_list || !tx_pending_list )
        return raw_spin_unlock_bh(&rmnet_ll_tx_lock);
    }
    v6 = tx_pending_list;
    ++stats[11];
    *v1 = v6;
    v1[1] = (__int64)&tx_pending_list;
    *(_QWORD *)(v6 + 8) = v1;
    tx_pending_list = (__int64)v1;
    ++dword_2FE20;
  }
  return raw_spin_unlock_bh(&rmnet_ll_tx_lock);
}
