__int64 __fastcall wiphy_verify_iface_combinations(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x12
  unsigned int v7; // w11
  int v8; // w13
  bool v9; // zf
  __int64 v10; // x13
  unsigned int v11; // w14
  int v12; // w15
  unsigned __int16 *v13; // x16
  int v14; // w17
  int v15; // w2

  if ( a3 < 1 )
    return 0;
  v4 = 0;
  v5 = (unsigned int)a3;
LABEL_3:
  v6 = a2 + 24 * v4;
  v7 = *(unsigned __int16 *)(v6 + 12);
  if ( v7 > 1 || *(_BYTE *)(v6 + 16) )
  {
    v8 = *(_DWORD *)(v6 + 8);
    if ( v8 )
    {
      if ( (a4 & 1) != 0 || (v8 != 1 ? (v9 = *(_BYTE *)(v6 + 16) == 0) : (v9 = 1), v9) )
      {
        v10 = *(unsigned __int8 *)(v6 + 14);
        if ( *(_BYTE *)(v6 + 14) )
        {
          v11 = 0;
          v12 = 0;
          v13 = (unsigned __int16 *)(*(_QWORD *)v6 + 2LL);
          while ( 1 )
          {
            v14 = *v13;
            if ( (v14 & v12) != 0 )
              break;
            v15 = *(v13 - 1);
            if ( !*(v13 - 1) || (*(_WORD *)(a1 + 92) & (unsigned __int16)v14) != 0 )
              break;
            if ( (a4 & 1) == 0 )
            {
              if ( (v14 & 0x400) != 0 )
              {
                if ( v15 != 1 )
                  break;
              }
              else if ( (v14 & 0x1000) != 0 && v15 != 1 )
              {
                break;
              }
            }
            if ( (v14 & 2) != 0 && *(_DWORD *)(v6 + 20) || (v14 & ~*(unsigned __int16 *)(a1 + 96)) != 0 )
              break;
            --v10;
            v12 |= v14;
            v11 += v15;
            v13 += 2;
            if ( !v10 )
            {
              if ( (v12 & 0x20) != 0 || v11 < v7 )
                break;
              if ( ++v4 != v5 )
                goto LABEL_3;
              return 0;
            }
          }
        }
      }
    }
  }
  __break(0x800u);
  return 4294967274LL;
}
