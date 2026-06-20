__int64 rmnet_shs_ll_deinit()
{
  __int64 i; // x19
  __int64 v1; // x8
  __int64 v2; // x0
  _QWORD *v3; // x8
  __int64 v4; // x23

  raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
  for ( i = 0; i != 512; ++i )
  {
    v1 = rmnet_shs_ll_filter_ht[i];
    if ( v1 )
    {
      v2 = v1 - 16;
      if ( v1 != 16 )
      {
        do
        {
          v4 = *(_QWORD *)(v2 + 16);
          v3 = *(_QWORD **)(v2 + 24);
          if ( v3 )
          {
            *v3 = v4;
            if ( v4 )
              *(_QWORD *)(v4 + 8) = v3;
            *(_QWORD *)(v2 + 24) = 0;
          }
          kfree(v2);
          --byte_19490;
          --rmnet_shs_filter_count;
          if ( !v4 )
            break;
          v2 = v4 - 16;
        }
        while ( v4 != 16 );
      }
    }
  }
  return raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
}
