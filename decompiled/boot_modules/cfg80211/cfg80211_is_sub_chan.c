__int64 __fastcall cfg80211_is_sub_chan(__int64 *a1, __int64 a2, char a3)
{
  __int64 v3; // x8
  int v4; // w9
  bool v5; // zf
  int v6; // w10
  int v7; // w8
  int v9; // w12
  int v10; // w11
  unsigned int v11; // w12
  unsigned int v12; // w11
  int v13; // w12
  int v14; // w11
  unsigned int v15; // w10
  int v16; // w9
  unsigned int v17; // w12

  v3 = *a1;
  if ( !*a1 )
    return (unsigned int)v3;
  v4 = *(_DWORD *)(a2 + 4);
  v5 = *(_DWORD *)(v3 + 4) == v4;
  LODWORD(v3) = v5;
  if ( v5 || (a3 & 1) != 0 )
    return (unsigned int)v3;
  v6 = *((_DWORD *)a1 + 2);
  LODWORD(v3) = 0;
  if ( v6 <= 4 )
  {
    if ( (unsigned int)v6 >= 2 )
    {
      if ( (unsigned int)(v6 - 3) >= 2 )
      {
        if ( v6 != 2 )
          goto LABEL_14;
        v7 = 20;
      }
      else
      {
        v7 = 40;
      }
      goto LABEL_16;
    }
    return (unsigned int)v3;
  }
  if ( (unsigned int)(v6 - 6) < 7 )
    return (unsigned int)v3;
  if ( v6 != 5 )
  {
    if ( v6 == 13 )
    {
      v7 = 160;
      goto LABEL_16;
    }
LABEL_14:
    __break(0x800u);
    return 0;
  }
  v7 = 80;
LABEL_16:
  v9 = *((_DWORD *)a1 + 3);
  v10 = v9 - v7;
  v11 = v7 - 10 + v9;
  v12 = v10 + 10;
  if ( v12 > v11 )
  {
LABEL_19:
    v13 = *((_DWORD *)a1 + 4);
    if ( !v13 )
      return 0;
    v14 = v13 - v7;
    v15 = v7 - 10 + v13;
    if ( v13 - v7 + 10 > v15 )
      return 0;
    v16 = v4 - 10;
    do
    {
      LODWORD(v3) = v16 == v14;
      if ( v16 == v14 )
        break;
      v17 = v14 + 30;
      v14 += 20;
    }
    while ( v17 <= v15 );
    return (unsigned int)v3;
  }
  while ( v4 != v12 )
  {
    v12 += 20;
    if ( v12 > v11 )
      goto LABEL_19;
  }
  return 1;
}
