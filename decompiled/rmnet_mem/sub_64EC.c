__int64 __fastcall sub_64EC(__int64 a1, __int64 a2)
{
  __int64 v2; // x29

  atomic_load_explicit((atomic_ullong *volatile)(v2 + 202), memory_order_acquire);
  return rmnet_mem_cache_add(a1, a2);
}
