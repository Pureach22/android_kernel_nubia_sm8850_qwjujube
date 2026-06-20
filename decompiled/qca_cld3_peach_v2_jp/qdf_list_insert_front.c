__int64 __fastcall qdf_list_insert_front(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x2
  _QWORD *v3; // x9

  v2 = (_QWORD *)*a1;
  v3 = a1;
  if ( *(_QWORD **)(*a1 + 8LL) != a1 || a2 == a1 || v2 == a2 )
  {
    _list_add_valid_or_report(a2, a1);
  }
  else
  {
    v2[1] = a2;
    *a2 = v2;
    a2[1] = a1;
    *a1 = a2;
  }
  ++*((_DWORD *)v3 + 4);
  return 0;
}
