__int64 __fastcall phys_to_dma(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 v4; // x9
  _QWORD *i; // x8
  unsigned __int64 v6; // x10
  bool v7; // cf
  unsigned __int64 v8; // x10

  v2 = *(_QWORD *)(a1 + 664);
  result = a2;
  if ( v2 )
  {
    v4 = *(_QWORD *)(v2 + 16);
    if ( v4 )
    {
      for ( i = (_QWORD *)(v2 + 8); ; i += 3 )
      {
        v6 = *(i - 1);
        v7 = a2 >= v6;
        v8 = a2 - v6;
        if ( v7 && v8 < v4 )
          break;
        v4 = i[4];
        if ( !v4 )
          return -1;
      }
      return *i + v8;
    }
    else
    {
      return -1;
    }
  }
  return result;
}
