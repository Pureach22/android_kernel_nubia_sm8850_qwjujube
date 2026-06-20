__int64 __fastcall wlan_cfg_set_dp_soc_rxdma_refill_ring_size(__int64 result, int a2)
{
  *(_DWORD *)(result + 600) = a2;
  return result;
}
