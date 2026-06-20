__int64 __fastcall mem_buf_get_sgl_buf_size(unsigned int *a1)
{
  __int64 v1; // x9
  __int64 v2; // x10
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 v6; // x11
  __int64 *v7; // x12
  __int64 v8; // x13
  __int64 v9; // x14
  __int64 v10; // t1
  __int64 v11; // x9
  __int64 *v12; // x11
  __int64 v13; // t1

  v1 = *a1;
  if ( !(_DWORD)v1 )
    return 0;
  if ( (_DWORD)v1 == 1 )
  {
    v2 = 0;
    v3 = 0;
  }
  else
  {
    v2 = (unsigned int)v1 & 0xFFFFFFFE;
    v5 = 0;
    v6 = 0;
    v7 = (__int64 *)((char *)a1 + 30);
    v8 = v2;
    do
    {
      v9 = *(v7 - 2);
      v10 = *v7;
      v7 += 4;
      v8 -= 2;
      v5 += v9;
      v6 += v10;
    }
    while ( v8 );
    v3 = v6 + v5;
    if ( v2 == v1 )
      return v3;
  }
  v11 = v1 - v2;
  v12 = (__int64 *)((char *)&a1[4 * v2 + 3] + 2);
  do
  {
    v13 = *v12;
    v12 += 2;
    --v11;
    v3 += v13;
  }
  while ( v11 );
  return v3;
}
