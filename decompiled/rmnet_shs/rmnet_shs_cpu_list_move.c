__int64 __fastcall rmnet_shs_cpu_list_move(__int64 a1, __int64 *a2)
{
  _QWORD *v4; // x8
  __int64 *v5; // x9
  __int64 v6; // x10
  __int64 *v7; // x2

  raw_spin_lock_bh(&rmnet_shs_hstat_tbl_lock);
  v4 = *(_QWORD **)(a1 + 64);
  v5 = (__int64 *)(a1 + 56);
  if ( *v4 == a1 + 56 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 56);
  }
  v7 = (__int64 *)*a2;
  if ( *(__int64 **)(*a2 + 8) != a2 || v5 == a2 || v7 == v5 )
  {
    _list_add_valid_or_report(v5, a2);
  }
  else
  {
    v7[1] = (__int64)v5;
    *(_QWORD *)(a1 + 56) = v7;
    *(_QWORD *)(a1 + 64) = a2;
    *a2 = (__int64)v5;
  }
  return raw_spin_unlock_bh(&rmnet_shs_hstat_tbl_lock);
}
