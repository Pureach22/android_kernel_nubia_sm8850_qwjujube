__int64 __fastcall sub_B0458(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a2 & 0x20000) != 0 )
    JUMPOUT(0xAC408);
  return ieee80211_ie_build_ht_oper(a1, a2, a3, a4, a5);
}
