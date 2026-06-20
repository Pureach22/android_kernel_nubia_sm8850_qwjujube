__int64 __fastcall rmnet_shs_cpu_list_add(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 v4; // x2
  unsigned __int64 v5; // x0

  raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
  v4 = *a2;
  v5 = a1 + 56;
  if ( *(unsigned __int64 **)(*a2 + 8) != a2 || (unsigned __int64 *)v5 == a2 || v4 == v5 )
  {
    _list_add_valid_or_report(v5, a2);
  }
  else
  {
    *(_QWORD *)(a1 + 56) = v4;
    *(_QWORD *)(a1 + 64) = a2;
    atomic_store(v5, a2);
    *(_QWORD *)(v4 + 8) = v5;
  }
  return raw_spin_unlock_bh(&rmnet_shs_hstat_tbl_lock);
}
