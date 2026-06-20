__int64 __fastcall dp_hw_link_desc_ring_deinit(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  return dp_srng_deinit(a1, (__int64 *)(a1 + 1912), 0xBu, 0, a13, a2, a3, a4, a5, a6, a7, a8, a9);
}
