__int64 __fastcall rmnet_shs_remove_llflow(__int64 a1)
{
  unsigned __int64 v2; // x21
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x23
  _QWORD *v7; // x8
  _UNKNOWN **v8; // x9
  _BYTE *v9; // x11
  __int64 result; // x0

  raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
  v2 = 0;
  while ( 1 )
  {
    v4 = rmnet_shs_ll_filter_ht[v2];
    if ( v4 )
    {
      v5 = v4 - 16;
      if ( v4 != 16 )
        break;
    }
LABEL_2:
    if ( v2++ >= 0x1FF )
    {
      raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
      return kfree(a1);
    }
  }
  while ( 1 )
  {
    v6 = *(_QWORD *)(v5 + 16);
    if ( (unsigned int)rmnet_shs_is_identical_filter(v5, a1) )
      break;
    if ( v6 )
    {
      v5 = v6 - 16;
      if ( v6 != 16 )
        continue;
    }
    goto LABEL_2;
  }
  v7 = *(_QWORD **)(v5 + 24);
  if ( v7 )
  {
    *v7 = v6;
    if ( v6 )
      *(_QWORD *)(v6 + 8) = v7;
    *(_QWORD *)(v5 + 24) = 0;
  }
  kfree(v5);
  raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
  raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
  v8 = (_UNKNOWN **)rmnet_shs_wq_hstat_tbl;
  if ( rmnet_shs_wq_hstat_tbl != (_UNKNOWN *)&rmnet_shs_wq_hstat_tbl )
  {
    do
    {
      v9 = v8[2];
      if ( v9 && v9[223] != 3 )
        v9[223] = 2;
      v8 = (_UNKNOWN **)*v8;
    }
    while ( v8 != &rmnet_shs_wq_hstat_tbl );
  }
  raw_spin_unlock_bh(&rmnet_shs_hstat_tbl_lock);
  result = kfree(a1);
  --byte_19490;
  --rmnet_shs_filter_count;
  return result;
}
