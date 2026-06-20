__int64 __fastcall sub_1C920(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x14

  *(_QWORD *)(v2 + 26320) = v3;
  return rmnet_map_checksum_downlink_packet(a1, a2);
}
