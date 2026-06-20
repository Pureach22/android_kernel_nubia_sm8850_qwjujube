__int64 __fastcall qdf_list_remove_back(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  __int64 v4; // x10
  __int64 v6; // x10

  if ( *(_QWORD *)a1 == a1 )
    return 13;
  v2 = *(_QWORD **)(a1 + 8);
  *a2 = v2;
  v3 = (_QWORD *)v2[1];
  if ( (_QWORD *)*v3 == v2 && (v4 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v4 + 8) = v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
    a1 = v6;
  }
  *v2 = v2;
  v2[1] = v2;
  --*(_DWORD *)(a1 + 16);
  return 0;
}
