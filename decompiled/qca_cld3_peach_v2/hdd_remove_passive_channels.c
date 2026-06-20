__int64 __fastcall hdd_remove_passive_channels(__int64 result, __int64 a2, unsigned __int8 *a3)
{
  unsigned __int8 v3; // w8
  unsigned __int64 v4; // x9
  __int64 v5; // x10
  __int64 i; // x11
  __int64 v7; // x12
  __int64 v8; // x13
  __int64 v9; // x14
  __int64 v10; // x16
  int v11; // w15
  __int64 v12; // x12

  v3 = *a3;
  if ( *a3 )
  {
    v4 = 0;
    v3 = 0;
    v5 = result + 328;
    do
    {
      for ( i = 0; i != 6; ++i )
      {
        v7 = *(_QWORD *)(v5 + 8 * i);
        if ( v7 && *(int *)(v7 + 20) >= 1 )
        {
          v8 = 0;
          v9 = 0;
          do
          {
            v10 = *(_QWORD *)v7 + v8;
            v11 = *(_DWORD *)(a2 + 4 * v4);
            if ( v11 == *(_DWORD *)(v10 + 4) && (*(_BYTE *)(v10 + 12) & 2) == 0 )
            {
              v12 = v3++;
              *(_DWORD *)(a2 + 4 * v12) = v11;
              v7 = *(_QWORD *)(v5 + 8 * i);
            }
            ++v9;
            v8 += 64;
          }
          while ( v9 < *(int *)(v7 + 20) );
        }
      }
      ++v4;
    }
    while ( v4 < *a3 );
  }
  *a3 = v3;
  return result;
}
