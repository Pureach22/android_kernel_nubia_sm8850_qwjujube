__int64 __fastcall wlan_hdd_free_iface_combination_mem(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 8288);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 8288) = 0;
  }
  return result;
}
