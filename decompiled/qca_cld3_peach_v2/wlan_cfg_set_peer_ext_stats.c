__int64 __fastcall wlan_cfg_set_peer_ext_stats(__int64 result, char a2)
{
  *(_BYTE *)(result + 732) = a2;
  return result;
}
