__int64 __fastcall sub_582A4C(__int64 a1, __int64 a2, int a3)
{
  atomic_uint *v3; // x9

  atomic_fetch_and_explicit(v3, ~a3, memory_order_relaxed);
  return wlan_cfg_get_pointer_timer_threshold_rx(a1);
}
