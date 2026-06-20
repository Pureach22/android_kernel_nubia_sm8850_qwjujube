__int64 __fastcall wlan_cfg_set_delay_mon_replenish(__int64 result, char a2)
{
  *(_BYTE *)(result + 634) = a2;
  return result;
}
