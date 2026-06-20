__int64 __fastcall msm_get_subset_cores(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  int v4; // w3
  int v5; // w8
  __int64 v6; // x11
  int *v7; // x9
  __int64 v8; // x13
  int v9; // w11
  int v10; // w12
  int v11; // w14
  int v12; // w15
  int v13; // w15

  v3 = a3;
  v4 = 0;
  if ( socinfo )
  {
    if ( (unsigned int)socinfo_format >= 0xE )
    {
      v5 = *(_DWORD *)(socinfo + 156);
      v4 = 0;
      if ( v5 )
      {
        v6 = *(unsigned int *)(socinfo + 160);
        if ( (_DWORD)v6 )
        {
          v7 = (int *)(socinfo + v6);
          if ( (unsigned int)socinfo_format < 0x16 )
          {
            if ( v5 == 1 )
            {
              v4 = *v7;
              return (int)scnprintf(v3, 4096, "%x\n", v4);
            }
            printk(&unk_D463);
            v3 = a3;
          }
          else
          {
            v8 = *(unsigned int *)(socinfo + 224);
            if ( (_DWORD)v8 )
            {
              v4 = 0;
              v9 = 0;
              v10 = 0;
              do
              {
                v11 = *(_DWORD *)(socinfo + v8 + 4LL * v9);
                v12 = v7[v9++];
                v13 = (v12 & ~(-1 << v11)) << v10;
                v10 += v11;
                v4 |= v13;
              }
              while ( v5 != v9 );
              return (int)scnprintf(v3, 4096, "%x\n", v4);
            }
          }
          v4 = 0;
        }
      }
    }
  }
  return (int)scnprintf(v3, 4096, "%x\n", v4);
}
