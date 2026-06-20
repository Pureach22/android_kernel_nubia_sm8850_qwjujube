__int64 __fastcall qdf_list_insert_back_size(__int64 a1, _QWORD *a2, int *a3)
{
  _QWORD *v3; // x8
  int v4; // w8
  int *v6; // x10
  __int64 v7; // x9

  v3 = *(_QWORD **)(a1 + 8);
  if ( a2 == (_QWORD *)a1 || v3 == a2 || *v3 != a1 )
  {
    _list_add_valid_or_report(a2, v3);
    a3 = v6;
    a1 = v7;
  }
  else
  {
    *(_QWORD *)(a1 + 8) = a2;
    *a2 = a1;
    a2[1] = v3;
    *v3 = a2;
  }
  v4 = *(_DWORD *)(a1 + 16) + 1;
  *(_DWORD *)(a1 + 16) = v4;
  *a3 = v4;
  return 0;
}
