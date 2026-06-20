__int64 __fastcall wlan_cfg_set_rxdma1_enable(__int64 result)
{
  *(_BYTE *)(result + 633) = 1;
  return result;
}
