__int64 __fastcall wlan_cfg_set_num_tx_desc_pool(__int64 result, int a2)
{
  *(_DWORD *)(result + 44) = a2;
  return result;
}
