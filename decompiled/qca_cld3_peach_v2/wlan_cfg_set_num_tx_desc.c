__int64 __fastcall wlan_cfg_set_num_tx_desc(__int64 result, int a2)
{
  *(_DWORD *)(result + 60) = a2;
  return result;
}
