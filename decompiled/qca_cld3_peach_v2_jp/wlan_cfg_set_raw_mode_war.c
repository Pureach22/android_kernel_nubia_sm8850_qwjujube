__int64 __fastcall wlan_cfg_set_raw_mode_war(__int64 result, char a2)
{
  *(_BYTE *)(result + 624) = a2;
  return result;
}
