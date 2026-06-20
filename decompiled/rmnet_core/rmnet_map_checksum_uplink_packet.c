__int64 __fastcall rmnet_map_checksum_uplink_packet(__int64 result, __int64 a2, __int64 a3, int a4, char a5)
{
  if ( a4 == 64 )
    return rmnet_map_v5_checksum_uplink_packet(result, a2, a3, a5 & 1);
  if ( a4 == 8 )
    return rmnet_map_v4_checksum_uplink_packet(result, a3);
  return result;
}
