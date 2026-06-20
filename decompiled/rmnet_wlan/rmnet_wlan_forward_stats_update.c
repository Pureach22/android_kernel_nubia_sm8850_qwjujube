__int64 __fastcall rmnet_wlan_forward_stats_update(__int64 result)
{
  if ( (unsigned int)result <= 0x2D )
    ++rmnet_wlan_forward_stats[(unsigned int)result];
  return result;
}
