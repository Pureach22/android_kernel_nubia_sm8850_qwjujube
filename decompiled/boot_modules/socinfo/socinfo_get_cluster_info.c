__int64 socinfo_get_cluster_info()
{
  __int64 result; // x0
  int v1; // w8
  __int64 v2; // x11
  unsigned int *v3; // x9
  __int64 v4; // x13
  int v5; // w11
  int v6; // w12
  int v7; // w14
  unsigned int v8; // w15
  int v9; // w15

  result = 0;
  if ( socinfo )
  {
    if ( (unsigned int)socinfo_format >= 0xE )
    {
      v1 = *(_DWORD *)(socinfo + 156);
      result = 0;
      if ( v1 )
      {
        v2 = *(unsigned int *)(socinfo + 160);
        if ( (_DWORD)v2 )
        {
          v3 = (unsigned int *)(socinfo + v2);
          if ( (unsigned int)socinfo_format < 0x16 )
          {
            if ( v1 == 1 )
              return *v3;
            printk(&unk_D463);
          }
          else
          {
            v4 = *(unsigned int *)(socinfo + 224);
            if ( (_DWORD)v4 )
            {
              LODWORD(result) = 0;
              v5 = 0;
              v6 = 0;
              do
              {
                v7 = *(_DWORD *)(socinfo + v4 + 4LL * v5);
                v8 = v3[v5++];
                v9 = (v8 & ~(-1 << v7)) << v6;
                v6 += v7;
                result = v9 | (unsigned int)result;
              }
              while ( v1 != v5 );
              return result;
            }
          }
          return 0;
        }
      }
    }
  }
  return result;
}
