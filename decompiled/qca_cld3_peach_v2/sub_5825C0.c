__int64 __fastcall sub_5825C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  atomic_uint *v5; // x9

  atomic_fetch_and_explicit(v5, ~(_DWORD)a3, memory_order_relaxed);
  return wlan_cfg_get_rx_flow_search_table_size(a1, a2, a3, a4, a5);
}
