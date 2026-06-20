__int64 __fastcall sub_4BD914(__int64 a1, __int64 a2)
{
  unsigned __int128 *v2; // x11
  __int64 v3; // kr08_8

  v3 = __ldaxp(v2) >> 64;
  return dp_get_peer_mac_from_peer_id(a1, a2, v3);
}
