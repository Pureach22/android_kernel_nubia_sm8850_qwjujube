__int64 __fastcall wlan_cfg_set_rx_refill_buf_pool_size(__int64 result, int a2)
{
  *(_DWORD *)(result + 736) = a2;
  return result;
}
