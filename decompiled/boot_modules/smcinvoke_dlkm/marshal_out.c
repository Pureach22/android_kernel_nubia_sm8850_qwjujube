__int64 __fastcall marshal_out(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x9
  unsigned __int64 v4; // x8
  _QWORD *v5; // x11
  __int64 *v6; // x10
  __int64 v7; // t1
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  _QWORD *v10; // x10
  __int64 *v11; // x11
  __int64 v12; // t1

  v3 = a3 & 0xF;
  v4 = ((unsigned __int8)a3 >> 4) + (unsigned int)v3;
  if ( (unsigned __int8)a3 >> 4 )
  {
    v5 = (_QWORD *)(result + 16LL * (a3 & 0xF) + 8);
    v6 = (__int64 *)(a2 + 24LL * (a3 & 0xF) + 16);
    do
    {
      v7 = *v6;
      v6 += 3;
      ++v3;
      *v5 = v7;
      v5 += 2;
    }
    while ( v3 < v4 );
  }
  if ( (unsigned __int16)a3 >> 12 )
  {
    v8 = (unsigned int)v4 + ((a3 >> 8) & 0xF);
    v9 = (unsigned int)v8 + ((unsigned __int16)a3 >> 12);
    v10 = (_QWORD *)(result + 16LL * (unsigned int)v8 + 8);
    v11 = (__int64 *)(a2 + 24LL * (unsigned int)v8 + 8);
    do
    {
      v12 = *v11;
      v11 += 3;
      ++v8;
      *(v10 - 1) = do_invoke;
      *v10 = v12;
      v10 += 2;
    }
    while ( v8 < v9 );
  }
  return result;
}
