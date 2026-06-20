__int64 __fastcall sub_6C883C(__int64 a1, __int64 a2, atomic_uint *a3)
{
  unsigned int v3; // w23

  atomic_fetch_or_explicit(a3, v3, memory_order_relaxed);
  return mlo_mgr_link_switch_connect_done(a1, a2);
}
