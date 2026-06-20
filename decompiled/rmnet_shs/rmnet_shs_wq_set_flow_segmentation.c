__int64 __fastcall rmnet_shs_wq_set_flow_segmentation(int a1, char a2)
{
  __int64 v4; // x0
  __int64 lock; // x0
  __int64 i; // x9
  __int64 j; // x8
  __int64 v8; // x11
  __int64 v9; // x8
  unsigned int v10; // w19

  v4 = raw_spin_lock_bh(&rmnet_shs_ht_splock);
  lock = _rcu_read_lock(v4);
  for ( i = 0; i != 512; ++i )
  {
    for ( j = rmnet_shs_ht[i]; j; j = *(_QWORD *)(v8 + 128) )
    {
      v8 = j - 128;
      if ( j == 128 )
        break;
      v9 = *(_QWORD *)(j - 40);
      if ( v9 && *(_DWORD *)(v9 + 300) == a1 )
      {
        *(_BYTE *)(v9 + 328) = a2;
        v10 = 1;
        goto LABEL_10;
      }
    }
  }
  v10 = 0;
LABEL_10:
  _rcu_read_unlock(lock);
  raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  return v10;
}
