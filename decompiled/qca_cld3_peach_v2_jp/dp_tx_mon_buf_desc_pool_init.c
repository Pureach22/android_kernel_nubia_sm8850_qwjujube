__int64 __fastcall dp_tx_mon_buf_desc_pool_init(__int64 a1)
{
  __int64 v1; // x19
  int dp_soc_tx_mon_buf_ring_size; // w0

  v1 = *(_QWORD *)(a1 + 20056);
  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(*(_QWORD *)(a1 + 40));
  return dp_mon_desc_pool_init((unsigned int *)(v1 + 696), dp_soc_tx_mon_buf_ring_size);
}
