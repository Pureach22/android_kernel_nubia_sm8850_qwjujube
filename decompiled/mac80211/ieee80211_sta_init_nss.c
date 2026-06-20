__int64 __fastcall ieee80211_sta_init_nss(__int64 result)
{
  __int64 v1; // x8
  char v2; // w11
  unsigned int v3; // w9
  char v4; // w11
  char v5; // w11
  char v6; // w11
  int v7; // w10
  int v8; // w11
  unsigned int v9; // w10
  unsigned int v10; // w11
  unsigned int v11; // w11
  int v12; // w12
  unsigned int v13; // w12
  unsigned int v14; // w10
  char v15; // w11

  v1 = *(_QWORD *)(result + 920);
  if ( *(_BYTE *)(v1 + 141) == 1 )
  {
    v2 = *(_BYTE *)(v1 + 155);
    v3 = *(_BYTE *)(v1 + 153) & 0xF;
    if ( v3 <= (*(_BYTE *)(v1 + 154) & 0xFu) )
      v3 = *(_BYTE *)(v1 + 154) & 0xF;
    if ( v3 <= (v2 & 0xFu) )
      v3 = v2 & 0xF;
    v4 = *(_BYTE *)(v1 + 157);
    if ( v3 <= (*(_BYTE *)(v1 + 156) & 0xFu) )
      v3 = *(_BYTE *)(v1 + 156) & 0xF;
    if ( v3 <= (v4 & 0xFu) )
      v3 = v4 & 0xF;
    v5 = *(_BYTE *)(v1 + 159);
    if ( v3 <= (*(_BYTE *)(v1 + 158) & 0xFu) )
      v3 = *(_BYTE *)(v1 + 158) & 0xF;
    if ( v3 <= (v5 & 0xFu) )
      LOBYTE(v3) = v5 & 0xF;
    v6 = *(_BYTE *)(v1 + 161);
    v3 = (unsigned __int8)v3;
    if ( (unsigned __int8)v3 <= (*(_BYTE *)(v1 + 160) & 0xFu) )
      v3 = *(_BYTE *)(v1 + 160) & 0xF;
    if ( v3 <= (v6 & 0xFu) )
      v3 = v6 & 0xF;
  }
  else
  {
    v3 = 0;
  }
  if ( *(_BYTE *)(v1 + 84) == 1 )
  {
    v7 = *(unsigned __int16 *)(v1 + 106);
    v8 = *(unsigned __int16 *)(v1 + 102);
    if ( (~v7 & 0xC000) != 0 )
    {
      v9 = 8;
    }
    else if ( (~v7 & 0x3000) != 0 )
    {
      v9 = 7;
    }
    else if ( (~v7 & 0xC00) != 0 )
    {
      v9 = 6;
    }
    else if ( (~v7 & 0x300) != 0 )
    {
      v9 = 5;
    }
    else if ( (~v7 & 0xC0) != 0 )
    {
      v9 = 4;
    }
    else if ( (~v7 & 0x30) != 0 )
    {
      v9 = 3;
    }
    else if ( (~v7 & 0xC) != 0 )
    {
      v9 = 2;
    }
    else
    {
      v9 = (~v7 & 3) != 0;
    }
    if ( (~v8 & 0xC000) != 0 )
    {
      v10 = 8;
    }
    else if ( (~v8 & 0x3000) != 0 )
    {
      v10 = 7;
    }
    else if ( (~v8 & 0xC00) != 0 )
    {
      v10 = 6;
    }
    else if ( (~v8 & 0x300) != 0 )
    {
      v10 = 5;
    }
    else if ( (~v8 & 0xC0) != 0 )
    {
      v10 = 4;
    }
    else if ( (~v8 & 0x30) != 0 )
    {
      v10 = 3;
    }
    else if ( (~v8 & 0xC) != 0 )
    {
      v10 = 2;
    }
    else
    {
      v10 = (~v8 & 3) != 0;
    }
    if ( v10 < v9 )
      v9 = v10;
    if ( (*(_BYTE *)(v1 + 91) & 8) == 0 )
      v9 = v10;
  }
  else
  {
    v9 = 0;
  }
  if ( *(_BYTE *)(v1 + 46) == 1 )
  {
    if ( *(_BYTE *)(v1 + 49) )
      v11 = 2;
    else
      v11 = 1;
    if ( !*(_BYTE *)(v1 + 50) )
      v11 = *(_BYTE *)(v1 + 49) != 0;
    if ( *(_BYTE *)(v1 + 51) )
      ++v11;
    if ( *(_BYTE *)(v1 + 52) )
      ++v11;
  }
  else
  {
    v11 = 0;
  }
  if ( *(_BYTE *)(v1 + 68) == 1 )
  {
    v12 = *(unsigned __int16 *)(v1 + 76);
    if ( (~v12 & 0xC000) != 0 )
    {
      v13 = 8;
    }
    else if ( (~v12 & 0x3000) != 0 )
    {
      v13 = 7;
    }
    else if ( (~v12 & 0xC00) != 0 )
    {
      v13 = 6;
    }
    else if ( (~v12 & 0x300) != 0 )
    {
      v13 = 5;
    }
    else if ( (~v12 & 0xC0) != 0 )
    {
      v13 = 4;
    }
    else if ( (~v12 & 0x30) != 0 )
    {
      v13 = 3;
    }
    else if ( (~v12 & 0xC) != 0 )
    {
      v13 = 2;
    }
    else
    {
      v13 = (~v12 & 3) != 0;
    }
  }
  else
  {
    v13 = 0;
  }
  if ( v13 > v11 )
    v11 = v13;
  if ( v9 <= v11 )
    v9 = v11;
  if ( v3 <= v9 )
    v3 = v9;
  v14 = *(unsigned __int8 *)(result + 7);
  if ( v3 <= 1 )
    v3 = 1;
  *(_BYTE *)(result + 8) = v3;
  if ( v3 >= v14 )
    v15 = v14;
  else
    v15 = v3;
  if ( v14 )
    LOBYTE(v3) = v15;
  *(_BYTE *)(v1 + 230) = v3;
  return result;
}
