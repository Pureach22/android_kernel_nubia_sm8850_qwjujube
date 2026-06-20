unsigned __int64 __fastcall ieee80211_config_default_beacon_key(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4)
{
  unsigned __int64 result; // x0

  if ( (a3 & 0x80000000) != 0 )
  {
    if ( *(_WORD *)(a2 + 8488) )
      return -22;
    result = a2 + 6304;
    if ( (unsigned __int64)(a2 + 6304) < 0xFFFFFFFFFFFFF001LL )
    {
LABEL_5:
      ieee80211_set_default_beacon_key(result, a4);
      return 0;
    }
  }
  else
  {
    if ( a3 >= 0xF )
    {
      __break(0x5512u);
      return ieee80211_start_ap(a1, MEMORY[0xFFFFFFFFFFFEE99C]);
    }
    result = *(_QWORD *)(a2 + 8LL * a3 + 7256);
    if ( !result )
      return -67;
    if ( result < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_5;
  }
  return result;
}
