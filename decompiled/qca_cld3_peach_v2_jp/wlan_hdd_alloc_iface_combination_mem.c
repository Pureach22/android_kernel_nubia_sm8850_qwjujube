__int64 __fastcall wlan_hdd_alloc_iface_combination_mem(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = _qdf_mem_malloc(0x1518u, "wlan_hdd_alloc_iface_combination_mem", 26643);
  if ( v2 )
    result = 0;
  else
    result = 4294967284LL;
  *(_QWORD *)(a1 + 8288) = v2;
  return result;
}
