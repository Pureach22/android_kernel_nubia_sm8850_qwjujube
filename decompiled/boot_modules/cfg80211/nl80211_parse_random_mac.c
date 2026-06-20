__int64 __fastcall nl80211_parse_random_mac(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int16 v5; // w9
  __int64 v6; // x8
  int v7; // w9
  int v8; // w8
  char v10; // w9
  char v11; // w8
  char v12; // w9

  v3 = *(_QWORD *)(a1 + 1720);
  if ( *(_QWORD *)(a1 + 48) )
  {
    if ( v3 )
    {
      v4 = *(_QWORD *)(a1 + 48);
      v5 = *(_WORD *)(v4 + 8);
      LODWORD(v4) = *(_DWORD *)(v4 + 4);
      *((_WORD *)a2 + 2) = v5;
      *a2 = v4;
      v6 = *(_QWORD *)(a1 + 1720);
      v7 = *(_DWORD *)(v6 + 4);
      *(_WORD *)(a3 + 4) = *(_WORD *)(v6 + 8);
      *(_DWORD *)a3 = v7;
      if ( (v7 & 1) != 0 )
      {
        v8 = *a2;
        if ( (*a2 & 1) == 0 )
        {
          *(_BYTE *)a2 = v8 & v7;
          *((_BYTE *)a2 + 1) = *(_BYTE *)(a3 + 1) & BYTE1(v8);
          *((_BYTE *)a2 + 2) = *(_BYTE *)(a3 + 2) & BYTE2(v8);
          v10 = *((_BYTE *)a2 + 4);
          *((_BYTE *)a2 + 3) = *(_BYTE *)(a3 + 3) & HIBYTE(v8);
          v11 = v10 & *(_BYTE *)(a3 + 4);
          v12 = *((_BYTE *)a2 + 5);
          *((_BYTE *)a2 + 4) = v11;
          *((_BYTE *)a2 + 5) = v12 & *(_BYTE *)(a3 + 5);
          return 0;
        }
      }
    }
    return 4294967274LL;
  }
  if ( v3 )
    return 4294967274LL;
  *((_WORD *)a2 + 2) = 0;
  *a2 = 0;
  *(_BYTE *)(a3 + 5) = 0;
  *(_DWORD *)(a3 + 1) = 0;
  *(_BYTE *)a2 = 2;
  *(_BYTE *)a3 = 3;
  return 0;
}
