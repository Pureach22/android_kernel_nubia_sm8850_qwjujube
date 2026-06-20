__int64 sub_7CEB8()
{
  __int64 v0; // x26

  if ( (v0 & 0x80000000000000LL) == 0 )
    JUMPOUT(0x82B18);
  return ieee80211_sta_set_buffered();
}
