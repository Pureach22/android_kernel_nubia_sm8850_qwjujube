__int64 __fastcall sub_45558(__int64 a1, __int64 a2)
{
  atomic_uint *v2; // x17

  atomic_fetch_add_explicit(v2, (unsigned int)v2, memory_order_acquire);
  return ieee80211_eht_cap_ie_to_sta_eht_cap(a1, a2);
}
