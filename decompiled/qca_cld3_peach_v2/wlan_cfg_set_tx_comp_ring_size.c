__int64 __fastcall wlan_cfg_set_tx_comp_ring_size(__int64 result, int a2)
{
  *(_DWORD *)(result + 140) = a2;
  return result;
}
