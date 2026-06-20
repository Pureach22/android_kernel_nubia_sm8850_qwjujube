__int64 __fastcall coresight_find_output_type(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 result; // x0
  unsigned __int64 v7; // x11
  unsigned __int64 v8; // x12

  v3 = *(unsigned int *)(a1 + 4);
  if ( (int)v3 >= 1 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    v5 = HIDWORD(a3);
    do
    {
      result = *(_QWORD *)(*(_QWORD *)v4 + 16LL);
      if ( result && *(_DWORD *)(result + 8) == a2 )
      {
        v7 = *(_QWORD *)(result + 12);
        v8 = HIDWORD(v7);
        if ( a2 <= 1 )
        {
          if ( !a2 )
            goto LABEL_4;
          if ( a2 == 1 && v5 == v8 )
            return result;
        }
        else if ( a2 == 2 )
        {
          if ( v5 == v8 )
            goto LABEL_4;
        }
        else if ( a2 == 3 || a2 == 4 )
        {
LABEL_4:
          if ( (_DWORD)a3 == (_DWORD)v7 )
            return result;
        }
      }
      --v3;
      v4 += 8;
    }
    while ( v3 );
  }
  return 0;
}
