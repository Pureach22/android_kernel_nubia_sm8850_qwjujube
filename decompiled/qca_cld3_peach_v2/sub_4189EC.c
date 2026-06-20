__int64 __fastcall sub_4189EC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  atomic_load_explicit((atomic_uint *volatile)(a8 - 39), memory_order_acquire);
  return lim_update_bss_eht_capable(a1, a2);
}
