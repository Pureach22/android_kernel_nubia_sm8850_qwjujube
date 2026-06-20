__int64 __fastcall sub_6943E8(__int64 a1, __int64 a2)
{
  __int64 v2; // x29

  atomic_load_explicit((atomic_ullong *volatile)(v2 + 202), memory_order_acquire);
  return host_log_acs_scan_start(a1, a2);
}
