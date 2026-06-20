__int64 __fastcall hdd_free_tx_rx_pkts_per_mcs(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 480);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_QWORD *)(a1 + 480) = 0;
  }
  result = *(_QWORD *)(a1 + 488);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 488) = 0;
  }
  return result;
}
