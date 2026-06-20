__int64 __fastcall _qptm_destroy_hierarchy(_QWORD *a1)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x20
  _QWORD *v4; // x21
  _QWORD *v6; // x8
  _QWORD *v7; // x0
  __int64 v8; // x9

  v1 = (_QWORD *)a1[137];
  v2 = a1 + 137;
  if ( v1 != a1 + 137 )
  {
    do
    {
      v4 = (_QWORD *)*v1;
      _qptm_destroy_hierarchy(v1 - 135);
      v1 = v4;
    }
    while ( v4 != v2 );
  }
  if ( *(_QWORD **)(qh + 24) != a1 )
    return powercap_unregister_zone(*(_QWORD *)(qh + 8), a1);
  mutex_lock(&qptm_list_lock);
  v6 = (_QWORD *)a1[149];
  v7 = a1 + 148;
  if ( (_QWORD *)*v6 == a1 + 148 && (v8 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
  {
    *(_QWORD *)(v8 + 8) = v6;
    *v6 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(v7);
  }
  a1[148] = 0xDEAD000000000100LL;
  a1[149] = 0xDEAD000000000122LL;
  mutex_unlock(&qptm_list_lock);
  return kfree(a1);
}
