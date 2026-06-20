__int64 __fastcall cfg80211_chandef_valid(__int64 *a1)
{
  __int64 v1; // x8
  unsigned int v2; // w20
  unsigned int v4; // w10
  int v5; // w19
  int v6; // w21
  __int64 *v7; // x23
  int v8; // w22
  int v9; // w8
  char v10; // w9
  int v11; // w8
  unsigned int v12; // w9
  int v13; // w10
  int v14; // w8
  unsigned int v15; // w11
  int v16; // w11
  unsigned int v17; // w9
  int v18; // w8
  int v19; // w10
  unsigned int v20; // w9
  __int64 *v21; // x19
  char v22; // w8
  int v23; // w14

  v1 = *a1;
  if ( !*a1 )
    return v1 & 1;
  v2 = *((unsigned __int16 *)a1 + 14);
  if ( v2 > 0x3E7 )
  {
LABEL_3:
    LOBYTE(v1) = 0;
    return v1 & 1;
  }
  v4 = *((_DWORD *)a1 + 2);
  v5 = *(_DWORD *)(v1 + 4);
  if ( v4 > 0xC )
  {
LABEL_21:
    if ( *((_DWORD *)a1 + 4) )
      goto LABEL_3;
    goto LABEL_22;
  }
  if ( ((1 << v4) & 0x1F00) == 0 )
  {
    if ( ((1 << v4) & 0xC3) != 0 )
    {
      if ( v2 + 1000 * *((_DWORD *)a1 + 3) != *(unsigned __int16 *)(v1 + 8) + 1000 * v5 )
        goto LABEL_3;
    }
    else if ( v4 == 4 )
    {
      v12 = *((_DWORD *)a1 + 4);
      if ( !v12 )
        goto LABEL_3;
      v13 = *((_DWORD *)a1 + 3);
      LOBYTE(v1) = 0;
      if ( v13 - v12 == 80 || v12 - v13 == 80 )
        return v1 & 1;
      v4 = 4;
      goto LABEL_74;
    }
    goto LABEL_21;
  }
  if ( *(_DWORD *)v1 != 4 )
    goto LABEL_3;
  v6 = *(unsigned __int16 *)(v1 + 8);
  v7 = a1;
  v8 = *((_DWORD *)a1 + 3);
  v9 = ieee80211_s1g_channel_width(*a1);
  if ( v9 <= 6 )
  {
    if ( v9 > 2 )
    {
      a1 = v7;
      if ( (unsigned int)(v9 - 3) < 2 )
      {
        v10 = 0;
        v11 = 40000;
      }
      else
      {
        v10 = 0;
        if ( v9 == 5 )
          v11 = 80000;
        else
          v11 = 2500;
      }
      goto LABEL_60;
    }
    a1 = v7;
    if ( (unsigned int)v9 < 2 )
    {
      v10 = 0;
      v11 = 10000;
      goto LABEL_60;
    }
    if ( v9 == 2 )
    {
      v10 = 0;
      v11 = 20000;
      goto LABEL_60;
    }
LABEL_59:
    v11 = -500;
    v10 = 1;
    __break(0x800u);
    goto LABEL_60;
  }
  if ( v9 <= 9 )
  {
    a1 = v7;
    if ( v9 == 7 )
    {
      v10 = 0;
      v11 = 5000;
    }
    else
    {
      v10 = 0;
      if ( v9 == 8 )
        v11 = 500;
      else
        v11 = 1000;
    }
  }
  else
  {
    a1 = v7;
    if ( v9 > 11 )
    {
      if ( v9 == 12 )
      {
        v10 = 0;
        v11 = 8000;
        goto LABEL_60;
      }
      if ( v9 == 13 )
      {
        v10 = 0;
        v11 = 160000;
        goto LABEL_60;
      }
      goto LABEL_59;
    }
    v10 = 0;
    if ( v9 == 10 )
      v11 = 2000;
    else
      v11 = 4000;
  }
LABEL_60:
  v4 = *((_DWORD *)a1 + 2);
  if ( v4 >= 0xE )
  {
    LOBYTE(v1) = 0;
    __break(0x800u);
    return v1 & 1;
  }
  if ( (v10 & 1) != 0 )
    goto LABEL_3;
  if ( *((_DWORD *)a1 + 4) )
    goto LABEL_3;
  v5 = v6 + 1000 * v5;
  v16 = dword_BA0B8[v4];
  v17 = v2 + 1000 * v8;
  if ( v11 + v5 > v16 + v17 || v5 - v11 < v17 - v16 )
    goto LABEL_3;
LABEL_22:
  LOBYTE(v1) = 0;
  if ( (int)v4 > 4 )
  {
    if ( v4 - 6 >= 7 )
    {
      if ( v4 == 5 )
      {
        v14 = *((_DWORD *)a1 + 3);
      }
      else
      {
        if ( v4 != 13 )
          return v1 & 1;
        v14 = *((_DWORD *)a1 + 3);
        v12 = 0;
        v15 = 13;
        if ( v14 == v5 + 150
          || v14 == v5 + 130
          || v14 == v5 + 110
          || v14 == v5 + 90
          || v14 == v5 - 90
          || v14 == v5 - 110
          || v14 == v5 - 130
          || v14 == v5 - 150 )
        {
          goto LABEL_80;
        }
      }
      v12 = 0;
      if ( v14 == v5 + 70 || v14 == v5 + 50 || v14 == v5 - 50 )
        goto LABEL_79;
      v15 = v4;
      if ( v14 == v5 - 70 )
        goto LABEL_80;
      goto LABEL_74;
    }
LABEL_47:
    v15 = v4;
    v12 = 0;
    goto LABEL_80;
  }
  if ( v4 < 2 )
    goto LABEL_47;
  if ( v4 - 3 >= 2 )
  {
    if ( v4 != 2 )
      return v1 & 1;
    v18 = *((_DWORD *)a1 + 3);
    v12 = 0;
    goto LABEL_76;
  }
  v12 = 0;
LABEL_74:
  v18 = *((_DWORD *)a1 + 3);
  if ( v18 == v5 + 30 )
  {
LABEL_79:
    v15 = v4;
    goto LABEL_80;
  }
  v15 = v4;
  if ( v18 != v5 - 30 )
  {
LABEL_76:
    if ( v18 != v5 + 10 )
    {
      v15 = v4;
      if ( v18 != v5 - 10 )
        goto LABEL_3;
      goto LABEL_80;
    }
    goto LABEL_79;
  }
LABEL_80:
  v19 = *((_DWORD *)a1 + 3);
  if ( (unsigned int)(v19 - 7116) >= 0xFFFFFB77 )
  {
    v23 = dword_BA10C[v15];
    LOBYTE(v1) = 0;
    if ( (unsigned int)(v19 - v23) < 0x1739 || (unsigned int)(v23 + v19) >> 1 > 0xDEA )
      return v1 & 1;
    if ( (unsigned __int16)(v19 - v23 - 5945) % (unsigned int)word_BA0F0[v15] )
      goto LABEL_3;
  }
  if ( v15 != 4 || v12 - 7116 < 0xFFFFFB77 )
    goto LABEL_86;
  LOBYTE(v1) = 0;
  if ( v12 >> 1 <= 0xDD6 )
  {
    v20 = v12 - 40;
    if ( v20 >= 0x1739 )
    {
      if ( (unsigned __int16)(((-13107 * (_WORD)v20 - 1189) << 12) | ((unsigned __int16)(-13107 * v20 - 1189) >> 4)) > 0x333u )
        goto LABEL_3;
LABEL_86:
      if ( !v15 || v19 != 2484 )
      {
        if ( !*((_BYTE *)a1 + 20) && !*((_DWORD *)a1 + 6)
          || (v21 = a1, v22 = cfg80211_edmg_chandef_valid(), a1 = v21, (v22 & 1) != 0) )
        {
          LOBYTE(v1) = valid_puncturing_bitmap(a1);
          return v1 & 1;
        }
      }
      goto LABEL_3;
    }
  }
  return v1 & 1;
}
