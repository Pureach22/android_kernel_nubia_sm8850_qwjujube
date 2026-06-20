__int64 __fastcall wlan_cfg_set_rx_flow_tag_enabled(__int64 result, char a2)
{
  *(_BYTE *)(result + 697) = a2;
  return result;
}
