__int64 __fastcall cfg80211_chandef_primary(__int64 a1, int a2, _WORD *a3)
{
  int v3; // w8
  int v4; // w9
  __int64 v5; // x10
  unsigned int v6; // w10
  unsigned int v7; // w12
  unsigned int v8; // w11
  unsigned int v9; // w8
  unsigned int v10; // w17
  unsigned int v11; // w16
  unsigned int v12; // w15
  unsigned int v13; // w15

  if ( a2 <= 6 )
  {
    if ( a2 > 2 )
    {
      if ( (unsigned int)(a2 - 3) < 2 )
      {
        v3 = 0;
        v4 = 80;
      }
      else
      {
        v3 = 0;
        if ( a2 == 5 )
          v4 = 160;
        else
          v4 = 5;
      }
      goto LABEL_27;
    }
    if ( (unsigned int)a2 < 2 )
    {
      v3 = 0;
      v4 = 20;
      goto LABEL_27;
    }
    if ( a2 == 2 )
    {
      v3 = 0;
      v4 = 40;
      goto LABEL_27;
    }
LABEL_26:
    v4 = -1;
    v3 = 1;
    __break(0x800u);
    goto LABEL_27;
  }
  if ( a2 <= 9 )
  {
    if ( a2 == 7 )
    {
      v3 = 0;
      v4 = 10;
    }
    else
    {
      v3 = 0;
      if ( a2 == 8 )
        v4 = 1;
      else
        v4 = 2;
    }
  }
  else
  {
    if ( a2 > 11 )
    {
      if ( a2 == 12 )
      {
        v3 = 0;
        v4 = 16;
        goto LABEL_27;
      }
      if ( a2 == 13 )
      {
        v3 = 0;
        v4 = 320;
        goto LABEL_27;
      }
      goto LABEL_26;
    }
    v3 = 0;
    if ( a2 == 10 )
      v4 = 4;
    else
      v4 = 8;
  }
LABEL_27:
  v5 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v5 >= 0xE )
  {
    __break(0x800u);
    __break(0x800u);
    return (unsigned int)-1;
  }
  if ( v3 || (v6 = dword_BA144[v5], v4 > (int)v6) )
  {
    __break(0x800u);
    return (unsigned int)-1;
  }
  v7 = *(unsigned __int16 *)(a1 + 30);
  v8 = *(_DWORD *)(*(_QWORD *)a1 + 4LL);
  v9 = *(_DWORD *)(a1 + 12);
  if ( a3 )
  {
    *a3 = v7;
    v7 = 0;
  }
  for ( ; (int)v6 > v4; v6 >>= 1 )
  {
    v10 = v7;
    v11 = v6 / 0x28;
    v12 = v6 >> 2;
    if ( v8 <= v9 )
    {
      if ( a3 )
        LOWORD(v10) = *a3;
      v9 -= v12;
      v13 = v10 & (unsigned __int16)~(-1 << v11);
      if ( !a3 )
      {
LABEL_44:
        v7 = v13;
        continue;
      }
    }
    else
    {
      if ( a3 )
        v10 = (unsigned __int16)*a3;
      v9 += v12;
      v13 = (unsigned __int16)(v10 >> v11);
      if ( !a3 )
        goto LABEL_44;
    }
    *a3 = v13;
  }
  return v9;
}
