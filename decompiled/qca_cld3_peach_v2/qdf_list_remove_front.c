__int64 __fastcall qdf_list_remove_front(_DWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  __int64 v4; // x10
  _DWORD *v6; // x10

  if ( *(_DWORD **)a1 == a1 )
    return 13;
  *a2 = *(_QWORD *)a1;
  v2 = *(_QWORD **)a1;
  v3 = *(_QWORD **)(*(_QWORD *)a1 + 8LL);
  if ( *v3 == *(_QWORD *)a1 && (v4 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v4 + 8) = v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)a1);
    a1 = v6;
  }
  *v2 = v2;
  v2[1] = v2;
  --a1[4];
  return 0;
}
