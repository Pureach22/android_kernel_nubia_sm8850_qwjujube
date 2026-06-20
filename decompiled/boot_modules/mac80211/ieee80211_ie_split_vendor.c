unsigned __int64 __fastcall ieee80211_ie_split_vendor(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  for ( ; a3 < a2; a3 += *(unsigned __int8 *)(a1 + a3 + 1) + 2LL )
  {
    if ( *(unsigned __int8 *)(a1 + a3) == 221 )
      break;
  }
  return a3;
}
