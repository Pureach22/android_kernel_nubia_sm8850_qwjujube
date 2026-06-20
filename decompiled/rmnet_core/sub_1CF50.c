__int64 __fastcall sub_1CF50(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return rmnet_map_v5_checksum_uplink_packet(a1, a2, a3, a4, a5, a2 ^ 0x3FFE000000000LL);
}
