__int64 sub_472F8()
{
  __int64 v0; // x25

  if ( (v0 & 0x100000000000LL) == 0 )
    JUMPOUT(0x4ADFC);
  return _cfg80211_alloc_event_skb();
}
