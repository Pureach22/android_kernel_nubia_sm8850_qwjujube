__int64 __fastcall sub_177E70(__int64 a1)
{
  __int64 v1; // x27

  atomic_load_explicit((atomic_uint *volatile)(v1 + 214), memory_order_acquire);
  return qdf_list_empty(a1);
}
