__int64 __fastcall insert_zspage(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 *v5; // x8
  __int64 v6; // x9
  __int64 v7; // t1
  unsigned int v10; // w11
  __int64 v11; // x10

  if ( a3 >= 0xE || (++*(_QWORD *)(a1 + 8LL * a3 + 216), a3 == 13) )
  {
    __break(0x5512u);
    return SetZsPageMovable(a1);
  }
  else
  {
    v3 = a1 + 16LL * a3;
    result = a2 + 24;
    v7 = *(_QWORD *)(v3 + 8);
    v5 = (__int64 *)(v3 + 8);
    v6 = v7;
    if ( *(__int64 **)(v7 + 8) != v5 || result == (_QWORD)v5 || v6 == result )
    {
      result = _list_add_valid_or_report(result);
      a3 = v10;
      a2 = v11;
    }
    else
    {
      *(_QWORD *)(v6 + 8) = result;
      *(_QWORD *)(a2 + 24) = v6;
      *(_QWORD *)(a2 + 32) = v5;
      *v5 = result;
    }
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFFFFFE1 | (2 * a3);
  }
  return result;
}
