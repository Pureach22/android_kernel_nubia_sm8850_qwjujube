__int64 __fastcall _rmnet_offload_stats_update(__int64 result, __int64 a2)
{
  if ( (unsigned int)result <= 0x1B )
    rmnet_offload_stats[(unsigned int)result] += a2;
  return result;
}
