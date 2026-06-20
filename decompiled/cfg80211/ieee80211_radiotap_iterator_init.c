__int64 __fastcall ieee80211_radiotap_iterator_init(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v5; // x10
  unsigned __int64 v6; // x9
  unsigned int v7; // w8
  unsigned int v8; // w8
  __int64 v9; // x11
  int v10; // w12
  unsigned __int64 v11; // x8
  bool v12; // cc

  if ( (unsigned int)a3 < 8 )
    return 4294967274LL;
  if ( *(_BYTE *)a2 )
    return 4294967274LL;
  if ( *(unsigned __int16 *)(a2 + 2) > a3 )
    return 4294967274LL;
  *(_QWORD *)a1 = a2;
  v5 = a2 + 8;
  v6 = *(unsigned __int16 *)(a2 + 2);
  *(_QWORD *)(a1 + 68) = v6;
  v7 = *(_DWORD *)(a2 + 4);
  *(_QWORD *)(a1 + 16) = &radiotap_ns;
  *(_QWORD *)(a1 + 24) = a2 + 8;
  *(_QWORD *)(a1 + 40) = a2 + 8;
  *(_QWORD *)(a1 + 76) = v7;
  *(_QWORD *)(a1 + 8) = a4;
  *(_DWORD *)(a1 + 64) = 1;
  if ( (v7 & 0x80000000) != 0 )
  {
    if ( (unsigned int)v6 < 0xC )
      return 4294967274LL;
    v9 = 0;
    while ( 1 )
    {
      v10 = *(_DWORD *)(a2 + v9 + 8);
      v5 = a2 + v9 + 12;
      *(_QWORD *)(a1 + 24) = v5;
      if ( (v10 & 0x80000000) == 0 )
        break;
      v11 = v9 + 16;
      v9 += 4;
      v12 = v11 > v6;
      v8 = -22;
      if ( v12 )
        return v8;
    }
  }
  v8 = 0;
  *(_QWORD *)(a1 + 48) = v5;
  return v8;
}
