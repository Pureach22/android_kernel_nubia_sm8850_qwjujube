__int64 __fastcall cfg80211_get_ies_channel_number(unsigned __int8 *a1, unsigned int a2, int a3)
{
  unsigned __int64 v3; // x9
  unsigned __int8 *v4; // x8
  __int64 v5; // x10
  unsigned int v6; // w8
  unsigned int *v7; // x9
  unsigned __int64 v8; // x11
  int v9; // w8
  unsigned int v10; // w8
  bool v11; // cc
  __int64 v12; // x8
  unsigned __int8 *v13; // x8
  __int64 v14; // x10
  unsigned __int64 v15; // x12
  unsigned __int8 *v16; // x10
  __int64 v17; // x11
  __int64 v18; // x10

  v3 = a2;
  v4 = &a1[a2];
  if ( a3 == 4 )
  {
    if ( (a2 & 0xFFFFFFFE) != 0 )
    {
      while ( 1 )
      {
        v14 = a1[1];
        if ( v3 < v14 + 2 )
          break;
        if ( *a1 == 232 )
        {
          v6 = -1;
          if ( a1 && (unsigned int)v14 >= 6 )
          {
            v13 = a1 + 5;
            return *v13;
          }
          return v6;
        }
        a1 += v14 + 2;
        v3 = v4 - a1;
        if ( v4 - a1 <= 1 )
          return 0xFFFFFFFFLL;
      }
    }
    return 0xFFFFFFFFLL;
  }
  if ( a3 == 3 )
  {
    if ( (a2 & 0xFFFFFFFE) != 0 )
    {
      while ( 1 )
      {
        v5 = a1[1];
        if ( v3 < v5 + 2 )
          break;
        if ( a1[1] && *a1 == 255 && a1[2] == 36 )
        {
          v6 = -1;
          if ( !a1 )
            return v6;
          if ( (unsigned int)v5 < 6 )
            return v6;
          v7 = (unsigned int *)(a1 + 3);
          if ( a1 == (unsigned __int8 *)-3LL )
            return v6;
          v8 = *v7;
          if ( (v8 & 0x4000) != 0 )
            v9 = 9;
          else
            v9 = 6;
          v10 = v9 + (((unsigned int)v8 >> 15) & 1);
          if ( (v8 & 0x20000) != 0 )
            v10 += 5;
          v11 = (unsigned int)v5 > v10;
          v6 = -1;
          if ( !v11 || (v8 & 0x20000) == 0 )
            return v6;
          v12 = 9;
          if ( (v8 & 0x4000) == 0 )
            v12 = 6;
          v13 = (unsigned __int8 *)v7 + v12 + ((v8 >> 15) & 1);
          if ( v13 )
            return *v13;
          return 0xFFFFFFFFLL;
        }
        a1 += v5 + 2;
        v3 = v4 - a1;
        if ( v4 - a1 <= 1 )
          return 0xFFFFFFFFLL;
      }
    }
    return 0xFFFFFFFFLL;
  }
  if ( (a2 & 0xFFFFFFFE) == 0 )
    return 0xFFFFFFFFLL;
  v15 = a2;
  v16 = a1;
  while ( 1 )
  {
    v17 = v16[1];
    if ( v15 < v17 + 2 )
      goto LABEL_44;
    if ( *v16 == 3 )
      break;
    v16 += v17 + 2;
    v15 = v4 - v16;
    if ( v4 - v16 <= 1 )
      goto LABEL_44;
  }
  if ( !v16 || (_DWORD)v17 != 1 )
  {
LABEL_44:
    while ( 1 )
    {
      v18 = a1[1];
      if ( v3 < v18 + 2 )
        break;
      if ( *a1 == 61 )
      {
        v6 = -1;
        if ( a1 && (unsigned int)v18 >= 0x16 )
        {
          v13 = a1 + 2;
          return *v13;
        }
        return v6;
      }
      a1 += v18 + 2;
      v3 = v4 - a1;
      if ( v4 - a1 <= 1 )
        return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v13 = v16 + 2;
  return *v13;
}
