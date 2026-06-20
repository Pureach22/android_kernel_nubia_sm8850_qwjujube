__int64 __fastcall qdf_list_remove_node(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  _QWORD *v5; // x10
  __int64 v6; // x9

  if ( *(_QWORD *)a1 == a1 )
    return 13;
  v2 = (_QWORD *)a2[1];
  if ( (_QWORD *)*v2 == a2 && (v3 = *a2, *(_QWORD **)(*a2 + 8LL) == a2) )
  {
    *(_QWORD *)(v3 + 8) = v2;
    *v2 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(a2);
    a2 = v5;
    a1 = v6;
  }
  *a2 = a2;
  a2[1] = a2;
  --*(_DWORD *)(a1 + 16);
  return 0;
}
