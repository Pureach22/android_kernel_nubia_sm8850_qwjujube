__int64 __fastcall qdf_list_insert_before(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _QWORD *v3; // x8
  __int64 v4; // x9

  v3 = (_QWORD *)a3[1];
  v4 = a1;
  if ( a2 == a3 || v3 == a2 || (_QWORD *)*v3 != a3 )
  {
    _list_add_valid_or_report(a2, v3);
  }
  else
  {
    a3[1] = a2;
    *a2 = a3;
    a2[1] = v3;
    *v3 = a2;
  }
  ++*(_DWORD *)(v4 + 16);
  return 0;
}
