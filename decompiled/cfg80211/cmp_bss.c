__int64 __fastcall cmp_bss(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x19
  unsigned __int64 v6; // x10
  _BYTE *v7; // x9
  unsigned __int64 v8; // x8
  __int64 v9; // x11
  unsigned __int64 v10; // x12
  _BYTE *v11; // x21
  unsigned __int64 v12; // x11
  _BYTE *v13; // x10
  __int64 v14; // x8
  int v15; // w11
  __int64 v16; // x22
  __int64 v17; // x23
  int v18; // w24
  int v19; // w0
  unsigned int v20; // w8
  unsigned __int64 v21; // x11
  _BYTE *v22; // x10
  unsigned __int64 v23; // x9
  __int64 v24; // x12
  unsigned __int64 v25; // x12
  _BYTE *v26; // x11
  __int64 v27; // x9
  int v28; // w8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x9
  bool v31; // cf
  int v32; // w8
  int v33; // w9
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // x11
  unsigned __int64 v38; // x11
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x10
  __int64 v41; // x12
  unsigned int v42; // w10
  __int64 v43; // x8
  int v44; // w10
  unsigned __int8 *v45; // x9
  size_t v47; // x2
  int v48; // w10

  if ( *(_QWORD *)a1 != *(_QWORD *)a2 )
    return 1000 * (*(_DWORD *)(*(_QWORD *)a2 + 4LL) - *(_DWORD *)(*(_QWORD *)a1 + 4LL))
         - *(unsigned __int16 *)(*(_QWORD *)a1 + 8LL)
         + (unsigned int)*(unsigned __int16 *)(*(_QWORD *)a2 + 8LL);
  v4 = *(_QWORD *)(a1 + 8);
  if ( !v4 )
    return 0xFFFFFFFFLL;
  v5 = *(_QWORD *)(a2 + 8);
  if ( !v5 )
    return 1;
  if ( (*(_WORD *)(a1 + 70) & 3) == 0 )
  {
    v6 = *(unsigned int *)(v4 + 24);
    if ( (unsigned int)v6 >= 2 )
    {
      v7 = (_BYTE *)(v4 + 29);
      v8 = v4 + 29 + v6;
      do
      {
        v9 = (unsigned __int8)v7[1];
        if ( v6 < v9 + 2 )
          break;
        if ( *v7 == 114 )
          goto LABEL_13;
        v7 += v9 + 2;
        v6 = v8 - (_QWORD)v7;
      }
      while ( (__int64)(v8 - (_QWORD)v7) > 1 );
    }
  }
  v7 = nullptr;
LABEL_13:
  if ( (*(_WORD *)(a2 + 70) & 3) == 0 )
  {
    v10 = *(unsigned int *)(v5 + 24);
    if ( (unsigned int)v10 >= 2 )
    {
      v11 = (_BYTE *)(v5 + 29);
      v12 = v5 + 29 + v10;
      v13 = (_BYTE *)(v5 + 29);
      do
      {
        v14 = (unsigned __int8)v13[1];
        if ( v10 < v14 + 2 )
          break;
        if ( *v13 == 114 )
        {
          if ( v7 && v13 )
          {
            v15 = (unsigned __int8)v7[1];
            if ( v15 == (_DWORD)v14 )
            {
              v16 = a1;
              v17 = a2;
              v18 = a3;
              v19 = memcmp(v7 + 2, v13 + 2, (unsigned __int8)v13[1]);
              a2 = v17;
              a3 = v18;
              v20 = v19;
              a1 = v16;
            }
            else
            {
              v20 = v14 - v15;
            }
            v21 = *(unsigned int *)(v4 + 24);
            if ( (unsigned int)v21 >= 2 )
            {
              v22 = (_BYTE *)(v4 + 29);
              v23 = v4 + 29 + v21;
              do
              {
                v24 = (unsigned __int8)v22[1];
                if ( v21 < v24 + 2 )
                  break;
                if ( *v22 == 113 )
                  goto LABEL_32;
                v22 += v24 + 2;
                v21 = v23 - (_QWORD)v22;
              }
              while ( (__int64)(v23 - (_QWORD)v22) > 1 );
            }
            v22 = nullptr;
LABEL_32:
            v25 = *(unsigned int *)(v5 + 24);
            if ( (unsigned int)v25 >= 2 )
            {
              v26 = &v11[v25];
              while ( 1 )
              {
                v27 = (unsigned __int8)v11[1];
                if ( v25 < v27 + 2 )
                  break;
                if ( *v11 == 113 )
                {
                  if ( !v22 || !v11 )
                    goto LABEL_43;
                  result = v20;
                  if ( !v20 )
                  {
                    v28 = (unsigned __int8)v22[1];
                    if ( v28 == (_DWORD)v27 )
                      return memcmp(v22 + 2, v11 + 2, (unsigned __int8)v11[1]);
                    else
                      return (unsigned int)(v27 - v28);
                  }
                  return result;
                }
                v11 += v27 + 2;
                v25 = v26 - v11;
                if ( v26 - v11 <= 1 )
                  goto LABEL_43;
              }
            }
          }
          break;
        }
        v13 += v14 + 2;
        v10 = v12 - (_QWORD)v13;
      }
      while ( (__int64)(v12 - (_QWORD)v13) > 1 );
    }
  }
LABEL_43:
  v29 = bswap64(*(unsigned int *)(a1 + 72) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 76) << 32));
  v30 = bswap64(*(unsigned int *)(a2 + 72) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 76) << 32));
  v31 = v29 >= v30;
  v32 = v29 > v30;
  v33 = !v31;
  result = (unsigned int)(v32 - v33);
  if ( v32 == v33 )
  {
    v34 = *(unsigned int *)(v4 + 24);
    if ( (unsigned int)v34 >= 2 )
    {
      v35 = v4 + 29;
      v36 = v4 + 29 + v34;
      do
      {
        v37 = *(unsigned __int8 *)(v35 + 1);
        if ( v34 < v37 + 2 )
          break;
        if ( !*(_BYTE *)v35 )
          goto LABEL_53;
        v35 += v37 + 2;
        v34 = v36 - v35;
      }
      while ( (__int64)(v36 - v35) > 1 );
    }
    v35 = 0;
LABEL_53:
    v38 = *(unsigned int *)(v5 + 24);
    if ( (unsigned int)v38 >= 2 )
    {
      v39 = v5 + 29;
      v40 = v5 + 29 + v38;
      do
      {
        v41 = *(unsigned __int8 *)(v39 + 1);
        if ( v38 < v41 + 2 )
          break;
        if ( !*(_BYTE *)v39 )
          goto LABEL_59;
        v39 += v41 + 2;
        v38 = v40 - v39;
      }
      while ( (__int64)(v40 - v39) > 1 );
    }
    v39 = 0;
LABEL_59:
    v42 = v35 | v39 ? -1 : 0;
    result = v35 ? 1LL : v42;
    if ( v35 && v39 )
    {
      if ( a3 != 2 )
      {
        if ( a3 == 1 )
          return *(unsigned __int8 *)(v39 + 1);
        v47 = *(unsigned __int8 *)(v35 + 1);
        v48 = *(unsigned __int8 *)(v39 + 1);
        if ( (_DWORD)v47 == v48 )
          return memcmp((const void *)(v35 + 2), (const void *)(v39 + 2), v47);
        else
          return (unsigned int)(v48 - v47);
      }
      v43 = *(unsigned __int8 *)(v35 + 1);
      v44 = *(unsigned __int8 *)(v39 + 1);
      if ( (_DWORD)v43 != v44 )
        return (unsigned int)(v44 - v43);
      if ( !(_DWORD)v43 )
        return 0;
      v45 = (unsigned __int8 *)(v39 + 2);
      result = 0;
      while ( !*v45++ )
      {
        if ( !--v43 )
          return result;
      }
      return 0xFFFFFFFFLL;
    }
  }
  return result;
}
