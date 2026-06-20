__int64 __fastcall ipa3_recycle_rx_wrapper(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x2
  _QWORD *v4; // x1

  a1[3] = 0;
  *a1 = a1;
  a1[1] = a1;
  raw_spin_lock_bh(a1[10] + 1684LL);
  v2 = a1[10];
  v3 = v2 + 1648;
  v4 = *(_QWORD **)(v2 + 1656);
  if ( (_QWORD *)(v2 + 1648) == a1 || v4 == a1 || *v4 != v3 )
  {
    _list_add_valid_or_report(a1, v4);
  }
  else
  {
    *(_QWORD *)(v2 + 1656) = a1;
    *a1 = v3;
    a1[1] = v4;
    *v4 = a1;
  }
  return raw_spin_unlock_bh(a1[10] + 1684LL);
}
