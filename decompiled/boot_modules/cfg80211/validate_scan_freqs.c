__int64 __fastcall validate_scan_freqs(_WORD *a1)
{
  unsigned __int16 *v1; // x0
  __int16 v2; // t1
  unsigned int v3; // w9
  unsigned __int16 *v4; // x8
  int v5; // w10
  unsigned int v6; // w11
  bool v7; // cc
  unsigned int v8; // w8
  unsigned __int16 *v9; // x10
  int v10; // w11
  __int64 v11; // x12
  unsigned int v12; // w12
  unsigned __int16 *v13; // x13
  int v14; // w14
  __int64 v15; // x15
  unsigned int v16; // w15

  v2 = *a1;
  v1 = a1 + 2;
  v3 = (unsigned __int16)(v2 - 4);
  if ( v3 < 4 )
  {
    return 0;
  }
  else
  {
    v4 = v1;
    v5 = v3;
    do
    {
      v6 = *v4;
      if ( v6 < 4 || v5 < v6 )
        break;
      if ( v6 != 8 )
        return 0;
      v7 = v5 <= 11;
      v5 -= 8;
      v4 += 4;
    }
    while ( !v7 );
    v8 = 0;
    v9 = v1;
    v10 = v3;
    do
    {
      v12 = *v9;
      if ( v12 < 4 || v10 < v12 )
        break;
      ++v8;
      v13 = v1;
      v14 = v3;
      do
      {
        v16 = *v13;
        if ( v16 < 4 || v14 < v16 )
          break;
        if ( v9 != v13 && *((_DWORD *)v9 + 1) == *((_DWORD *)v13 + 1) )
          return 0;
        v15 = (v16 + 3) & 0x1FFFC;
        v14 -= v15;
        v13 = (unsigned __int16 *)((char *)v13 + v15);
      }
      while ( v14 > 3 );
      v11 = (v12 + 3) & 0x1FFFC;
      v10 -= v11;
      v9 = (unsigned __int16 *)((char *)v9 + v11);
    }
    while ( v10 > 3 );
  }
  return v8;
}
