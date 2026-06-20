unsigned __int64 __fastcall cfg80211_chandef_compatible(unsigned __int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 result; // x0
  unsigned int v4; // w11
  unsigned int v5; // w12
  int v7; // w8
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x19
  __int64 v10; // x8
  int v11; // w11
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w10
  unsigned int v15; // w11
  bool v16; // cc
  unsigned int v17; // w15
  int v18; // w10
  unsigned int v19; // w12
  unsigned int v20; // w10
  unsigned int v21; // w11
  unsigned int v22; // w13
  bool v23; // cc
  unsigned int v24; // w17

  v2 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 != *(_QWORD *)a2 )
  {
LABEL_2:
    result = 0;
    goto LABEL_3;
  }
  v4 = *(_DWORD *)(a1 + 8);
  v5 = *(_DWORD *)(a2 + 8);
  if ( v4 == v5 )
  {
    if ( *(_DWORD *)(a1 + 12) == *(_DWORD *)(a2 + 12)
      && *(unsigned __int16 *)(a1 + 28) == *(unsigned __int16 *)(a2 + 28)
      && *(_DWORD *)(a1 + 16) == *(_DWORD *)(a2 + 16) )
    {
      v7 = *(unsigned __int16 *)(a1 + 30);
      result = a2;
      if ( v7 == *(unsigned __int16 *)(a2 + 30) )
        goto LABEL_3;
    }
    goto LABEL_2;
  }
  result = 0;
  if ( v4 - 6 < 7 || v5 - 6 < 7 )
    goto LABEL_3;
  if ( v4 <= v5 )
    v8 = a1;
  else
    v8 = a2;
  if ( v4 <= v5 )
    v9 = a2;
  else
    v9 = a1;
  if ( v4 <= v5 )
    v10 = v2;
  else
    v10 = *(_QWORD *)a2;
  v11 = *(_DWORD *)(v8 + 8);
  if ( (unsigned int)v11 < 2 )
    goto LABEL_24;
  if ( v11 <= 5 )
  {
    if ( (unsigned int)(v11 - 3) < 2 )
    {
      v14 = 80;
      goto LABEL_37;
    }
    if ( v11 == 2 )
    {
      v13 = *(_DWORD *)(v8 + 12);
      v12 = *(unsigned __int16 *)(v8 + 30);
      goto LABEL_44;
    }
    if ( v11 == 5 )
    {
      v14 = 160;
      goto LABEL_37;
    }
LABEL_55:
    v12 = 0;
    __break(0x800u);
    __break(0x800u);
    goto LABEL_29;
  }
  if ( (unsigned int)(v11 - 6) < 7 )
  {
    v12 = 0;
    __break(0x800u);
LABEL_29:
    v13 = -1;
    goto LABEL_44;
  }
  if ( v11 != 13 )
    goto LABEL_55;
  v14 = 320;
LABEL_37:
  v15 = *(_DWORD *)(v10 + 4);
  v13 = *(_DWORD *)(v8 + 12);
  v12 = *(unsigned __int16 *)(v8 + 30);
  do
  {
    v16 = v15 > v13;
    v17 = v12 & (unsigned __int16)~(unsigned __int16)(-1 << (v14 / 0x28));
    v12 = (unsigned __int16)(v12 >> (v14 / 0x28));
    if ( v15 > v13 )
      v13 += v14 >> 2;
    else
      v13 -= v14 >> 2;
    if ( !v16 )
      v12 = v17;
    v16 = v14 > 0x51;
    v14 >>= 1;
  }
  while ( v16 );
LABEL_44:
  v18 = *(_DWORD *)(v9 + 8);
  if ( v18 > 4 )
  {
    if ( (unsigned int)(v18 - 6) >= 7 )
    {
      if ( v18 != 5 )
      {
        if ( v18 == 13 )
        {
          v19 = 320;
          goto LABEL_59;
        }
LABEL_57:
        v20 = 0;
        __break(0x800u);
        __break(0x800u);
        v21 = -1;
        goto LABEL_66;
      }
      v19 = 160;
      goto LABEL_59;
    }
LABEL_52:
    v20 = 0;
    __break(0x800u);
    v21 = -1;
    goto LABEL_66;
  }
  if ( (unsigned int)v18 < 2 )
    goto LABEL_52;
  if ( (unsigned int)(v18 - 3) >= 2 )
  {
    if ( v18 == 2 )
    {
      v21 = *(_DWORD *)(v9 + 12);
      v20 = *(unsigned __int16 *)(v9 + 30);
      goto LABEL_66;
    }
    goto LABEL_57;
  }
  v19 = 80;
LABEL_59:
  v21 = *(_DWORD *)(v9 + 12);
  v22 = *(_DWORD *)(*(_QWORD *)v9 + 4LL);
  v20 = *(unsigned __int16 *)(v9 + 30);
  do
  {
    v23 = v22 > v21;
    v24 = v20 & (unsigned __int16)~(unsigned __int16)(-1 << (v19 / 0x28));
    v20 = (unsigned __int16)(v20 >> (v19 / 0x28));
    if ( v22 > v21 )
      v21 += v19 >> 2;
    else
      v21 -= v19 >> 2;
    if ( !v23 )
      v20 = v24;
    v16 = v19 > 0x51;
    v19 >>= 1;
  }
  while ( v16 );
LABEL_66:
  result = -22;
  if ( v13 != v21 || v12 != v20 )
    goto LABEL_3;
  if ( v9 && *(_DWORD *)(v8 + 8) == 2 )
  {
LABEL_24:
    result = v9;
    goto LABEL_3;
  }
  result = check_chandef_primary_compat(v8, v9, 3);
  if ( !result )
  {
    if ( *(_DWORD *)(v8 + 8) == 4 )
    {
      result = 0;
    }
    else
    {
      result = check_chandef_primary_compat(v8, v9, 5);
      if ( !result )
        __break(0x800u);
    }
  }
LABEL_3:
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return 0;
  return result;
}
