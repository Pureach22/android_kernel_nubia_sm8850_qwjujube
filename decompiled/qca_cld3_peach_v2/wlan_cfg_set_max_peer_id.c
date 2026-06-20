__int64 __fastcall wlan_cfg_set_max_peer_id(__int64 result, int a2)
{
  *(_DWORD *)(result + 76) = a2;
  return result;
}
