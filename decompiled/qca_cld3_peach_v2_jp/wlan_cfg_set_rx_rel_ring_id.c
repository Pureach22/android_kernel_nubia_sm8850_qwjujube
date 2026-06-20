__int64 __fastcall wlan_cfg_set_rx_rel_ring_id(__int64 result, char a2)
{
  *(_BYTE *)(result + 796) = a2;
  return result;
}
