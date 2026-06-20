__int64 __fastcall sub_1BC340(__int64 a1)
{
  __int64 v1; // x27

  atomic_load_explicit((atomic_uint *volatile)(v1 + 214), memory_order_acquire);
  return wlan_serialization_list_empty(a1);
}
