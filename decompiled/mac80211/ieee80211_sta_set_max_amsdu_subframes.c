__int64 __fastcall ieee80211_sta_set_max_amsdu_subframes(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w8

  *(_BYTE *)(result + 2717) = 0;
  if ( a3 >= 8 )
  {
    v3 = *(unsigned __int8 *)(a2 + 7) >> 7;
    if ( a3 != 8 )
      v3 = v3 & 0xFFFFFFFD | (2 * (*(_BYTE *)(a2 + 8) & 1));
    if ( v3 )
      *(_BYTE *)(result + 2717) = 4 << (4 - v3);
  }
  return result;
}
