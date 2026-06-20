bool __fastcall cfg80211_edmg_chandef_valid(__int64 a1)
{
  char v1; // w9
  int v2; // w8
  unsigned int v3; // w10
  unsigned __int64 v4; // x11
  _BOOL8 result; // x0
  unsigned int v6; // w13
  unsigned int v7; // w14
  unsigned __int64 v8; // x12
  unsigned int v9; // w15
  unsigned __int64 v10; // x13
  unsigned int v11; // w15
  unsigned int v12; // w16
  unsigned __int64 v13; // x14
  unsigned int v14; // w17
  unsigned __int64 v15; // x15
  unsigned int v16; // w9
  unsigned int v17; // w10

  v1 = *(_BYTE *)(a1 + 20);
  if ( !v1 )
    return 0;
  v2 = *(_DWORD *)(a1 + 24);
  if ( !v2 || (unsigned int)(*(_DWORD *)(*(_QWORD *)a1 + 4LL) - 58320) > 0x2E68 )
    return 0;
  v3 = v1 & 1;
  v4 = v1 & 2;
  result = 0;
  if ( (v1 & 2) != 0 )
    v6 = v3 + 1;
  else
    v6 = 0;
  if ( v6 <= v3 )
    v7 = v1 & 1;
  else
    v7 = v6;
  v8 = v1 & 4;
  if ( (v1 & 4) != 0 )
    v9 = v6 + 1;
  else
    v9 = 0;
  if ( v9 > v7 )
    v7 = v9;
  v10 = v1 & 8;
  if ( (v1 & 8) != 0 )
    v11 = v9 + 1;
  else
    v11 = 0;
  if ( v11 <= v7 )
    v12 = v7;
  else
    v12 = v11;
  v13 = v1 & 0x10;
  if ( (v1 & 0x10) != 0 )
    v14 = v11 + 1;
  else
    v14 = 0;
  if ( v14 > v12 )
    v12 = v14;
  v15 = v1 & 0x20;
  if ( (v1 & 0x20) != 0 )
    v16 = v14 + 1;
  else
    v16 = 0;
  if ( v16 <= v12 )
    v16 = v12;
  if ( v2 > 9 )
  {
    if ( v2 > 12 )
    {
      if ( v2 == 13 )
        goto LABEL_51;
      if ( v2 == 14 )
        goto LABEL_53;
      if ( v2 != 15 )
        return result;
    }
    else
    {
      if ( v2 == 10 )
        goto LABEL_53;
      if ( v2 != 11 )
        goto LABEL_49;
    }
    goto LABEL_47;
  }
  if ( v2 > 6 )
  {
    if ( v2 != 7 )
    {
      if ( v2 != 8 )
      {
LABEL_51:
        if ( v16 < 2 )
          return 0;
        goto LABEL_54;
      }
LABEL_49:
      if ( !v16 )
        return 0;
      goto LABEL_54;
    }
LABEL_47:
    if ( v16 < 4 )
      return 0;
    goto LABEL_54;
  }
  if ( v2 == 4 )
    goto LABEL_49;
  if ( v2 == 5 )
    goto LABEL_51;
  if ( v2 != 6 )
    return result;
LABEL_53:
  if ( v16 < 3 )
    return 0;
LABEL_54:
  result = 0;
  if ( ((1 << v2) & 0xF0) != 0 )
    return 1;
  v17 = v3 + (v4 >> 1) + (v8 >> 2) + (v10 >> 3) + (v13 >> 4) + (v15 >> 5);
  if ( ((1 << v2) & 0xF00) != 0 )
    return v17 >= 2;
  if ( ((1 << v2) & 0xF000) != 0 )
  {
    result = 0;
    if ( v17 >= 4 && v16 >= 2 )
      return 1;
  }
  return result;
}
