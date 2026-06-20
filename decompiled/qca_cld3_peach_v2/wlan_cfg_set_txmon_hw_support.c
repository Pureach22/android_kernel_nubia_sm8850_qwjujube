__int64 __fastcall wlan_cfg_set_txmon_hw_support(__int64 result, char a2)
{
  *(_BYTE *)(result + 805) = a2;
  return result;
}
