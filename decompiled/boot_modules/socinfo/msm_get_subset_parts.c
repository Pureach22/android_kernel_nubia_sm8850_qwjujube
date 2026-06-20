__int64 __fastcall msm_get_subset_parts(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w3
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x9
  unsigned __int8 *v9; // x10
  __int64 v10; // x14
  int v11; // w12
  int v12; // w13
  __int64 v13; // x17
  __int64 v14; // x2
  __int64 v15; // x3
  int v16; // t1
  __int64 v17; // x13

  v4 = -22;
  if ( socinfo )
  {
    if ( (unsigned int)socinfo_format >= 0xE )
    {
      v5 = *(unsigned int *)(socinfo + 164);
      if ( (_DWORD)v5 )
      {
        v6 = *(unsigned int *)(socinfo + 168);
        if ( (_DWORD)v6 )
        {
          v7 = socinfo + v6;
          if ( (unsigned int)v5 < 2 )
          {
            v8 = 0;
            v4 = 0;
            v9 = (unsigned __int8 *)(socinfo + v6);
            do
            {
LABEL_10:
              v16 = *v9;
              v9 += 4;
              v17 = 1LL << v8++;
              v4 |= (v16 << 31 >> 31) & v17;
            }
            while ( v5 != v8 );
            return (int)scnprintf(a3, 4096, "%x\n", v4);
          }
          v8 = (unsigned int)v5 & 0xFFFFFFFE;
          v10 = 0;
          v11 = 0;
          v9 = (unsigned __int8 *)(v7 + 4 * v8);
          v12 = 0;
          do
          {
            v13 = v7 + 4 * v10;
            v14 = 1LL << v10;
            v15 = 2LL << v10;
            v10 += 2;
            v11 |= ((int)(*(_DWORD *)v13 << 31) >> 31) & v14;
            v12 |= (*(unsigned __int8 *)(v13 + 4) << 31 >> 31) & v15;
          }
          while ( v8 != v10 );
          v4 = v12 | v11;
          if ( v8 != v5 )
            goto LABEL_10;
        }
      }
    }
  }
  return (int)scnprintf(a3, 4096, "%x\n", v4);
}
