__int64 __fastcall ieee80211_check_tim(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w9
  unsigned int v5; // w8

  v3 = 0;
  if ( a1 && a2 >= 4u )
  {
    v4 = (unsigned __int8)(a3 >> 3);
    v5 = *(_BYTE *)(a1 + 2) & 0xFE;
    if ( v4 < v5 )
      return 0;
    if ( v4 > (unsigned __int8)(a2 + v5 - 4) )
      return 0;
    return (*(unsigned __int8 *)(a1 + (unsigned __int8)((a3 >> 3) - v5) + 3) & (1 << (a3 & 7))) != 0;
  }
  return v3;
}
