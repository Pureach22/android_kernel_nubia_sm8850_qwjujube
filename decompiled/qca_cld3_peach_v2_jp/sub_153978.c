__int64 __fastcall sub_153978(int a1, int a2, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  atomic_load_explicit((atomic_uint *volatile)(a6 + 25), memory_order_acquire);
  return hif_post_init(a1, a2, a3);
}
