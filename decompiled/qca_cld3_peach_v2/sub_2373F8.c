__int64 __fastcall sub_2373F8(atomic_uint *a1)
{
  atomic_load_explicit(a1, memory_order_acquire);
  return wmi_extract_rtt_hdr();
}
