__int64 __fastcall fastrpc_context_save_interrupted(_QWORD *a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x2
  _QWORD *v6; // x1

  raw_spin_lock(a1[23] + 320LL);
  v2 = (_QWORD *)a1[1];
  if ( (_QWORD *)*v2 == a1 && (v3 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v3 + 8) = v2;
    *v2 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  v4 = a1[23];
  v5 = v4 + 48;
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  v6 = *(_QWORD **)(v4 + 56);
  if ( (_QWORD *)(v4 + 48) == a1 || v6 == a1 || *v6 != v5 )
  {
    _list_add_valid_or_report(a1, v6, v5);
  }
  else
  {
    *(_QWORD *)(v4 + 56) = a1;
    *a1 = v5;
    a1[1] = v6;
    *v6 = a1;
  }
  return raw_spin_unlock(a1[23] + 320LL);
}
