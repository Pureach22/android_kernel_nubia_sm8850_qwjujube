__int64 __fastcall rmnet_shs_add_llflow(__int64 a1)
{
  __int64 i; // x22
  __int64 j; // x8
  __int64 v4; // x20
  void *v5; // x0
  __int64 result; // x0
  __int64 *v7; // x8
  __int64 v8; // x10
  __int64 v9; // x9
  _UNKNOWN **v10; // x9
  _BYTE *v11; // x11

  raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
  for ( i = 0; i != 512; ++i )
  {
    for ( j = rmnet_shs_ll_filter_ht[i]; j; j = *(_QWORD *)(v4 + 16) )
    {
      v4 = j - 16;
      if ( j == 16 )
        break;
      if ( (unsigned int)rmnet_shs_is_identical_filter(j - 16, a1) )
      {
        kfree(a1);
        v5 = &rmnet_shs_ll_ht_splock;
        return raw_spin_unlock_bh(v5);
      }
    }
  }
  if ( (unsigned __int8)byte_19490 < 0x64u )
  {
    ++byte_19490;
    ++rmnet_shs_filter_count;
    if ( rmnet_shs_debug )
      rmnet_shs_print_llflow((_BYTE *)a1);
    v7 = &rmnet_shs_ll_filter_ht[(unsigned int)(1640531527 * *(_DWORD *)(a1 + 48)) >> 23];
    v8 = *v7;
    *(_QWORD *)(a1 + 16) = *v7;
    v9 = a1 + 16;
    if ( v8 )
      *(_QWORD *)(v8 + 8) = v9;
    *v7 = v9;
    *(_QWORD *)(a1 + 24) = v7;
    raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
    raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
    v10 = (_UNKNOWN **)rmnet_shs_wq_hstat_tbl;
    if ( rmnet_shs_wq_hstat_tbl != (_UNKNOWN *)&rmnet_shs_wq_hstat_tbl )
    {
      do
      {
        v11 = v10[2];
        if ( v11 )
        {
          if ( v11[223] != 3 )
            v11[223] = 2;
        }
        v10 = (_UNKNOWN **)*v10;
      }
      while ( v10 != &rmnet_shs_wq_hstat_tbl );
    }
    v5 = &rmnet_shs_hstat_tbl_lock;
    return raw_spin_unlock_bh(v5);
  }
  else
  {
    kfree(a1);
    result = raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
    ++qword_1A4B8;
  }
  return result;
}
