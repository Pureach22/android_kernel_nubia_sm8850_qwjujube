__int64 __fastcall hdd_txrx_populate_cds_config(__int64 a1, __int64 *a2)
{
  __int64 result; // x0

  *(_DWORD *)(a1 + 20) = *(_DWORD *)(cfg_psoc_get_values(*a2) + 560);
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(cfg_psoc_get_values(*a2) + 556);
  result = ucfg_dp_is_rx_threads_enabled(*a2);
  *(_BYTE *)(a1 + 28) = result & 1;
  return result;
}
