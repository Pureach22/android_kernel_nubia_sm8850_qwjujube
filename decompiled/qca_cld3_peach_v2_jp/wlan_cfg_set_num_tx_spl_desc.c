__int64 __fastcall wlan_cfg_set_num_tx_spl_desc(__int64 result, int a2)
{
  *(_DWORD *)(result + 64) = a2;
  return result;
}
