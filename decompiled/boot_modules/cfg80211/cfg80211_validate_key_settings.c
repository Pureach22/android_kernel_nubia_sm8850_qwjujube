__int64 __fastcall cfg80211_validate_key_settings(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4,
        __int64 a5)
{
  unsigned int v5; // w9
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  bool v8; // w14
  unsigned int v9; // w15
  bool v10; // cc
  int v11; // w15
  bool v12; // zf
  int v13; // w9
  char v14; // w8
  int v15; // w8
  unsigned __int16 v17; // w8
  int v18; // w8
  unsigned __int64 v19; // x8
  _DWORD *v20; // x10
  __int64 v21; // x12
  unsigned __int64 v22; // x11

  if ( (a4 & 1) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 1109) & 0x42) != 0 )
    {
      v5 = 7;
      if ( (a3 & 0x80000000) != 0 )
        return 4294967274LL;
      goto LABEL_19;
    }
    v6 = *(unsigned int *)(a1 + 1148);
    if ( (int)v6 >= 1 )
    {
      v7 = 0;
      v8 = 1;
      do
      {
        v9 = *(_DWORD *)(*(_QWORD *)(a1 + 1152) + 4 * v7) - 1027078;
        v10 = v9 > 7;
        v11 = (1 << v9) & 0xE1;
        v12 = v10 || v11 == 0;
        if ( !v12 )
          break;
        v8 = ++v7 < v6;
      }
      while ( v6 != v7 );
      if ( v8 )
        v5 = 5;
      else
        v5 = 3;
      if ( (a3 & 0x80000000) != 0 )
        return 4294967274LL;
      goto LABEL_19;
    }
  }
  v5 = 3;
  if ( (a3 & 0x80000000) != 0 )
    return 4294967274LL;
LABEL_19:
  if ( v5 < a3 )
    return 4294967274LL;
  if ( a5 && ((a4 ^ 1) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 1093) & 1) == 0 )
      return 4294967274LL;
  }
  else if ( ((a5 == 0) & a4) != 0 )
  {
    return 4294967274LL;
  }
  v13 = *(_DWORD *)(a2 + 28);
  v14 = v13 - 4;
  if ( (unsigned int)(v13 - 1027076) > 9 )
  {
LABEL_38:
    if ( v13 != 1027073 )
    {
      if ( v13 != 1027074 )
        goto LABEL_66;
      if ( a3 && (a4 & 1) != 0 || *(_DWORD *)(a2 + 32) )
        return 4294967274LL;
      goto LABEL_65;
    }
LABEL_44:
    if ( a3 > 3 )
      return 4294967274LL;
    goto LABEL_48;
  }
  if ( ((1 << v14) & 0x71) == 0 )
  {
    if ( ((1 << v14) & 0x384) != 0 )
    {
      if ( a3 < 4 || (a4 & 1) != 0 )
        return 4294967274LL;
      goto LABEL_48;
    }
    if ( v13 == 1027077 )
      goto LABEL_44;
    goto LABEL_38;
  }
  v15 = *(_DWORD *)(a2 + 32);
  if ( v15 == 2 || !((v15 != 1) | a4 & 1) )
    return 4294967274LL;
  if ( (*(_BYTE *)(a1 + 1108) & 0x10) != 0 )
  {
    if ( a3 < 2 )
      goto LABEL_48;
  }
  else if ( !a3 )
  {
    goto LABEL_48;
  }
  if ( (a4 & 1) != 0 )
    return 4294967274LL;
LABEL_48:
  if ( v13 <= 1027079 )
  {
    if ( v13 <= 1027075 )
    {
      if ( *(_DWORD *)(a2 + 16) != 5 )
        return 4294967274LL;
      goto LABEL_66;
    }
    if ( v13 != 1027076 )
    {
      if ( v13 == 1027077 )
      {
        if ( *(_DWORD *)(a2 + 16) != 13 )
          return 4294967274LL;
        goto LABEL_66;
      }
      if ( v13 != 1027078 )
        goto LABEL_66;
    }
  }
  else if ( v13 > 1027082 )
  {
    if ( v13 != 1027083 )
    {
      if ( v13 != 1027084 )
      {
        v17 = -21491;
LABEL_64:
        if ( v13 != (v17 | 0xF0000) )
          goto LABEL_66;
      }
LABEL_65:
      if ( *(_DWORD *)(a2 + 16) != 32 )
        return 4294967274LL;
      goto LABEL_66;
    }
  }
  else if ( v13 != 1027080 )
  {
    if ( v13 != 1027081 )
    {
      v17 = -21494;
      goto LABEL_64;
    }
    goto LABEL_65;
  }
  if ( *(_DWORD *)(a2 + 16) != 16 )
    return 4294967274LL;
LABEL_66:
  if ( *(_QWORD *)(a2 + 8) && (unsigned int)(v13 - 1027073) <= 0xC )
  {
    v18 = 1 << (v13 - 1);
    if ( (v18 & 0x1FAA) != 0 )
    {
      if ( *(_DWORD *)(a2 + 20) == 6 )
        goto LABEL_70;
      return 4294967274LL;
    }
    if ( (v18 & 0x11) != 0 )
      return 4294967274LL;
  }
LABEL_70:
  v19 = *(unsigned int *)(a1 + 1148);
  if ( (int)v19 < 1 )
    return 4294967274LL;
  v20 = *(_DWORD **)(a1 + 1152);
  if ( *v20 == v13 )
    return 0;
  v21 = 1;
  do
  {
    v22 = v21;
    if ( v19 == v21 )
      break;
    v12 = v20[v21++] == v13;
  }
  while ( !v12 );
  if ( v22 >= v19 )
    return (unsigned int)-22;
  else
    return 0;
}
