__int64 __fastcall sub_B0624(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (a3 & 4) != 0 )
    JUMPOUT(0xAF15C);
  return ieee80211_ie_build_vht_oper(a1, a2, a3);
}
