void rmnet_shs_cancel_table()
{
  __int64 i; // x19
  __int64 v1; // x8
  __int64 v2; // x21
  _QWORD *v3; // x0
  __int64 v4; // x21
  _QWORD *v5; // t1
  __int64 v6; // x22
  _QWORD *v7; // x23

  if ( qword_19468 )
  {
    raw_spin_lock_bh(&rmnet_shs_ht_splock);
    for ( i = 0; i != 512; ++i )
    {
      v1 = rmnet_shs_ht[i];
      if ( v1 )
      {
        v2 = v1 - 128;
        if ( v1 != 128 )
        {
          do
          {
            v5 = *(_QWORD **)(v2 + 96);
            v4 = v2 + 96;
            v3 = v5;
            v6 = *(_QWORD *)(v4 + 32);
            if ( v5 )
            {
              do
              {
                v7 = (_QWORD *)*v3;
                consume_skb();
                v3 = v7;
              }
              while ( v7 );
            }
            *(_DWORD *)(v4 + 24) = 0;
            *(_QWORD *)(v4 + 8) = 0;
            *(_QWORD *)(v4 + 16) = 0;
            *(_QWORD *)v4 = 0;
            if ( !v6 )
              break;
            v2 = v6 - 128;
          }
          while ( v6 != 128 );
        }
      }
    }
    word_19492 = 512;
    qword_19460 = 0;
    qword_19468 = 0;
    raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  }
}
