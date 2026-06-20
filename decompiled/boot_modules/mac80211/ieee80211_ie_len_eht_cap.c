__int64 __fastcall ieee80211_ie_len_eht_cap(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 lock; // x0
  unsigned int **v5; // x8
  __int64 v6; // x21
  __int64 unlock; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x9
  int v12; // w8
  int v13; // w11
  unsigned int v14; // w10
  __int64 v15; // x12
  _BYTE *v16; // x10
  __int64 result; // x0
  __int64 v18; // x13
  int v19; // w12
  __int64 v20; // x11
  __int64 v21; // x9
  __int64 v22; // x12
  _BYTE *i; // x9
  int v24; // w10
  int v25; // w11
  int v26; // w10
  int v27; // w8
  int v28; // w19
  unsigned int v29; // w8
  unsigned __int8 v30; // w20

  v2 = *(_QWORD *)(a1 + 1616);
  if ( *(_WORD *)(a1 + 5800) )
    __break(0x800u);
  lock = _rcu_read_lock(a1, a2);
  v5 = *(unsigned int ***)(a1 + 5640);
  if ( !v5 )
  {
    _rcu_read_unlock(lock);
    return 0;
  }
  v6 = **v5;
  unlock = _rcu_read_unlock(lock);
  if ( (unsigned int)v6 >= 6 )
  {
    __break(0x5512u);
    return ieee80211_put_eht_cap(unlock, v8, v9, v10);
  }
  v11 = *(_QWORD *)(*(_QWORD *)(v2 + 72) + 8 * v6 + 328);
  if ( !v11 )
    return 0;
  v12 = *(_DWORD *)(a1 + 4720);
  v13 = *(unsigned __int8 *)(a1 + 5848);
  if ( v13 == 1 )
  {
    if ( v12 == 2 )
    {
      v14 = 8;
      v15 = *(unsigned __int16 *)(v11 + 92);
      if ( !*(_WORD *)(v11 + 92) )
        goto LABEL_10;
      goto LABEL_14;
    }
    if ( v12 == 3 )
    {
      v14 = 9;
      v15 = *(unsigned __int16 *)(v11 + 92);
      if ( !*(_WORD *)(v11 + 92) )
      {
LABEL_10:
        v16 = nullptr;
LABEL_22:
        if ( !*(_BYTE *)(a1 + 5848) )
          goto LABEL_34;
        goto LABEL_29;
      }
      goto LABEL_14;
    }
  }
  v14 = (unsigned __int8)*(_DWORD *)(a1 + 4720);
  if ( v14 >= 0xC )
  {
    __break(0x800u);
    v12 = *(_DWORD *)(a1 + 4720);
    v16 = nullptr;
    if ( (*(_BYTE *)(a1 + 5848) & 1) == 0 )
      goto LABEL_34;
    goto LABEL_29;
  }
  v15 = *(unsigned __int16 *)(v11 + 92);
  if ( !*(_WORD *)(v11 + 92) )
    goto LABEL_10;
LABEL_14:
  if ( v14 == 4 )
    LOBYTE(v14) = 3;
  v18 = 1LL << v14;
  v16 = (_BYTE *)(*(_QWORD *)(v11 + 96) + 2LL);
  while ( ((unsigned __int16)v18 & *((_WORD *)v16 - 1)) == 0 )
  {
    --v15;
    v16 += 128;
    if ( !v15 )
      goto LABEL_24;
  }
  if ( v16 != byte_2 )
  {
    if ( (*v16 & 1) != 0 )
      goto LABEL_22;
LABEL_24:
    v16 = nullptr;
    if ( (v13 & 1) != 0 )
      goto LABEL_29;
    goto LABEL_34;
  }
  v16 = nullptr;
  if ( !*(_BYTE *)(a1 + 5848) )
    goto LABEL_34;
LABEL_29:
  if ( v12 == 2 )
  {
    v19 = 8;
    goto LABEL_35;
  }
  if ( v12 == 3 )
  {
    v19 = 9;
    goto LABEL_35;
  }
LABEL_34:
  v19 = (unsigned __int8)v12;
  if ( (unsigned __int8)v12 >= 0xCu )
  {
    __break(0x800u);
    return 0;
  }
LABEL_35:
  v20 = *(unsigned __int16 *)(v11 + 92);
  if ( !*(_WORD *)(v11 + 92) )
    return 0;
  v21 = *(_QWORD *)(v11 + 96);
  if ( v19 == 4 )
    LOBYTE(v19) = 3;
  v22 = 1LL << v19;
  for ( i = (_BYTE *)(v21 + 59); ((unsigned __int16)v22 & *(_WORD *)(i - 59)) == 0; i += 128 )
  {
    if ( !--v20 )
      return 0;
  }
  if ( i == (_BYTE *)&unk_3B || *i != 1 )
    return 0;
  result = 0;
  if ( v16 && i )
  {
    v24 = (unsigned __int8)v16[7];
    if ( (v24 & 2) != 0 )
    {
      v28 = 17;
    }
    else
    {
      v25 = (v24 << 29 >> 31) & 3;
      if ( (v24 & 8) != 0 )
        v25 += 3;
      if ( (i[3] & 2) != 0 )
        v26 = v25 + 3;
      else
        v26 = v25;
      if ( v12 == 3 )
        v27 = 3;
      else
        v27 = 4;
      if ( v26 )
        v27 = v26;
      v28 = v27 + 14;
    }
    if ( (i[8] & 8) != 0 )
    {
      v30 = i[21];
      v29 = ((unsigned int)_sw_hweight16(v30 & 0xF0) * (6 * (v30 & 0xF) + 6) + 16) >> 3;
    }
    else
    {
      v29 = 0;
    }
    return v29 + v28;
  }
  return result;
}
