__int64 __fastcall qdf_mem_multi_page_link(__int64 a1, unsigned __int16 *a2, unsigned int a3, int a4, char a5)
{
  unsigned __int64 v5; // x8
  int v6; // w10
  _QWORD *v7; // x14
  unsigned int v8; // w0
  unsigned int v9; // w15
  _QWORD *v10; // x17
  unsigned __int64 v11; // x16
  _QWORD *v12; // x16
  __int64 result; // x0

  if ( !a2[1] )
    return 0;
  v5 = 0;
  v6 = 0;
  do
  {
    if ( a5 )
    {
      v7 = *(_QWORD **)(*((_QWORD *)a2 + 2) + 8 * v5);
      if ( !v7 )
        return 4294967284LL;
    }
    else
    {
      v7 = *(_QWORD **)(*((_QWORD *)a2 + 1) + 24 * v5);
      if ( !v7 )
        return 4294967284LL;
    }
    LOWORD(v8) = *a2;
    if ( *a2 )
    {
      v9 = 0;
      while ( v9 != (unsigned __int16)v8 - 1 )
      {
        v10 = (_QWORD *)((char *)v7 + a3);
        *v7 = v10;
        if ( !(2 - a4 + v6 + v9) )
        {
          v6 = a4 - 1;
LABEL_4:
          v7 = v10;
          goto LABEL_5;
        }
        v8 = *a2;
        ++v9;
        v7 = (_QWORD *)((char *)v7 + a3);
        if ( v9 >= v8 )
        {
          v6 += v9;
          goto LABEL_4;
        }
      }
      v11 = v5 + 1;
      if ( v5 + 1 == a2[1] )
      {
        v6 += v9;
      }
      else
      {
        if ( a5 )
          v12 = (_QWORD *)(*((_QWORD *)a2 + 2) + 8 * v11);
        else
          v12 = (_QWORD *)(*((_QWORD *)a2 + 1) + 24 * v11);
        v6 += v9 + 1;
        *v7 = *v12;
      }
    }
LABEL_5:
    ++v5;
  }
  while ( v5 < a2[1] );
  result = 0;
  if ( v7 )
    *v7 = 0;
  return result;
}
