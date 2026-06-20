__int64 __fastcall rmnet_offload_stats_update(__int64 result)
{
  if ( (unsigned int)result <= 0x1B )
    ++rmnet_offload_stats[(unsigned int)result];
  return result;
}
