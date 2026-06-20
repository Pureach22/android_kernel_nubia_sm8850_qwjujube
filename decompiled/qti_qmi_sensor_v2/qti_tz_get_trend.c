__int64 __fastcall qti_tz_get_trend(__int64 a1, int *a2, _DWORD *a3)
{
  __int64 result; // x0
  int v5; // w9
  int v6; // w8
  int *v7; // x12
  char v8; // w13

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = *a2;
      v6 = *(_DWORD *)(a1 + 1088);
      v7 = *((int **)a2 + 26);
      if ( v7 != a2 + 52 )
      {
        v8 = 0;
        do
        {
          if ( *((int **)v7 - 19) == a2 )
          {
            if ( *((_QWORD *)v7 - 16) != *((_QWORD *)v7 - 17) )
              return 4294967274LL;
            v8 = 1;
          }
          v7 = *(int **)v7;
        }
        while ( v7 != a2 + 52 );
        result = 4294967274LL;
        if ( ((unsigned __int8)v8 & (v6 < v5)) == 1 && v6 > v5 - a2[1] )
        {
          result = 0;
          *a3 = 0;
        }
      }
    }
  }
  return result;
}
