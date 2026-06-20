__int64 __fastcall sub_21A02C(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w21
  int v4; // w23

  return wmi_unified_peer_active_traffic_map_send(a1, a2, a3, v4 | (unsigned int)(v3 >> 31));
}
