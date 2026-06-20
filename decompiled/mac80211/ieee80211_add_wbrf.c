__int64 __fastcall ieee80211_add_wbrf(__int64 result, __int64 a2)
{
  if ( *(_BYTE *)(result + 5464) == 1 )
    return nl80211_chan_width_to_mhz(*(unsigned int *)(a2 + 8));
  return result;
}
