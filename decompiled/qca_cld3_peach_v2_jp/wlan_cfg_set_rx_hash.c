__int64 __fastcall wlan_cfg_set_rx_hash(__int64 result, char a2)
{
  *(_BYTE *)(result + 528) = a2;
  return result;
}
