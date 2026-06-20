__int64 __fastcall socinfo_get_part_info(unsigned int a1)
{
  unsigned __int64 v1; // x9
  __int64 v2; // x8
  __int64 v3; // x11
  unsigned __int8 *v4; // x11
  __int64 v5; // x9
  unsigned int v6; // w12
  unsigned __int8 *v7; // x10
  __int64 v8; // x14
  int v9; // w12
  int v10; // w13
  unsigned __int8 *v11; // x17
  __int64 v12; // x2
  __int64 v13; // x3
  int v14; // t1
  __int64 v15; // x14

  if ( a1 >= 0x11 )
  {
    printk(&unk_D6FA);
    return 0;
  }
  v1 = 4294967274LL;
  if ( socinfo )
  {
    if ( (unsigned int)socinfo_format >= 0xE )
    {
      v2 = *(unsigned int *)(socinfo + 164);
      if ( (_DWORD)v2 )
      {
        v3 = *(unsigned int *)(socinfo + 168);
        if ( (_DWORD)v3 )
        {
          v4 = (unsigned __int8 *)(socinfo + v3);
          if ( (unsigned int)v2 >= 2 )
          {
            v5 = (unsigned int)v2 & 0xFFFFFFFE;
            v8 = 0;
            v9 = 0;
            v7 = &v4[4 * v5];
            v10 = 0;
            do
            {
              v11 = &v4[4 * v8];
              v12 = 1LL << v8;
              v13 = 2LL << v8;
              v8 += 2;
              v9 |= ((int)(*(_DWORD *)v11 << 31) >> 31) & v12;
              v10 |= (v11[4] << 31 >> 31) & v13;
            }
            while ( v5 != v8 );
            v6 = v10 | v9;
            if ( v5 == v2 )
              goto LABEL_12;
          }
          else
          {
            v5 = 0;
            v6 = 0;
            v7 = v4;
          }
          do
          {
            v14 = *v7;
            v7 += 4;
            v15 = 1LL << v5++;
            v6 |= (v14 << 31 >> 31) & v15;
          }
          while ( v2 != v5 );
LABEL_12:
          v1 = v6;
        }
      }
    }
  }
  return (v1 >> a1) & 1;
}
