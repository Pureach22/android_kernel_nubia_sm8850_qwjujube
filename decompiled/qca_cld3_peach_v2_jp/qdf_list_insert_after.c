__int64 __fastcall qdf_list_insert_after(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _QWORD *v3; // x8
  __int64 v4; // x9

  v3 = (_QWORD *)*a3;
  v4 = a1;
  if ( *(_QWORD **)(*a3 + 8LL) != a3 || a2 == a3 || v3 == a2 )
  {
    _list_add_valid_or_report(a2, a3);
  }
  else
  {
    v3[1] = a2;
    *a2 = v3;
    a2[1] = a3;
    *a3 = a2;
  }
  ++*(_DWORD *)(v4 + 16);
  return 0;
}
