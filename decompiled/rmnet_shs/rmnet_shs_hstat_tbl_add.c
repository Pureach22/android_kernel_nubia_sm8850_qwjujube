__int64 __fastcall rmnet_shs_hstat_tbl_add(__int64 a1)
{
  _UNKNOWN **v2; // x0
  void *v3; // x2

  raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
  v2 = (_UNKNOWN **)(a1 + 72);
  v3 = rmnet_shs_wq_hstat_tbl;
  if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)rmnet_shs_wq_hstat_tbl) != &rmnet_shs_wq_hstat_tbl
    || v2 == &rmnet_shs_wq_hstat_tbl
    || rmnet_shs_wq_hstat_tbl == (_UNKNOWN *)v2 )
  {
    _list_add_valid_or_report(v2, &rmnet_shs_wq_hstat_tbl);
  }
  else
  {
    *(_QWORD *)(a1 + 72) = rmnet_shs_wq_hstat_tbl;
    *(_QWORD *)(a1 + 80) = &rmnet_shs_wq_hstat_tbl;
    atomic_store((unsigned __int64)v2, (unsigned __int64 *)&rmnet_shs_wq_hstat_tbl);
    *(_QWORD *)((char *)&unk_8 + (_QWORD)v3) = v2;
  }
  return raw_spin_unlock_bh(&rmnet_shs_hstat_tbl_lock);
}
