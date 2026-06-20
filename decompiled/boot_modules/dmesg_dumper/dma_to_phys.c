__int64 __fastcall dma_to_phys(__int64 a1, unsigned __int64 a2)
{
  _QWORD *v2; // x8
  __int64 result; // x0
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x10
  bool v6; // cf
  unsigned __int64 v7; // x10

  v2 = *(_QWORD **)(a1 + 664);
  result = a2;
  if ( v2 )
  {
    v4 = v2[2];
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = v2[1];
        v6 = a2 >= v5;
        v7 = a2 - v5;
        if ( v6 && v7 < v4 )
          break;
        v4 = v2[5];
        v2 += 3;
        if ( !v4 )
          return -1;
      }
      return *v2 + v7;
    }
    else
    {
      return -1;
    }
  }
  return result;
}
