__int64 __fastcall ieee80211_ie_len_he_cap(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 lock; // x0
  unsigned int **v5; // x8
  __int64 v6; // x21
  __int64 unlock; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x8
  int v12; // w9
  unsigned int v13; // w10
  __int64 v14; // x9
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x10
  unsigned int v18; // w9
  int v19; // w19
  int v20; // w20
  unsigned int v21; // w8
  char v22; // w21

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
    return ieee80211_put_he_cap(unlock, v8, v9, v10);
  }
  v11 = *(_QWORD *)(*(_QWORD *)(v2 + 72) + 8 * v6 + 328);
  if ( !v11 )
    return 0;
  v12 = *(_DWORD *)(a1 + 4720);
  if ( *(_BYTE *)(a1 + 5848) != 1 )
    goto LABEL_12;
  if ( v12 == 2 )
  {
    v13 = 8;
    v14 = *(unsigned __int16 *)(v11 + 92);
    if ( !*(_WORD *)(v11 + 92) )
      return 0;
    goto LABEL_14;
  }
  if ( v12 != 3 )
  {
LABEL_12:
    v13 = (unsigned __int8)*(_DWORD *)(a1 + 4720);
    if ( v13 >= 0xC )
    {
      __break(0x800u);
      return 0;
    }
    v14 = *(unsigned __int16 *)(v11 + 92);
    if ( !*(_WORD *)(v11 + 92) )
      return 0;
    goto LABEL_14;
  }
  v13 = 9;
  v14 = *(unsigned __int16 *)(v11 + 92);
  if ( !*(_WORD *)(v11 + 92) )
    return 0;
LABEL_14:
  v16 = *(_QWORD *)(v11 + 96);
  if ( v13 == 4 )
    LOBYTE(v13) = 3;
  v17 = 1LL << v13;
  while ( ((unsigned __int16)v17 & *(_WORD *)v16) == 0 )
  {
    --v14;
    v16 += 128;
    if ( !v14 )
      return 0;
  }
  result = 0;
  if ( v16 && v16 != -2 && (*(_BYTE *)(v16 + 2) & 1) != 0 )
  {
    v18 = *(unsigned __int8 *)(v16 + 9);
    if ( (v18 & 8) != 0 )
      v19 = 8;
    else
      v19 = 4;
    v20 = (v18 >> 2) & 4;
    if ( *(char *)(v16 + 15) < 0 )
    {
      v22 = *(_BYTE *)(v16 + 32);
      v21 = ((unsigned int)(unsigned __int8)(_sw_hweight8(v22 & 0x78) * (6 * (v22 & 7) + 6) + 7) + 7) >> 3;
    }
    else
    {
      v21 = 0;
    }
    return v20 + v19 + v21 + 20;
  }
  return result;
}
