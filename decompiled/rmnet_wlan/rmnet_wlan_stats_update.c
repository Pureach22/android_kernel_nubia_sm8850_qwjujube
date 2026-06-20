__int64 __fastcall rmnet_wlan_stats_update(__int64 result)
{
  if ( (unsigned int)result <= 0x16 )
    ++rmnet_wlan_stats[(unsigned int)result];
  return result;
}
