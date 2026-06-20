unsigned __int64 __fastcall rmnet_frag_header_ptr(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  unsigned int v4; // w10
  __int64 v5; // x8
  unsigned int v6; // w20
  __int64 *v8; // x11
  __int64 *v9; // x22
  unsigned int v10; // w8
  unsigned int v11; // w12
  __int64 v12; // x13
  unsigned __int64 v13; // x10
  __int64 *v14; // x23
  unsigned int v15; // w24
  unsigned int v16; // w9
  unsigned int v17; // w10
  __int64 v18; // x9
  unsigned __int64 v19; // x8
  size_t v20; // x21

  v4 = *(_DWORD *)(a1 + 48);
  v5 = 0;
  if ( a3 + a2 <= v4 && v4 >= a2 )
  {
    v6 = a3;
    if ( v4 >= a3 )
    {
      v9 = (__int64 *)(a1 + 16);
      v8 = *(__int64 **)(a1 + 16);
      if ( v8 != (__int64 *)(a1 + 16) )
      {
        v10 = a2;
        while ( 1 )
        {
          v11 = *((_DWORD *)v8 + 6);
          if ( v10 < v11 )
            break;
          v8 = (__int64 *)*v8;
          v10 -= v11;
          if ( v8 == v9 )
            goto LABEL_14;
        }
        v12 = v8[2];
        v13 = 0;
        if ( v12 && (v12 & 1) == 0 )
          v13 = (((v12 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *((unsigned int *)v8 + 7);
        if ( v10 + a3 <= v11 )
          return v13 + v10;
        v4 = *(_DWORD *)(a1 + 48);
      }
LABEL_14:
      v5 = 0;
      if ( a3 + a2 <= v4 && v4 >= a2 && v4 >= a3 )
      {
        if ( a3 )
        {
          v14 = (__int64 *)*v9;
          if ( (__int64 *)*v9 != v9 )
          {
            v15 = 0;
            do
            {
              v16 = *((_DWORD *)v14 + 6);
              if ( a2 >= v16 )
              {
                a2 -= v16;
              }
              else
              {
                v17 = v16 - a2;
                v18 = v14[2];
                v19 = 0;
                if ( v6 >= v17 )
                  v20 = v17;
                else
                  v20 = v6;
                if ( v18 && (v18 & 1) == 0 )
                  v19 = (((v18 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                      + *((unsigned int *)v14 + 7);
                memcpy((void *)(a4 + v15), (const void *)(v19 + a2), v20);
                a2 = 0;
                v15 += v20;
                v6 -= v20;
              }
              v14 = (__int64 *)*v14;
            }
            while ( v14 != v9 && v6 );
          }
        }
        return a4;
      }
    }
  }
  return v5;
}
