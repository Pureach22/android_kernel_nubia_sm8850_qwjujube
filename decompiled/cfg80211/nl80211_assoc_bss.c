__int64 __fastcall nl80211_assoc_bss(__int64 a1, __int64 a2, unsigned int a3, _QWORD *a4, unsigned int a5, int a6)
{
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 channel_khz; // x0
  int v16; // w8
  __int64 result; // x0

  v6 = a4[6];
  if ( !v6 )
    return -22;
  v7 = a4[38];
  if ( !v7 )
    return -22;
  v9 = (unsigned int)(1000 * *(_DWORD *)(v7 + 4));
  v10 = a4[290];
  if ( v10 )
    v9 = (unsigned int)(*(_DWORD *)(v10 + 4) + v9);
  channel_khz = ieee80211_get_channel_khz(a1 + 992, v9);
  if ( !channel_khz || (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
    return -22;
  v16 = (a5 >> 30) & 2;
  if ( a5 == a6 )
    ++v16;
  result = _cfg80211_get_bss(a1 + 992, channel_khz, v6 + 4, a2, a3, 0, 2, v16 ^ 2u);
  if ( !result )
    return -2;
  return result;
}
