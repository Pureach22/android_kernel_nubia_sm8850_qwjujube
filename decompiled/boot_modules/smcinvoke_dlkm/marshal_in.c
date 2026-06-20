__int64 __fastcall marshal_in(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 *v3; // x9
  _QWORD *v4; // x10
  __int64 v5; // x12
  __int64 v6; // t1
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x9
  __int64 *v9; // x11
  _QWORD *v10; // x10
  __int64 v11; // t1
  int v12; // w10
  unsigned __int64 v13; // x9
  __int64 *v14; // x11
  _QWORD *v15; // x10
  __int64 v16; // t1
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x10
  _DWORD *v20; // x12
  unsigned __int64 v21; // x14
  _DWORD *v22; // x10

  if ( (a3 & 0xF) != 0 )
  {
    v3 = (__int64 *)(a2 + 8);
    v4 = (_QWORD *)(result + 16);
    v5 = a3 & 0xF;
    do
    {
      --v5;
      *(v4 - 1) = *(v3 - 1);
      v6 = *v3;
      v3 += 2;
      *((_DWORD *)v4 - 4) = 1;
      *v4 = v6;
      v4 += 3;
    }
    while ( v5 );
  }
  v7 = ((unsigned __int8)a3 >> 4) + (a3 & 0xF);
  if ( (unsigned __int8)a3 >> 4 )
  {
    v8 = a3 & 0xF;
    v9 = (__int64 *)(a2 + 16 * v8 + 8);
    v10 = (_QWORD *)(result + 24 * v8 + 16);
    do
    {
      ++v8;
      *(v10 - 1) = *(v9 - 1);
      v11 = *v9;
      v9 += 2;
      *((_DWORD *)v10 - 4) = 2;
      *v10 = v11;
      v10 += 3;
    }
    while ( v8 < v7 );
  }
  v12 = (a3 >> 8) & 0xF;
  v13 = (unsigned int)(v7 + v12);
  if ( v12 )
  {
    v14 = (__int64 *)(a2 + 16LL * (unsigned int)v7 + 8);
    v15 = (_QWORD *)(result + 24LL * (unsigned int)v7 + 8);
    do
    {
      v16 = *v14;
      v14 += 2;
      ++v7;
      *((_DWORD *)v15 - 2) = 3;
      *v15 = v16;
      v15 += 3;
    }
    while ( v7 < v13 );
  }
  if ( (unsigned __int16)a3 >> 12 )
  {
    v17 = (unsigned int)v13 + ((unsigned __int16)a3 >> 12);
    if ( v13 + 1 > v17 )
      v18 = v13 + 1;
    else
      v18 = (unsigned int)v13 + ((unsigned __int16)a3 >> 12);
    v19 = v18 - v13;
    if ( v19 < 2 )
      goto LABEL_18;
    v20 = (_DWORD *)(result + 24LL * (unsigned int)v13);
    v13 += v19 & 0xFFFFFFFFFFFFFFFELL;
    v21 = v19 & 0xFFFFFFFFFFFFFFFELL;
    do
    {
      *v20 = 4;
      v21 -= 2LL;
      v20[6] = 4;
      v20 += 12;
    }
    while ( v21 );
    if ( v19 != (v19 & 0xFFFFFFFFFFFFFFFELL) )
    {
LABEL_18:
      v22 = (_DWORD *)(result + 24LL * (int)v13);
      do
      {
        ++v13;
        *v22 = 4;
        v22 += 6;
      }
      while ( v13 < v17 );
    }
  }
  return result;
}
