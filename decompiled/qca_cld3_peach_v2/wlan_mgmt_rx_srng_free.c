__int64 __fastcall wlan_mgmt_rx_srng_free(__int64 a1)
{
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 16), *(_QWORD *)(*(_QWORD *)(a1 + 16) + 40LL), *(_DWORD *)(a1 + 64));
  return _qdf_mem_free(*(_QWORD *)(a1 + 80));
}
