__int64 __fastcall sub_9B34C(__int64 a1)
{
  __int64 v1; // x12

  return adreno_ib_create_object_list(a1, atomic_load_explicit((atomic_uint *volatile)(v1 + 246), memory_order_acquire));
}
