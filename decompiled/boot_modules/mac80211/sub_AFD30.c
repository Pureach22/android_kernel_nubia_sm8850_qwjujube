__int64 __fastcall sub_AFD30(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (a2 & 0x80000000000LL) == 0 )
    JUMPOUT(0xAFB0C);
  return ieee80211_ie_build_vht_cap(a1, a2, a3);
}
