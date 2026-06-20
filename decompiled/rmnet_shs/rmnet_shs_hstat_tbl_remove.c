__int64 __fastcall rmnet_shs_hstat_tbl_remove(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 *v3; // x0
  __int64 v4; // x9

  raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
  v2 = *(_QWORD **)(a1 + 80);
  v3 = (__int64 *)(a1 + 72);
  if ( *v2 == a1 + 72 && (v4 = *v3, *(__int64 **)(*v3 + 8) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  *(_QWORD *)(a1 + 80) = 0xDEAD000000000122LL;
  return raw_spin_unlock_bh(&rmnet_shs_hstat_tbl_lock);
}
