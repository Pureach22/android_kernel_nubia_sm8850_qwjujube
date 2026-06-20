__int64 __fastcall wlan_cfg_set_peer_jitter_stats(__int64 result, char a2)
{
  *(_BYTE *)(result + 756) = a2;
  return result;
}
