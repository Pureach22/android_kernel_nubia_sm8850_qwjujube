__int64 __fastcall util_find_mlie(unsigned __int8 *a1, unsigned __int64 a2, _QWORD *a3, _QWORD *a4)
{
  unsigned int v4; // w8
  unsigned __int64 v5; // x8
  unsigned __int8 *v6; // x9
  __int64 v7; // x12
  __int64 v8; // x10
  bool v9; // cf
  unsigned __int64 v10; // x8
  unsigned __int8 *v12; // x11
  unsigned __int8 *v13; // x11
  int v14; // t1
  unsigned __int8 *v15; // x11
  int v16; // t1

  v4 = 29;
  if ( !a1 || !a2 || !a3 || !a4 )
    return v4;
  *a3 = 0;
  *a4 = 0;
  if ( a2 < 3 )
    return 0;
  v5 = a2;
  v6 = a1;
  while ( 1 )
  {
    v7 = v6[1];
    v8 = v7 + 2;
    v9 = v5 >= v7 + 2;
    v5 -= v7 + 2;
    if ( !v9 )
      return 0;
    if ( v6[1] && *v6 == 255 && v6[2] == 107 )
      break;
    v6 += v8;
    if ( v5 <= 2 )
      return 0;
  }
  if ( !v6 )
    return 0;
  v10 = (unsigned __int64)&a1[a2];
  if ( v6 + 2 > &a1[a2] )
    return 4;
  if ( (unsigned int)v7 < 3 )
    return 27;
  if ( (unsigned __int64)&v6[v8] > v10 )
    return 4;
  if ( (unsigned __int64)&v6[v7 + 4] <= v10 )
  {
    v12 = &v6[v7];
    if ( (unsigned __int64)&v6[v7 + 4 + v6[v7 + 3]] <= v10 )
    {
      v14 = v12[2];
      v13 = v12 + 2;
      if ( v14 == 242 )
      {
        if ( v13 )
        {
          while ( (_DWORD)v7 == 255 )
          {
            v7 = v13[1];
            if ( !v13[1] )
              break;
            v8 += v7 + 2;
            if ( (unsigned __int64)(v13 + 2) <= v10 && (unsigned __int64)&v13[v7 + 4] <= v10 )
            {
              v15 = &v13[v7];
              if ( (unsigned __int64)&v15[v15[3] + 4] <= v10 )
              {
                v16 = v15[2];
                v13 = v15 + 2;
                if ( v16 == 242 )
                {
                  if ( v13 )
                    continue;
                }
              }
            }
            goto LABEL_23;
          }
          return 27;
        }
      }
    }
  }
LABEL_23:
  *a3 = v6;
  *a4 = v8;
  return 0;
}
