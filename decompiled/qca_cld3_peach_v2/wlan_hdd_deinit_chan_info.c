__int64 __fastcall wlan_hdd_deinit_chan_info(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 1736);
  *(_QWORD *)(a1 + 1736) = 0;
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
