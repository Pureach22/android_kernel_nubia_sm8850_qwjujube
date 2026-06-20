__int64 __fastcall dcc_add_write(__int64 a1, int a2, int a3, int a4)
{
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w10
  _QWORD *v12; // x8
  __int64 v13; // x2
  _QWORD *v14; // x1
  unsigned int v15; // w9

  v8 = _kmalloc_cache_noprof(strcmp, 3520, 56);
  if ( v8 )
  {
    *(_DWORD *)(v8 + 20) = a3;
    *(_DWORD *)(v8 + 32) = 3;
    *(_DWORD *)v8 = a2 & 0xFFFFFFF0;
    *(_DWORD *)(v8 + 4) = a2 & 0xF;
    v9 = *(_QWORD *)(a1 + 320);
    v10 = *(unsigned __int8 *)(a1 + 332);
    v11 = *(_DWORD *)(v9 + 4 * v10);
    *(_DWORD *)(v9 + 4 * v10) = v11 + 1;
    *(_DWORD *)(v8 + 8) = 1;
    *(_DWORD *)(v8 + 12) = v11;
    v12 = (_QWORD *)(v8 + 40);
    *(_BYTE *)(v8 + 28) = a4 != 0;
    *(_QWORD *)(v8 + 40) = v8 + 40;
    *(_QWORD *)(v8 + 48) = v8 + 40;
    v13 = *(_QWORD *)(a1 + 312) + 16LL * *(unsigned __int8 *)(a1 + 332);
    v14 = *(_QWORD **)(v13 + 8);
    if ( v8 + 40 == v13 || v14 == v12 || *v14 != v13 )
    {
      _list_add_valid_or_report(v8 + 40, v14);
      return 0;
    }
    else
    {
      v15 = 0;
      *(_QWORD *)(v13 + 8) = v12;
      *(_QWORD *)(v8 + 40) = v13;
      *(_QWORD *)(v8 + 48) = v14;
      *v14 = v12;
    }
  }
  else
  {
    return (unsigned int)-12;
  }
  return v15;
}
