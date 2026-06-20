unsigned __int64 __fastcall ieee80211_scan_state_send_probe(__int64 a1, __int64 *a2)
{
  __int64 v2; // x24
  __int64 v3; // x19
  int v4; // w26
  __int64 v5; // x25
  unsigned int v6; // w8
  __int64 v7; // x21
  __int64 v8; // x27
  __int64 v9; // x28
  int v10; // w20
  int v11; // w9
  unsigned int v12; // w22
  __int64 v13; // x0
  unsigned int *v14; // x22
  __int64 random_u16; // x0
  __int64 v16; // x1
  __int64 v17; // x23
  __int64 v18; // x21
  int v19; // w19
  __int64 v20; // x20
  int v21; // w25
  __int64 v22; // x26
  unsigned __int64 result; // x0
  __int64 v24; // x8
  __int64 v26; // [xsp+18h] [xbp-18h]
  int v27; // [xsp+2Ch] [xbp-4h]

  v2 = *(_QWORD *)(a1 + 4752);
  v3 = a1;
  if ( *(_BYTE *)(v2 + 129) )
    v4 = 134225920;
  else
    v4 = 0x2000;
  if ( *(int *)(v2 + 8) >= 1 )
  {
    v5 = **(unsigned int **)(a1 + 24);
    if ( (unsigned int)v5 > 5 )
    {
      __break(0x5512u);
      return _ieee80211_scan_completed(a1, a2);
    }
    v6 = *(_DWORD *)(v2 + 36);
    v7 = *(_QWORD *)(a1 + 4968);
    v8 = 0;
    v9 = 0;
    v26 = v7;
    v10 = (v6 >> 9) & 4;
    v27 = (v6 >> 11) & 2 | v10;
    do
    {
      v14 = *(unsigned int **)(v3 + 24);
      random_u16 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, unsigned int *, __int64, _QWORD, _QWORD, _QWORD, int))ieee80211_build_probe_req)(
                     v7,
                     v3 + 4872,
                     v2 + 84,
                     *(unsigned int *)(v2 + 40 + 4 * v5),
                     v14,
                     *(_QWORD *)v2 + v8,
                     *(unsigned __int8 *)(*(_QWORD *)v2 + v8 + 32),
                     *(_QWORD *)(v2 + 16),
                     *(_QWORD *)(v2 + 24),
                     v27);
      if ( random_u16 )
      {
        v17 = random_u16;
        if ( v10 )
        {
          v18 = v3;
          v19 = v10;
          v20 = v5;
          v21 = v4;
          v22 = *(_QWORD *)(random_u16 + 224);
          random_u16 = get_random_u16();
          *(_DWORD *)(v17 + 80) |= 0x80u;
          *(_WORD *)(v22 + 22) = 16 * random_u16;
          v4 = v21;
          v5 = v20;
          v10 = v19;
          v3 = v18;
          v7 = v26;
        }
        v11 = *(_DWORD *)(v17 + 80) | 0x400;
        *(_DWORD *)(v17 + 40) |= v4;
        *(_DWORD *)(v17 + 80) = v11;
        v12 = *v14;
        _rcu_read_lock(random_u16, v16);
        v13 = _ieee80211_tx_skb_tid_band(v7, v17, 7, 0xFFFFFFFFLL, v12);
        _rcu_read_unlock(v13);
      }
      ++v9;
      v8 += 33;
    }
    while ( v9 < *(int *)(v2 + 8) );
  }
  result = _msecs_to_jiffies(*(unsigned __int16 *)(v2 + 32));
  if ( result < 0xF )
  {
    v24 = 7;
  }
  else
  {
    result = _msecs_to_jiffies(*(unsigned __int16 *)(v2 + 32));
    v24 = result - 7;
  }
  *a2 = v24;
  *(_DWORD *)(v3 + 4888) = 0;
  return result;
}
