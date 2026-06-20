__int64 __fastcall cti_add_connection_entry(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x8
  _QWORD *v8; // x0
  __int64 v9; // x2
  _QWORD *v10; // x1
  __int64 v11; // x3
  __int64 v13; // x0

  a3[2] = a4;
  if ( a4 )
  {
    v7 = *(_QWORD *)(a4 + 168);
    if ( !v7 )
      v7 = *(_QWORD *)(a4 + 56);
    a3[3] = v7;
  }
  else if ( a5 )
  {
    v13 = devm_kstrdup(a1, a5, 3264);
    a3[3] = v13;
    if ( !v13 )
      return 4294967284LL;
  }
  v8 = a3 + 4;
  v9 = a2 + 24;
  v10 = *(_QWORD **)(a2 + 32);
  if ( a3 + 4 == (_QWORD *)(a2 + 24) || v10 == v8 || *v10 != v9 )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)(a2 + 32) = v8;
    a3[4] = v9;
    a3[5] = v10;
    *v10 = v8;
  }
  v11 = *(unsigned int *)(a2 + 68);
  ++*(_DWORD *)(a2 + 16);
  _bitmap_or(a2 + 80, a2 + 80, *a3 + 8LL, v11);
  _bitmap_or(a2 + 96, a2 + 96, a3[1] + 8LL, *(unsigned int *)(a2 + 68));
  return 0;
}
